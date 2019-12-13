#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


int main() 
{
	bool bPlayAgain = false;
	do
	{  
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}

//introduce the game
void PrintIntro()
{

	constexpr int WORLD_LENGHT = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORLD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	FBullCowGame BCGame; //instantiate a new game

//loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		std::string Guess = GetGuess();
		//print the guess
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

//get a guess from the player
std::string GetGuess()
{
	
	std::cout << "Enter your guess: ";
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
