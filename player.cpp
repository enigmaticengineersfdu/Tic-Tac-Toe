#include "board.hpp"
#include <iostream>
#include <sstream>
using namespace std;

//This is the player class, for each user
class player {
private:
	string name;
	coord cd;
	marker m;
	string moveX, moveY;

public:

	// This is the Default Constructor for the player object
	player(string n, marker m1)
	{
		name = n;
		m = m1;
		moveX = "";
		moveY = "";

	}

	//This function returns the player's name
	string getName()
	{
		return name;
	}

	//This function returns the player's marker
	marker getMarker()
	{
		return m;
	}


	//This function asks for the player's moves, and returns the coordinates 
	coord getMove()
	{
		cout << "Where would " << name << " like to move? \n\n";
		cout << "Enter row: ";
		cin >> moveX;

		while (!isdigit(moveX[0]))
		{
			cout << "\nIncorrect: Must enter a number. " << endl;
			cout << "Enter row: ";
			cin >> moveX;
		}
		moveX = moveX[0];
		stringstream s(moveX);
		s >> cd.first;

		cout << "Enter column: ";
		cin >> moveY;
		cout << endl;
		while (!isdigit(moveY[0]))
		{
			cout << "\nIncorrect: Must enter a number. " << endl;
			cout << "Enter column: ";
			cin >> moveY;
		}
		moveY = moveY[0];
		stringstream ss(moveY);
		ss >> cd.second;

		return cd;

	}

};
