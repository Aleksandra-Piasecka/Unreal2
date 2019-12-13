#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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

	constexpr int WORD_LENGHT = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
// TODO change from FOR to WHILE loop once we are validating tries
//loop for the number of turns asking for guesses
	for (int i = 1; i <= MaxTries; i++) 
	{
		std::string Guess = GetGuess(); //TODO make loop checking valid 

		//submit valid guess to the game
		//print number of bull and cows


		//print the guess
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO add a game summary
}

//get a guess from the player
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout <<"Try " << CurrentTry <<". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}
