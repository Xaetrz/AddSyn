/*
  ==============================================================================

    EnvelopeGenerator.cpp
    Created: 30 Apr 2015 11:06:14pm
    Author:  Jonathan

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "EnvelopeGenerator.h"

EnvelopeGenerator::EnvelopeGenerator()
{
	levels = new Levels();
}

EnvelopeGenerator::~EnvelopeGenerator()
{
	delete levels;
}

void EnvelopeGenerator::setLevels(int levelIndex, EnvelopeType envType, double value)
{
	if (envType == Attack)
		levels->attackValues[levelIndex] = value;
	else if (envType == Sustain)
		levels->sustainValues[levelIndex] = value;
	else
		levels->releaseValues[levelIndex] = value;
}

void EnvelopeGenerator::setRates(EnvelopeType envType, double value)
{
	if (envType == Attack)
		levels->attackRate = value;
	else if (envType == Sustain)
		levels->sustainRate = value;
	else
		levels->releaseRate = value;
}

void EnvelopeGenerator::setSustain(bool isSustain)
{
	levels->isSustain = isSustain;
}

const Levels& EnvelopeGenerator::getLevels()
{
	return *levels;
}
