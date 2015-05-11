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
	SineWaveVoice(EnvelopeGenerator* eg)
		: angleDelta(0.0),
		tailOff(0.0)
	{
		envGen = eg;
		currEnvSection = Attack;
		sampleCounter = 0;
		needFinishSustain = false;
	}

	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SineWaveSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity,
		SynthesiserSound* /*sound*/,
		int /*currentPitchWheelPosition*/) override
	{
		currEnvSection = Attack;
		currentAngle = 0.0;
		sampleCounter = 0;
		level = velocity * 0.15;
		tailOff = 0.0;
		needFinishSustain = false;

		double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		double cyclesPerSample = cyclesPerSecond / getSampleRate();

		const double attackRate = envGen->getLevels().attackRate;
		angleDelta = cyclesPerSample * 2.0 * double_Pi;
	}

	void stopNote(float /*velocity*/, bool allowTailOff) override
	{
		if (allowTailOff)
		{
			// start a tail-off by setting this flag. The render callback will pick up on
			// this and do a fade out, calling clearCurrentNote() when it's finished.

			if (currEnvSection != Release) // we only need to begin a tail-off if it's not already doing so - the
				// stopNote method could be called more than once.
			{
				if (envGen->getLevels().isSustain)
					needFinishSustain = true;
				else 
				{
					currEnvSection = Release;
					sampleCounter = 0;
				}
			}
		}
		else
		{
			// we're being told to stop playing immediately, so reset everything..

			clearCurrentNote();
			angleDelta = 0.0;
			currEnvSection = Attack;
			sampleCounter = 0;
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
		Levels levels = envGen->getLevels();
		if (angleDelta != 0.0)
		{
			if (level > 0)
			{
				while (--numSamples >= 0)
				{

					// Find where we are in the levels sections and set volume level
					int currEnvIndex;
					if (currEnvSection == Attack)
					{
						currEnvIndex = (sampleCounter * 100 * levels.attackRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = levels.sustainValues[0];
							currEnvSection = Sustain;
							sampleCounter = 0;
						}
						else 
						{
							level = levels.attackValues[currEnvIndex];
						}
					}
					else if (currEnvSection == Sustain)
					{
						currEnvIndex = (sampleCounter  * 100 * levels.sustainRate / getSampleRate());
						if ((!levels.isSustain && currEnvIndex >= 12) || needFinishSustain)
						{
							currEnvSection = Release;
							sampleCounter = 0;
							level = levels.releaseValues[0];
						}
						else 
						{
							currEnvIndex %= 12;
							level = levels.sustainValues[currEnvIndex];
						}
					}
					else  // Release
					{
						currEnvIndex = (sampleCounter * 100 * levels.releaseRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = 0;
							sampleCounter = 0;
						}
						else 
						{
							level = levels.releaseValues[currEnvIndex];
						}
					}
					

					const float currentSample = (float)(sin(currentAngle) * level * 0.15);

					for (int i = outputBuffer.getNumChannels(); --i >= 0;)
						outputBuffer.addSample(i, startSample, currentSample);

					currentAngle += angleDelta;
					++startSample;
					++sampleCounter;

					if (level == 0)
					{
						clearCurrentNote();

						angleDelta = 0.0;
						currEnvSection = Attack;
						sampleCounter = 0;
						break;
					}
				}
			}
		}
	}

private:
	double currentAngle, angleDelta, level, tailOff;
	EnvelopeGenerator* envGen;
	EnvelopeType currEnvSection;
	int sampleCounter;  // Used for calculating length of envelope sections
	bool needFinishSustain;
};

