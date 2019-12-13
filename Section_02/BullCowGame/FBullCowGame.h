#pragma once
#include <string>

class FBullCowGame 
{
public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make more rich return value
	bool CheckGuessValidity(std::string); // TODO make more rich return value
	// provide a method for counting bulls&cows and increasing turn #

private:
	int MyCurrentTry;
	int MyMaxTries;

};