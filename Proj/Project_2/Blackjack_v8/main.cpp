/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on December 7, 2022
 * Purpose: Project 2, Blackjack (v8)
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
#include "Gamble.h"
#include "Stats.h"

//Function Prototypes
void playBlackjack(const int, ifstream&, string, float&, int&);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int DECK_OF_CARDS = 52;
    float funds;           //Total funds to gamble with
    float startF;          //Starting funds
    int gPlay    = 0;      //Number of games played
    char choice;
    
    //Deck of cards file
    ifstream inFile;
    string inName = "deckOfCards.dat";
    
    //Intro message
    cout<<"Welcome to Blackjack!"<<endl;
    cout<<"How much money are you willing to gamble? $";
    cin>>funds;
    while (funds < 0)
    {
        cout<<"Invalid input, must be positive: ";
        cin>>funds;
    }
    cout<<endl;
    startF = funds;
    
    //Program Menu
    do{
        //Play a game of blackjack
        playBlackjack(DECK_OF_CARDS, inFile, inName, funds, gPlay);
        
        //Ask for repeat play
        cout<<"Do you want to play again? (Y/N)"<<endl;
        cin>>choice;
        //Input validation
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            cout<<"Invalid input, enter 'Y' for yes or 'N' for no: ";
            cin>>choice;
        }
        cout<<endl;
    }while(choice == 'y' or choice == 'Y');
    
    //Output Stats
    cout<<"\nGames Played: "<<gPlay<<endl;
    cout<<winnings(startF,funds)<<endl;
    
    //Exit Program
        return 0;
}

