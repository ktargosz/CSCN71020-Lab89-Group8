#pragma once
#include "classifier.h"
class NearestNeighbor : public Classifier
{
public:

	virtual double Classify(Position unknown) override;
	NearestNeighbor(std::string textFile);

private:

};

