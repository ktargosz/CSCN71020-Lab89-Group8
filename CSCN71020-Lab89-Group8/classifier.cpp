#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Position.h"
#include "Classifier.h"

using namespace std;

Classifier::Classifier(string textFile) : positionArr(vector<Position>())
{
	ifstream fin;

	fin.open(textFile);


	if (fin.is_open())
	{
		string line;

		while (getline(fin, line))
		{
			string delimiter = ",";

			double data[4];


			for (int k = 0; k < 4; k++)
			{
				string token = line.substr(0, line.find(delimiter));

				data[k] = stod(token);

				line.erase(0, line.find(delimiter) + 1);

			}

			Position currentLineData{ data[0], data[1], data[2], data[3] };

			positionArr.push_back(currentLineData);


		}
	}
	else
	{
		exit;
	}
}