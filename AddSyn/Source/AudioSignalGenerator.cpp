/*
  ==============================================================================

    AudioSignalGenerator.cpp
    Created: 30 Apr 2015 11:06:48pm
    Author:  Jonathan

  ==============================================================================
*/

#include "AudioSignalGenerator.h"

AudioSignalGenerator::AudioSignalGenerator()
{
	envGen = new EnvelopeGenerator();
	oscill = new Oscillator(envGen);
	isActive = false;
}

AudioSignalGenerator::~AudioSignalGenerator()
{
	delete oscill;
	delete envGen;
}

void AudioSignalGenerator::setLevels(int levelIndex, EnvelopeType envType, double value)
{
	envGen->setLevels(levelIndex, envType, value);
}

void AudioSignalGenerator::setRates(EnvelopeType envType, double value)
{
	envGen->setRates(envType, value);
}

void AudioSignalGenerator::setWaveType(WaveType wt)
{
	oscill->setWaveType(wt);
}

void AudioSignalGenerator::setSustain(bool isSustain)
{
	envGen->setSustain(isSustain);
}

void AudioSignalGenerator::setActive(bool isA)
{
	isActive = isA;
}

const Levels& AudioSignalGenerator::getLevels()
{
	return envGen->getLevels();
}

WaveType AudioSignalGenerator::getWaveType()
{
	return oscill->getWaveType();
}

bool AudioSignalGenerator::getActive()
{
	return isActive;
}

SynthesiserSound& AudioSignalGenerator::getSynthSound()
{
	return oscill->getSynthSound();
}

SynthesiserVoice& AudioSignalGenerator::getSynthVoice()
{
	return oscill->getSynthVoice();
}