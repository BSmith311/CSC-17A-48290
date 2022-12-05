/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 30, 2022
 * Purpose: Project 2, Blackjack (v5)
 * Current: Altered class again, more efficient and clean now.
 *          Returned most functions from Project 1
 *          
 * Future:  Add checklist items
 *          Learn how to use doxygen
 *          Add several blackjack features, betting, splitting, insurance, etc.
 * 
 * Notes:   For splitting, set first p2 card to second p1 card, draw new card for p1 and p2
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//User Libraries
//#include "Hand.h"
#include "Game.h"

//Function Prototypes
void showRules();
void playBlackjack(const int, ifstream&, string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int DECK_OF_CARDS = 52;
    enum Menu{PLAY = 1, STATS = 2, RULES = 3};
    int gWon;
    int gPlay;
    int pDraw;
    int dDraw;
    int choice;
    int *ptr = nullptr;
    
    //Deck of cards file
    ifstream inFile;
    string inName = "deckOfCards.dat";
    
    //Program Menu
    do{
        cout<<"Please select one of the following options:"<<endl;
        cout<<"1. Play Blackjack"<<endl;
        cout<<"2. View stats"<<endl;
        cout<<"3. View the Rules"<<endl;
        cin>>choice;
        cout<<endl;
        
        //Process inputs
        switch(choice)
        {
            case PLAY:
            {
                //Call blackjack function
                playBlackjack(DECK_OF_CARDS, inFile, inName);
                
                break;
            }
            case STATS:
            {
                //stats(gWon,gPlay,pDraw,dDraw);
                break;
            }
            case RULES:
            {
                showRules();
                break;
            }
            default: 
            {
                cout<<"Quitting Blackjack"<<endl;
            }
        }
    }while(choice >= 1 && choice <= 3);
    
    //Output Stats
    
    
    //Exit Program
        return 0;
}

