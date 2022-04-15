#include "nearestNeighbor.h"
#define INITALMIN 1000

/// @file nearestNeighbor.cpp
/// @brief This file implements the nearestNeighbor methods
/// @author Group 8
/// @date April 2022

using namespace std;

double nearestNeighbor::classify(position unknown)
{
	double currentMinDistance = INITALMIN;

	double classificationOfMin = -1;

	for (int i = 0; i < positionArr.size(); i++)
	{
		if (positionArr[i].distance(unknown) < currentMinDistance)
		{
			classificationOfMin = positionArr[i].getClassification();

			currentMinDistance = positionArr[i].distance(unknown);
		}
	}
	return classificationOfMin;
};

nearestNeighbor::nearestNeighbor(string textFile) : classifier(textFile) {};