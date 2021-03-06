#include "GameFileManager.h"

GameFileManager::GameFileManager() :fileIsOpen(false), mCurentFileName(""), unsavedChanges(false)
{

}

bool GameFileManager::getFileIsOpenStatus() const
{
	return fileIsOpen;
}

bool GameFileManager::getUnsavedChanges() const
{
	return unsavedChanges;
}

string GameFileManager::getFileName() const
{
	return mCurentFileName;
}


void GameFileManager::setFileIsOpenStatus(bool status)
{
	fileIsOpen = status;
}

void GameFileManager::setUnsavedChanges(bool status)
{
	unsavedChanges = status;
}

void GameFileManager::setFileName(string name)
{
	mCurentFileName=name;
}


void GameFileManager::open(string fileName,Hero& hero,Map& map)
{
	if (getFileIsOpenStatus())
	{
		cout << "Currently file " << fileName << " is opened. Close it and try again!" << std::endl;
		return;
	}
	setFileName(fileName);
	setFileIsOpenStatus(true);
	ifstream file(fileName);

	if (file)
	{
		file >> hero;
		file >> map;
		cout << "Successfully opened " << fileName<<endl;
		try
		{
			file.close();
		}
		catch (const std::exception&)
		{

		}
	}
	else
	{
		fstream newFile(fileName,ios::app);
		cout << "Created file " << fileName <<"."<< endl;
		try
		{
			newFile.close();
		}
		catch (const std::exception&)
		{

		}
		
	}
	
	
}

void GameFileManager::close()
{
	if (fileIsOpen)
	{
		cout << "Successfully closed " << mCurentFileName;
	}
	fileIsOpen = false;
	mCurentFileName = "";
	unsavedChanges = false;
}

void GameFileManager::save(const Hero& hero,const Map& map)
{
	if (fileIsOpen)
	{
		ofstream file(mCurentFileName);
		file << hero;
		file << map;
		try
		{
			file.close();
		}
		catch (const std::exception&)
		{

		}
		unsavedChanges = false;
	}
	else
	{
		cout << "No file is currently open!" << endl;
	}
	
}

void GameFileManager::saveAs(string newFileName, const Hero& hero, const Map& map)
{
	if (fileIsOpen)
	{
		ofstream file(newFileName);
		file << hero;
		file << map;
		try
		{
			file.close();
		}
		catch (const std::exception&)
		{

		}
		unsavedChanges = false;
	}
	else
	{
		cout << "No file is currently open!" << endl;
	}
}