//Functions
//Plays a game of blackjack
void playBlackjack(const int DECK_OF_CARDS, ifstream& inFile, string inName)
{
    //Setup blackjack class
    Game blackjack;
    blackjack.setDeck(DECK_OF_CARDS, inFile, inName);
    
    //Draw 2 cards for the dealer and player
    for (int i = 0; i < 2; i++)
    {
        blackjack.drawDCard();
        blackjack.drawP1Card();
    }
    
    //Player Turn
    char choice;
    cout<<"Player's Turn:"<<endl;
    
    //Display initial hand
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    blackjack.dealer.printFirst();
    cout<<"\nPlayer's Current Hand: ";
    blackjack.player1.printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
    
    do
    {
        //Ace rule check
        if (blackjack.player1.getTotal() > 21) blackjack.player1.aceRule();
        
        cout<<"Hit or Stand (H/S): ";
        cin>>choice;
        while (choice != 'H' && choice != 'h' && choice != 'S' && choice != 's')
        {
            cout<<"Invalid choice, enter 'H' to hit or 'S' to Stand: ";
            cin>>choice;
        }
        
        if (choice == 'H' or choice == 'h')
        {
            //Draw a card
            blackjack.drawP1Card();
            
            //Ace rule check
            if (blackjack.player1.getTotal() > 21) blackjack.player1.aceRule();
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.dealer.printFirst();
            cout<<"\nPlayer's Current Hand: ";
            blackjack.player1.printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
    }while (blackjack.player1.getTotal() < 21 && choice != 'S' && choice != 's');
    
    //Dealer's Turn
    if (blackjack.player1.getTotal() < 22)
    {
        //Ace rule check
        if (blackjack.dealer.getTotal() > 21) blackjack.dealer.aceRule();
        
        cout<<"\nDealer's Turn:"<<endl;
        blackjack.printHands();
        
        do{
            //Draw a card
            blackjack.drawDCard();
            
            //Ace rule check
            if (blackjack.dealer.getTotal() > 21) blackjack.dealer.aceRule();
            
            //Print new hand
            blackjack.printHands();
        }while (blackjack.dealer.getTotal() < 17);
    }
    
    //Output results
    cout<<"\nFinal Results:"<<endl;
    blackjack.printHands();
    blackjack.checkWinner();
    cout<<endl;
}

//Sets the deck for the game
void Game::setDeck(const int DECK_OF_CARDS, ifstream& file, string fileName)
{
    //Initialize the Random Number Seed
    srand(static_cast<unsigned>(time(0)));
    
    //Open File
    file.open(fileName);
    if(!file)
    {
        cout<<"Error opening input file for the deck of cards."<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Deal the cards using rand
    string cardIn;
    for (int i = 0; i < deckSize; i++)
    {
        cardP[i] = (rand()%DECK_OF_CARDS+1);
    }
    
    //Assign the name of the card
    for (int i = 1; i <= DECK_OF_CARDS; i++)
    {
        //Input current card
        file>>cardIn;
        
        //Check hand for current card
        for (int j = 0; j < deckSize; j++)
        {
            if (i == cardP[j])
            {
                cardN[j] = cardIn;
            }
        }
    }
    
    //Assign the point value of the card
    for (int i=0; i < deckSize; i++){
        if (cardP[i] >= 1  && cardP[i] <= 4) cardP[i] = 11;
        else if (cardP[i] >= 5  && cardP[i] <= 8) cardP[i] = 2;
        else if (cardP[i] >= 9  && cardP[i] <= 12)cardP[i] = 3;
        else if (cardP[i] >= 13 && cardP[i] <= 16)cardP[i] = 4;
        else if (cardP[i] >= 17 && cardP[i] <= 20)cardP[i] = 5;
        else if (cardP[i] >= 21 && cardP[i] <= 24)cardP[i] = 6;
        else if (cardP[i] >= 25 && cardP[i] <= 28)cardP[i] = 7;
        else if (cardP[i] >= 29 && cardP[i] <= 32)cardP[i] = 8;
        else if (cardP[i] >= 33 && cardP[i] <= 36)cardP[i] = 9;
        else if (cardP[i] >= 37 && cardP[i] <= 52)cardP[i] = 10;
    }
    
    //Close File
    file.close();
}

//Prints the hands for the player's first hand and dealer's hand
void Game::printHands()
{
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    dealer.printCards();
    cout<<"\nPlayer's Current Hand: ";
    player1.printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
}

//Checks the winner for the player's first hand
void Game::checkWinner()
        {
            if (player1.getTotal() < 22)
            {
                if (dealer.getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                }
                if (player1.getTotal() > dealer.getTotal())
                {
                    cout<<"You win!"<<endl;
                }
                else if (player1.getTotal() < dealer.getTotal())
                {
                    cout<<"You lost."<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                }
            }
            else cout<<"You busted, you lose."<<endl;
            
        }

//Show the rules of blackjack
void showRules()
{
    //Output the rules of blackjack (DON'T FORGET TO ADD NEW RULES LATER!!!)
    cout<<"Rules of Blackjack:"<<endl;
    cout<<"The player and dealer are both given two cards to begin."<<endl;
    cout<<"Only the dealer's first card will be revealed during the player's turn."<<endl;
    cout<<"The goal is to get as close to 21 as you can without busting (going over)."<<endl;
    cout<<"On your turn, you can choose to either 'Hit' or 'Stand'."<<endl;
    cout<<"If you choose to hit, you will receive one additional card."<<endl;
    cout<<"If you choose to stand, your turn will end and the dealer's turn will begin."<<endl;
    cout<<"The dealer will 'Hit' until they reach a score of 17 or greater."<<endl;
    cout<<"Aces are worth 11 points, but they will become 1 point if the score is over 21."<<endl;
    cout<<"If you bust, you automatically lose. If the dealer busts, you automatically win."<<endl;
    cout<<"If your score is higher than the dealer, you win. If lower, you lose. If the same, it's a draw."<<endl<<endl;
}