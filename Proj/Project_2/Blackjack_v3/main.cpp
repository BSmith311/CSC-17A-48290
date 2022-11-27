/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on November 27, 2022
 * Purpose: Project 2, Blackjack (v3)
 * Current: Imported and altered for Project 2, minimal functionality
 *          Replaced structures with classes (using headers)
 *          Overall formatting adjustments
 * Future:  Add inheritance, operator overloading, polymorphism, and templates
 *          Learn how to use doxygen
 *          Add several blackjack features, betting, splitting, insurance, etc.
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
#include "Hand.h"

//Function Prototypes
//void blackjack(const Hand&);
//void blackjack(int&,int&,int&,int&,char[],ifstream&,string);
//void stats(int,int,int,int);
void rules();
//Hand *deal(int, const int,ifstream&,string);
//void showHands (Hand *dealer,Hand *player,bool,char[]);
//void playerTurn(Hand *dealer,Hand *player,const int,bool&,bool,int&,char[]);
//void dealerTurn(Hand *dealer,Hand *player,const int,bool&,bool,int&,char[]);
//void results(Hand *dealer,Hand *player,bool,bool,bool,int&,char[]);

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
    
    //Open Files
    fstream statsFile;
    string fileName = "blackjack_stats.bin";
    ifstream inFile;
    string inName = "deckOfCards.dat";

    statsFile.open(fileName, ios::in | ios::out | ios::binary);
    
    //Create file if it doesn't exist
    if (!statsFile){
        gWon=gPlay=pDraw=dDraw=0;
        cout<<"Error opening "<<fileName<<endl;
        cout<<"Creating the file now."<<endl;
        statsFile.open(fileName, ios::out | ios::binary);
        statsFile.write(reinterpret_cast<char *>(&gWon), sizeof(int));
        statsFile.write(reinterpret_cast<char *>(&gPlay), sizeof(int));
        statsFile.write(reinterpret_cast<char *>(&pDraw), sizeof(int));
        statsFile.write(reinterpret_cast<char *>(&dDraw), sizeof(int));
        cout<<"The file is now created. Please rerun the program"<<endl;
        return 0;
    }
    
    //Read file
    statsFile.read(reinterpret_cast<char *>(&gWon), sizeof(int));
    statsFile.read(reinterpret_cast<char *>(&gPlay), sizeof(int));
    statsFile.read(reinterpret_cast<char *>(&pDraw), sizeof(int));
    statsFile.read(reinterpret_cast<char *>(&dDraw), sizeof(int));
    
/*
    //Print Hands
    cout<<"Player Hand 1:"<<endl;
    player1.printHand();
    
    cout<<endl<<"Player Hand 2:"<<endl;
    player2.printHand();
    
    cout<<endl<<"Dealer Hand:"<<endl;
    dealer.printHand();
*/
    
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
                //Define the instances of the hand class
                Hand player1;
                Hand player2;
                Hand dealer;
                
                //Fill the hand classes
                player1.setHand(DECK_OF_CARDS,inFile,inName);
                player2.setHand(DECK_OF_CARDS,inFile,inName);
                dealer.setHand(DECK_OF_CARDS,inFile,inName);
                
                //Output Initial Hands
                cout<<"Initial Hands:"<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<"Dealer's Current Hand: ";
                dealer.printHand();
                cout<<"Player's Current Hand: ";
                player1.printHand();
                cout<<"-------------------------------------------------------------"<<endl<<endl;
                
                break;
            }
            case STATS:
            {
                //stats(gWon,gPlay,pDraw,dDraw);
                break;
            }
            case RULES:
            {
                rules();
                break;
            }
            default: 
            {
                ptr = &gPlay;
                //cout<<"A total of "<<*ptr<<" games of Blackjack have been played!"<<endl;
                cout<<"Quitting Blackjack"<<endl;
            }
        }
    }while(choice >= 1 && choice <= 3);
    
    //Output Stats
    statsFile.seekg(0L, ios::beg);
    statsFile.write(reinterpret_cast<char *>(&gWon), sizeof(int));
    statsFile.write(reinterpret_cast<char *>(&gPlay), sizeof(int));
    statsFile.write(reinterpret_cast<char *>(&pDraw), sizeof(int));
    statsFile.write(reinterpret_cast<char *>(&dDraw), sizeof(int));
    
    //Close Files
    statsFile.close();
    
    //Exit Program
        return 0;
}

