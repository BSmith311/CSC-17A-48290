/* 
 * File:   main.cpp
 * Author: Brandon Smith
 * Created on September 5
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>
#include <ctype.h>
#include <math.h>
#include <string.h>
using namespace std;

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, conversions, or the columns for 2-D arrays

//Function Prototypes Here
bool inRange(const char [],unsigned short &);//Output true,unsigned or false
bool reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

short subtrct(signed short a,int x)
{
if (a > x)
return a - (signed short)x;
else
return a;
}

//Program Execution Begins Here
int main(int argc, char** argv) {
//Declare all Variables Here
const int SIZE=80; //More than enough
char digits[SIZE]; //Character digits or not
unsigned short unShort;//Unsigned short
short snShort; //Signed short

//Input or initialize values Here
cout<<"Reverse a number and subtract if possible."<<endl;
cout<<"Input a number in the range of an unsigned short"<<endl;
cin>>digits;

//Test if it is in the Range of an unsigned short
if(!inRange(digits,unShort)){
cout<<"No Conversion Possible"<<endl;
return 0;
}

//Reverse and see if it falls in the range of an signed short
if(!reverse(unShort,snShort)){
cout<<"No Conversion Possible"<<endl;
return 0;
}

//Now subtract if the result is not negative else don't subtract
snShort=subtrct(snShort,999);

//Output the result
cout<<snShort<<endl;

//Exit
return 0;
}

bool inRange(const char digits[] ,unsigned short &un){
int i;
// int size = sizeof(digits)/ sizeof(digits[0]);
int size = strlen(digits);

if(size > 5)
return false;

// check for the character other than digits
for (i = 0; i< size; i++){
if(!isdigit(digits[i]))
return false;
}

int j=0;
int sum =0;
for( i = 0; i<size ; i++){
sum = (digits[i] - '0')+ (sum * 10);
}

if(sum >0 && sum <65535){
un = sum;
return true;
}
}

bool reverse(unsigned short un,signed short &sn){
unsigned short n = un;
unsigned short reversedNumber;
int remainder,flag = 1;
if (n >= 10000)
flag = 0;
while(n != 0)
{
remainder = n%10;
reversedNumber = reversedNumber*10 + remainder;
n /= 10;
}
if (flag)
if(reversedNumber >= 1000){
reversedNumber *= 10;
}
else if(reversedNumber >= 100){
reversedNumber *= 100;
}
else if(reversedNumber >= 10){
reversedNumber *= 1000;
}
else if(reversedNumber == 0){
reversedNumber *= 10000;
}
if(reversedNumber > 32767 )
return false;
else{
sn = (signed short)reversedNumber;
return true;
}
}