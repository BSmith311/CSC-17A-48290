/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 15
 * Purpose: Read and output monthly budget expenses using Structures
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structure Declaration
    struct MonthlyBudget{
        float housing, 
              utilities, 
              houseExpen, 
              transport, 
              food, 
              medical, 
              insurance, 
              entertainment, 
              clothing, 
              misc, 
              total;
    };

//Function Prototypes
void budgetSpent(MonthlyBudget&);
void budgetReport(MonthlyBudget,MonthlyBudget);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Create Structure Variables
    MonthlyBudget budget, spent;
    
    //Set Budget Structure
    budget.housing=500.00,
    budget.utilities=150.00,
    budget.houseExpen=65.00,
    budget.transport=50.00,
    budget.food=250.00,
    budget.medical=30.00,
    budget.insurance=100.00,
    budget.entertainment=150.00,
    budget.clothing=75.00,
    budget.misc=50,
    budget.total=1420;
    
    //Call Functions
    budgetSpent(spent);
    budgetReport(spent,budget);
    
    //Exit stage right!
    return 0;
}

//Functions
void budgetSpent(MonthlyBudget& spent){
    cout<<"Enter housing cost for the month:$"<<endl;
    cin>>spent.housing;
    cout<<"Enter utilities cost for the month:$"<<endl;
    cin>>spent.utilities;
    cout<<"Enter household expenses cost for the month:$"<<endl;
    cin>>spent.houseExpen;
    cout<<"Enter transportation cost for the month:$"<<endl;
    cin>>spent.transport;
    cout<<"Enter food cost for the month:$"<<endl;
    cin>>spent.food;
    cout<<"Enter medical cost for the month:$"<<endl;
    cin>>spent.medical;
    cout<<"Enter insurance cost for the month:$"<<endl;
    cin>>spent.insurance;
    cout<<"Enter entertainment cost for the month:$"<<endl;
    cin>>spent.entertainment;
    cout<<"Enter clothing cost for the month:$"<<endl;
    cin>>spent.clothing;
    cout<<"Enter miscellaneous cost for the month:$"<<endl;
    cin>>spent.misc;
    //Calculate total expenses
    spent.total=(spent.housing+spent.utilities+spent.houseExpen
                +spent.transport+spent.food+spent.medical+spent.insurance
                +spent.entertainment+spent.clothing+spent.misc);
}

void budgetReport(MonthlyBudget spent,MonthlyBudget budget){
    //Housing Report
    if (spent.housing>budget.housing)
    {cout<<"Housing Over"<<endl;}
    else if (spent.housing<budget.housing)
    {cout<<"Housing Under"<<endl;}
    else {cout<<"Housing Even"<<endl;}
    //Utilities Report
    if (spent.utilities>budget.utilities)
    {cout<<"Utilities Over"<<endl;}
    else if (spent.utilities<budget.utilities)
    {cout<<"Utilities Under"<<endl;}
    else {cout<<"Utilities Even"<<endl;}
    //Household Expenses Report
    if (spent.houseExpen>budget.houseExpen)
    {cout<<"Household Expenses Over"<<endl;}
    else if (spent.houseExpen<budget.houseExpen)
    {cout<<"Household Expenses Under"<<endl;}
    else {cout<<"Household Expenses Even"<<endl;}
    //Transportation Report
    if (spent.transport>budget.transport)
    {cout<<"Transportation Over"<<endl;}
    else if (spent.transport<budget.transport)
    {cout<<"Transportation Under"<<endl;}
    else {cout<<"Transportation Even"<<endl;}
    //Food Report
    if (spent.food>budget.food)
    {cout<<"Food Over"<<endl;}
    else if (spent.food<budget.food)
    {cout<<"Food Under"<<endl;}
    else {cout<<"Food Even"<<endl;}
    //Medical Report
    if (spent.medical>budget.medical)
    {cout<<"Medical Over"<<endl;}
    else if (spent.medical<budget.medical)
    {cout<<"Medical Under"<<endl;}
    else {cout<<"Medical Even"<<endl;}
    //Insurance Report
    if (spent.insurance>budget.insurance)
    {cout<<"Insurance Over"<<endl;}
    else if (spent.insurance<budget.insurance)
    {cout<<"Insurance Under"<<endl;}
    else {cout<<"Insurance Even"<<endl;}
    //Entertainment Report
    if (spent.entertainment>budget.entertainment)
    {cout<<"Entertainment Over"<<endl;}
    else if (spent.entertainment<budget.entertainment)
    {cout<<"Entertainment Under"<<endl;}
    else {cout<<"Entertainment Even"<<endl;}
    //Clothing Report
    if (spent.clothing>budget.clothing)
    {cout<<"Clothing Over"<<endl;}
    else if (spent.clothing<budget.clothing)
    {cout<<"Clothing Under"<<endl;}
    else {cout<<"Clothing Even"<<endl;}
    //Miscellaneous Report
    if (spent.misc>budget.misc)
    {cout<<"Miscellaneous Over"<<endl;}
    else if (spent.misc<budget.misc)
    {cout<<"Miscellaneous Under"<<endl;}
    else {cout<<"Miscellaneous Even"<<endl;}
    //Total Report
    if (spent.total>budget.total)
    {cout<<"You were $"<<fixed<<setprecision(2)<<(spent.total-budget.total)<<" over budget";}
    else if (spent.total<budget.total)
    {cout<<"You were $"<<fixed<<setprecision(2)<<(budget.total-spent.total)<<" under budget";}
}