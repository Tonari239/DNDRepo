#include "weapon.h"

Weapon::Weapon(int x,int y, double percentStat, int level) : Treasure(x,y,level,percentStat)
{

}

Weapon::Weapon(int x, int y, int level) :Treasure(x,y,level)
{

}


string Weapon::getName() const
{
	return "weapon";
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}