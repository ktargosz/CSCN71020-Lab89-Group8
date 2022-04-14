#include <iostream>
#include <math.h>
#include <cmath>
#include "Position.h"

using namespace std;

Position::Position(double x, double y, double z) : x(x), y(y), z(z), classification(-1) {};

Position::Position(double x, double y, double z, double classification) : x(x), y(y), z(z), classification(classification) {};

double Position::distance(Position other)
{
	double distance = sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2) + pow(this->z - other.z, 2));

	return distance;
}

double Position::getClassification()
{
	return this->classification;
}