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

			double data[4];

			for (int k = 0; k < 4; k++)
			{
				string token = fileLine.substr(0, fileLine.find(delimiter));

				data[k] = stod(token);

				fileLine.erase(0, fileLine.find(delimiter) + 1);

			}

			position currentLineData{ data[0], data[1], data[2], data[3] };

			positionArr.push_back(currentLineData);
		}
	}
	else
	{
		cout << "File Error";
		exit(1);
	}
}