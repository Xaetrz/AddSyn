/*
  ==============================================================================

    AudioSignalGenerator.h
    Created: 30 Apr 2015 11:06:56pm
    Author:  Jonathan

  ==============================================================================
*/

#ifndef AUDIOSIGNALGENERATOR_H_INCLUDED
#define AUDIOSIGNALGENERATOR_H_INCLUDED

#include "Oscillator.h"
#include "EnvelopeGenerator.h"

class AudioSignalGenerator
{
public:

private:
    Oscillator* oscill;
    EnvelopeGenerator* envGen;
};



#endif  // AUDIOSIGNALGENERATOR_H_INCLUDED
