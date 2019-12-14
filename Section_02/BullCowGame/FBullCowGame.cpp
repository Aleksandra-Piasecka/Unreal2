#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
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
	constexpr int32  MAX_TRIES = 8;
	const FString HIDDEN_WORD = "donkey";

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
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function
	}
	else if (false)	//if the guess isn't all lovercase
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
