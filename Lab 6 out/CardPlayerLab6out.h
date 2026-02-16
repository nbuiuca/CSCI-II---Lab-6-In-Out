#ifndef CARDPLAYER_H
#define CARDPLAYER_H


class CardPlayer
{
private:
	int wildCard;
	char color;
	int  noCards;
	int wager;
	int winnings;
	int* hand;

public:
	CardPlayer();
	~CardPlayer();
	void setWager(int wager);
	int getWager();
	void setNoCards(int noCards);
	int getNoCards();
	void setColor(char color);
	void genWildCard();
	int getWildCard();
	void displayWildCard(int x, int y);
	int computeWildCardScore();
	void displayHand(int x, int y);
	int computeScore();
	void deal();
	void sort();
	int binarySearch(int value);
	int accumulateWinnings(bool win);
	int getTotalWinnings();

};

#endif
#pragma once
