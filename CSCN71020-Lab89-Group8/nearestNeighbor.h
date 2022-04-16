#pragma once
#include "classifier.h"

#define INIT_DISTANCE 100

/// @file nearestNeighbor.h
/// @brief This file contains the nearestNeighbor class
/// @author Group8
/// @date April 2022

class nearestNeighbor : public classifier
{
public:

	virtual double classify(position unknown) override;
	nearestNeighbor(std::string textFile);
};

