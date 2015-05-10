/*
  ==============================================================================

    Oscillator.h
    Created: 30 Apr 2015 11:06:02pm
    Author:  Jonathan

  ==============================================================================
*/

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

#include "WaveType.h"
class EnvelopeGenerator;

class Oscillator
{
public:
	Oscillator(const EnvelopeGenerator* envGen);
	~Oscillator();
	void setWaveType(WaveType wt);
	WaveType getWaveType();
	SynthesiserVoice& getSynthVoice();
private:
	WaveType wavetype;
	SynthesiserVoice* synthVoice;
};

#endif  // OSCILLATOR_H_INCLUDED
