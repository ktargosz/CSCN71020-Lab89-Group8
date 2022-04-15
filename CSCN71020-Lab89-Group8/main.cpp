#include "main.h"
#include "nearestNeighbor.h"

/// @file main.cpp
/// @brief This is the main.cpp file
/// @author Group 8
/// @date April 2022

using namespace std;

/// Function will ask the user what they would like to classify
/// They may classify either unique coordinates or the unknownData text file
int main()
{
	string trainingTextFile = TRAININGDATA_FILE; // Training data text file name

	nearestNeighbor NN{ trainingTextFile }; // Using the training data in "classifier(string textFile)"

	int input = 0; // User input selection

	double x, y, z = 0; // Coordinates to be classified (if user selects 1)

	// Menu options + get user input
	cout << "Please select an option:" << endl;
	cout << "1. Enter new data to classify" << endl;
	cout << "2. Classify unknownData.txt" << endl;
	cin >> input;

	// Input selection 1 
	if (input == 1)
	{
		// Ask the user for x,y,z coordinates 
		cout << "Enter the x value: ";
		cin >> x;
		cout << "Enter the y value: ";
		cin >> y;
		cout << "Enter the z value: ";
		cin >> z;

		// Put each user coordinate through the posision::position - runs through nearestNeighbor::classify, position::distance, position::getClassification
		position input(x, y, z);

		// Return the classfication of the specified coordinates
		if (NN.classify(input) == -1)
			cout << endl << "X:" << x << " Y:" << y << " Z:" << z << endl << endl << "Classification: " << NN.classify(input) << " (invalid)" << endl;
		else
			cout << endl << "X:" << x << " Y:" << y << " Z:" << z << endl << endl << "Classification: " << NN.classify(input) << endl;

	}

	// Input selection 2
	if (input == 2)
	{
		fstream inputFile;

		inputFile.open(UNKNOWNDATA_FILE); // Open text file to be classified

		if (inputFile.is_open())
		{
			string line;

			// Get each line of the unknownData file
			while (getline(inputFile, line))
			{
				string delimiter = ","; // Each point is separated by a comma

				// Each set of data points gets put into an array of doubles
				double data[3]; 
				for (int x = 0; x < 3; x++)
				{
					string coordinate = line.substr(0, line.find(delimiter));

					data[x] = stod(coordinate);

					line.erase(0, line.find(delimiter) + 1);

				}
				
				// Every set of 3 data points (x,y,z) are classified
				position currentLineData{ data[0], data[1], data[2], };

				// Return the classfication of the specified coordinates
				cout << endl << "point (" << data[0] << "," << data[1] << "," << data[2] << ") is classified as: " << NN.classify(currentLineData) << endl;
			}
		}
		else // Return error message and exit if file cannot be opened
		{
			cout << "Error opening file";
			exit(1);
		}
	}
}