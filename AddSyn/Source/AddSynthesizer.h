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

//#include "PluginProcessor.h"
//#include "PluginEditor.h"
struct Levels;


class AddSynthesizer : public Synthesiser
{
public:
	AddSynthesizer(Levels* levels);
	~AddSynthesizer();
private:
    AudioSignalGenerator* generators;
};



#endif  // ADDSYNTHESIZER_H_INCLUDED
