#include "gameEngine.h"

GameEngine::GameEngine(const Hero& hero) :previousPreviousMapInfo(1, 2, 2, 10, 10), previousMapInfo(2, 3, 2, 15, 10), mHero(hero), mMap(previousPreviousMapInfo)
{
	generateLevel();
}

void GameEngine::generateLevel()
{
	if (mHero.getCurrentLevel() != 1)
	{
		generateMap();
	}
	positionHeroAtStart();
}

void GameEngine::updatePreviousMapInfo(Map currentMap)
{
	previousPreviousMapInfo = previousMapInfo;
	previousMapInfo = {currentMap.getLevel(),currentMap.getMonstersCount(),currentMap.getTreasuresCount(),currentMap.getRows(),currentMap.getCols() };
}

void  GameEngine::positionHeroAtStart()
{
	int xCoordinate = 1;
	int yCoordinate = 1;
	mHero.setCoordinates(xCoordinate, yCoordinate);
	mMap.setEntityOnMap(xCoordinate, yCoordinate, 'H'); //Symbol of hero will be H
}

void  GameEngine::moveHero(string direction)
{
	int initialLevel = mHero.getCurrentLevel();
	bool isNotLevelledUp=true;
	if (direction != "left" && direction != "right" && direction != "up" && direction != "down")
	{
		cout <<"Invalid direction! No actOnDirectionion taken.";
		return;
	}
	int xOldCoordinate = mHero.getXCoordinate();
	int yOldCoordinate = mHero.getYCoordinate();
	if (direction == "left")
	{
		actOnDirection(xOldCoordinate, yOldCoordinate, xOldCoordinate, yOldCoordinate - 1, initialLevel);
	}
	else if (direction == "right")
	{
		actOnDirection(xOldCoordinate, yOldCoordinate, xOldCoordinate, yOldCoordinate+1, initialLevel);
	}
	else if (direction == "up")
	{
		actOnDirection(xOldCoordinate, yOldCoordinate, xOldCoordinate - 1, yOldCoordinate, initialLevel);
	}
	else if (direction == "down")
	{
		actOnDirection(xOldCoordinate, yOldCoordinate, xOldCoordinate + 1, yOldCoordinate, initialLevel);
	} 
}

void GameEngine::actOnDirection(int xOldCoordinate, int yOldCoordinate, int xNewCoordinate, int yNewCoordinate,int initialLevel)
{
	bool destIsWall = destinationIsWall(xNewCoordinate,yNewCoordinate);
	if (!destIsWall)
	{
		act(xNewCoordinate,yNewCoordinate);
		bool isNotLevelledUp = mHero.getCurrentLevel() == initialLevel;
		if (isNotLevelledUp)
		{
			mMap.markCellAsVisited(xOldCoordinate, yOldCoordinate);
		}
	}
}

void GameEngine::determineactOnDirectionion(int x,int y)
{
	if (destinationIsTreasure(x, y))
	{
		system("CLS");
		collectTreasure(x,y);
	}
	else if (destinationIsMonster(x, y))
	{
		try
		{
			int monsterIndex = mMap.getMonsterIndexByCoordinates(x, y);
			bool result = mHero.battle(mMap.mMonsters[monsterIndex]);
			if (result)
			{
				mMap.mMonsters.erase(mMap.mMonsters.begin() + monsterIndex);
				mMap.setEntityOnMap(x, y, '.'); // monster is no longer on cell
			}
		}
		catch (int)
		{
			throw - 1; // will catch this in main and end program;
		}
		
	}
	else if (destinationIsExit(x, y))
	{
		mHero.levelUp();
		generateLevel();
	}
}

void GameEngine::collectTreasure(int x, int y)
{
	int treasureIndex = mMap.getTreasureIndexByCoordinates(x, y);
	mHero.takeTreasure(*mMap.mTreasures.getAt(treasureIndex));
	mMap.mTreasures.removeIndex(treasureIndex);
}

bool GameEngine::destinationIsWall(int x, int y) const
{
	return mMap.getCell(x, y).getSymbol() == '#';
}

bool GameEngine::destinationIsTreasure(int x, int y) const
{
	return mMap.getCell(x, y).getSymbol() == 'T';
}

bool GameEngine::destinationIsMonster(int x, int y) const
{
	return mMap.getCell(x, y).getSymbol() == 'M';
}

bool GameEngine::destinationIsExit(int x, int y) const
{
	return x == mMap.getRows() - 2 && y == mMap.getCols() - 1;
}

void GameEngine::generateMap()
{
	int level = mHero.getCurrentLevel();
	if (level == 1)
	{
		return;
	}
	else if (level == 2)
	{
		mMap = Map(previousMapInfo);
	}
	else
	{
		mMap = Map(previousPreviousMapInfo, previousMapInfo);
		updatePreviousMapInfo(mMap);
	}
}

void GameEngine::act(int nextXCoordinate,int nextYCoordinate)
{
	int currentLevel = mHero.getCurrentLevel();
	mHero.setCoordinates(nextXCoordinate, nextYCoordinate);
	determineactOnDirectionion(mHero.getXCoordinate(), mHero.getYCoordinate());
	int newLevel = mHero.getCurrentLevel();
	if (currentLevel == newLevel)
	{
		mMap.mGrid.setCellValue(nextXCoordinate, nextYCoordinate, 'H');
	}
	
	
	
	
}

void GameEngine::visualizeMap() const
{
	system("CLS");
	mMap.visualize();
}

