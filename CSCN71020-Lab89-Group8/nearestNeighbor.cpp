#include "nearestNeighbor.h"

/// @file nearestNeighbor.cpp
/// @brief This file implements the nearestNeighbor methods
/// @author Group 8
/// @date April 2022

using namespace std;

double nearestNeighbor::classify(position unknown)
{
	double initialDistance = INIT_DISTANCE;

	double classMin = INVALID_ORIENTATION; // -1 is an invalid orientation. Valid returns will be 1-6

	for (int i = 0; i < positionArr.size(); i++)
	{
		if (positionArr[i].distance(unknown) < initialDistance) // Setting the distance when valid
		{
			classMin = positionArr[i].getClassification();
			initialDistance = positionArr[i].distance(unknown);
		}
	}
	return classMin;
};

// Construct nearestNeighbor 
nearestNeighbor::nearestNeighbor(string textFile) : classifier(textFile) {};