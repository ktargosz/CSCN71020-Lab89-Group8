#include "nearestNeighbor.h"

/// @file nearestNeighbor.cpp
/// @brief This file implements the nearestNeighbor methods
/// @author Group 8
/// @date April 2022

using namespace std;

double nearestNeighbor::classify(position unknown)
{
	double currentMinimum = INIT_DISTANCE;

	double classMin = -1;

	for (int i = 0; i < positionArr.size(); i++)
	{
		if (positionArr[i].distance(unknown) < currentMinimum)
		{
			classMin = positionArr[i].getClassification();
			currentMinimum = positionArr[i].distance(unknown);
		}
	}
	return classMin;
};

nearestNeighbor::nearestNeighbor(string textFile) : classifier(textFile) {};