class SquareWaveVoice : public SynthesiserVoice
{
public:
	SquareWaveVoice(EnvelopeGenerator* eg)
		: angleDelta(0.0),
		tailOff(0.0)
	{
		envGen = eg;
		currEnvSection = Attack;
		sampleCounter = 0;
		needFinishSustain = false;
	}

	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SquareWaveSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity,
		SynthesiserSound* /*sound*/,
		int /*currentPitchWheelPosition*/) override
	{
		currEnvSection = Attack;
		currentAngle = 0.0;
		sampleCounter = 0;
		level = velocity * 0.15;
		tailOff = 0.0;
		needFinishSustain = false;

		double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		double cyclesPerSample = cyclesPerSecond / getSampleRate();

		const double attackRate = envGen->getLevels().attackRate;
		angleDelta = cyclesPerSample * 2.0 * double_Pi;
	}

	void stopNote(float /*velocity*/, bool allowTailOff) override
	{
		if (allowTailOff)
		{
			// start a tail-off by setting this flag. The render callback will pick up on
			// this and do a fade out, calling clearCurrentNote() when it's finished.

			if (currEnvSection != Release) // we only need to begin a tail-off if it's not already doing so - the
				// stopNote method could be called more than once.
			{
				if (envGen->getLevels().isSustain)
					needFinishSustain = true;
				else
				{
					currEnvSection = Release;
					sampleCounter = 0;
				}
			}
		}
		else
		{
			// we're being told to stop playing immediately, so reset everything..

			clearCurrentNote();
			angleDelta = 0.0;
			currEnvSection = Attack;
			sampleCounter = 0;
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
		Levels levels = envGen->getLevels();
		if (angleDelta != 0.0)
		{
			if (level > 0)
			{
				while (--numSamples >= 0)
				{

					// Find where we are in the levels sections and set volume level
					int currEnvIndex;
					if (currEnvSection == Attack)
					{
						currEnvIndex = (sampleCounter * 100 * levels.attackRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = levels.sustainValues[0];
							currEnvSection = Sustain;
							sampleCounter = 0;
						}
						else
						{
							level = levels.attackValues[currEnvIndex];
						}
					}
					else if (currEnvSection == Sustain)
					{
						currEnvIndex = (sampleCounter * 100 * levels.sustainRate / getSampleRate());
						if ((!levels.isSustain && currEnvIndex >= 12) || needFinishSustain)
						{
							currEnvSection = Release;
							sampleCounter = 0;
							level = levels.releaseValues[0];
						}
						else
						{
							currEnvIndex %= 12;
							level = levels.sustainValues[currEnvIndex];
						}
					}
					else  // Release
					{
						currEnvIndex = (sampleCounter * 100 * levels.releaseRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = 0;
							sampleCounter = 0;
						}
						else
						{
							level = levels.releaseValues[currEnvIndex];
						}
					}

					float currentSample = level * 0.15;
					if (sin(currentAngle) < 0)
					{
						currentSample *= -1;
					}

					for (int i = outputBuffer.getNumChannels(); --i >= 0;)
						outputBuffer.addSample(i, startSample, currentSample);

					currentAngle += angleDelta;
					++startSample;
					++sampleCounter;

					if (level == 0)
					{
						clearCurrentNote();

						angleDelta = 0.0;
						currEnvSection = Attack;
						sampleCounter = 0;
						break;
					}
				}
			}
		}
	}

private:
	double currentAngle, angleDelta, level, tailOff;
	EnvelopeGenerator* envGen;
	EnvelopeType currEnvSection;
	int sampleCounter;  // Used for calculating length of envelope sections
	bool needFinishSustain;
};

