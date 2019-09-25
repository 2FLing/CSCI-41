#include<iostream>
#include<stdio.h>
#include"FlightSearch.h"
int main()
{
	createMap();
	char a;
	char cityOfOrigin, cityOfDestination, adjacentCity;
	do {
		cout << "Please choose one of the following:" << endl;
		cout << "+------------------------   ---+\n";
		cout << "| 1. Search Flights            |\n";
		cout << "| 2. Add New Flight            |\n";
		cout << "| 3. Display Flight Map        |\n";
		cout << "| 4. Exit Program              |\n";
		cout << "+------------------------------+\n";
		cin >> a;
		switch (a)
		{
		case '1':
		{cout << "Please enter the city of the origin: \n";
		cin >> cityOfOrigin;
		cityOfOrigin = toupper(cityOfOrigin);
		cout << "Please enter the city of the destination: \n";
		cin >> cityOfDestination;
		cityOfDestination = toupper(cityOfDestination);
		if (inPath(cityOfOrigin, cityOfDestination))
			cout << "Yes, flight or flights found!\n";
		else
			cout << "No, there is no flight to get there!\n";
		break; }
		case '2':
		{cout << "Please enter the city of the origin: \n";
		cin >> cityOfOrigin;
		cityOfOrigin = toupper(cityOfOrigin);
		cout << "Please enter new adjacent city: \n";
		cin >> adjacentCity;
		adjacentCity=toupper(adjacentCity);
		if (addAdjacentCity(cityOfOrigin, adjacentCity)) {
			cout << "New adjacent city is added." << endl;
		}
		else {
			cout << "Adding adjacent city failed." << endl;
		}
		break; }
		case '3':
		{displayFlightMap();
		break; }
		case '4':
		{
			cout << "You choose to exit the program." << endl;
			break; }
		default:
		{cout << "Invalid input, please enter 1, 2, 3., or 4" << endl;
		break; }
		};

	} while (a != '4');
	system("pause");
	return 0;
}