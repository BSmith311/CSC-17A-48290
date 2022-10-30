/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 25, 2022
 * Purpose: Project 1, Blackjack (v1)
 * Current: Basic Blackjack game, no major features yet
 * Future:  Check for errors, add requirements for checklist, etc
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Structures
struct Card{
    string cardN;
    int cardP;
};

struct Hand{
    Card *card;
    int total;
    int handSize;
};

//Function Prototypes
Hand *deal(int, const int);
void showHands (Hand *dealer,Hand *player,bool);
void playerTurn(Hand *dealer,Hand *player,const int,bool&,bool);
void dealerTurn(Hand *dealer,Hand *player,const int,bool&,bool);
void results(Hand *dealer,Hand *player,bool,bool,bool);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned>(time(0)));
    
    //Declare Variables
    const int DECK_OF_CARDS = 52;
    const int DEALER_CARDS  = 17;
    const int PLAYER_CARDS  = 21;
    bool pBust = false;     //Player bust
    bool dBust = false;     //Dealer bust
    bool hideDH = true;     //Hide dealers hand
    
    //Deal out the cards
    Hand *dealer = deal(DEALER_CARDS,DECK_OF_CARDS);
    Hand *player = deal(PLAYER_CARDS,DECK_OF_CARDS);
    
    //Player's Turn
    //Set initial hand info
    player->handSize = 2;
    player->total = player->card[0].cardP+player->card[1].cardP;
    
    cout<<"Player's Turn:"<<endl;
    
    //Call Player turn function
    playerTurn(dealer,player,PLAYER_CARDS,pBust,hideDH);
    
    //Dealer's Turn
    //Set initial hand info
    dealer->handSize = 2;
    dealer->total = dealer->card[0].cardP+dealer->card[1].cardP;
    hideDH = false;
    
    //If player did not bust
    if (!pBust)
    {
       cout<<"Dealer's Turn:"<<endl;
    
        //Call Dealer turn function
        dealerTurn(dealer,player,DEALER_CARDS,dBust,hideDH); 
    }
    
    //Output Game Results
    results(dealer,player,pBust,dBust,hideDH);
    
    
    //Close Files
    
    
    //Cleanup
    delete dealer;
    delete player;
    
    
    //Exit Program
        return 0;
}