class SawtoothWaveVoice : public SynthesiserVoice
{
public:
	SawtoothWaveVoice(EnvelopeGenerator* eg)
		: angleDelta(0.0),
		tailOff(0.0)
	{
		envGen = eg;
		currEnvSection = Attack;
		sampleCounter = 0;
		needFinishSustain = false;
	}

	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<SawtoothWaveSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity,
		SynthesiserSound* /*sound*/,
		int /*currentPitchWheelPosition*/) override
	{
		currEnvSection = Attack;
		currentAngle = 0.0;
		sampleCounter = 0;
		level = velocity * 0.15;
		tailOff = 0.0;
		needFinishSustain = false;

		double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		double cyclesPerSample = cyclesPerSecond / getSampleRate();

		const double attackRate = envGen->getLevels().attackRate;
		angleDelta = cyclesPerSample * 2.0 * double_Pi;
	}

	void stopNote(float /*velocity*/, bool allowTailOff) override
	{
		if (allowTailOff)
		{
			// start a tail-off by setting this flag. The render callback will pick up on
			// this and do a fade out, calling clearCurrentNote() when it's finished.

			if (currEnvSection != Release) // we only need to begin a tail-off if it's not already doing so - the
				// stopNote method could be called more than once.
			{
				if (envGen->getLevels().isSustain)
					needFinishSustain = true;
				else
				{
					currEnvSection = Release;
					sampleCounter = 0;
				}
			}
		}
		else
		{
			// we're being told to stop playing immediately, so reset everything..

			clearCurrentNote();
			angleDelta = 0.0;
			currEnvSection = Attack;
			sampleCounter = 0;
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
		Levels levels = envGen->getLevels();
		if (angleDelta != 0.0)
		{
			if (level > 0)
			{
				while (--numSamples >= 0)
				{

					// Find where we are in the levels sections and set volume level
					int currEnvIndex;
					if (currEnvSection == Attack)
					{
						currEnvIndex = (sampleCounter * 100 * levels.attackRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = levels.sustainValues[0];
							currEnvSection = Sustain;
							sampleCounter = 0;
						}
						else
						{
							level = levels.attackValues[currEnvIndex];
						}
					}
					else if (currEnvSection == Sustain)
					{
						currEnvIndex = (sampleCounter * 100 * levels.sustainRate / getSampleRate());
						if ((!levels.isSustain && currEnvIndex >= 12) || needFinishSustain)
						{
							currEnvSection = Release;
							sampleCounter = 0;
							level = levels.releaseValues[0];
						}
						else
						{
							currEnvIndex %= 12;
							level = levels.sustainValues[currEnvIndex];
						}
					}
					else  // Release
					{
						currEnvIndex = (sampleCounter * 100 * levels.releaseRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = 0;
							sampleCounter = 0;
						}
						else
						{
							level = levels.releaseValues[currEnvIndex];
						}
					}

					float currentSample = (fmod(currentAngle, 1.f) * 2 - 1) * level * 0.15;
					
					for (int i = outputBuffer.getNumChannels(); --i >= 0;)
						outputBuffer.addSample(i, startSample, currentSample);

					currentAngle += angleDelta;
					++startSample;
					++sampleCounter;

					if (level == 0)
					{
						clearCurrentNote();

						angleDelta = 0.0;
						currEnvSection = Attack;
						sampleCounter = 0;
						break;
					}
				}
			}
		}
	}

private:
	double currentAngle, angleDelta, level, tailOff;
	EnvelopeGenerator* envGen;
	EnvelopeType currEnvSection;
	int sampleCounter;  // Used for calculating length of envelope sections
	bool needFinishSustain;
};

class TriangleWaveVoice : public SynthesiserVoice
{
public:
	TriangleWaveVoice(EnvelopeGenerator* eg)
		: angleDelta(0.0),
		tailOff(0.0)
	{
		envGen = eg;
		currEnvSection = Attack;
		sampleCounter = 0;
		needFinishSustain = false;
	}

	bool canPlaySound(SynthesiserSound* sound) override
	{
		return dynamic_cast<TriangleWaveSound*> (sound) != nullptr;
	}

	void startNote(int midiNoteNumber, float velocity,
		SynthesiserSound* /*sound*/,
		int /*currentPitchWheelPosition*/) override
	{
		currEnvSection = Attack;
		currentAngle = 0.0;
		sampleCounter = 0;
		level = velocity * 0.15;
		tailOff = 0.0;
		needFinishSustain = false;

		double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		double cyclesPerSample = cyclesPerSecond / getSampleRate();

		const double attackRate = envGen->getLevels().attackRate;
		angleDelta = cyclesPerSample * 2.0 * double_Pi;
	}

