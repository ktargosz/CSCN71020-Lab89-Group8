#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "position.h"

class Classifier
{
public:

	virtual double Classify(Position unknown) = 0;

protected:

	Classifier(std::string textFile);
	std::vector<Position> positionArr;

private:

};

