//Nhan Bui
//Lab 6 out
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graph1.h"
#include "CardPlayerLab6out.h"

CardPlayer::CardPlayer()
{
	wildCard = 0;
	color = 'r';
	noCards = 0;
	wager = 0;
	winnings = 0;
	hand = NULL;
}
CardPlayer::~CardPlayer() 
{
	delete[]hand;
}
void CardPlayer::setWager(int wager) 
{
	if (wager < 5) {
		this->wager = 5;
	}
	else if (wager > 100) {
		this->wager = 100;
	}
	else
		this->wager = wager;
}
int CardPlayer::getWager() {
	return wager;
}
void CardPlayer::setNoCards(int noCards) {
	if (noCards < 5) {
		this->noCards = 5;
	}
	else if (noCards > 10) {
		this->noCards = 10;
	}
	else {
		this->noCards = noCards;
	}
	hand = new int[this->noCards];
}
int CardPlayer::getNoCards()
{
	return noCards;
}
void CardPlayer::setColor(char color) {
	this->color = color;
}
void CardPlayer :: genWildCard()
{
	wildCard = rand() % 13 + 2;
}
int CardPlayer::getWildCard()
{
	return wildCard;
}
void CardPlayer :: displayWildCard(int x, int y) {
	string fn = "";
	if (color == 'r')
	{
		fn = "h";
	
	}
	else {
		fn = "s";
	}
	displayBMP(fn + to_string(wildCard) + ".bmp", x, y);
}
int CardPlayer::computeWildCardScore() {
	int num = 0;
	if (wildCard >= 11 && wildCard <= 13) {
		// Face cards (Jack, Queen, King) are worth 10 points
		num = 10;
		return num;
	}
	else if (wildCard == 14) {
		// Ace is worth 11 points
		num = 11;
		return num;
	}
	else {
		// others equal to their card number.
		num = wildCard;
		return num;
	}
}
int CardPlayer::computeScore() {
	int score = 0;
	int num = 0;
	int i = 0;
	for (i = 0; i < noCards; i++)
	{
		if (hand[i] == 10 || hand[i] == 11 || hand[i] == 12 || hand[i] == 13)
		{
			num = 10;
		}
		else if (hand[i] == 14)
		{
			num = 11;
		}
		else
		{
			num = hand[i];
		}
		score += num;
	}
	return score;
}
void CardPlayer::deal() {
	{
		bool duplicate = false;


		for (int i = 0; i < noCards; i++)
		{
			hand[i] = rand() % 13 + 2;

			do
			{
				duplicate = false;
				for (int j = 0; j < i; j++)
				{
					if (hand[i] == hand[j])
					{
						hand[i] = rand() % 13 + 2;
						duplicate = true;
						break;
					}
				}
			} while (duplicate);
		}

	}

}
void CardPlayer::sort() {
	for (int i = 0; i < noCards - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < noCards; ++j) {
			if (hand[j] < hand[minIndex])
				minIndex = j;
		}
		swap(hand[i], hand[minIndex]);
	}
}
int CardPlayer::binarySearch(int value) {
	int left = 0;
	int right = noCards - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;  // Calculate mid number

		if (hand[mid] == value) {
			return mid;  // value found -> return
		}
		else if (hand[mid] < value) {
			left = mid + 1;  // search right half
		}
		else {
			right = mid - 1;  // search left half
		}
	}
	return -1;  // Value not found
}
int CardPlayer::accumulateWinnings(bool win) {
	if (win == true) {
		winnings += wager;  //add wager  if win
	}
	else {
		winnings -= wager;  // lose wager if lose
	}
	return winnings;
}
int CardPlayer::getTotalWinnings() {
	return winnings;  // Return the total accumulated winnings
}
void CardPlayer::displayHand(int x, int y)
{
	int i = 0;
	string fn = "";

	if (color == 'r')
	{
		fn = "d";
	}
	else
	{
		fn = "c";
	}

	for (i = 0; i < noCards; i++)
	{
		displayBMP(fn + to_string(hand[i]) + ".bmp", x, y + 20 * i);

	}
}