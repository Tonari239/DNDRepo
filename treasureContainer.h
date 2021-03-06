#ifndef __TREASURE_CONTAINER_H
#define __TREASURE_CONTAINER_H
#define DEFAULT_CAPACITY 4
#define SIZE_UP_CAPACITY_MULTIPLIER 2
#define SIZE_DOWN_CAPACITY_MULTIPLIER 1.0/2

#include "spell.h"
#include "armor.h"
#include "weapon.h"

using namespace std;

class TreasureContainer
{
	Treasure** mData;
	int mCount;
	int mCapacity;

	void copyFrom(const TreasureContainer& other);
	void resize(double multiplier);
	void resizeAccordingly();
	void _free();
public:
	TreasureContainer(int capacity = DEFAULT_CAPACITY);
	TreasureContainer(const TreasureContainer& other);
	~TreasureContainer();
	TreasureContainer& operator=(const TreasureContainer& other);

	int getCount() const;

	void addTreasure(const Treasure& T);
	void removeIndex(int index);

	const Treasure* getAt(int index) const;
	Treasure& operator[](int index);
	Treasure operator[](int index) const;
	
	friend ostream& operator<<(ostream& out, const TreasureContainer& tc);
	friend istream& operator>>(istream& in, TreasureContainer& tc);

};

#endif