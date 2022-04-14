#include <iostream>
#include "NearestNeighbor.h"
#include <fstream>

using namespace std;

int main()
{
	string textFileTraining = "trainingData.txt";

	NearestNeighbor NN{ textFileTraining };

	int input = 0;

	double x = 0;
	double y = 0;
	double z = 0;


	cout << "What do you want to classify?" << endl;
	cout << "1. Enter data to classify" << endl;
	cout << "2. Classify the unknownData Textfile" << endl;



	cin >> input;


	if (input == 1)
	{
		cout << "Enter the x value: ";

		cin >> x;

		cout << "Enter the y value: ";

		cin >> y;

		cout << "Enter the z value: ";

		cin >> z;

		Position input(x, y, z);

		cout << endl << "If the x value is: " << x << ",and the y value is: " << y << ", and the z value is: " << z << endl << endl << "Then the classification of this position is: " << NN.Classify(input) << endl;

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

				Position currentLineData{ data[0], data[1], data[2], };

				cout << endl << "point (" << data[0] << "," << data[1] << "," << data[2] << ") is classified as: " << NN.Classify(currentLineData) << endl;
			}
		}
		else
		{
			exit;
		}
	}
}