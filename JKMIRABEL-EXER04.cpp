/*
 * Programmer: Mirabel, Jan Krishtian C.
 * Date Created: 04/20/2022
 * Terminal No: 2019104318
 * Program: CS
 * Course / Section: CS127L-8L/AM1
 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;
void userName();
void passWord();
void inventoryData();
// initialize structures
struct items
{
    string prodName;
    double price;
    int stock;
    int sold;
};
struct productList
{
    int productSize;
    string prodType;
    items item[50];
};
int main()
{

    // login
    // username = admin
    // pass = exer_04
    userName();
    passWord();
    inventoryData();

    system("pause");
}
////////////////////////////////////////////////////////////////////////
void inventoryData()
{
    int productAmt;
    system("cls");
    cout << setw(40) << "***** INVENTORY SYSTEM C++.2 *****" << endl;
    cout << "ENTER NUMBER OF PRODUCTS FOR INVENTORY: ";
    cin >> productAmt;
    productList product[productAmt];
    cout << "ENTER " << productAmt << " PRODUCT(S)" << endl;
    int i = 0;
    while (i < productAmt)
    {
        cout << "Product " << i + 1 << ": ";
        cin >> product[i].prodType;
        cout << "\nHow many " << product[i].prodType << "?: ";
        cin >> product[i].productSize;
        for (int j = 0; j < product[i].productSize; j++)
        {
            cout << product[i].prodType << "[" << j + 1 << "]: ";
            cin >> product[i].item[j].prodName;
            cout << "Price: Php";
            cin >> product[i].item[j].price;
            cout << "Stock: ";
            cin >> product[i].item[j].stock;
            cout << "Sold: ";
            cin >> product[i].item[j].sold;
            cout << "\n";
            cin.ignore();
        }
        cout << endl;
        i++;
    }
    // displaying the inventory
    system("cls");

    cout << " ***** INVENTORY SYSTEM C++.2 *****" << endl;
    cout << "PROD NO. PRODUCT         NAME                     PRICE       STOCK      SOLD      LEFT      " << endl;
    cout << fixed << setprecision(2);
    cout << left;
    for (int a = 0; a < productAmt; a++)
    {
        cout << setw(9) << a + 1 << setw(16) << product[a].prodType;
        for (int b = 0; b < product[a].productSize; b++)
        {
            if (b == 0)
            {
                cout << setw(25) << product[a].item[b].prodName
                     << setw(12) << product[a].item[b].price
                     << setw(11) << product[a].item[b].stock
                     << setw(10) << product[a].item[b].sold
                     << setw(10) << (product[a].item[b].stock - product[a].item[b].sold);
            }
            else
            {
                cout << setw(25) << " "
                     << setw(25) << product[a].item[b].prodName
                     << setw(12) << product[a].item[b].price
                     << setw(11) << product[a].item[b].stock
                     << setw(10) << product[a].item[b].sold
                     << setw(10) << (product[a].item[b].stock - product[a].item[b].sold);
            }
            cout << endl;
        }
    }
}
////////////////////////////////////////////////////////////////////////
void userName()
{
    // username: admin
    system("cls");
    string userName;
    int userAtt = 3;
    do
    {

        system("cls");
        cout << setw(40) << "PRODUCT INVENTORY SYSTEM CS127L" << endl;
        cout << "USERNAME: ";
        getline(cin, userName);
        if (userName != "admin")
        {
            cout << "Wrong Username.. " << userAtt << " attempts left." << endl;
            userAtt--;
            system("pause");
        }
        try
        {
            if (userAtt < 0)
            {
                throw 99;
            }
        }
        catch (...)
        {
            system("cls");
            cout << "you have reached the maximum amount of attempts.." << endl;
            cout << "try again later." << endl;
            system("pause");
            exit(0);
        }
    } while (userName != "admin");
}
////////////////////////////////////////////////////////////////////////
void passWord()
{
    // password: exer_04
    system("cls");
    char pass[256];
    int i = 0;
    int passatt = 4;
    char pas[] = "exer_04";
    char c;
    try
    {
        do
        {
            system("cls");
            cout << setw(40) << "PRODUCT INVENTORY SYSTEM CS127L" << endl;
            cout << "PASSWORD: ";
            for (i = 0;;) // pass input replace to * loop
            {
                c = getch();
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_'))
                {
                    pass[i] = c;
                    i++;
                    cout << "*";
                }
                if (c == '\b' && i >= 1) // backspace
                {
                    cout << "\b \b";
                    i--;
                }
                if (c == '\r') // enter
                {
                    pass[i] = '\0';
                    break;
                }
            } // loop end
            if (strcmp(pass, pas) == 0)
                break;
            else
            {
                --passatt;
                cout << "\nWrong Password.. " << passatt << " attempts left." << endl;
                system("pause");
            }
        } while (passatt > 0);
        if (passatt == 0)
        {
            throw passatt;
        }
    }
    catch (int passatt)
    {
        system("cls");
        cout << "you have reached the maximum amount of attempts.." << endl;
        cout << "try again later." << endl;
        system("pause");
        exit(0);
    }
}
