//Lab 6 in
// Nhan Bui
#include <iostream>
#include <ctime>
#include "graph1.h"
#include "CardPlayer.h"
#include "time.h"

using namespace std;

int main()
{
    //Variable Declaration/Initialization
    int noCards = 0;
    char color = 'r';
    CardPlayer player1;
    CardPlayer dealer;

    srand(time(0));

    //Display Graphics
    displayGraphics();

    //Prompt for the suit color
    cout << "Enter the suit color (r for red suits, b for black suits): ";
    cin >> color;

    //Set the color
    if (color == 'r')
    {
        player1.setColor(color);
        dealer.setColor('b');
    }
    else
    {
        player1.setColor('b');
        dealer.setColor(color);
    }

    //Prompt for the number of cards
    cout << "Enter the number of cards to deal to each player (>= 5 but <= 10): ";
    cin >> noCards;


    //Set the nuCards (will need to dynamically allocate the hand inside of this method)
    player1.setNoCards(noCards);
    dealer.setNoCards(noCards);
    //Deal the cards
    player1.deal();
    dealer.deal();
    gout << setPos(150, 90) << setColor(255, 255, 255) << "Player1" << endg;
    gout << setPos(250, 90) << setColor(255, 255, 255) << "Dealer" << endg;
    //Display the cards
    player1.displayHand(150, 100);
    dealer.displayHand(250, 100);   
    //Display the score
    gout << setPos(150, 100 + 20 * (player1.getNoCards() - 1) + 115) << setColor(255, 255, 255) << "Score: " << player1.computeScore() << endg;
    gout << setPos(250, 100 + 20 * (player1.getNoCards() - 1) + 115) << setColor(255, 255, 255) << "Score: " << dealer.computeScore() << endg;

    return 0;

}