//Functions
//Plays a game of blackjack
void playBlackjack(const int DECK_OF_CARDS, ifstream& inFile, string inName, 
                   float &funds, int &gPlay)
{
    //Declare variables
    bool split = false;
    char splitChoice;
    bool insurance = false;
    bool firstTurn = true;
    float insBet;
    float bet;
    
    //Setup blackjack and gambling classes
    Game blackjack;
    blackjack.setDeck(DECK_OF_CARDS, inFile, inName);
    Gamble gambling(funds);
    
    //Get user's bet
    cout<<"How much would you like to bet?"
        <<" (Current Funds: $"<<gambling.getFunds()<<")"<<endl;
    cout<<"Bet: $";
    cin>>bet;
    
    try
    {
        gambling.BadBet(bet);
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
    
    gambling.setBet(bet);
    
    //Player Turn
    char choice;
    char choice2;
    cout<<endl<<"Player's Turn:"<<endl;
    
    //Display initial hand
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    blackjack.hands[2].printFirst();
    cout<<"\nPlayer's Current Hand: ";
    blackjack.hands[0].printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
    
    //Check for insurance
    if (blackjack.hands[2].getCardP(0) == 11){
        cout<<"The dealer's first card is an Ace, how much is your insurance bet?"<<endl;
        cout<<"(You can bet $0 if you want no insurance)"<<endl;
        cout<<"Insurance bet: $";
        cin>>insBet;
        
        //Check for bad insurance bet
        try
        {
            gambling.BadBet(insBet);
        }
        catch (string exceptionString)
        {
            cout<<exceptionString<<endl;
            exit(EXIT_SUCCESS);
        }
        
        if (insBet > 0)
        {
            insurance = true;
            gambling.setInsurance(insBet);
        }
        
        cout<<endl;
    }
    
    //Check for splitting
    if (blackjack.hands[0].getCardP(0) == blackjack.hands[0].getCardP(1))
    {
        cout<<"Your first two cards are worth the same! Would you like to split?"<<endl
            <<"This will double your bet amount! (Y/N): ";
        cin>>splitChoice;
        while (splitChoice != 'Y' && splitChoice != 'y' && 
               splitChoice != 'N' && splitChoice != 'n')
        {
            cout<<"Invalid choice, enter 'Y' to split or 'N' to keep your current hand: ";
            cin>>splitChoice;
        }
        
        if (splitChoice == 'Y' or splitChoice == 'y')
        {
            //Check if player can afford to split
            try
            {
                gambling.BadBet(bet);
            }
            catch (string exceptionString)
            {
                cout<<exceptionString<<endl;
                exit(EXIT_SUCCESS);
            }

            gambling.setBet(bet);
            split = true;
            cout<<endl;
        }
    }
    
    //Non-split game play
    if (!split)
    {
    
    //Ace rule check
    if (blackjack.hands[0].getTotal() > 21)
    {
        blackjack.hands[0].aceRule();
    }
    
    if (blackjack.hands[0].getCardP(0) == blackjack.hands[0].getCardP(1)){
        //Redisplay initial hand
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Dealer's Current Hand: ";
        blackjack.hands[2].printFirst();
        cout<<"\nPlayer's Current Hand: ";
        blackjack.hands[0].printCards();
        cout<<"-------------------------------------------------------------"<<endl<<endl;
    }
    
    //Hit, stand, or double down
    while (blackjack.hands[0].getTotal() < 21 && choice != 'S' && choice != 's')
    {
        //Ace rule check
        if (blackjack.hands[0].getTotal() > 21)
        {
            blackjack.hands[0].aceRule();
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
            firstTurn = false;
        }
        else
        {
            cout<<"Hit or Stand (H/S): ";
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
            if (blackjack.hands[0].getTotal() > 21)
            {
                blackjack.hands[0].aceRule();
            }
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.hands[2].printFirst();
            cout<<"\nPlayer's Current Hand: ";
            blackjack.hands[0].printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
        else if (choice == 'D' or choice == 'd')
        {
            try
            {
                gambling.BadBet(bet);
            }
            catch (string exceptionString)
            {
                cout<<exceptionString<<endl;
                exit(EXIT_SUCCESS);
            }
            gambling.doubleBet();
            bet *= 2;
            
            //Draw a card
            blackjack.drawP1Card();
            
            //Ace rule check
            if (blackjack.hands[0].getTotal() > 21)
            {
                blackjack.hands[0].aceRule();
            }
            
            break;
        }
    }
    
    //Dealer's Turn
    //Ace rule check
    if (blackjack.hands[2].getTotal() > 21)
    {
        blackjack.hands[2].aceRule();
    }
    
    if (blackjack.hands[0].getTotal() < 22)
    {
        //Ace rule check
        if (blackjack.hands[2].getTotal() > 21)
        {
            blackjack.hands[2].aceRule();
        }
        
        cout<<"\nDealer's Turn:"<<endl;
        blackjack.printCards();
        
        //Loop while dealer is under 17
        while (blackjack.hands[2].getTotal() < 17)
        {
            //Draw a card
            blackjack.drawDCard();
            
            //Ace rule check
            if (blackjack.hands[2].getTotal() > 21) blackjack.hands[2].aceRule();
            
            //Print new hand
            blackjack.printCards();
        }
    }
    
    //Output final hand
    cout<<"\nFinal Results:"<<endl;
    blackjack.printCards();
    
    //Check winner
    //If player has blackjack
    if (blackjack.hands[0].getTotal() == 21 && blackjack.hands[0].getDrawn() == 2)
    {
        //Dealer also has blackjack, draw
        if (blackjack.hands[2].getTotal() == 21 && blackjack.hands[2].getDrawn() == 2)
        {
            cout<<"It's a draw!"<<endl;
            cout<<"You get back $"<<gambling.getBet()<<endl;
            gambling.payOut();
        }
        //Else player wins x2.5 bet
        else
        {
            cout<<"Blackjack! You win!"<<endl;
            cout<<"You won $"<<(gambling.getBet() * 2.5)<<"!"<<endl;
            gambling.payOut(bet,2.5);
        }
    }
    else if (blackjack.hands[0].getTotal() < 22)
            {
                if (blackjack.hands[2].getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                    cout<<"You won $"<<(gambling.getBet() * 2)<<"!"<<endl;
                    gambling.payOut(bet,2);
                }
                else if (blackjack.hands[0].getTotal() > blackjack.hands[2].getTotal())
                {
                    cout<<"You win!"<<endl;
                    cout<<"You won $"<<(gambling.getBet() * 2)<<"!"<<endl;
                    gambling.payOut(bet,2);
                }
                else if (blackjack.hands[0].getTotal() < blackjack.hands[2].getTotal())
                {
                    cout<<"You lost, better luck next time!"<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                    cout<<"You get back $"<<gambling.getBet()<<endl;
                    gambling.payOut();
                }
            }
    else
    {
        cout<<"You busted, better luck next time!"<<endl;
    }
    
    //Check insurance
    if (insurance)
    {
        if (blackjack.hands[2].getTotal() == 21 && blackjack.hands[2].getDrawn() == 2)
        {
            cout<<"The dealer had blackjack, your insurance paid $"
                <<(gambling.getInsurance() * 2)<<"!"<<endl;
            gambling.payOut(insBet);
        }
        else
        {
            cout<<"The dealer did not have blackjack, your insurance is lost."<<endl;
        }
    }
    
    if (blackjack.hands[0].getTotal() < 21)
    {
        //Show next card
        blackjack.drawP1Card();
        blackjack.pushFunction(blackjack.hands[0].getCardN(blackjack.hands[0].getDrawn()-1));

        cout<<"Your next card would have been ";
        cout<<blackjack.getNextCard(0)<<endl;

        //Call pop function
        blackjack.popFunction();
    }
    else if (blackjack.hands[0].getTotal() > 21 && blackjack.hands[2].getTotal() < 17)
    {
        //Show next card
        blackjack.drawDCard();
        blackjack.pushFunction(blackjack.hands[2].getCardN(blackjack.hands[2].getDrawn()-1));

        cout<<"The dealer's next card would have been ";
        cout<<blackjack.getNextCard(0)<<endl;

        //Call pop function
        blackjack.popFunction();
    }
    }
    
    //Split game play
    else
    {
    //Split the hands
    blackjack.splitHands();
    
    //Ace rule check
    if (blackjack.hands[0].getTotal() > 21)
    {
        blackjack.hands[0].aceRule();
    }
    
    if (blackjack.hands[1].getTotal() > 21)
    {
        blackjack.hands[1].aceRule();
    }
    
    //Display initial hands
    cout<<"Initial Hands: "<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    blackjack.hands[2].printFirst();
    cout<<"\nPlayer's First Hand: ";
    blackjack.hands[0].printCards();
    cout<<"\nPlayer's Second Hand: ";
    blackjack.hands[1].printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
    
    //First Hand
    while (blackjack.hands[0].getTotal() < 21 && choice != 'S' && choice != 's')
    {
        //Ace rule check
        if (blackjack.hands[0].getTotal() > 21)
        {
            blackjack.hands[0].aceRule();
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
            if (blackjack.hands[0].getTotal() > 21)
            {
                blackjack.hands[0].aceRule();
            }
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.hands[2].printFirst();
            cout<<"\nPlayer's First Hand: ";
            blackjack.hands[0].printCards();
            cout<<"\nPlayer's Second Hand: ";
            blackjack.hands[1].printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
    }
    
    //Second Hand
    while (blackjack.hands[1].getTotal() < 21 && choice2 != 'S' && choice2 != 's')
    {
        //Ace rule check
        if (blackjack.hands[1].getTotal() > 21)
        {
            blackjack.hands[1].aceRule();
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
            if (blackjack.hands[1].getTotal() > 21)
            {
                blackjack.hands[1].aceRule();
            }
            
            //Print new hand
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"Dealer's Current Hand: ";
            blackjack.hands[2].printFirst();
            cout<<"\nPlayer's First Hand: ";
            blackjack.hands[0].printCards();
            cout<<"\nPlayer's Second Hand: ";
            blackjack.hands[1].printCards();
            cout<<"-------------------------------------------------------------"<<endl<<endl;
        }
    }
    
    //Dealer's Turn
    //Ace rule check
    if (blackjack.hands[2].getTotal() > 21)
    {
        blackjack.hands[2].aceRule();
    }
    
    if (blackjack.hands[0].getTotal() < 22 or blackjack.hands[1].getTotal() < 22)
    {
        //Ace rule check
        if (blackjack.hands[2].getTotal() > 21)
        {
            blackjack.hands[2].aceRule();
        }
        
        cout<<"\nDealer's Turn:"<<endl;
        blackjack.printSplitCards();
        
        //Loop while dealer is under 17
        while (blackjack.hands[2].getTotal() < 17)
        {
            //Draw a card
            blackjack.drawDCard();
            
            //Ace rule check
            if (blackjack.hands[2].getTotal() > 21) blackjack.hands[2].aceRule();
            
            //Print new hand
            blackjack.printSplitCards();
        }
    }
    
    //Output final hand
    cout<<"\nFinal Results:"<<endl;
    blackjack.printSplitCards();
    
    //Check first hand winner
    cout<<"First Hand: ";
    //If player has blackjack
    if (blackjack.hands[0].getTotal() == 21 && blackjack.hands[0].getDrawn() == 2)
    {
        //Dealer also has blackjack, draw
        if (blackjack.hands[2].getTotal() == 21 && blackjack.hands[2].getDrawn() == 2)
        {
            cout<<"It's a draw!"<<endl;
            cout<<"First Hand: You get back $"<<gambling.getBet()<<endl;
            gambling.payOut();
        }
        //Else player wins x2.5 bet
        else
        {
            cout<<"Blackjack! You win!"<<endl;
            cout<<"First Hand: You won $"<<(gambling.getBet() * 2.5)<<"!"<<endl;
            gambling.payOut(bet,2.5);
        }
    }
    else if (blackjack.hands[0].getTotal() < 22)
            {
                if (blackjack.hands[2].getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                    cout<<"First Hand: You won $"<<(gambling.getBet() * 2)<<"!"<<endl;
                    gambling.payOut(bet,2);
                }
                else if (blackjack.hands[0].getTotal() > blackjack.hands[2].getTotal())
                {
                    cout<<"You win!"<<endl;
                    cout<<"First Hand: You won $"<<(gambling.getBet() * 2)<<"!"<<endl;
                    gambling.payOut(bet,2);
                }
                else if (blackjack.hands[0].getTotal() < blackjack.hands[2].getTotal())
                {
                    cout<<"You lost, better luck next time!"<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                    cout<<"First Hand: You get back $"<<gambling.getBet()<<endl;
                    gambling.payOut();
                }
            }
    else
    {
        cout<<"You busted, better luck next time!"<<endl;
    }
    
    //Check second hand winner
    cout<<"Second Hand: ";
    //If player has blackjack
    if (blackjack.hands[1].getTotal() == 21 && blackjack.hands[1].getDrawn() == 2)
    {
        //Dealer also has blackjack, draw
        if (blackjack.hands[2].getTotal() == 21 && blackjack.hands[2].getDrawn() == 2)
        {
            cout<<"It's a draw!"<<endl;
            cout<<"Second Hand: You get back $"<<gambling.getBet()<<endl;
            gambling.payOut();
        }
        //Else player wins x2.5 bet
        else
        {
            cout<<"Blackjack! You win!"<<endl;
            cout<<"Second Hand: You won $"<<(gambling.getBet() * 2.5)<<"!"<<endl;
            gambling.payOut(bet,2.5);
        }
    }
    else if (blackjack.hands[1].getTotal() < 22)
            {
                if (blackjack.hands[2].getTotal() > 21)
                {
                    cout<<"Dealer busts, you win!"<<endl;
                    cout<<"Second Hand: You won $"<<(gambling.getBet() * 2)<<"!"<<endl;
                    gambling.payOut(bet,2);
                }
                else if (blackjack.hands[1].getTotal() > blackjack.hands[2].getTotal())
                {
                    cout<<"You win!"<<endl;
                    cout<<"Second Hand: You won $"<<(gambling.getBet() * 2)<<"!"<<endl;
                    gambling.payOut(bet,2);
                }
                else if (blackjack.hands[1].getTotal() < blackjack.hands[2].getTotal())
                {
                    cout<<"You lost, better luck next time!"<<endl;
                }
                else
                {
                    cout<<"It's a draw!"<<endl;
                    cout<<"Second Hand: You get back $"<<gambling.getBet()<<endl;
                    gambling.payOut();
                }
            }
    else
    {
        cout<<"You busted, better luck next time!"<<endl;
    }
    
    //Check insurance
    if (insurance)
    {
        if (blackjack.hands[2].getTotal() == 21 && blackjack.hands[2].getDrawn() == 2)
        {
            cout<<"The dealer had blackjack, your insurance paid $"
                <<(gambling.getInsurance() * 2)<<"!"<<endl;
            gambling.payOut(insBet);
        }
        else
        {
            cout<<"The dealer did not have blackjack, your insurance is lost."<<endl;
        }
    }
    
    if (blackjack.hands[0].getTotal() < 21)
    {
        //Show next card
        blackjack.drawP1Card();
        blackjack.pushFunction(blackjack.hands[0].getCardN(blackjack.hands[0].getDrawn()-1));

        cout<<"Your first hand's card would have been ";
        cout<<blackjack.getNextCard(0)<<endl;

        //Call pop function
        blackjack.popFunction();
        
    }
    if (blackjack.hands[1].getTotal() < 21)
    {
        //Show next card
        blackjack.drawP2Card();
        blackjack.pushFunction(blackjack.hands[1].getCardN(blackjack.hands[1].getDrawn()-1));
        
        cout<<"Your second hand's next card would have been ";
        cout<<blackjack.getNextCard(0)<<endl;
    
        //Call pop function
        blackjack.popFunction();
        
    }
    if (blackjack.hands[2].getTotal() < 17)
    {
        //Show next card
        blackjack.drawDCard();
        blackjack.pushFunction(blackjack.hands[2].getCardN(blackjack.hands[2].getDrawn()-1));

        cout<<"The dealer's next card would have been ";
        cout<<blackjack.getNextCard(0)<<endl;

        //Call pop function
        blackjack.popFunction();
    }
    }

    //Save results
    gPlay++;
    funds = gambling.getFunds();
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
    tempP = hands[1].getCardP(0);
    tempN = hands[1].getCardN(0);
    
    //Copy the second card from first hand to first card of second hand
    hands[1].setCardP(0,hands[0].getCardP(1));
    hands[1].setCardN(0,hands[0].getCardN(1));
    
    //Copy the temp card info to the second card of first hand
    hands[0].setCardP(1,tempP);
    hands[0].setCardN(1,tempN);
    
    //Reset Totals
    hands[0].setInitialTotal();
    hands[1].setInitialTotal();
}

//Prints the hands for the player's first hand and dealer's hand
void Game::printCards()
{
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    hands[2].printCards();
    cout<<"\nPlayer's Current Hand: ";
    hands[0].printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
}

//Prints the hands for the player's first and second hand and dealer's hand
void Game::printSplitCards()
{
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Dealer's Current Hand: ";
    hands[2].printCards();
    cout<<"\nPlayer's First Hand: ";
    hands[0].printCards();
    cout<<"\nPlayer's Second Hand: ";
    hands[1].printCards();
    cout<<"-------------------------------------------------------------"<<endl<<endl;
}