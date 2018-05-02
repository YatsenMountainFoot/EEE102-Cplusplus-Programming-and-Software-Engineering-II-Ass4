//=======================
//		mage.h
//=======================

// Derived from base class player
// For the job Mage

#include "player.h"
class mage : public player// subclass mage publicly inherited from base player
{
private:
	enum growth {
		BaseHPmax = 175, IncHP = 10,
		BaseMPmax = 225, IncMP = 35, MPUse = 50,
		BaseAP = 20, IncAP = 1, CriticalFactor = 9,
		BaseDP = 20, IncDP = 1,
		BaseSpeed = 15, IncSpeed = 2,
		BaseIntel = 25, IncIntel = 5,
		BaseLuck = 25, IncLuck = 3,
		EXPfactor = 50
	};
	const string skill[3]{ "Plasma Arrow", "Electric Explosion", "Lightning" };
public:
	mage(int lv_in = 1, string name_in = "Not Given");
	// constructor with default level of 1 and name of "Not given"
	void isLevelUp();
	bool attack(player &p);
	bool specialatt(player &p);
	/* These three are derived from the pure virtual functions of base class
	The definition of them will be given in this subclass. */
	void AI(player &p);				// Computer opponent
	void printSkill(int x);
};
