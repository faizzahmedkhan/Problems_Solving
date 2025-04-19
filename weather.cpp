#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){
    string Days[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    float Temperature[7][24]; //2D Array to record temperatures, 7 for days and 24 for hours
    float AvgTemp[7]; // Array to store avg temperatures 
    float total=0;
    float avgtotal = 0;

    for (int i = 0; i < 7; i++) // Loop for each day, i indicates the number of day
    {
        for (int j = 0; j < 24; j++) //Loop for each hour, j indicates the number of hour
        {
            cout<<"Enter Temperature for "<<Days[i] <<" hour "<< j+1<<endl;
            cin>>Temperature[i][j];
            Temperature[i][j]= floor(Temperature[i][j] * 10.0) / 10.0; // Converting temperature to 1 decimal place
            if (Temperature[i][j]>50.0 || Temperature[i][j]<-20.0) // Checking if temperature is above 50 or below -20
            {
                cout<<"Not Acceptable"<<endl;
                j=j-1; // Repeating the number of iteration to get the correct input for jth hour
                continue;
            }
            total+=Temperature[i][j]; // adding temperatures to total for each day
        }
        AvgTemp[i]=(total/24); // Average of the 24 hours temperature
        total=0; // setting total to 0, for next day's temperature
    }
    for (int i = 0; i < 7; i++) // Loop for each day
    {
        cout<<"Average Temperature is "<<AvgTemp[i]<<" Celsius for "<<Days[i]<<endl; // Average for each Day's Temperature
        float Fahrenheit=(AvgTemp[i]*9/5)+32;
        cout<<"Average Temperature is "<<Fahrenheit<<" Fahrenheit for "<<Days[i]<<endl; // Output in Fahrenheit
        avgtotal=avgtotal+AvgTemp[i]; // Adding the average of each day
    }
    cout<<"Total average temperature is: "<<avgtotal/7<<" Celsius"<<endl; // Average of 7 days' avg temperature
    cout<<"Total average temperature is: "<<(((avgtotal/7)*9/5)+32)<<" Fahrenheit"<<endl; // Output in Fahrenheit
}