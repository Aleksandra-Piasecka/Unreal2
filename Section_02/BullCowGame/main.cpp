/* This is the console executable, that make us of the BullCow class
This acts as the view in a MVC pattern and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game
int main() 
{
	bool bPlayAgain = false;
	do
	{  
		PrintIntro();
		PlayGame();

		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	return 0;
}

//introduce the game
void PrintIntro()
{

	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
// TODO change from FOR to WHILE loop once we are validating tries
//loop for the number of turns asking for guesses
	for (int32 i = 1; i <= MaxTries; i++) 
	{
		FText Guess = GetGuess(); //TODO make loop checking valid 

		//submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print number of bull and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
			
		std::cout << std::endl;
	}
	// TODO add a game summary
}

//get a guess from the player
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout <<"Try " << CurrentTry <<". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}
