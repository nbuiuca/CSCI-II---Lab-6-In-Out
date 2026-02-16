//Nhan Bui
//Lab 6 out
#include <iostream>
#include <ctime>
#include "graph1.h"
#include <cstdlib>
#include "CardPlayerLab6out.h"
using namespace std;
int main() {
	srand(time(0));
	int noCards = 0;
	int wager = 0;
	CardPlayer player1;
	CardPlayer dealer;
	char suitColor = 'r';
	char wildCardRound = 'y';
	char Answer;
	displayGraphics();
	cout << "Enter suit color for player (r for red, b for black): ";
	cin >> suitColor;
	if (suitColor == 'r')
	{
		player1.setColor(suitColor);
		dealer.setColor('b');
	}
	else
	{
		player1.setColor(suitColor);
		dealer.setColor('r');
	}
	do {
		cout << "Enter the number of cards to deal to each player (>= 5 but <= 10): ";
		cin >> noCards;
		player1.setNoCards(noCards);
		dealer.setNoCards(noCards);
		cout << "Enter the wager (>= 5 but <=100): ";
		cin >> wager;
		player1.setWager(wager);
		player1.deal();
		dealer.deal();
		player1.displayHand(150, 100);
		dealer.displayHand(250, 100);
		gout << setPos(150, 80) << "Player 1" << endg;
		gout << setPos(250, 80) << "Dealer" << endg;
		Sleep(3 * 1000);
		player1.sort();
		dealer.sort();
		player1.displayHand(150, 100);
		dealer.displayHand(250, 100);
		gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115) << setColor(255, 255, 255) << "Score: " << player1.computeScore() << endg;
		gout << setPos(250, 100 + 20 * (player1.getNoCards() - 1) + 115) << setColor(255, 255, 255) << "Score: " << dealer.computeScore() << endg;
		int playerScore = player1.computeScore();
		int dealerScore = dealer.computeScore();

		bool playerWon = playerScore > dealerScore;
		int totalWinnings = player1.accumulateWinnings(playerWon);
		gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115 + 30) << setColor(255, 255, 255) << "Total Winnings: " << totalWinnings << endg;
		gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115 + 10) << setColor(255, 255, 255) << (playerWon ? "Player wins the round!" : "Dealer wins the round!") << endg;
		
		

		cout << "Play Wild Card Round? (y/n): ";
		cin >> wildCardRound;
		if (tolower(wildCardRound) == 'y') {
			clearText();
			//Generate and Display Wild Cards
			player1.genWildCard();
			dealer.genWildCard();

		
			player1.displayWildCard(150, 5);
			
			dealer.displayWildCard(250, 5);
			gout << setPos(150, 100) << setColor(255, 0, 255) <<
				"Wild Card" << endg;
			gout << setPos(250, 100) << setColor(255, 0, 255) <<
				"Wild Card" << endg;
			int newPlayerScore = 0;
			int newDealerScore = 0;
			if (player1.binarySearch(player1.getWildCard()) == -1)
			{
				newPlayerScore = player1.computeScore() + player1.computeWildCardScore();
				gout << setPos(130, 100 + 20 * (player1.getNoCards() - 1) + 115) <<
					setColor(255, 255, 255) << "New Score: " << newPlayerScore << endg;
			}
			else
			{
				newPlayerScore = player1.computeScore() + player1.computeWildCardScore() + 10;
				gout << setPos(130, 100 + 20 * (player1.getNoCards() - 1) + 115) <<
					setColor(255, 255, 255) << "New Score: " << newPlayerScore << endg;
			}
			if (dealer.binarySearch(dealer.getWildCard()) == -1)
			{
				newDealerScore = dealer.computeScore() + dealer.computeWildCardScore();
				gout << setPos(270, 100 + 20 * (dealer.getNoCards() - 1) + 115) <<
					setColor(255, 255, 255) << "New Score: " << newDealerScore << endg;
			}
			else
			{
				newDealerScore = dealer.computeScore() + dealer.computeWildCardScore() + 10;
				gout << setPos(270, 100 + 20 * (dealer.getNoCards() - 1) + 115) <<
					setColor(255, 255, 255) << "New Score: " << newDealerScore << endg;
			}
			
			bool playerWonWildCard = newPlayerScore > newDealerScore;
			
			player1.accumulateWinnings(playerWonWildCard);
			string result = "";
			bool wl = true;
			if (newPlayerScore > newDealerScore)
			{
				result = "win";
			}
			else
			{
				result = "false";
				wl = false;
			}
			gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115 + 10) << setColor(255, 255, 255) << (playerWonWildCard ? "Player wins the Wild Card round!"
				: "Dealer wins the Wild Card round!");
			gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115 + 30) << setColor(255, 255, 255) << "Total Winnings: " << player1.getTotalWinnings();
			gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115 + 20) <<
				setColor(255, 255, 255) << "You " +result + " this Amount " <<
				player1.getWager() << endg;

			//gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115 + 20 + 20) <<
				//setColor(255, 255, 255) << "Accumulated Winnings <-Losses> " <<
				//player1.accumulateWinnings(playerWonWildCard) << endg;
		}

		cout << "Play again? (y/n): ";
		cin >> Answer;
		clearGraphics();

		player1.~CardPlayer();
		dealer.~CardPlayer();
	} while (tolower(Answer) == 'y');
	return 0;
}