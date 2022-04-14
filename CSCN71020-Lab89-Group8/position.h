#pragma once

class Position
{
public:

	Position(double x, double y, double z);

	Position(double x, double y, double z, double classification);

	double distance(Position other);

	double getClassification();

private:

	double x;
	double y;
	double z;

	double classification;

};