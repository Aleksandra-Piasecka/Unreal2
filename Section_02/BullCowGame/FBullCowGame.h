#pragma once
#include <string>

class FBullCowGame 
{
public:
	void Return();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);



private:
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(string);

};