//Assignment 9 (Midterm Project 1 Flight Search Problem)

#include<iostream>
#include<iomanip>
#include"Node.h"
#include"Stack.h"
using namespace std;

struct city {
	char cityName;
	bool visited;
	Node<char>* adjacent;
};
int const MAX = 9; //currently the company serves 9 cities
city flightMap[MAX]; // declare a global array for flight map;

					 //Please complete following functions
void createMap();
bool isInMap(char aCity);
void displayFlightMap();
void markVisited(char aCity);
void unVisitedAll();
bool isVisited(char aCity);
bool addAdjacentCity(char aCity, char adjCity);
bool getNextUnvisitedAdjCity(char aCity, char& adjCity);
bool inPath(char OriginCity, char DestinationCity);

void createMap()
{
	Node<char>* newNode;
	char city_name = 'A';
	for (int i = 0; i < MAX; i++)
	{
		flightMap[i].cityName = city_name;
		city_name++;
		flightMap[i].visited = false;
	}
	flightMap[0].adjacent = new Node<char>('B', NULL);
	flightMap[1].adjacent = NULL;
	flightMap[2].adjacent = new Node<char>('B', NULL);
	newNode = new Node<char>('E', NULL);
	flightMap[3].adjacent = new Node<char>('C', newNode);
	newNode = new Node<char>('H', NULL);
	flightMap[4].adjacent = new Node<char>('F', newNode);
	flightMap[5].adjacent = new Node<char>('G', NULL);
	flightMap[6].adjacent = new Node<char>('E', NULL);
	newNode = new Node<char>('C', NULL);
	flightMap[7].adjacent = new Node<char>('I', newNode);
	flightMap[8].adjacent = NULL;
}
void displayFlightMap()
{
	string visited, city_name;
	cout << setw(14)<<"City Name"<<setw(14)<<"Visited"<< setw(24)<<"Adjacent City"<<endl;
	for (int i = 0; i < MAX; i++)
	{
		if (flightMap[i].visited == true)
			visited = "True";
		else
			visited = "False";
		if (flightMap[i].adjacent == NULL)
			city_name = "None";
		else
			city_name = flightMap[i].adjacent->getItem();
		if (city_name == "None")
		{
			cout << setw(10) << flightMap[i].cityName << setw(17) << visited << setw(21) << city_name << "  ";
		}
		else
		{
			cout << setw(10) << flightMap[i].cityName << setw(17) << visited << setw(18) << city_name << "  ";
		}
		if (flightMap[i].adjacent != NULL and flightMap[i].adjacent->getNext() != NULL)
		{
			Node<char>* temp_node = flightMap[i].adjacent->getNext();
			while (temp_node != NULL)
			{
				cout << temp_node->getItem() << " ";
				temp_node = temp_node->getNext();
			}
			cout << endl;
		}
		else
			cout << endl;
	}
}
void markVisited(char aCity)
{
	bool found = false;
	for (int i = 0; i < MAX; i++)
	{
		if (flightMap[i].cityName == aCity)
		{
			flightMap[i].visited = true;
			found = true;
			break;
		}
	}
	if (!found)
		cout << "City is not found!" << endl;
}
void unVisitedAll()
{
	for (int i = 0; i < MAX; i++)
	{
		flightMap[i].visited = false;
	}
}
bool isInMap(char aCity)
{
	bool InMap = false;
	for (int i = 0; i < MAX; i++)
	{
		if (flightMap[i].cityName == aCity)
		{
			InMap = true;
			break;
		}
	}
	return InMap;
}
bool isVisited(char aCity)
{
	bool visited = false;
	int index = 0;
	if (isInMap(aCity))
	{
		while ((flightMap[index].cityName != aCity))
			index++;
		if (flightMap[index].visited)
			visited = true;
	}
	else
		cout << "The city is not in the Map." << endl;
	return visited;
}
bool addAdjacentCity(char aCity, char adjCity)
{
	if (!isInMap(aCity) or !isInMap(adjCity))
	{
		cout << "Invalid Inputs!" << endl;
		cout << "The Program Aborted!" << endl;
		exit(1);
	}
	else
	{
		int index;
		Node<char>* temp_node;
		for (index = 0; index < MAX; index++)
		{
			if (flightMap[index].cityName == aCity)//get the location of the city
				break;
		}
		if (flightMap[index].adjacent!=NULL and flightMap[index].adjacent->getItem() == adjCity)
		{
			cout << "The adjancentCity is already exist!" << endl;
			return false;
		}
		else
		{
			temp_node = new Node<char>(adjCity, flightMap[index].adjacent);
			flightMap[index].adjacent = temp_node;
			return true;
		}
	}

}
bool getNextUnvisitedAdjCity(char aCity, char& adjCity)
{
	if (!isInMap(aCity))
	{
		cout << "Invalid Inputs!" << endl;
		cout << "The Program Aborted!" << endl;
		exit(1);
	}
	else
	{
		int index;
		Node<char>* temp_node;
		for (index = 0; index < MAX; index++)
		{
			if (flightMap[index].cityName == aCity)
				break;
		}
		temp_node = flightMap[index].adjacent;
		if (temp_node == NULL)
			return false;
		else
		{
			while (temp_node != NULL)
			{
				if (isVisited(temp_node->getItem()))
				{
					temp_node = temp_node->getNext();
				}
				else
				{
					adjCity = temp_node->getItem();
					return true;
				}

			}
			return false;
		}
	}
}
bool inPath(char OriginCity, char DestinationCity)
{
	Stack<char>myStack;
	char topCity, nextCity;
	bool success;
	int index;
	unVisitedAll();
	for (index = 0; index < MAX; index++)
	{
		if (flightMap[index].cityName == OriginCity)
			break;
	}
	flightMap[index].visited = true;
	myStack.push(flightMap[index].cityName);
	while (!myStack.isEmpty() and myStack.peek() != DestinationCity)
	{
		topCity = myStack.peek();
		success = getNextUnvisitedAdjCity(topCity, nextCity);
		if (!success)
			myStack.pop();
		else
		{
			if (nextCity == DestinationCity)
				return true;
			else
			{

				markVisited(nextCity);
				myStack.push(nextCity);
			}
		}
		if (myStack.isEmpty())
			return false;
	}
}