//Functions
void Hand::setHand(const int DECK_OF_CARDS, ifstream &inFile, string inName)
{
    //Open File
    inFile.open(inName);
    if(!inFile)
    {
        cout<<"Error opening input file for the deck of cards."<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Deal the cards using rand
    string cardIn;
    for (int i = 0; i < size; i++)
    {
        cardP[i] = (rand()%DECK_OF_CARDS+1);
    }
    
    //Assign the name of the card
    for (int i = 1; i <= DECK_OF_CARDS; i++)
    {
        //Input current card
        inFile>>cardIn;
        
        //Check hand for current card
        for (int j = 0; j < size; j++)
        {
            if (i == cardP[j])
            {
                cardN[j] = cardIn;
            }
        }
    }
    
    //Assign the point value of the card
    for (int i=0; i<size; i++){
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
    inFile.close();
}

void Hand::printHand()
{
    //Calculate total
    cardTotal = cardP[0] + cardP[1];
    
    //Output Total and Card Names
    cout<<cardTotal<<endl;
    cout<<left<<setw(13)<<cardN[0]
        <<left<<setw(13)<<cardN[1]<<endl;
}

/*
void blackjack(const Hand &hand)
{
    cout<<hand.getTotal();
}
*/

/*
void blackjack(int &gWon, int &gPlay, int &pDraw, int &dDraw, char name[], ifstream &inFile, string inName){
    //Declare Variables
    const int DECK_OF_CARDS = 52;
    const int DEALER_CARDS  = 17;
    const int PLAYER_CARDS  = 21;
    bool pBust = false;     //Player bust
    bool dBust = false;     //Dealer bust
    bool hideDH = true;     //Hide dealers hand
    int count=0;
    
    //Increment counters
    gPlay++;
    pDraw+=2;
    dDraw+=2;
    
    //Deal out the cards
    Hand *dealer = deal(DEALER_CARDS,DECK_OF_CARDS,inFile,inName);
    Hand *player = deal(PLAYER_CARDS,DECK_OF_CARDS,inFile,inName);
    
    //Player's Turn
    //Set initial hand info
    player->handSize = 2;
    player->total = player->card[0].cardP+player->card[1].cardP;
    
    while (name[count] != '\0'){
        cout<<name[count];
        count++;
    }
    cout<<"'s Turn:"<<endl;
    
    //Call Player turn function
    playerTurn(dealer,player,PLAYER_CARDS,pBust,hideDH,pDraw,name);
    
    //Dealer's Turn
    //Set initial hand info
    dealer->handSize = 2;
    dealer->total = dealer->card[0].cardP+dealer->card[1].cardP;
    hideDH = false;
    
    //If player did not bust
    if (!pBust){
       cout<<"Dealer's Turn:"<<endl;
    
        //Call Dealer turn function
        dealerTurn(dealer,player,DEALER_CARDS,dBust,hideDH,dDraw,name); 
    }
    
    //Output Game Results
    results(dealer,player,pBust,dBust,hideDH,gWon,name);
    
    //Cleanup
    delete dealer;
    delete player;
}
*/

void rules(){
    char pause;
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
    cout<<"If your score is higher than the dealer, you win. If lower, you lose. If the same, it's a draw."<<endl;
    cout<<"Any input will return you to the menu:";
    cin>>pause;
    cout<<endl;
}

/*
void stats(int gWon, int gPlay, int pDraw, int dDraw){
    cout<<"Global Game Stats:"<<endl;
    cout<<"Total games played: "<<gPlay<<endl;
    cout<<"Total games won: "<<gWon<<endl;
    cout<<"Total cards drawn: "<<(pDraw+dDraw)<<endl;
    cout<<"Cards drawn by the Player: "<<pDraw<<endl;
    cout<<"Cards drawn by the Dealer: "<<dDraw<<endl<<endl;
}
*/

/*
Hand *deal(int size, const int DECK_OF_CARDS, ifstream &inFile, string inName){
    //Open File
    inFile.open(inName);
    if(!inFile){
        cout<<"Error opening input file for the deck of cards."<<endl;
        exit(EXIT_FAILURE);
    }
    
    //Dynamically create the structure
    Hand *cards = new Hand;
    cards->card = new Card[size];
    
    //Deal the cards using RNG
    string cardIn;
    for (int i=0; i<size; i++){
        cards->card[i].cardP = (rand()%DECK_OF_CARDS+1);
    }
    
    //Assign the name of the card
    for (int i=1; i<=DECK_OF_CARDS; i++){
        //Input current card
        inFile>>cardIn;
        
        //Check hand for current card
        for (int j=0; j<size; j++){
            if (i == cards->card[j].cardP){
                cards->card[j].cardN = cardIn;
            }
        }
    }
    
    //Assign the point value of the card
    for (int i=0; i<size; i++){
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
*/

/*
void showHands (Hand *dealer, Hand *player, bool hide, char name[]){
    //Declare variable
    int count=0;
    
    cout<<"-------------------------------------------------------------"<<endl;
    if (hide){
        //Output hidden dealer hand
        cout<<"Dealer's Current Hand: "<<dealer->card[0].cardP<<" + ?"<<endl;
        cout<<left<<setw(13)<<dealer->card[0].cardN<<left<<setw(13)<<" ?"<<endl<<endl;
    }else{
        //Output dealer's hand
        cout<<"Dealer's Current Hand: "<<dealer->total<<endl;
        cout<<left<<setw(13)<<dealer->card[0].cardN
            <<left<<setw(13)<<dealer->card[1].cardN;
        for (int i=2; i<dealer->handSize; i++){
            if (i==5 or i==9 or i==13 or i==17 or i==21){    //Spacing
                cout<<endl;
            }
            cout<<left<<setw(13)<<dealer->card[i].cardN;
        }
        cout<<endl<<endl;
    }
    
    //Output player's hand
    while (name[count] != '\0'){
        cout<<name[count];
        count++;
    }
    cout<<"'s Current Hand: "<<player->total<<endl;
    cout<<left<<setw(13)<<player->card[0].cardN
        <<left<<setw(13)<<player->card[1].cardN;
    for (int i=2; i<player->handSize; i++){
        if (i==5 or i==9 or i==13 or i==17 or i==21){    //Spacing
            cout<<endl;
        }
        cout<<left<<setw(13)<<player->card[i].cardN;
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------"<<endl<<endl;
}
*/

/*
void playerTurn(Hand *dealer, Hand *player, const int size, bool& bust, bool hide, int& pDraw, char name[]){
    //Declare Variable
    char choice;
    
    //Hit or Stand?
    do{
        //Output current hands
        showHands(dealer,player,hide,name);
        
        if (player->total < 21){
            cout<<"Would you like to hit or stand? Enter 'H' or 'S': ";
            cin>>choice;
            if (choice == 'H' or choice == 'h'){
                player->total += player->card[player->handSize].cardP;
                player->handSize++;
                pDraw++;
            }
            
            //Output hand if player hits 21
            if (player->total == 21)showHands(dealer,player,hide,name);
        }
        
        //Set ace value to 1 if player busts
        if (player->total > 21){
            for (int i=0; i<size; i++){
                if (player->card[i].cardP == 11)player->card[i].cardP=1;
            }
            
            //Recalculate player total
            player->total = 0;
            for (int j=0; j<player->handSize; j++){
                player->total += player->card[j].cardP;
            }
        }
        
        //If player busts end turn and set bust to true
        if (player->total > 21){
            showHands(dealer,player,hide,name);
            bust=true;
        }
    }while(player->total < 21 && (choice == 'H' or choice == 'h'));
    
    //Write players hand info to file
    ofstream outFile;
    string outName;
    
    outName = "playerhandinfo.bin";
    outFile.open(outName, ios::out | ios::binary | ios::trunc);
    outFile.write(reinterpret_cast<char *>(player),sizeof(player));
    outFile.close();
}
*/

/*
void dealerTurn(Hand *dealer, Hand *player, const int size, bool& bust, bool hide, int& dDraw, char name[]){
    //Set ace value to 1 if dealer draws 2 aces
        if (dealer->total > 21){
            for (int i=0; i<size; i++){
                if (dealer->card[i].cardP == 11)dealer->card[i].cardP=1;
            }
            
            //Set new dealer total
            dealer->total = 2;
        }
    
    //Output current hands
    showHands(dealer,player,hide,name);
    
    while (dealer->total < 17){
        dealer->total += dealer->card[dealer->handSize].cardP;
        dealer->handSize++;
        dDraw++;
        showHands(dealer,player,hide,name);
        
        //Set ace value to 1 if dealer busts
        if (dealer->total > 21){
            for (int i=0; i<size; i++){
                if (dealer->card[i].cardP == 11)dealer->card[i].cardP=1;
            }
            
            //Recalculate dealer total
            dealer->total = 0;
            for (int j=0; j<dealer->handSize; j++){
                dealer->total += dealer->card[j].cardP;
            }
        }
    }
    //If dealer busts end turn and set bust to true
        if (dealer->total > 21){
            bust=true;
        }
}

void results(Hand *dealer,Hand *player,bool pBust, bool dBust, bool hide, int& gWon, char name[]){
    cout<<"*************************************************************"<<endl;
    cout<<"                        Final Results                        "<<endl;
    showHands(dealer,player,hide,name);
    
    if (pBust){
        cout<<"You busted! Better luck next time!"<<endl;
    }else{
        if (dBust){
            cout<<"Dealer busts! You win!"<<endl;
            gWon++;
        }else{
            if (player->total > dealer->total){
                cout<<"You win! Congratulations!"<<endl;
                gWon++;
            }
            else if (player->total < dealer->total){
                cout<<"You lost, better luck next time!"<<endl;
            }else{
                cout<<"It's a draw!"<<endl;
            }
        }
    }
    cout<<"*************************************************************"<<endl<<endl;
}
*/
