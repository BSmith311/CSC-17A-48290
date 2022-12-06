/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on December 5, 2022
 * Purpose: Project 2, Blackjack (v6)
 * Current: Added gamble header/class for betting, splitting (needs testing), and insurance. 
 *          Added several checklist items
 *          
 * Future:  Add doubling down
 *          Continue to add checklist items
 *          Learn how to use doxygen
 *          Test insurance and splitting more (make cheat functions to test)
 *          Add new rules to rules function
 *          Check if starting with double aces results in error, pretty sure it will
 *              Possible Fix: Call ace rule before displaying initial hand
 *                            Have to call it after split check though
 *          Make it so if user hits blackjack and dealer doesn't, user wins
 *          Pay out 2.5x for blackjack
 *          Change gamble class so game class inherits it
 * 
 * Notes:   
 *          Remember to upload to github
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
    //Change funds from static and move outside of function, output here
    
    //Exit Program
        return 0;
}

//Functions
//Plays a game of blackjack
void playBlackjack(const int DECK_OF_CARDS, ifstream& inFile, string inName)
{
    //Declare variables
    static float funds = 10000.00;
    bool split = false;
    char splitChoice;
    bool insurance = false;
    float insBet;
    float bet;
    
    //Setup blackjack class
    Game blackjack;
    blackjack.setDeck(DECK_OF_CARDS, inFile, inName);
    blackjack.gambling.setFunds(funds);
    
    //Get user's bet
    cout<<"How much would you like to bet?"
        <<"(Current Funds: $"<<blackjack.gambling.getFunds()<<")"<<endl;
    cout<<"Bet: $";
    cin>>bet;
    
    try
    {
        blackjack.gambling.BadBet(bet);
    }
    catch (string exceptionString)
    {
        cout<<exceptionString<<endl;
        exit(EXIT_SUCCESS);
    }
    
    //Draw 2 cards for the dealer and player
    for (int i = 0; i < 2; i++)
    {
        blackjack.drawDCard();
        blackjack.drawP1Card();
    }
    
    blackjack.gambling.setBet(bet);
    
    //Player Turn
    char choice;
    char choice2;
    cout<<endl<<"Player's Turn:"<<endl;
    
    //Display initial hand
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    blackjack.dealer.printFirst();
    cout<<"\nPlayer's Current Hand: ";
    blackjack.player1.printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
    
    //Check for insurance
    if (blackjack.dealer.getCardP(0) == 11){
        cout<<"The dealer's first card is an Ace, how much is your insurance bet?"<<endl;
        cout<<"(You can bet $0 if you want no insurance)"<<endl;
        cout<<"Insurance bet: $";
        cin>>insBet;
        
        //Check for bad insurance bet
        try
        {
            blackjack.gambling.BadBet(insBet);
        }
        catch (string exceptionString)
        {
            cout<<exceptionString<<endl;
            exit(EXIT_SUCCESS);
        }
        
        if (insBet > 0)
        {
            insurance = true;
            blackjack.gambling.setInsurance(insBet);
        }
    }
    
    //Check for splitting
    if (blackjack.player1.getCardP(0) == blackjack.player1.getCardP(1))
    {
        cout<<"Your first two cards are worth the same! Would you like to split? (Y/N): ";
        cin>>splitChoice;
        while (splitChoice != 'Y' && splitChoice != 'y' && 
               splitChoice != 'n' && splitChoice != 'n')
        {
            cout<<"Invalid choice, enter 'Y' to split or 'N' to keep your current hand: ";
            cin>>splitChoice;
        }
        
        if (splitChoice == 'Y' or splitChoice == 'y')
        {
            //Check if player can afford to split
            try
            {
                blackjack.gambling.BadBet(bet);
            }
            catch (string exceptionString)
            {
                cout<<exceptionString<<endl;
                exit(EXIT_SUCCESS);
            }

            blackjack.gambling.doubleBet();
            split = true;
        }
    }
    
    //Non-split game play
    if (!split)
    {
    //Hit, stand, or double down
    while (blackjack.player1.getTotal() < 21 && choice != 'S' && choice != 's')
    {
        //Ace rule check
        if (blackjack.player1.getTotal() > 21)
        {
            blackjack.player1.aceRule();
        }
        
        //Hit or Stand
        cout<<"Hit or Stand (H/S): ";
        cin>>choice;
        while (choice != 'H' && choice != 'h' && choice != 'S' && choice != 's')
        {
            cout<<"Invalid choice, enter 'H' to hit or 'S' to Stand: ";
            cin>>choice;
        }
        
        //Hit
        if (choice == 'H' or choice == 'h')
        {
            //Draw a card
            blackjack.drawP1Card();
            
            //Ace rule check
            if (blackjack.player1.getTotal() > 21)
            {
                blackjack.player1.aceRule();
            }
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.dealer.printFirst();
            cout<<"\nPlayer's Current Hand: ";
            blackjack.player1.printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
    }
    
    //Dealer's Turn
    if (blackjack.player1.getTotal() < 22)
    {
        //Ace rule check
        if (blackjack.dealer.getTotal() > 21)
        {
            blackjack.dealer.aceRule();
        }
        
        cout<<"\nDealer's Turn:"<<endl;
        blackjack.printHands();
        
        //Loop while dealer is under 17
        while (blackjack.dealer.getTotal() < 17)
        {
            //Draw a card
            blackjack.drawDCard();
            
            //Ace rule check
            if (blackjack.dealer.getTotal() > 21) blackjack.dealer.aceRule();
            
            //Print new hand
            blackjack.printHands();
        }
    }
    
    //Output final hand
    cout<<"\nFinal Results:"<<endl;
    blackjack.printHands();
    
    //Check winner
    if (blackjack.player1.getTotal() < 22)
            {
                if (blackjack.dealer.getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                    cout<<"You won $"<<(blackjack.gambling.getBet() * 2)<<"!"<<endl;
                    blackjack.gambling.payOut(bet,2);
                }
                else if (blackjack.player1.getTotal() > blackjack.dealer.getTotal())
                {
                    cout<<"You win!"<<endl;
                    cout<<"You won $"<<(blackjack.gambling.getBet() * 2)<<"!"<<endl;
                    blackjack.gambling.payOut(bet,2);
                }
                else if (blackjack.player1.getTotal() < blackjack.dealer.getTotal())
                {
                    cout<<"You lost, better luck next time!"<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                    cout<<"You get back $"<<blackjack.gambling.getBet()<<endl;
                    blackjack.gambling.payOut();
                }
            }
            else
            {
                cout<<"You busted, you lose."<<endl;
            }
    
    //Check insurance
    if (insurance)
    {
        if (blackjack.dealer.getTotal() == 21 && blackjack.dealer.getDrawn() == 2)
        {
            cout<<"The dealer had blackjack, your insurance paid $"
                <<(blackjack.gambling.getInsurance() * 2)<<"!"<<endl;
            blackjack.gambling.payOut(insBet);
        }
        else
        {
            cout<<"The dealer did not have blackjack, your insurance is lost."<<endl;
        }
    }
    
    funds = blackjack.gambling.getFunds();
    cout<<endl;
    }
    
    //Split game play
    else
    {
    //Split the hands
    blackjack.splitHands();
    
    //Display initial hands
    cout<<"Initial Hands: "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    blackjack.dealer.printFirst();
    cout<<"\nPlayer's First Hand: ";
    blackjack.player1.printCards();
    cout<<"\nPlayer's Second Hand: ";
    blackjack.player2.printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
    
    //First Hand
    while (blackjack.player1.getTotal() < 21 && choice != 'S' && choice != 's')
    {
        //Ace rule check
        if (blackjack.player1.getTotal() > 21)
        {
            blackjack.player1.aceRule();
        }
        
        //Hit or Stand
        cout<<"Hit or Stand (H/S): ";
        cin>>choice;
        while (choice != 'H' && choice != 'h' && choice != 'S' && choice != 's')
        {
            cout<<"Invalid choice, enter 'H' to hit or 'S' to Stand: ";
            cin>>choice;
        }
        
        //Hit
        if (choice == 'H' or choice == 'h')
        {
            //Draw a card
            blackjack.drawP1Card();
            
            //Ace rule check
            if (blackjack.player1.getTotal() > 21)
            {
                blackjack.player1.aceRule();
            }
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.dealer.printFirst();
            cout<<"\nPlayer's First Hand: ";
            blackjack.player1.printCards();
            cout<<"\nPlayer's Second Hand: ";
            blackjack.player2.printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
    }
    
    //Second Hand
    while (blackjack.player2.getTotal() < 21 && choice2 != 'S' && choice2 != 's')
    {
        //Ace rule check
        if (blackjack.player2.getTotal() > 21)
        {
            blackjack.player2.aceRule();
        }
    
        cout<<"Hit or Stand (H/S): ";
        cin>>choice2;
        while (choice2 != 'H' && choice2 != 'h' && choice2 != 'S' && choice2 != 's')
        {
            cout<<"Invalid choice, enter 'H' to hit or 'S' to Stand: ";
            cin>>choice2;
        }
    
        //Hit
        if (choice2 == 'H' or choice2 == 'h')
        {
            //Draw a card
            blackjack.drawP2Card();
            
            //Ace rule check
            if (blackjack.player2.getTotal() > 21)
            {
                blackjack.player2.aceRule();
            }
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.dealer.printFirst();
            cout<<"\nPlayer's First Hand: ";
            blackjack.player1.printCards();
            cout<<"\nPlayer's Second Hand: ";
            blackjack.player2.printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
    }
    
    //Dealer's Turn
    if (blackjack.player1.getTotal() < 22 or blackjack.player2.getTotal() < 22)
    {
        //Ace rule check
        if (blackjack.dealer.getTotal() > 21)
        {
            blackjack.dealer.aceRule();
        }
        
        cout<<"\nDealer's Turn:"<<endl;
        blackjack.printSplitHands();
        
        //Loop while dealer is under 17
        while (blackjack.dealer.getTotal() < 17)
        {
            //Draw a card
            blackjack.drawDCard();
            
            //Ace rule check
            if (blackjack.dealer.getTotal() > 21) blackjack.dealer.aceRule();
            
            //Print new hand
            blackjack.printSplitHands();
        }
    }
}
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
        if (cardP[i] >= 1  && cardP[i] <= 4)
        {
            cardP[i] = 11;
        }
        else if (cardP[i] >= 5  && cardP[i] <= 8)
        {
            cardP[i] = 2;
        }
        else if (cardP[i] >= 9  && cardP[i] <= 12)
        {
            cardP[i] = 3;
        }
        else if (cardP[i] >= 13 && cardP[i] <= 16)
        {
            cardP[i] = 4;
        }
        else if (cardP[i] >= 17 && cardP[i] <= 20)
        {
            cardP[i] = 5;
        }
        else if (cardP[i] >= 21 && cardP[i] <= 24)
        {
            cardP[i] = 6;
        }
        else if (cardP[i] >= 25 && cardP[i] <= 28)
        {
            cardP[i] = 7;
        }
        else if (cardP[i] >= 29 && cardP[i] <= 32)
        {
            cardP[i] = 8;
        }
        else if (cardP[i] >= 33 && cardP[i] <= 36)
        {
            cardP[i] = 9;
        }
        else if (cardP[i] >= 37 && cardP[i] <= 52)
        {
            cardP[i] = 10;
        }
    }
    
    //Close File
    file.close();
}

//Splits the player's hand
void Game::splitHands()
{
    int tempP;
    string tempN;
    
    //Second hand starts with the second card of initial hand
    //Save the first card info from the second hand
    tempP = player2.getCardP(0);
    tempN = player2.getCardN(0);
    
    //Copy the second card from first hand to first card of second hand
    player2.setCardP(0,player1.getCardP(1));
    player2.setCardN(0,player1.getCardN(1));
    
    //Copy the temp card info to the second card of first hand
    player1.setCardP(1,tempP);
    player1.setCardN(1,tempN);
    
    //Reset Totals
    player1.setInitialTotal();
    player2.setInitialTotal();
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

//Prints the hands for the player's first and second hand and dealer's hand
void Game::printSplitHands()
{
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    dealer.printCards();
    cout<<"\nPlayer's First Hand: ";
    player1.printCards();
    cout<<"\nPlayer's Second Hand: ";
    player2.printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
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