//=======================
//		mage.cpp
//=======================
#include "mage.h"
#include <iostream>

using std::cout;
using std::endl;
// constructor. default values don't need to be repeated here
mage::mage(int lv_in, string name_in)
{
	role = mg;	// enumerate type of job
	LV = lv_in;
	name = name_in;

	// Initialising the character's properties, based on his level
	HPmax = BaseHPmax + IncHP * (LV - 1);		// HP increases 8 point2 per level
	HP = HPmax;
	MPmax = BaseMPmax + IncMP * (LV - 1);		// MP increases 2 points per level
	MP = MPmax;
	AP = BaseAP + IncAP * (LV - 1);			// AP increases 4 points per level
	DP = BaseDP + IncDP * (LV - 1);			// DP increases 4 points per level
	speed = BaseSpeed + IncSpeed * (LV - 1);		// speed increases 2 points per level
	intelligence = BaseIntel + IncIntel *(LV - 1);
	luck = BaseLuck + IncLuck * (LV - 1);
	playerdeath = 0;
	EXP = LV*LV * EXPfactor;
	bag.set(lv_in, lv_in);
}

void mage::isLevelUp()
{
	if (EXP >= LV*LV * 75)
	{
		LV++;
		HPmax += IncHP;
		MPmax += IncMP;
		AP += IncAP;
		DP += IncDP;
		speed += IncSpeed;
		intelligence += IncIntel;
		luck += IncLuck;
		cout << name << " Level UP!" << endl;
		cout << "HP improved " << IncHP << " points to " << HPmax << endl;
		cout << "MP improved " << IncMP << " points to " << MPmax << endl;
		cout << "AP improved " << IncAP << " points to " << AP << endl;
		cout << "DP improved " << IncDP << " points to " << DP << endl;
		cout << "Speed improved " << IncSpeed << " points to " << speed << endl;
		cout << "Intelligence improved " << IncIntel << " points to " << intelligence << endl;
		cout << "Luck improved " << IncLuck << " points to " << luck << endl;
		system("pause");
		isLevelUp();	// recursively call this function, so the character can level up multiple times if got enough exp
	}
}

bool mage::attack(player &p)
{
	double HPtemp = 0;		// opponent's HP decrement
	double EXPtemp = 0;		// player obtained exp
	double hit = 1;			// attach factor, probably give critical attack
	srand((unsigned)time(NULL));		// generating random seed based on system time

										// If speed greater than opponent, you have some possibility to do double attack
	if ((speed>p.speed) && (rand() % 100<(speed - p.speed)))		// rand()%100 means generates a number no greater than 100
	{
		HPtemp = (int)((hit*intelligence / (p.intelligence+ p.speed))*intelligence*luck/p.luck * 5 / (rand() % 4 + 10));		// opponent's HP decrement calculated based their AP/DP, and uncertain chance
		cout << name << "'s quick strike hit " << p.name << ", " << p.name << "'s HP decreased " << HPtemp << endl;
		p.HP = int(p.HP - HPtemp);
		EXPtemp = (int)(HPtemp*1.2);
	}

	// If speed smaller than opponent, the opponent has possibility to evade
	if ((speed<p.speed) && (rand() % 100<3 * p.luck / luck))
	{
		cout << name << "'s "; printSkill(0); cout << "attack has been evaded by " << p.name << endl;
		system("pause");
		return 1;
	}

	// 10% chance give critical attack
	if (rand() % 100 <= 10 * luck / p.luck)
	{
		hit = CriticalFactor;
		cout << "Critical attack--"; printSkill(1); cout << ":" << endl;
	}

	// Normal attack
	HPtemp = (int)((hit*AP / (p.intelligence + p.speed))*AP *luck/p.luck* 15 / (rand() % 4 + 10));
	cout << name << " uses "; printSkill(0); cout << "," << p.name << "'s HP decreases " << HPtemp << endl;
	EXPtemp = (int)(EXPtemp + HPtemp*1.2);
	p.HP = (int)(p.HP - HPtemp);
	cout << name << " obtained " << EXPtemp << " experience." << endl;
	EXP = (int)(EXP + EXPtemp);
	system("pause");
	return 1;		// Attack success
}

bool mage::specialatt(player &p)
{
	if (MP<MPUse)
	{
		cout << "You don't have enough magic points!" << endl;
		system("pause");
		return 0;		// Attack failed
	}
	else
	{
		MP -= MPUse;			// consume 40 MP to do special attack

								//10% chance opponent evades
		if (rand() % 100 <= 10)
		{
			cout << name << "'s "; printSkill(2); cout << " has been evaded by " << p.name << endl;
			system("pause");
			return 1;
		}

		double HPtemp = 0;
		double EXPtemp = 0;
		//double hit=1;			
		//srand(time(NULL));		
		HPtemp = (int)(AP * 2 + 20 * AP / DP);		// not related to opponent's DP
		EXPtemp = (int)(HPtemp*1.5);		// special attack provides more experience
		cout << name << " uses "; printSkill(2); cout << "," << p.name << "'s HP decreases " << HPtemp << endl;
		cout << name << " obtained " << EXPtemp << " experience." << endl;
		p.HP = (int)(p.HP - HPtemp);
		EXP = (int)(EXP + EXPtemp);
		system("pause");
	}
	return 1;	// special attack succeed
}

// Computer opponent
void mage::AI(player &p)
{
	if ((HP<(int)((1.0*p.AP / DP)*p.AP*1.5)) && (HP + 100 <= 1.1*HPmax) && (bag.nOfHeal()>0) && (HP>(int)((1.0*p.AP / DP)*p.AP*0.5)))
		// AI's HP cannot sustain 3 rounds && not too lavish && still has heal && won't be killed in next round
	{
		useHeal();
	}
	else
	{
		if (MP >= MPUse && HP>0.5*HPmax && rand() % 100 <= 30)
			// AI has enough MP, it has 30% to make special attack
		{
			specialatt(p);
			p.isDead();		// check whether player is dead
		}
		else
		{
			if (MP<MPUse && HP>0.5*HPmax && bag.nOfMW())
				// Not enough MP && HP is safe && still has magic water
			{
				useMW();
			}
			else
			{
				attack(p);	// normal attack
				p.isDead();
			}
		}
	}
}

void mage::printSkill(int x) {
	cout << skill[x];
}