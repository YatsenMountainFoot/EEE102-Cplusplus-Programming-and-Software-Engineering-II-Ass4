//=======================
//		main.cpp
//=======================

// main function for the RPG style game

#include <iostream>
#include <string>
using namespace std;

#include "swordsman.h"
#include "archer.h"
#include "mage.h"
int intParser();
char charParser();

int main()
{
	
	string tempName;
	bool success=0;		//flag for storing whether operation is successful
	cout <<"Please input player's name: ";
	getline(cin, tempName);		// get player's name from keyboard input
	player *human = nullptr;		// use pointer of base class, convenience for polymorphism
	player *enemy = nullptr;
	int tempJob;		// temp choice for job selection
	int tempEnemy;		// temp random choice for enemy job 
	int numOfEnemy = 1;
	do
	{
		cout <<"Please choose a job: 1 Swordsman, 2 Archer, 3 Mage"<<endl;
		tempJob = intParser();
		system("cls");		// clear the screen
		switch(tempJob)
		{
		case 1:
			human=new swordsman(1,tempName);	// create the character with user inputted name and job
			success=1;		// operation succeed
			break;
		case 2:
			human = new archer(1, tempName);	// create the character with user inputted name and job
			success = 1;		// operation succeed
			break;
		case 3:
			human = new mage(1, tempName);	// create the character with user inputted name and job
			success = 1;		// operation succeed
			break;
		default:
			break;				// In this case, success=0, character creation failed
		}
	}while(success!=1);		// so the loop will ask user to re-create a character
	cout << "Name the number of opponents: " << endl;
	while ((numOfEnemy = intParser())<=0) {
		cout << "Sorry, number of opponents should be positive integer: ";
	};
	int tempCom;			// temp command inputted by user
	int nOpp=0;				// the Nth opponent
	for(int i=1;nOpp<numOfEnemy;i+=2)	// i is opponent's level
	{
		nOpp++;
		system("cls");	
		
		srand((unsigned)time(NULL));
		tempEnemy = rand() % 3;
		if(tempEnemy == 1)
			enemy = new swordsman(i, "Warrior");	// Initialise an opponent, level i, name "Junior"
		else if (tempEnemy == 2)
			enemy = new archer(i, "Sniper");	// Initialise an opponent, level i, name "Junior"
		else 
			enemy = new mage(i, "Sage");	// Initialise an opponent, level i, name "Junior"
		cout<<"STAGE" <<nOpp<<endl;
		cout << "Your opponent, a Level " << i << " "; enemy->showRole(); cout << endl;
		system("pause");
		human->reFill();				// get HP/MP refill before start fight
		
		while(!human->death() && !enemy->death())	// no died
		{
			success=0;
			while (success!=1)
			{
				showinfo(*human, *enemy);				// show fighter's information
				cout<<"Please give command: "<<endl;
				cout << "1 "; human->printSkill(0); cout << "; 2 "; human->printSkill(2); cout << "; 3 Use Heal; 4 Use Magic Water; 0 Exit Game" << endl;
				tempCom = intParser();
				switch(tempCom)
				{
				case 0:
					cout<<"Are you sure to exit? Y/N"<<endl;
					char temp;
					temp = charParser();
					if(temp=='Y'||temp=='y')
						return 0;
					else
						break;
				case 1:
					success=human->attack(*enemy);
					human->isLevelUp();
					enemy->isDead();
					break;
				case 2:
					success=human->specialatt(*enemy);
					human->isLevelUp();
					enemy->isDead();
					break;
				case 3:
					success=human->useHeal();
					break;
				case 4:
					success=human->useMW();
					break;
				default:
					break;
				}
			}
			if(!enemy->death())		// If AI still alive
				enemy->AI(*human);
			else							// AI died
			{
				cout<<"YOU WIN"<<endl;
				human->transfer(*enemy);		// player got all AI's items
			}
			if (human->death())
			{
				system("cls");
				cout<<endl<<setw(50)<<"GAME OVER"<<endl;
				delete enemy;
				delete human;//6_???????????		// player is dead, program is getting to its end, what should we do here?
				system("pause");
				return 0;
			}
		}
	}
	delete enemy;
	delete human;//7_?????????			// You win, program is getting to its end, what should we do here?
	system("cls");
	cout<<"Congratulations! You defeated all opponents!!"<<endl;
	system("pause");
	return 0;
}
		
int intParser() {
	int temp;
	bool isErr = true;
	//while (input failed) or (input succeeded with redundant tail, clear steream and repeat)
	while ((isErr = !(cin >> temp)) || (!isErr && cin.get() != '\n')) {
		if (isErr) { cin.clear(); }
		//reset cin
		while (cin.get() != '\n')//clear a whole line
			continue;
		cout << "\t\tPlease enter an integer: ";
	}
	return temp;
}
char charParser() {
	char temp;
	bool isErr = true;
	//while (input failed) or (input succeeded with redundant tail, clear steream and repeat)
	while ((isErr = !(cin >> temp)) || (!isErr && cin.get() != '\n')) {
		if (isErr) { cin.clear(); }
		//reset cin
		while (cin.get() != '\n')//clear a whole line
			continue;
		cout << "\t\tPlease enter a character: ";
	}
	return temp;
}
