#include <iostream>
#include <string>
using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main() 
{
	PrintIntro();
	GetGuessAndPrintBack();
	GetGuessAndPrintBack();
	return 0;
}

//introduce the game
void PrintIntro()
{

	constexpr int WORLD_LENGHT = 9;
	cout << "Welcome to Bulls and Cows, a fun word game. \n";
	cout << "Can you guess the " << WORLD_LENGHT;
	cout << " letter isogram I'm thinking of?\n";
	return;
}

//get a guess from the player
string GetGuessAndPrintBack()
{
	
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	//print the guess
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}