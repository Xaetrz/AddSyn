/*
  ==============================================================================

    EnvelopeGenerator.h
    Created: 30 Apr 2015 11:06:23pm
    Author:  Jonathan

  ==============================================================================
*/

#ifndef ENVELOPEGENERATOR_H_INCLUDED
#define ENVELOPEGENERATOR_H_INCLUDED

#include "EnvelopeType.h"
#include "Levels.h"

class EnvelopeGenerator
{
public:
	EnvelopeGenerator();
	~EnvelopeGenerator();
	void setLevels(int levelIndex, EnvelopeType envType, double value);
	void setRates(EnvelopeType envType, double value);
	void setSustain(bool isSustain);
	const Levels& getLevels();
private:
	Levels* levels;
};



#endif  // ENVELOPEGENERATOR_H_INCLUDED
