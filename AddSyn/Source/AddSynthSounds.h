/*
  ==============================================================================

    AddSynthSounds.h
    Created: 10 May 2015 11:47:16am
    Author:  Jonathan

  ==============================================================================
*/

#ifndef ADDSYNTHSOUNDS_H_INCLUDED
#define ADDSYNTHSOUNDS_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SineWaveSound : public SynthesiserSound
{
public:
	SineWaveSound() {}

	bool appliesToNote(int /*midiNoteNumber*/) override  { return true; }
	bool appliesToChannel(int /*midiChannel*/) override  { return true; }
};

class TriangleWaveSound : public SynthesiserSound
{
public:
	TriangleWaveSound() {}

	bool appliesToNote(int /*midiNoteNumber*/) override  { return true; }
	bool appliesToChannel(int /*midiChannel*/) override  { return true; }
};

class SquareWaveSound : public SynthesiserSound
{
public:
	SquareWaveSound() {}

	bool appliesToNote(int /*midiNoteNumber*/) override  { return true; }
	bool appliesToChannel(int /*midiChannel*/) override  { return true; }
};

class SawtoothWaveSound : public SynthesiserSound
{
public:
	SawtoothWaveSound() {}

	bool appliesToNote(int /*midiNoteNumber*/) override  { return true; }
	bool appliesToChannel(int /*midiChannel*/) override  { return true; }
};


#endif  // ADDSYNTHSOUNDS_H_INCLUDED
