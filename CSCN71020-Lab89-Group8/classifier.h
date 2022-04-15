#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "position.h"

/// @file classifier.h
/// @brief This file contains the class classifier
/// @author Group 8
/// @date April 2022

class classifier
{
public:

	virtual double classify(position unknown) = 0;

protected:

	classifier(std::string textFile);
	std::vector<position> positionArr;
};