//Functions
Hand *deal(int size, const int DECK_OF_CARDS)
{
    //Open Files
    ifstream inFile;
    string inName;
    inName = "deckOfCards.dat";
    inFile.open(inName);
    if(!inFile){
        cout<<"Error opening input file."<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Dynamically create the structure
    Hand *cards = new Hand;
    cards->card = new Card[size];
    
    //Deal the cards using RNG
    string cardIn;
    for (int i=0; i<size; i++)
    {
        cards->card[i].cardP = (rand()%DECK_OF_CARDS+1);
    }
    
    //Assign the name of the card
    for (int i=1; i<=DECK_OF_CARDS; i++)
    {
        //Input current card
        inFile>>cardIn;
        
        //Check hand for current card
        for (int j=0; j<size; j++)
        {
            if (i == cards->card[j].cardP)
            {
                cards->card[j].cardN = cardIn;
            }
        }
    }
    
    //Assign the point value of the card
    for (int i=0; i<size; i++)
    {
        if (cards->card[i].cardP >= 1  && cards->card[i].cardP <= 4) cards->card[i].cardP=11;
        else if (cards->card[i].cardP >= 5  && cards->card[i].cardP <= 8) cards->card[i].cardP=2;
        else if (cards->card[i].cardP >= 9  && cards->card[i].cardP <= 12)cards->card[i].cardP=3;
        else if (cards->card[i].cardP >= 13 && cards->card[i].cardP <= 16)cards->card[i].cardP=4;
        else if (cards->card[i].cardP >= 17 && cards->card[i].cardP <= 20)cards->card[i].cardP=5;
        else if (cards->card[i].cardP >= 21 && cards->card[i].cardP <= 24)cards->card[i].cardP=6;
        else if (cards->card[i].cardP >= 25 && cards->card[i].cardP <= 28)cards->card[i].cardP=7;
        else if (cards->card[i].cardP >= 29 && cards->card[i].cardP <= 32)cards->card[i].cardP=8;
        else if (cards->card[i].cardP >= 33 && cards->card[i].cardP <= 36)cards->card[i].cardP=9;
        else if (cards->card[i].cardP >= 37 && cards->card[i].cardP <= 52)cards->card[i].cardP=10;
    }
    
    //Cleanup
    inFile.close();
    
    return cards;
}

void showHands (Hand *dealer, Hand *player, bool hide)
{
    cout<<"-------------------------------------------------------------"<<endl;
    if (hide)
    {
        //Output hidden dealer hand
        cout<<"Dealer's Current Hand: "<<dealer->card[0].cardP<<" + ?"<<endl;
        cout<<left<<setw(13)<<dealer->card[0].cardN<<left<<setw(13)<<" ?"<<endl<<endl;
    }
    else
    {
        //Output dealer's hand
        cout<<"Dealer's Current Hand: "<<dealer->total<<endl;
        cout<<left<<setw(13)<<dealer->card[0].cardN
            <<left<<setw(13)<<dealer->card[1].cardN;
        for (int i=2; i<dealer->handSize; i++)
        {
            if (i==5 or i==9 or i==13 or i==17 or i==21)    //Spacing
            {
                cout<<endl;
            }
            cout<<left<<setw(13)<<dealer->card[i].cardN;
        }
        cout<<endl<<endl;
    }
    
    //Output player's hand
    cout<<"Player's Current Hand: "<<player->total<<endl;
    cout<<left<<setw(13)<<player->card[0].cardN
        <<left<<setw(13)<<player->card[1].cardN;
    for (int i=2; i<player->handSize; i++)
    {
        if (i==5 or i==9 or i==13 or i==17 or i==21)    //Spacing
        {
            cout<<endl;
        }
        cout<<left<<setw(13)<<player->card[i].cardN;
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------"<<endl<<endl;
}

void playerTurn(Hand *dealer, Hand *player, const int size, bool& bust, bool hide)
{
    //Declare Variables
    char choice;
    
    //Hit or Stand?
    do
    {
        //Output current hands
        showHands(dealer,player,hide);
        
        if (player->total < 21)
        {
            cout<<"Would you like to hit or stand? Enter 'H' or 'S': ";
            cin>>choice;
            if (choice == 'H' or choice == 'h')
            {
                player->total += player->card[player->handSize].cardP;
                player->handSize++;
            }
            else cout<<endl;
            
            //Output hand if player hits 21
            if (player->total == 21)showHands(dealer,player,hide);
        }
        
        //Set ace value to 1 if player busts
        if (player->total > 21)
        {
            for (int i=0; i<size; i++)
            {
                if (player->card[i].cardP == 11)player->card[i].cardP=1;
            }
            
            //Recalculate player total
            player->total = 0;
            for (int j=0; j<player->handSize; j++)
            {
                player->total += player->card[j].cardP;
            }
        }
        
        //If player busts end turn and set bust to true
        if (player->total > 21)
        {
            showHands(dealer,player,hide);
            bust=true;
        }
    }while(player->total < 21 && (choice == 'H' or choice == 'h')); //Make sure this works right
}

void dealerTurn(Hand *dealer, Hand *player, const int size, bool& bust, bool hide)
{
    //Output current hands
    showHands(dealer,player,hide);
    
    while (dealer->total < 17)
    {
        dealer->total += dealer->card[dealer->handSize].cardP;
        dealer->handSize++;
        showHands(dealer,player,hide);
        
        //Set ace value to 1 if dealer busts
        if (dealer->total > 21)
        {
            for (int i=0; i<size; i++)
            {
                if (dealer->card[i].cardP == 11)dealer->card[i].cardP=1;
            }
            
            //Recalculate dealer total
            dealer->total = 0;
            for (int j=0; j<dealer->handSize; j++)
            {
                dealer->total += dealer->card[j].cardP;
            }
        }
    }
    //If dealer busts end turn and set bust to true
        if (dealer->total > 21)
        {
            showHands(dealer,player,hide);
            bust=true;
        }
}

void results(Hand *dealer,Hand *player,bool pBust, bool dBust, bool hide)
{
    cout<<"*************************************************************"<<endl;
    cout<<"                        Final Results                        "<<endl;
    showHands(dealer,player,hide);
    
    if (pBust)
    {
        cout<<"You busted! Better luck next time!"<<endl;
    }
    else
    {
        if (dBust)
        {
            cout<<"Dealer busts! You win!"<<endl;
        }
        else
        {
            if (player->total > dealer->total)
            {
                cout<<"You win! Congratulations!"<<endl;
            }
            else if (player->total < dealer->total)
            {
                cout<<"You lost, better luck next time!"<<endl;
            }
            else
            {
                cout<<"It's a draw!"<<endl;
            }
        }
    }
    cout<<"*************************************************************"<<endl;
}