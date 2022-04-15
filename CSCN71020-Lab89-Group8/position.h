#pragma once

/// @file position.h
/// @brief This file contains the class position
/// @author Group 8
/// @date April 2022

class position
{
public:

	position(double x, double y, double z);

	position(double x, double y, double z, double classification);

	double distance(position other);

	double getClassification();

private:

	double x;
	double y;
	double z;

	double classification;

};