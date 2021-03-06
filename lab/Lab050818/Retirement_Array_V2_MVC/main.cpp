/* 
 * File:   main.cpp
 * Author: Jonathan Acosta
 * Created on May 8th, 2018, 11:25 AM
 * Purpose: Retirement with arrays and MVC model
 */

//system Libraries
#include <iostream> //I/O Library-> cout, endl
#include <iomanip>  //Format Library
using namespace std; //namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array 

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    //Salary in $/year, Return on Investment in %, 
    //Savings required in $, Percentage Deposit in %
    float salary,roi,savReq,percDep;//Initial Conditions
    //Number of Years, Savings at the Beginning of 
    //Interest Earned at the End of Year
    //Deposit at the end of the year
    const int NYRS=100;//Size of the array
    int nYears;//NUmber of years the array utilized
    float svBegYr[NYRS],inEndYr[NYRS],dpEndYr[NYRS];
    int year[NYRS];
    
    //Initial Variables
    salary=1.e5f;//$100,000
    roi=5e-2;    //5%
    savReq=salary/roi;
    percDep=1e-1f;//10% 
    nYears=50;         //50 years
    svBegYr[0]=0;         //NO Savings int $'s at start
    inEndYr[0]=0;         //No interest at the beginning
    dpEndYr[0]=percDep*salary; //Deposit at the end of every year
    
    //Map/Process All computation Here
    year[0]=2021;
    int nYear;
    for(nYear=0;nYear<=nYears&&savReq>svBegYr[nYear];nYear++){
        int isvBgYr=(svBegYr[nYear]+inEndYr[nYear]+dpEndYr[nYear])*100;//Calculates in Pennies
        year[nYear+1]=year[nYear]+1;
        svBegYr[nYear+1]=isvBgYr/100;//Shifts back to dollars
        dpEndYr[nYear+1]=dpEndYr[nYear];
        inEndYr[nYear+1]=svBegYr[nYear+1]*roi;
    }
    
    //Output the Results, hence Display
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Year  Year     Savings    Interest  Deposit"<<endl;
    for(nYear=0;nYear<=nYears&&savReq>svBegYr[nYear];nYear++){
        cout<<setw(2)<<nYear
                <<setw(8)<<year[nYear]
                <<setw(12)<<svBegYr[nYear]
                <<setw(10)<<inEndYr[nYear]
                <<setw(12)<<dpEndYr[nYear]<<endl;
        
    }
    cout<<"Savings to Retire = $"<<svBegYr[nYear]
           <<" in year "<<year[nYear]<<endl;
    //Display Outputs
    
    //Exit Program!
    return 0;
}