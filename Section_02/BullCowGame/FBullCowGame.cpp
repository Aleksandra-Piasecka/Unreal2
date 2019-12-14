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
	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) const
{
	return false;
}

// receive a valid guess, incriments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTry++;

	//setup a return number
	FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenght; i++) // i = MyHiddenWordChar
	{
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLenght; j++) // j = GuesChar
		{
			if (Guess[j] == MyHiddenWord[i]) // if they match then
			{
				if (i == j) // if the're in the same place
				{
					BullCowCount.Bulls++; //incriment bulls
				}
				else
				{
					BullCowCount.Cows++; //incriment cows
				}
			}
		}
	}
	return BullCowCount;
}
