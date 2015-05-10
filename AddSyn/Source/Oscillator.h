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

class Oscillator
{
public:
	Oscillator();
	~Oscillator();
	void setWaveType(WaveType wt);
	WaveType getWaveType();
private:
	WaveType wavetype;
};

#endif  // OSCILLATOR_H_INCLUDED
