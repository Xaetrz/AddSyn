/*
  ==============================================================================

    AddSynthesizer.cpp
    Created: 17 Apr 2015 4:19:57pm
    Author:  Jonathan

  ==============================================================================
*/

#include "AddSynthesizer.h"

AddSynthesizer::AddSynthesizer()
{
	synth = new Synthesiser();
	gens = new AudioSignalGenerator[16];
	gens[0].setActive(true);

	for (int i = 0; i < 16; i++)
	{
		gens[i].setWaveType(Sine);
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
}

void AddSynthesizer::setSustain(int instrumentIndex, bool isSustain)
{
	gens[instrumentIndex].setSustain(isSustain);
}

void AddSynthesizer::setActive(int instrumentIndex, bool isActive)
{
	gens[instrumentIndex].setActive(isActive);
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