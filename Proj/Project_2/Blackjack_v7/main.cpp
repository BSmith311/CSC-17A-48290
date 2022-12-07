/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on December 6, 2022
 * Purpose: Project 2, Blackjack (v7)
 * Current: Added cheat functions to check code more efficiently 
 *          (REMEMBER TO REMOVE IN FINAL VERSION)
 *          Fixed splitting function
 *          Fixed misc bugs
 *          Minor additions (ie rules)
 *          
 * Future:  Continue to add checklist items
 *          Learn how to use doxygen
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
    enum Menu{PLAY = 1, RULES = 2};
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
        cout<<"2. View the Rules"<<endl;
        cout<<"3. Exit the program"<<endl;
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
    }while(choice >= 1 && choice <= 2);
    
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
    bool firstTurn = true;
    float insBet;
    float bet;
    
    //Setup blackjack class
    Game blackjack;
    blackjack.setDeck(DECK_OF_CARDS, inFile, inName);
    blackjack.gambling.setFunds(funds);
    
    //Get user's bet
    cout<<"How much would you like to bet?"
        <<" (Current Funds: $"<<blackjack.gambling.getFunds()<<")"<<endl;
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
        blackjack.drawP2Card();
    }
    
    blackjack.gambling.setBet(bet);
    
    //Cheat 
    //(REMOVE IN FINAL VERSION)
/*
    blackjack.player1.setCardN(0,"Ace_Cheat1");
    blackjack.player1.setCardP(0,11);
    
    blackjack.player1.setCardN(1,"Ace_Cheat2");
    blackjack.player1.setCardP(1,11);
    
    blackjack.player1.setInitialTotal();
*/
    
