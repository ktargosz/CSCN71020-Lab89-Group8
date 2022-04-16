#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Position.h"
#include "Classifier.h"

/// @file classifier.cpp
/// @brief This file implements the classifier methods
/// @author Group 8
/// @date April 2022

using namespace std;

/// Classifier contructor will reads points from file and place them into positionArr 
classifier::classifier(string textFile) : positionArr(vector<position>())
{
	// Opening file
	ifstream inputFile;
	inputFile.open(textFile);

	if (inputFile.is_open())
	{
		string fileLine;

		while (getline(inputFile, fileLine))
		{
			string delimiter = ","; // Coordinates are separated by a comma in the text files

			// Each set of data points gets put into an array of doubles
			double data[4];
			for (int x = 0; x < 4; x++)
			{
				string coordinate = fileLine.substr(0, fileLine.find(delimiter));
				data[x] = stod(coordinate);
				fileLine.erase(0, fileLine.find(delimiter) + 1);
			}

			// Position object is created with each data point gathered from the file
			position currentLineData{ data[0], data[1], data[2], data[3] };

			positionArr.push_back(currentLineData);
		}
	}
	else // Return error message and exit if file cannot be opened
	{
		cout << "Error opening file";
		exit(1);
	}
}