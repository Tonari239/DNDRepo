#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H

#include "hero.h"
#include "map.h"
class GameEngine
{
	Hero mHero;
	Map mMap;

	static MapInfo previousMapInfo;
	static MapInfo previousPreviousMapInfo;

	void positionHeroAtStart();
	void generateMap();
	void collectTreasure(int x, int y);
	void determineactOnDirectionion(int x,int y);
	bool destinationIsWall(int x,int y) const;
	bool destinationIsTreasure(int x,int y) const;
	bool destinationIsMonster(int x,int y) const;
	bool destinationIsExit(int x,int y) const;
	void act(int x, int y);

public:
	GameEngine(const Hero& hero);
	void moveHero(string direction);
	void generateLevel();
	static void updatePreviousMapInfo(Map currentMap);
	void visualizeMap() const;
	void actOnDirection(int xOldCoordinate, int yOldCorodinate, int xNewCoordinate, int yNewCoordinate,int initialLevel);
};

#endif