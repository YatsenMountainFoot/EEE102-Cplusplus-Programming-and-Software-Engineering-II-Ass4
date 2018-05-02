//=======================
//		archer.h
//=======================

// Derived from base class player
// For the job Archer

#include "player.h"
class archer : public player//5_?????????		// subclass swordsman publicly inherited from base player
{
private:
	enum growth {
		BaseHPmax = 200, IncHP = 20,
		BaseMPmax = 145, IncMP = 20, MPUse = 35,
		BaseAP = 20, IncAP = 1, CriticalFactor = 5,
		BaseDP = 25, IncDP = 2,
		BaseSpeed = 25, IncSpeed = 5,
		BaseIntel = 16, IncIntel = 2,
		BaseLuck = 40, IncLuck = 5,
		EXPfactor = 60
	};
	const string skill[3]{ "Sharp Shooting", "Arrow Storm", "Cluster Bomb" };
public:
	archer(int lv_in = 1, string name_in = "Not Given");
	// constructor with default level of 1 and name of "Not given"
	void isLevelUp();
	bool attack(player &p);
	bool specialatt(player &p);
	/* These three are derived from the pure virtual functions of base class
	The definition of them will be given in this subclass. */
	void AI(player &p);				// Computer opponent
	void printSkill(int x);
};
