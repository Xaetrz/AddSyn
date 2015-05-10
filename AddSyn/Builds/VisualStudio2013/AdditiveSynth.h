#ifndef ADDITIVESYNTH_H
#define ADDITIVESYNTH_H

#include "AudioSignalGenerator.h"

class AdditiveSynth
{
private:
	AudioSignalGenerator* generators;
	int volume;

public:
	AdditiveSynth();
	~AdditiveSynth();
};

#endif