/*
  ==============================================================================

    Oscillator.cpp
    Created: 30 Apr 2015 11:05:53pm
    Author:  Jonathan

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "AddSynthSounds.h"
#include "EnvelopeGenerator.h"

class SineWaveVoice : public SynthesiserVoice
{
public:
	SineWaveVoice(const EnvelopeGenerator* eg)
		: angleDelta(0.0),
		tailOff(0.0)
	{
		envGen = eg;
	}

	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SineWaveSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity,
		SynthesiserSound* /*sound*/,
		int /*currentPitchWheelPosition*/) override
	{
		currentAngle = 0.0;
		level = velocity * 0.15;
		tailOff = 0.0;

		double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		double cyclesPerSample = cyclesPerSecond / getSampleRate();

		angleDelta = cyclesPerSample * 2.0 * double_Pi;
	}

	void stopNote(float /*velocity*/, bool allowTailOff) override
	{
		if (allowTailOff)
		{
			// start a tail-off by setting this flag. The render callback will pick up on
			// this and do a fade out, calling clearCurrentNote() when it's finished.

			if (tailOff == 0.0) // we only need to begin a tail-off if it's not already doing so - the
				// stopNote method could be called more than once.
				tailOff = 1.0;
		}
		else
		{
			// we're being told to stop playing immediately, so reset everything..

			clearCurrentNote();
			angleDelta = 0.0;
		}
	}

	void pitchWheelMoved(int /*newValue*/) override
	{
		// can't be bothered implementing this for the demo!
	}

	void controllerMoved(int /*controllerNumber*/, int /*newValue*/) override
	{
		// not interested in controllers in this case.
	}

	void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override
	{
		if (angleDelta != 0.0)
		{
			if (tailOff > 0)
			{
				while (--numSamples >= 0)
				{
					const float currentSample = (float)(sin(currentAngle) * level * tailOff);

					for (int i = outputBuffer.getNumChannels(); --i >= 0;)
						outputBuffer.addSample(i, startSample, currentSample);

					currentAngle += angleDelta;
					++startSample;

					tailOff *= 0.99;

					if (tailOff <= 0.005)
					{
						clearCurrentNote();

						angleDelta = 0.0;
						break;
					}
				}
			}
			else
			{
				while (--numSamples >= 0)
				{
					const float currentSample = (float)(sin(currentAngle) * level);

					for (int i = outputBuffer.getNumChannels(); --i >= 0;)
						outputBuffer.addSample(i, startSample, currentSample);

					currentAngle += angleDelta;
					++startSample;
				}
			}
		}
	}

private:
	double currentAngle, angleDelta, level, tailOff;
	const EnvelopeGenerator* envGen;
};

Oscillator::Oscillator(const EnvelopeGenerator* envGen)
{
	wavetype = Sine;
	synthVoice = new SineWaveVoice(envGen);
}

Oscillator::~Oscillator()
{

}

void Oscillator::setWaveType(WaveType wt)
{
	wavetype = wt;

	// Change synth voice!!!!!!!!!!!!
}

WaveType Oscillator::getWaveType()
{
	return wavetype;
}

SynthesiserVoice& Oscillator::getSynthVoice()
{
	return *synthVoice;
}