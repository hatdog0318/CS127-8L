/*
* Programmer: MIRABEL, Jan Krishtian C.
* Date Created: 04/26/2022
* Program: CS
* Course / Section: CS127-8L/AM1
* Purpose: Define an array structure definition named ShoeRec suitable for a shoe records of the type illustrated
*/
//include basic libraries
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

#define size 2

using namespace std; 

//define a struct with the following variables 
//StockNumber, ShoeType, ShoeBrand, DatePurchase, shoeCost, TotalValue
struct ShoeRec
{
    //define struct as datePurchase
    struct DatePurchase
    {
        int month;
        int day;
        int year;

        //setter
        void setMonth(int mth){
            while(mth > 12 || mth < 1){
                cout << "Invalid month. Please enter a valid month: ";
                cin >> mth;
            }
            month = mth;
        }

        //set day
        void setDay(int d) {
            while(d > 31 || d < 1){
                cout << "Invalid day. Please enter a valid day: ";
                cin >> d;
            }
            day = d;
        }

        //set year
        void setYear(int Y) {
            while(Y > 2021 || Y < 2000){
                cout << "Invalid year. Please enter a valid year: ";
                cin >> Y;
            }
            year = Y;
        }
        //define toString function
        string toString()
        {
            stringstream ss;
            ss << month << "-" << day << "-" << year;
            return ss.str();
        }
    };

    int NumofShoe = 0; 
    //constructor ShoeRec
    ShoeRec()
    {
        //check if NumofShoe <= 20
        if (NumofShoe <= 20)
        {
            //if true, then add 1 to NumofShoe
            NumofShoe++;
        }
        else
        {
            //if false, then exit the program
            cout << "You have reached the maximum number of shoes" << endl;
            exit(0);
        }
    }

    //define a shoe
    struct Shoe{
        string StockNumber;
        string ShoeType;
        string ShoeBrand;
        DatePurchase date; 
        int shoeQuantity;
        double shoeCost;
        double TotalValue;

        //constructor to initialize the variables
        Shoe(){
            StockNumber = "";
            ShoeType = "";
            ShoeBrand = "";
            date.month = 0;
            date.day = 0;
            date.year = 0;
            shoeQuantity = 0;
            shoeCost = 0;
            TotalValue = 0;
        }


        //define setters

        void setStockNumber(string stockNumber){
            //length of 8 only 
            while(stockNumber.length() != 8){
                cout << "Invalid Stock Number. Please enter a valid Stock Number: ";
                cin >> stockNumber;
            }
            StockNumber = stockNumber;
        }

        void setShoeQuantity(int shoeQty){
            //length of 8 only 
            while(shoeQty > 50 || shoeQty < 5){
                cout << "Invalid Stock Number. Please enter a valid Stock Number: ";
                cin >> shoeQty;
            }
            shoeQuantity = shoeQty;
        }

        void setShoeCost(double shoeCt){
            shoeCost = shoeCt;
        }

        void setShoeType(string shoeType){
            ShoeType = shoeType;
        }


        void setShoeBrand(string shoeBrand){
            ShoeBrand = shoeBrand;
        }

        void setDate(int month, int day, int year){
            date.setMonth(month);
            date.setDay(day);
            date.setYear(year);
        }
    };
    //declare a shoe
    Shoe shoe; 
};

void compVal(ShoeRec getshoe[])
{
    //loop through size of array
    for(int i = 0; i < size; i++)
    {
        //call compVal function
        getshoe[i].shoe.TotalValue = getshoe[i].shoe.shoeQuantity * getshoe[i].shoe.shoeCost;
    }
}
//define inputShoe function
void inputShoe(ShoeRec getshoe[])
{
    string tempStr; 
    int tempInt; 
    //loop through size of array
    for(int i = 0; i < size; i++)
    {
        //prompt the user to input shoe information
        cout << "Enter the following Shoe Information" <<endl; 
        cout << "Item "<< i+1<< endl;
        cout << "Enter Stock Number: "<< endl; 
        cin >> tempStr; 
        getshoe[i].shoe.setStockNumber(tempStr); 
        cout << "Enter ShoeType: "<< endl; 
        cin >> tempStr; 
        getshoe[i].shoe.setShoeType(tempStr);
        cout << "Enter ShoeBrand: "<< endl;
        cin >> tempStr; 
        getshoe[i].shoe.setShoeBrand(tempStr);
        cout << "Enter Date Purchase: (DD MM YYYY)"<<endl; 
        int day, month, year; 
        cin >> month >> day >> year;
        getshoe[i].shoe.setDate(month, day, year); 
        cout << "Enter Shoe Quantity: "; 
        cin >> tempInt;
        getshoe[i].shoe.setShoeQuantity(tempInt);
        cout << "Enter Shoe Cost: "; 
        double shoecost; 
        cin >> shoecost; 
        getshoe[i].shoe.setShoeCost(shoecost);
        cout << endl; 
    }
        //call compVal function
        compVal(getshoe);
}


int main()
{
    //ShoeRec of size 10
    ShoeRec shoeRec[10];
    //call inputShoe function
    inputShoe(shoeRec);
    //create a file named shoeinventory.txt
    ofstream outFile;
    outFile.open("shoeinventory.txt");
    //print out the information
    cout << left << setw(15) << "StockNumber"<< setw(15) << "ShoeType" << setw(15) << "ShoeBrand" << setw(15) << "DatePurchase" << setw(15) << "ShoeQuantity" << setw(15) << "ShoeCost" << setw(15) << "TotalValue" << endl;
    outFile << left << setw(15) << "StockNumber"<< setw(15) << "ShoeType" << setw(15) << "ShoeBrand" << setw(15) << "DatePurchase" << setw(15) << "ShoeQuantity" << setw(15) << "ShoeCost" << setw(15) << "TotalValue" << endl;
    for (int i = 0; i < size; i++)
    {
        //for print the data and cost with format Php999.00
        stringstream stream;
        stream <<fixed <<setprecision(2) << shoeRec[i].shoe.shoeCost; 
        string shoecoststr = "Php"+stream.str(); 
        //empty the stream 
        stream.str("");
        stream.clear(); 
        stream <<fixed <<setprecision(2) << shoeRec[i].shoe.TotalValue; 
        string totalcoststr = "Php"+stream.str(); 
        outFile << left << setw(15) << shoeRec[i].shoe.StockNumber << setw(15) << shoeRec[i].shoe.ShoeType << setw(15) << shoeRec[i].shoe.ShoeBrand << setw(15) << shoeRec[i].shoe.date.toString() << setw(15) << shoeRec[i].shoe.shoeQuantity << setw(15) << shoecoststr << setw(15) <<totalcoststr << endl;
        cout << left << setw(15) << shoeRec[i].shoe.StockNumber << setw(15) << shoeRec[i].shoe.ShoeType << setw(15) << shoeRec[i].shoe.ShoeBrand << setw(15) << shoeRec[i].shoe.date.toString() << setw(15) << shoeRec[i].shoe.shoeQuantity << setw(15) << shoecoststr << setw(15) <<totalcoststr << endl;
        
    }
    return 0; 
}
