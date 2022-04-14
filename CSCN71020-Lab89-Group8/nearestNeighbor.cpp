#include "nearestNeighbor.h"
#define INITALMIN 1000

using namespace std;

double NearestNeighbor::Classify(Position unknown)
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

NearestNeighbor::NearestNeighbor(string textFile) : Classifier(textFile) {};