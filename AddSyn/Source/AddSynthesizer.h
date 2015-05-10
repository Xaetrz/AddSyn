/*
  ==============================================================================

    AddSynthesizer.h
    Created: 17 Apr 2015 4:19:47pm
    Author:  Jonathan

  ==============================================================================
*/

#ifndef ADDSYNTHESIZER_H_INCLUDED
#define ADDSYNTHESIZER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioSignalGenerator.h"
#include "EnvelopeType.h"

class AddSynthesizer //: public Synthesiser
{
public:
	AddSynthesizer();
	~AddSynthesizer();

	void setLevels(int instrumentIndex, int levelIndex, EnvelopeType envType, double value);
	void setRates(int instrumentIndex, EnvelopeType envType, double value);
	void setWaveType(int instrumentIndex, WaveType wt);
	void setSustain(int instrumentIndex, bool isSustain);
	void setActive(int instrumentIndex, bool isActive);
	const Levels& getLevels(int instrumentIndex);
	WaveType getWaveType(int instrumentIndex);
	bool getActive(int instrumentIndex);
	Synthesiser* synth;
	
private:
	AudioSignalGenerator* gens;
};


#endif  // ADDSYNTHESIZER_H_INCLUDED
