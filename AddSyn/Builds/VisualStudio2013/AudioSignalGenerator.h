#ifndef AUDIOSIGNALGENERATOR_H
#define AUDIOSIGNALGENERATOR_H

#include "Oscillator.h"
#include "EnvelopeGenerator.h"

class AudioSignalGenerator
{
private:
	Oscillator oscillator;
	EnvelopeGenerator envGen;

public:
	AudioSignalGenerator();
	~AudioSignalGenerator();
};

#endif