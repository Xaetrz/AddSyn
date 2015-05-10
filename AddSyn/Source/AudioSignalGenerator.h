/*
  ==============================================================================

    AudioSignalGenerator.h
    Created: 30 Apr 2015 11:06:56pm
    Author:  Jonathan

  ==============================================================================
*/

#ifndef AUDIOSIGNALGENERATOR_H_INCLUDED
#define AUDIOSIGNALGENERATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "EnvelopeGenerator.h"
#include "EnvelopeType.h"

class AudioSignalGenerator
{
public:
	AudioSignalGenerator();
	~AudioSignalGenerator();
	void setLevels(int levelIndex, EnvelopeType envType, double value);
	void setRates(EnvelopeType envType, double value);
	void setWaveType(WaveType wt);
	void setSustain(bool isSustain);
	void setActive(bool isActive);
	const Levels& getLevels();
	WaveType getWaveType();
	bool getActive();
	SynthesiserVoice& getSynthVoice();
private:
    Oscillator* oscill;
    EnvelopeGenerator* envGen;
	bool isActive;
};



#endif  // AUDIOSIGNALGENERATOR_H_INCLUDED
