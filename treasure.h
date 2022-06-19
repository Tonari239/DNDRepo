#ifndef __TREASURE_H
#define __TREASURE_H

#include "baseEntity.h"
#include <iostream>
using namespace std;

class Treasure : public BaseEntity
{
	double mPercentStat;
public:
	Treasure(int x=-1,int y=-1, double percentStat=20, int level = 1);
	Treasure(int x = -1, int y = -1, int level=1);
	virtual ~Treasure() = default;
	double getPercentStat() const;
	void setPercentStat(double percentStat);
	virtual Treasure* clone() const;
	void levelUp() override;
	virtual string getName() const;

	friend ostream& operator<<(ostream& out, const Treasure& treasure);
	friend istream& operator>>(istream& in, Treasure& treasure);
};

#endif