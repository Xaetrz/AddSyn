/*
  ==============================================================================

    Levels.h
    Created: 9 May 2015 9:30:59pm
    Author:  Jonathan

  ==============================================================================
*/

#ifndef LEVELS_H_INCLUDED
#define LEVELS_H_INCLUDED

struct Levels
{
	double attackValues[12];
	double sustainValues[12];
	double releaseValues[12];
	double attackRate;
	double sustainRate;
	double releaseRate;
	bool isSustain;

	Levels()
	{
		for (int i = 0; i < 12; i++)
		{
			attackValues[i] = 5.f;
			sustainValues[i] = 5.f;
			releaseValues[i] = 5.f;
		}

		attackRate = 5.f;
		sustainRate = 5.f;
		releaseRate = 5.f;
		isSustain = true;
	}
};

#endif  // LEVELS_H_INCLUDED
