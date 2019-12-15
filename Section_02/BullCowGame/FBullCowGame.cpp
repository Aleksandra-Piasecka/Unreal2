#pragma once

#include "FBullCowGame.h"
#include <map>

// to make syntax Unreal friendly
#define TMap std::map 
using int32 = int;


FBullCowGame::FBullCowGame() //default constructor
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}
int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}
int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "donkey"; //this must be isogram
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function
	}
	else if (!IsLowercase(Guess))	//if the guess isn't all lovercase
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if (Guess.length() != GetHiddenWordLenght())
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// receive a valid guess, incriments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLenght = MyHiddenWord.length();
	
	// loop through all letters in the hidden word
	for (int32 i = 0; i < WordLenght; i++) // i = MyHiddenWordChar
	{
		// compare letters against the guess
		for (int32 j = 0; j < WordLenght; j++) // j = GuesChar
		{
			if (Guess[j] == MyHiddenWord[i]) // if they match then
			{
				if (i == j) // if the're in the same place
				{
					BullCowCount.Bulls++; //incriment bulls
				}
				else
				{
					BullCowCount.Cows++; //must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLenght)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LetterSeen; //set up a map
	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case

		if (LetterSeen[Letter])	// if the letter is in the map
		{
			return false;// we do NOT have an isogram
		}
		else
		{
			LetterSeen[Letter] = true;// add the letter to the map as seen
		}
	}
								 
	return true; // for example in case where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) // if not a lowercase letter
		{
			return false;

		}
	}
	return true;
}
