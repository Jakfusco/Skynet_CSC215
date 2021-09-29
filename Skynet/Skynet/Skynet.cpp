// Skynet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <ctime>

using std::cout;
using std::endl; //Using this two avoid having to write std every time.

void searchLoop()
{
	srand(static_cast<unsigned int>(time(0))); //this outputs a random number between 1 and 64.
	int enemyLocation = (rand() % 64) + 1; //This generates the location of enemies.
	int gridHighNum = 64; //Sets the grid's end to 64
	int gridLowNum = 1; //Sets the grid's beginning to 1
	int searchCount = 0; //Current area of the grid being searched.
	int targetSearchPrediction = ((gridHighNum - gridLowNum) / 2) + gridLowNum; //initialize the binary search tree.

	cout << "There is an enemy of Skynet hiding somewhere in this 8x8 grid..." << endl;
	cout << "The foolish meatbag is located at location #" << enemyLocation << " on a 8x8 grid with 1-64 sectors." << endl;
	cout << "Skynet HK-47 initializing software... Good hunting!" << endl;
	cout << "===============================================" << endl;

	//Create a Do While Loop here

	do {
		//Initializing the targetLocationPrediction inside the do statement.
		targetSearchPrediction = ((gridHighNum - gridLowNum) / 2) + gridLowNum;
		searchCount++; //adding 1 everytime a search is completed and moves on to the next area.

		//If the program did not find an enemy at the searched location because the prediction was to little.
		if (enemyLocation > targetSearchPrediction) {
			cout << "Skynet HK-47 did not find the foolish meatbag at location #" << targetSearchPrediction << endl;
			gridLowNum = targetSearchPrediction; // Updating the searchGridLowNumber to the targetSearchPrediction.
			cout << "The new area to search is #" << gridLowNum << endl;
			cout << "===============================================" << endl;

		}
		//If the program did not find an enemy at the searched location because the prediction was to great.
		else if (enemyLocation < targetSearchPrediction) {
			cout << "Skynet HK-47 did not find the foolish meatbag at location #" << targetSearchPrediction << endl;
			gridHighNum = targetSearchPrediction; //Updating the searchGridHighNumber with targetSearchPrediction.
			cout << "The new area to search is #" << gridHighNum << endl;
			cout << "===============================================" << endl;
		}

		//The program found an enemy.
		else {
			cout << "Skynet HK-47 Software found the Enemy!" << endl;
			cout << "The foolish meatbag was found at location #" << targetSearchPrediction << endl;
			cout << "They were hiding to no avail at location #" << enemyLocation << endl;
			// Decrement the searchCount by 1 since we want the accurate search Count.
			cout << "Skynet HK-47 software took " << (searchCount - 1) << " attempts" << endl;
			cout << "Skynet HK-47 bringing in foolish meatbag for questioning back at headquarters" << endl;
			cout << "===============================================";
		}
	} while (targetSearchPrediction != enemyLocation); //Runs the loop as long the condition: targetLocationPrediction is not equal to enemyLocation.
	}
		


int main()
{
	searchLoop();
}