	void stopNote(float /*velocity*/, bool allowTailOff) override
	{
		if (allowTailOff)
		{
			// start a tail-off by setting this flag. The render callback will pick up on
			// this and do a fade out, calling clearCurrentNote() when it's finished.

			if (currEnvSection != Release) // we only need to begin a tail-off if it's not already doing so - the
				// stopNote method could be called more than once.
			{
				if (envGen->getLevels().isSustain)
					needFinishSustain = true;
				else
				{
					currEnvSection = Release;
					sampleCounter = 0;
				}
			}
		}
		else
		{
			// we're being told to stop playing immediately, so reset everything..

			clearCurrentNote();
			angleDelta = 0.0;
			currEnvSection = Attack;
			sampleCounter = 0;
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
		Levels levels = envGen->getLevels();
		if (angleDelta != 0.0)
		{
			if (level > 0)
			{
				while (--numSamples >= 0)
				{

					// Find where we are in the levels sections and set volume level
					int currEnvIndex;
					if (currEnvSection == Attack)
					{
						currEnvIndex = (sampleCounter * 100 * levels.attackRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = levels.sustainValues[0];
							currEnvSection = Sustain;
							sampleCounter = 0;
						}
						else
						{
							level = levels.attackValues[currEnvIndex];
						}
					}
					else if (currEnvSection == Sustain)
					{
						currEnvIndex = (sampleCounter * 100 * levels.sustainRate / getSampleRate());
						if ((!levels.isSustain && currEnvIndex >= 12) || needFinishSustain)
						{
							currEnvSection = Release;
							sampleCounter = 0;
							level = levels.releaseValues[0];
						}
						else
						{
							currEnvIndex %= 12;
							level = levels.sustainValues[currEnvIndex];
						}
					}
					else  // Release
					{
						currEnvIndex = (sampleCounter * 100 * levels.releaseRate / getSampleRate());
						if (currEnvIndex >= 12)
						{
							level = 0;
							sampleCounter = 0;
						}
						else
						{
							level = levels.releaseValues[currEnvIndex];
						}
					}

					float currentSample = (1 - fabs(fmod(currentAngle, 1.f) - 0.5)*4) * level * 0.15;
					
					for (int i = outputBuffer.getNumChannels(); --i >= 0;)
						outputBuffer.addSample(i, startSample, currentSample);

					currentAngle += angleDelta;
					++startSample;
					++sampleCounter;

					if (level == 0)
					{
						clearCurrentNote();

						angleDelta = 0.0;
						currEnvSection = Attack;
						sampleCounter = 0;
						break;
					}
				}
			}
		}
	}

private:
	double currentAngle, angleDelta, level, tailOff;
	EnvelopeGenerator* envGen;
	EnvelopeType currEnvSection;
	int sampleCounter;  // Used for calculating length of envelope sections
	bool needFinishSustain;
};

Oscillator::Oscillator(EnvelopeGenerator* eg)
{
	wavetype = Sine;
	envGen = eg;
	synthVoice = new SineWaveVoice(eg);
}

Oscillator::~Oscillator()
{

}

void Oscillator::setWaveType(WaveType wt)
{
	wavetype = wt;

	if (wavetype == Sine)
		synthVoice = new SineWaveVoice(envGen);
	else if (wavetype == Square)
		synthVoice = new SquareWaveVoice(envGen);
	else if (wavetype == Triangle)
		synthVoice = new TriangleWaveVoice(envGen);
	else
		synthVoice = new SawtoothWaveVoice(envGen);
}

WaveType Oscillator::getWaveType()
{
	return wavetype;
}

SynthesiserVoice& Oscillator::getSynthVoice()
{
	if (wavetype == Sine)
		synthVoice = new SineWaveVoice(envGen);
	else if (wavetype == Square)
		synthVoice = new SquareWaveVoice(envGen);
	else if (wavetype == Triangle)
		synthVoice = new TriangleWaveVoice(envGen);
	else
		synthVoice = new SawtoothWaveVoice(envGen);


	return *synthVoice;
}