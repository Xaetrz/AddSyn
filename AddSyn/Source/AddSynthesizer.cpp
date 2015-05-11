/*
  ==============================================================================

    AddSynthesizer.cpp
    Created: 17 Apr 2015 4:19:57pm
    Author:  Jonathan

  ==============================================================================
*/

#include "AddSynthesizer.h"
#include "AddSynthSounds.h"

AddSynthesizer::AddSynthesizer()
{
	synth = new Synthesiser[16];
	gens = new AudioSignalGenerator[16];
	gens[0].setActive(true);

	for (int i = 0; i < 16; i++)
	{
		gens[i].setWaveType(Sine);
		synth[i].addSound(new SineWaveSound());
		synth[i].addSound(new TriangleWaveSound());
		synth[i].addSound(new SquareWaveSound());
		synth[i].addSound(new SawtoothWaveSound());

		// Five polyphonic sounds per audio signal generator
		for (int k = 0; k < 5; k++)
			synth[i].addVoice(&gens[i].getSynthVoice());
	}

	
	
}

AddSynthesizer::~AddSynthesizer()
{
//	delete[] gens;
}

void AddSynthesizer::setLevels(int instrumentIndex, int levelIndex, EnvelopeType envType, double value)
{
	gens[instrumentIndex].setLevels(levelIndex, envType, value);
}

void AddSynthesizer::setRates(int instrumentIndex, EnvelopeType envType, double value)
{
	gens[instrumentIndex].setRates(envType, value);
}

void AddSynthesizer::setWaveType(int instrumentIndex, WaveType wt)
{
	gens[instrumentIndex].setWaveType(wt);
	ResetSynth();
}

void AddSynthesizer::setSustain(int instrumentIndex, bool isSustain)
{
	gens[instrumentIndex].setSustain(isSustain);
}

void AddSynthesizer::setActive(int instrumentIndex, bool isActive)
{
	gens[instrumentIndex].setActive(isActive);
	ResetSynth();
}

const Levels& AddSynthesizer::getLevels(int instrumentIndex)
{
	return gens[instrumentIndex].getLevels();
}

WaveType AddSynthesizer::getWaveType(int instrumentIndex)
{
	return gens[instrumentIndex].getWaveType();
}

bool AddSynthesizer::getActive(int instrumentIndex)
{
	return gens[instrumentIndex].getActive();
}

// This will crash if called, cannot figure out why even when using locks
void AddSynthesizer::ResetSynth()
{
	for (int i = 0; i < 16; i++)
	{
		synth[i].clearVoices();
		if (gens[i].getActive())
		{
			for (int k = 0; k < 5; k++)
				synth[i].addVoice(&gens[i].getSynthVoice());
		}
	}
}