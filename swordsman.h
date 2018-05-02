//=======================
//		swordsman.h
//=======================

// Derived from base class player
// For the job Swordsman

#include "player.h"
class swordsman : public player//5_?????????		// subclass swordsman publicly inherited from base player
{
private:
	enum growth {
		BaseHPmax = 300, IncHP = 30, 
		BaseMPmax = 100, IncMP = 10, MPUse = 40,
		BaseAP = 30, IncAP = 5, CriticalFactor = 2,
		BaseDP = 25, IncDP = 3, 
		BaseSpeed = 16, IncSpeed = 1,
		BaseIntel = 16, IncIntel = 1,
		BaseLuck = 15, IncLuck = 2, 
		EXPfactor = 60
	};
	const string skill[3]{ "Upper Cut", "Phonex Prey", "Shuttle Stab" };
public:
	swordsman(int lv_in=1, string name_in="Not Given");	
	// constructor with default level of 1 and name of "Not given"
	void isLevelUp();
	bool attack (player &p);
	bool specialatt(player &p);
	/* These three are derived from the pure virtual functions of base class
	The definition of them will be given in this subclass. */
	void AI(player &p);				// Computer opponent
	void printSkill(int x);
};
