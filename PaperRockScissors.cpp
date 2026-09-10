// PaperRockScissors.cpp : Defines the entry point for the application.
//

#include "PaperRockScissors.h"
#include <iostream>
#include <random>


using namespace std;



// get player choice 
int playerChoice() 
{
	int Pchoice;

	

	while (true) {

		std::cin >> Pchoice;

		if (Pchoice == 1) {
			//Paper
			return Pchoice;
		}
		else if (Pchoice == 2) {
			//Rock
			return Pchoice;
		}
		else if (Pchoice == 3) {
			//Scissors
			return Pchoice;
		}
		else {
			//error
			std::cout << "Error: invalid input detected, please try again. \n";
		}
	}
	
	return 0;
}
// get player input to continue
int continueChoice() 
{
	int conti;

	while (true) {

		std::cin >> conti;

		if (conti == 1) {

			return conti;
		}
		else if (conti == 2) {

			return conti;
		}
		else {
			std::cout << "Error: invalid input detected, please try again. \n";
		}
	}
	return 0;
}
// get computer output 
int cpuChoice()
{
	int Cchoice;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(1, 3);

	Cchoice = distrib(gen);

	return Cchoice;
}
// get winner win == 1, , loss == 2
int getWinner(int P, int C)
{
	if ((P == 1 && C == 2) || (P == 2 && C == 3) || (P == 3 && C == 1)) {
		// player win
		return 1;
	}
	else if (P == C) {
		// draw
		
		return 2;
	}
	else {
		// player loss 
		
		return 3;
	}
	return 0;
}
int main()
{
	int player;
	int computer;
	int conti;
	int roundsPlayed = 0;
	int wins = 0;
	int loss = 0;
	int draw = 0;



	
	std::cout << "Welcome to Paper Rock Scissors! \n";
	std::cout << "The rules are simple, You will select between paper rock and scissors. \n";
	std::cout << "Then your choice will be compared against a computer's output. \n";
	std::cout << "The player with the winning hand... Wins! \n";
	std::cout << "You can play for as long as you like, but, once you stop the tournament winner will be decided\n";
	std::cout << "\n";
	std::cout << "\n";


	while (true) {
		roundsPlayed = roundsPlayed + 1;

		std::cout << "Player's choice.\n";
		std::cout << "[1] Paper \n";
		std::cout << "[2] Rock \n";
		std::cout << "[3] Scissors \n";

		player = playerChoice();
		computer = cpuChoice();


		if (getWinner(player, computer) == 1) {
			std::cout << "Player Wins! \n";
			wins = wins + 1;
		}
		else if (getWinner(player, computer) == 2) {
			std::cout << "Its a Draw! \n";
			draw = draw + 1;
		}
		else if (getWinner(player, computer) == 3) {
			std::cout << "CPU Wins \n";
			loss = loss + 1;
		}
		else {
			std::cout << "uhh theres something wrong";
		}
		std::cout << "\n";
		std::cout << "\n";

		std::cout << "Play again?\n";
		std::cout << "[1] play again!\n";
		std::cout << "[2] I'm done...\n";

		std::cout << "\n";
		std::cout << "\n";

		if (continueChoice() == 2) {
			break;
		}
	}

	//results
	if (wins > loss) {
		std::cout << "Player Wins the Tourney!\n";
	}
	else if (wins < loss) {
		std::cout << "Computer Wins the tourney!\n";
	}
	else {
		std::cout << "The Tournament Ends in a draw!\n";
	}

	//statistics
	std::cout << "Rounds Played: " << roundsPlayed << "\n";
	std::cout << "Player Wins: " << wins << "\n";
	std::cout << "Computer Wins: " << loss << "\n";
	std::cout << "Rounds Tied: " << draw << "\n";
	std::cout << "\n";

	std::cout << "Thanks for playing!\n";

	return 0;
}
