/*
* File:   main.cpp
* Author: Brandon Smith
* Created on September 15
* Purpose: Read and Report Weather Statistics
*/

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Structure Declaration
struct WeatherData{
    string name;            //Name of the month
    float rain, lowT, highT;//Rainfall, lowest temp, highest temp
};

//Execution
int main(int argc, char** argv){
	//Declare Variables
	float avgTemp, avgRain;
	float lowest=100000, 
	      highest=-100000;
	string lowMonth, highMonth; //Name of lowest temp month & highest temp month
	
	//Initialize Variables
	avgTemp=avgRain=0;
	
	//Create Structure Variables
	WeatherData January, Februrary, March, April, 
	            May, June, July, August, September, 
	            October, November, December;
	
	//January
	//User inputs
	cin>>January.name>>January.rain;
	cin>>January.lowT>>January.highT;
	
	//Input Validation
	while(January.lowT<-100 or January.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>January.lowT;
	}
	while(January.highT<-100 or January.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>January.highT;
	}
	
	//Add to Averages 
	avgTemp+=(January.lowT+January.highT);
	avgRain+=January.rain;
	//Lowest and Highest Temp Check
	if (January.lowT<lowest){
	    lowMonth=January.name;
	    lowest=January.lowT;
	}
	if (January.highT>highest){
	    highMonth=January.name;
	    highest=January.highT;
	}
	
	//Februrary
	//User inputs
	cin>>Februrary.name>>Februrary.rain;
	cin>>Februrary.lowT>>Februrary.highT;
	
	//Input Validation
	while(Februrary.lowT<-100 or Februrary.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>Februrary.lowT;
	}
	while(Februrary.highT<-100 or Februrary.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>Februrary.highT;
	}
	
	//Add to Averages 
	avgTemp+=(Februrary.lowT+Februrary.highT);
	avgRain+=Februrary.rain;
	//Lowest and Highest Temp Check
	if (Februrary.lowT<lowest){
	    lowMonth=Februrary.name;
	    lowest=Februrary.lowT;
	}
	if (Februrary.highT>highest){
	    highMonth=Februrary.name;
	    highest=Februrary.highT;
	}
	
	//March
	//User inputs
	cin>>March.name>>March.rain;
	cin>>March.lowT>>March.highT;
	
	//Input Validation
	while(March.lowT<-100 or March.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>March.lowT;
	}
	while(March.highT<-100 or March.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>March.highT;
	}
	
	//Add to Averages 
	avgTemp+=(March.lowT+March.highT);
	avgRain+=March.rain;
	//Lowest and Highest Temp Check
	if (March.lowT<lowest){
	    lowMonth=March.name;
	    lowest=March.lowT;
	}
	if (March.highT>highest){
	    highMonth=March.name;
	    highest=March.highT;
	}
	
	//April
	//User inputs
	cin>>April.name>>April.rain;
	cin>>April.lowT>>April.highT;
	
	//Input Validation
	while(April.lowT<-100 or April.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>April.lowT;
	}
	while(April.highT<-100 or April.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>April.highT;
	}
	
	//Add to Averages 
	avgTemp+=(April.lowT+April.highT);
	avgRain+=April.rain;
	//Lowest and Highest Temp Check
	if (April.lowT<lowest){
	    lowMonth=April.name;
	    lowest=April.lowT;
	}
	if (April.highT>highest){
	    highMonth=April.name;
	    highest=April.highT;
	}
	
	//May
	//User inputs
	cin>>May.name>>May.rain;
	cin>>May.lowT>>May.highT;
	
	//Input Validation
	while(May.lowT<-100 or May.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>May.lowT;
	}
	while(May.highT<-100 or May.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>May.highT;
	}
	
	//Add to Averages 
	avgTemp+=(May.lowT+May.highT);
	avgRain+=May.rain;
	//Lowest and Highest Temp Check
	if (May.lowT<lowest){
	    lowMonth=May.name;
	    lowest=May.lowT;
	}
	if (May.highT>highest){
	    highMonth=May.name;
	    highest=May.highT;
	}
	
	//June
	//User inputs
	cin>>June.name>>June.rain;
	cin>>June.lowT>>June.highT;
	
	//Input Validation
	while(June.lowT<-100 or June.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>June.lowT;
	}
	while(June.highT<-100 or June.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>June.highT;
	}
	
	//Add to Averages 
	avgTemp+=(June.lowT+June.highT);
	avgRain+=June.rain;
	//Lowest and Highest Temp Check
	if (June.lowT<lowest){
	    lowMonth=June.name;
	    lowest=June.lowT;
	}
	if (June.highT>highest){
	    highMonth=June.name;
	    highest=June.highT;
	}
	
	//July
	//User inputs
	cin>>July.name>>July.rain;
	cin>>July.lowT>>July.highT;
	
	//Input Validation
	while(July.lowT<-100 or July.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>July.lowT;
	}
	while(July.highT<-100 or July.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>July.highT;
	}
	
	//Add to Averages 
	avgTemp+=(July.lowT+July.highT);
	avgRain+=July.rain;
	//Lowest and Highest Temp Check
	if (July.lowT<lowest){
	    lowMonth=July.name;
	    lowest=July.lowT;
	}
	if (July.highT>highest){
	    highMonth=July.name;
	    highest=July.highT;
	}
	
	//August
	//User inputs
	cin>>August.name>>August.rain;
	cin>>August.lowT>>August.highT;
	
	//Input Validation
	while(August.lowT<-100 or August.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>August.lowT;
	}
	while(August.highT<-100 or August.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>August.highT;
	}
	
	//Add to Averages 
	avgTemp+=(August.lowT+August.highT);
	avgRain+=August.rain;
	//Lowest and Highest Temp Check
	if (August.lowT<lowest){
	    lowMonth=August.name;
	    lowest=August.lowT;
	}
	if (August.highT>highest){
	    highMonth=August.name;
	    highest=August.highT;
	}
	//September
	//User inputs
	cin>>September.name>>September.rain;
	cin>>September.lowT>>September.highT;
	
	//Input Validation
	while(September.lowT<-100 or September.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>September.lowT;
	}
	while(September.highT<-100 or September.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>September.highT;
	}
	
	//Add to Averages 
	avgTemp+=(September.lowT+September.highT);
	avgRain+=September.rain;
	//Lowest and Highest Temp Check
	if (September.lowT<lowest){
	    lowMonth=September.name;
	    lowest=September.lowT;
	}
	if (September.highT>highest){
	    highMonth=September.name;
	    highest=September.highT;
	}
	
	//October
	//User inputs
	cin>>October.name>>October.rain;
	cin>>October.lowT>>October.highT;
	
	//Input Validation
	while(October.lowT<-100 or October.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>October.lowT;
	}
	while(October.highT<-100 or October.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>October.highT;
	}
	
	//Add to Averages 
	avgTemp+=(October.lowT+October.highT);
	avgRain+=October.rain;
	//Lowest and Highest Temp Check
	if (October.lowT<lowest){
	    lowMonth=October.name;
	    lowest=October.lowT;
	}
	if (October.highT>highest){
	    highMonth=October.name;
	    highest=October.highT;
	}
	
	//November
	//User inputs
	cin>>November.name>>November.rain;
	cin>>November.lowT>>November.highT;
	
	//Input Validation
	while(November.lowT<-100 or November.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>November.lowT;
	}
	while(November.highT<-100 or November.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>November.highT;
	}
	
	//Add to Averages 
	avgTemp+=(November.lowT+November.highT);
	avgRain+=November.rain;
	//Lowest and Highest Temp Check
	if (November.lowT<lowest){
	    lowMonth=November.name;
	    lowest=November.lowT;
	}
	if (November.highT>highest){
	    highMonth=November.name;
	    highest=November.highT;
	}
	
	//December
	//User inputs
	cin>>December.name>>December.rain;
	cin>>December.lowT>>December.highT;
	
	//Input Validation
	while(December.lowT<-100 or December.lowT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>December.lowT;
	}
	while(December.highT<-100 or December.highT>140){
	    cout<<"Invalid temperature, please enter a value between -100 and 140 degrees Fahrenheit."<<endl;
	    cin>>December.highT;
	}
	
	//Add to Averages 
	avgTemp+=(December.lowT+December.highT);
	avgRain+=December.rain;
	//Lowest and Highest Temp Check
	if (December.lowT<lowest){
	    lowMonth=December.name;
	    lowest=December.lowT;
	}
	if (December.highT>highest){
	    highMonth=December.name;
	    highest=December.highT;
	}
	
	//Calculate Averages
	avgRain=(avgRain/12);
	avgTemp=(avgTemp/24);
	
	//Final Output
	cout<<"Average Rainfall "
	    <<fixed<<setprecision(1)<<avgRain
	    <<" inches/month"<<endl;
    
    cout<<setprecision(0);
    cout<<"Lowest  Temperature "<<left<<setw(8)<<lowMonth
        <<right<<setw(3)<<lowest<<" Degrees Fahrenheit"<<endl;
	
	cout<<"Highest Temperature "<<left<<setw(8)<<highMonth
        <<right<<setw(3)<<highest<<" Degrees Fahrenheit"<<endl;
    
    cout<<"Average Temperature for the year "<<avgTemp
        <<" Degrees Fahrenheit"<<endl;
	
	//End Program
	return 0;
}