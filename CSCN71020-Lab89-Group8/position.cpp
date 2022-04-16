#include <iostream>
#include <math.h>
#include <cmath>
#include "Position.h"

/// @file position.cpp
/// @brief This file implements the position methods
/// @author Group 8
/// @date April 2022

using namespace std;

// Constructors and initializers
position::position(double x, double y, double z) : x(x), y(y), z(z), classification(-1) {};
position::position(double x, double y, double z, double classification) : x(x), y(y), z(z), classification(classification) {};

double position::distance(position otherPosition)
{
	double distance = sqrt(pow(this->x - otherPosition.x, 2) + pow(this->y - otherPosition.y, 2) + pow(this->z - otherPosition.z, 2)); // Getting the distances from our position to another position
	return distance;
}

double position::getClassification()
{
	return this->classification;
}