/*
    blackjack.dealer.setCardN(0,"Ace_Cheat1");
    blackjack.dealer.setCardP(0,11);
    
    blackjack.dealer.setCardN(1,"10_Cheat2");
    blackjack.dealer.setCardP(1,10);
    
    blackjack.dealer.setInitialTotal();
*/
    //(REMOVE IN FINAL VERSION)
    
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
        
        cout<<endl;
    }
    
    //Check for splitting
    if (blackjack.player1.getCardP(0) == blackjack.player1.getCardP(1))
    {
        cout<<"Your first two cards are worth the same! Would you like to split?"<<endl
            <<"This will double your bet amount! (Y/N): ";
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

            blackjack.gambling.setBet(bet);
            split = true;
            cout<<endl;
        }
    }
    
    //Non-split game play
    if (!split)
    {
    
    //Ace rule check
    if (blackjack.player1.getTotal() > 21)
    {
        blackjack.player1.aceRule();
    }
    
    if (blackjack.player1.getCardP(0) == blackjack.player1.getCardP(1)){
        //Redisplay initial hand
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Dealer's Current Hand: ";
        blackjack.dealer.printFirst();
        cout<<"\nPlayer's Current Hand: ";
        blackjack.player1.printCards();
        cout<<"-------------------------------------------------------------"<<endl<<endl;
    }
    
    //Hit, stand, or double down
    while (blackjack.player1.getTotal() < 21 && choice != 'S' && choice != 's')
    {
        //Ace rule check
        if (blackjack.player1.getTotal() > 21)
        {
            blackjack.player1.aceRule();
        }
        
        //Hit or Stand
        if (firstTurn)
        {
            cout<<"Hit, Stand or Double Down (H/S/D): ";
            cin>>choice;
            while (choice != 'H' && choice != 'h' && choice != 'S' && 
                   choice != 's' && choice != 'D' && choice != 'd')
            {
                cout<<"Invalid choice, enter 'H' to hit, 'S' to stand, or 'D' to double down: ";
                cin>>choice;
            }
        }
        else
        {
            cout<<"Hit, Stand or Double Down (H/S/D): ";
            cin>>choice;
            while (choice != 'H' && choice != 'h' && 
                   choice != 'S' && choice != 's')
            {
                cout<<"Invalid choice, enter 'H' to hit or 'S' to stand: ";
                cin>>choice;
            }
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
        else if (choice == 'D' or choice == 'd')
        {
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
            bet *= 2;
            
            //Draw a card
            blackjack.drawP1Card();
            
            //Ace rule check
            if (blackjack.player1.getTotal() > 21)
            {
                blackjack.player1.aceRule();
            }
            
            break;
        }
        
        firstTurn = false;
    }
    
    //Dealer's Turn
    //Ace rule check
        if (blackjack.dealer.getTotal() > 21)
        {
            blackjack.dealer.aceRule();
        }
    
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
    //If player has blackjack
    if (blackjack.player1.getTotal() == 21 && blackjack.player1.getDrawn() == 2)
    {
        //Dealer also has blackjack, draw
        if (blackjack.dealer.getTotal() == 21 && blackjack.dealer.getDrawn() == 2)
        {
            cout<<"It's a draw!"<<endl;
            cout<<"You get back $"<<blackjack.gambling.getBet()<<endl;
            blackjack.gambling.payOut();
        }
        //Else player wins x2.5 bet
        else
        {
            cout<<"Blackjack! You win!"<<endl;
            cout<<"You won $"<<(blackjack.gambling.getBet() * 2.5)<<"!"<<endl;
            blackjack.gambling.payOut(bet,2.5);
        }
    }
    else if (blackjack.player1.getTotal() < 22)
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
        cout<<"You busted, better luck next time!"<<endl;
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
    }
    
    //Split game play
    else
    {
    //Split the hands
    blackjack.splitHands();
    
    //Ace rule check
    if (blackjack.player1.getTotal() > 21)
    {
        blackjack.player1.aceRule();
    }
    
    if (blackjack.player2.getTotal() > 21)
    {
        blackjack.player2.aceRule();
    }
    
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
        cout<<"First Hand Hit or Stand (H/S): ";
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
    
        cout<<"Second Hand Hit or Stand (H/S): ";
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
    //Ace rule check
        if (blackjack.dealer.getTotal() > 21)
        {
            blackjack.dealer.aceRule();
        }
    
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
    
    //Output final hand
    cout<<"\nFinal Results:"<<endl;
    blackjack.printSplitHands();
    
    //Check first hand winner
    cout<<"First Hand: ";
    //If player has blackjack
    if (blackjack.player1.getTotal() == 21 && blackjack.player1.getDrawn() == 2)
    {
        //Dealer also has blackjack, draw
        if (blackjack.dealer.getTotal() == 21 && blackjack.dealer.getDrawn() == 2)
        {
            cout<<"It's a draw!"<<endl;
            cout<<"First Hand: You get back $"<<blackjack.gambling.getBet()<<endl;
            blackjack.gambling.payOut();
        }
        //Else player wins x2.5 bet
        else
        {
            cout<<"Blackjack! You win!"<<endl;
            cout<<"First Hand: You won $"<<(blackjack.gambling.getBet() * 2.5)<<"!"<<endl;
            blackjack.gambling.payOut(bet,2.5);
        }
    }
    else if (blackjack.player1.getTotal() < 22)
            {
                if (blackjack.dealer.getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                    cout<<"First Hand: You won $"<<(blackjack.gambling.getBet() * 2)<<"!"<<endl;
                    blackjack.gambling.payOut(bet,2);
                }
                else if (blackjack.player1.getTotal() > blackjack.dealer.getTotal())
                {
                    cout<<"You win!"<<endl;
                    cout<<"First Hand: You won $"<<(blackjack.gambling.getBet() * 2)<<"!"<<endl;
                    blackjack.gambling.payOut(bet,2);
                }
                else if (blackjack.player1.getTotal() < blackjack.dealer.getTotal())
                {
                    cout<<"You lost, better luck next time!"<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                    cout<<"First Hand: You get back $"<<blackjack.gambling.getBet()<<endl;
                    blackjack.gambling.payOut();
                }
            }
    else
    {
        cout<<"You busted, better luck next time!"<<endl;
    }
    
    //Check second hand winner
    cout<<"Second Hand: ";
    //If player has blackjack
    if (blackjack.player2.getTotal() == 21 && blackjack.player2.getDrawn() == 2)
    {
        //Dealer also has blackjack, draw
        if (blackjack.dealer.getTotal() == 21 && blackjack.dealer.getDrawn() == 2)
        {
            cout<<"It's a draw!"<<endl;
            cout<<"Second Hand: You get back $"<<blackjack.gambling.getBet()<<endl;
            blackjack.gambling.payOut();
        }
        //Else player wins x2.5 bet
        else
        {
            cout<<"Blackjack! You win!"<<endl;
            cout<<"Second Hand: You won $"<<(blackjack.gambling.getBet() * 2.5)<<"!"<<endl;
            blackjack.gambling.payOut(bet,2.5);
        }
    }
    else if (blackjack.player2.getTotal() < 22)
            {
                if (blackjack.dealer.getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                    cout<<"Second Hand: You won $"<<(blackjack.gambling.getBet() * 2)<<"!"<<endl;
                    blackjack.gambling.payOut(bet,2);
                }
                else if (blackjack.player2.getTotal() > blackjack.dealer.getTotal())
                {
                    cout<<"You win!"<<endl;
                    cout<<"Second Hand: You won $"<<(blackjack.gambling.getBet() * 2)<<"!"<<endl;
                    blackjack.gambling.payOut(bet,2);
                }
                else if (blackjack.player2.getTotal() < blackjack.dealer.getTotal())
                {
                    cout<<"You lost, better luck next time!"<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                    cout<<"Second Hand: You get back $"<<blackjack.gambling.getBet()<<endl;
                    blackjack.gambling.payOut();
                }
            }
    else
    {
        cout<<"You busted, better luck next time!"<<endl;
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
}
    
    funds = blackjack.gambling.getFunds();
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
    cout<<"The goal is to get your card total as close to 21 as possible, "
        <<"without going over."<<endl;
    cout<<"The player and dealer are both given two cards to start."<<endl;
    cout<<"The dealer will only reveal their first card in the beginning."<<endl;
    cout<<"If the player has two cards of the same value, they can split."<<endl;
    cout<<"Splitting doubles the bet and allows the player to play two hands at once."<<endl;
    cout<<"The player can choose to 'hit' to receive an additional card, "
        <<"or 'stand' to keep their current hand."<<endl;
    cout<<"Additionally, on the first turn the player can 'double down'."<<endl;
    cout<<"Doubling down means the bet is doubled and one card is drawn, it ends the turn as well."<<endl;
    cout<<"Once the player's turn ends, the dealer will begin their turn."<<endl;
    cout<<"The dealer will draw cards until their total points is under 17."<<endl;
    cout<<"Aces are worth 11 points, but if the total is over 21 they become worth 1 point."<<endl;
    cout<<"If the player busts, the player automatically loses."<<endl;
    cout<<"If the dealer busts and the player doesn't, the player wins."<<endl;
    cout<<"The person with the higher score (while under 22) wins."<<endl;
    cout<<"A blackjack occurs when an Ace and 10 point card are drawn to start."<<endl;
    cout<<"Blackjacks cannot be beaten, it also pays 2.5 times the bet."<<endl;
    cout<<"If the dealer's first card is an ace, the player can buy insurance."<<endl;
    cout<<"If the dealer has blackjack, the insurance is paid out by 2."<<endl<<endl;
}