/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on October 16, 2022
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Vectors
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//Function Prototypes Here
void prnt1DVec(vector<int> &,int);
void prnt2DVec(vector<vector<int> >,int,int);
void fillVec(vector<int> &,int,int,int);
void swap(int &,int &);
void smlLst(vector<int> &,int);
void mrkSort(vector<int> &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D vectors
    int colsize=3;//The column size for a 2 dimensional vector
    vector<int>avec;
    vector<int>bvec;
    vector<int>cvec;
    
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel vector
    fillVec(avec,rowsize,highRng,lowRng);
    fillVec(bvec,rowsize,highRng/10,lowRng/10);
    fillVec(cvec,rowsize,highRng/100,lowRng/100);
    
    //Sort the vector the for all positions
    mrkSort(avec);
    mrkSort(bvec);
    mrkSort(cvec);
    
    //Fill the 2-D vector
    vector<vector<int> >table{{avec},{bvec},{cvec}};
    
    //Print the values in the vector
    prnt1DVec(avec,perLine);
    prnt1DVec(bvec,perLine);
    prnt1DVec(cvec,perLine);
    prnt2DVec(table,rowsize,colsize);
    
    //Cleanup
    avec.clear();
    bvec.clear();
    cvec.clear();
    table.clear();

    //Exit
    return 0;
}

void fillVec(vector<int> &a,int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a.push_back(rand()%(hr-lr+1)+lr);
    }
}

void prnt2DVec(vector<vector<int> > a,int rowsize,int colsize){
     cout<<endl<<"The Vector Values"<<endl;
     
     for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<left<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prnt1DVec(vector<int> &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> &a){
    for(int pos=0;pos<a.size()-1;pos++){
        smlLst(a,pos);
    }
}

void smlLst(vector<int> &a,int pos){
    for(int i=pos+1;i<a.size();i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}