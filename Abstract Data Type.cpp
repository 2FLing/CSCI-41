#include<stdio.h>
#include<random>
#include"bag.h"
using namespace std;
int main()
{
	Bag myBag;
	int attemp = 0,guess_num,score=0;
	for (int i = 0; i < 6; i++)
		myBag.add(rand() % 100);//Add 6 random numbers in range 0-99 to the bag
	while (attemp <10 and !myBag.isEmpty())//if attemp is less then 10 and bag is not empty keep asking the user
	{
		attemp++;
		cout << "Can you guess what number is in the bag?" << endl;
		cin >> guess_num;
		if (myBag.contains(guess_num))//if the guess number is in the bag
		{
			cout << "Right!" << endl;
			score += 10;
			myBag.remove(guess_num);
		}
		else
		{
			cout << "This number is not inside of the bag!" << endl;
		}
	}
	if (attemp < 10)//If the times of attemp is less then 10 and bag is empty
	{
		score += 200;//Add extra 200 points
		cout << "Game over!" << endl;
	}
	if(attemp==10 and !myBag.isEmpty())//If the user reached 10 attemps and the bag is not empty
	{
		cout << "Game over!" << endl;
		cout << "Your socre is : " << score << endl;//Display the score
	}

	return 0;
}