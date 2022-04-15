#include <iostream>
#include "NearestNeighbor.h"
#include <fstream>

/// @file main.cpp
/// @brief This is the main.cpp file
/// @author Group 8
/// @date April 2022

using namespace std;

/// Function will ask the user what they would like to classify
/// They may classify either unique coordinates or the unknownData text file
/// </summary>
/// <returns></returns>
int main()
{
	string textFileTraining = "trainingData.txt";

	nearestNeighbor NN{ textFileTraining };

	int input = 0; // Input selection

	double x, y, z = 0; // Coordinates to be classified

	cout << "Please select an option:" << endl;
	cout << "1. Enter new data to classify" << endl;
	cout << "2. Classify unknownData.txt" << endl;

	cin >> input;


	if (input == 1)
	{
		cout << "Enter the x value: ";

		cin >> x;

		cout << "Enter the y value: ";

		cin >> y;

		cout << "Enter the z value: ";

		cin >> z;

		position input(x, y, z);

		cout << endl << "If the x value is: " << x << ",and the y value is: " << y << ", and the z value is: " << z << endl << endl << "Then the classification of this position is: " << NN.classify(input) << endl;

	}

	if (input == 2)
	{
		fstream fin;

		fin.open("unknownData.txt");

		if (fin.is_open())
		{

			string line;

			while (getline(fin, line))
			{
				string delimiter = ",";

				double data[4];


				for (int k = 0; k < 3; k++)
				{
					string token = line.substr(0, line.find(delimiter));

					data[k] = stod(token);

					line.erase(0, line.find(delimiter) + 1);

				}

				position currentLineData{ data[0], data[1], data[2], };

				cout << endl << "point (" << data[0] << "," << data[1] << "," << data[2] << ") is classified as: " << NN.classify(currentLineData) << endl;
			}
		}
		else
		{
			exit(1);
		}
	}
}