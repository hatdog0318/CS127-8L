/*
Programmer: Mirabel, Jan Krishtian C.
Subject: CS127-8L_AM1
Instructor: Pascua, Cristina A.
*/

#include <iostream>
#include <iomanip>
using namespace std;
char getMenu();
void getBinDisplay(int *ptr,int *xsize);
int getLoc(int *ptr,int size,int *xtarget);
int getSize();
void getInput(double *ptr,int xsize);
double getElim(double *ptr,int xsize);
void getTry();
//start of the main method
int main()
{
char sagot;
int binNum[12] ={4,7,8,10,14,21,22,36,62,77,81,91};
int size=12;
int loc,target,gradesize;
double elim,sum=0;
char options;
//run a while until value of sagot is N/n;
while(sagot!='3')
{
//display menu;
getMenu();
//take input user choice from the menus
cin>>sagot;
switch(sagot)
{
case '1':
//start do - while loop
do
{
// call the getBinDisplay method to display thearrays
getBinDisplay(binNum,&size);
cout<<"\nenter your target key:";
cin>>target;
loc = getLoc(binNum,size,&target); // call the binary search method to get the locations
if(loc ==-1){ //if loc is -1 mean target is not in the array
cout<<target<<" is not in the list"<<endl;
}
else{
cout<<target<<" is at position["<<loc<<"]"<<endl;
}
getTry();
//ask user if he want the try again
cin>>options;
}
while(options =='y' ||options=='Y');
getTry();
case '2':
do
{
	sum=0;
gradesize =getSize();
double arr[gradesize];
getInput(arr,gradesize); // method to take input inthe grade array
elim=getElim(arr,gradesize); // method call the check which grade we need to eiminate
for(int i=0;i<gradesize;i++)
{
sum=sum+arr[i];
}
sum=sum-elim; // eliminate the elim grade from the sum
// below is to set the decimal upto 2 decimal places
std::cout << std::fixed;
 std::cout << std::setprecision(2);
cout<<elim<<" is eliminated"<<endl;
cout<<"average is "<<sum/(gradesize-1)<<endl;
getTry();
//ask user if he wants to try again
cin>>options;
}
while(options =='y' ||options=='Y');
getTry();
case '3':
break;
default:
// if user choose any other options display only 3 values are allowed
cout<<"invalid choice please try again"<<endl;
}
}
}
char getMenu()
{
// display the menus
cout<<"----------CHOICES---------"<<endl;
cout<<"[1] Binary searching"<<endl;
cout<<"[2] Grade elimination"<<endl;
cout<<"[3] exit"<<endl;
cout<<"enter your choice:";
}
void getBinDisplay(int *ptr,int *xsize)
{
cout<<"\nOption1: Binary Searching"<<endl;
cout<<"\nDisplaying element in the array"<<endl;
for(int i=0;i<*xsize;i++)
{
cout<<setw(5)<<ptr[i];
}
cout<<endl;
}
//binary search to search the target values from the sorted arrays
int getLoc(int *ptr,int size,int *xtarget)
{
// Repeat until the pointers low and high meet each other
int low=0;
int high = size-1;
 while (low <= high)
{
 int mid = low + (high - low) / 2;
 if (ptr[mid] == *xtarget)
 return mid;
 if (ptr[mid] < *xtarget)
 low = mid + 1;
 else
 high = mid - 1;
 }
 return -1;
}
int getSize()
{
cout<<"Option2 : Grade Elimination"<<endl;
int size;
// ask the user to enter the size of the array
// if size is invalid throw it and catch that and ask user to re-enter the values
do
{
try
{
cout<<"enter your desired number of grades [5 to 10 only]: ";
cin>>size;
if(size <5 || size > 10)
{
throw size;
}
}
catch(int num)
{
cout<<num<<" invalid... pease re-enter"<<endl;
}
}
while(size<5 || size>10);
}
// method to get all the grades
// and validate the grade between 0 to 100
void getInput(double *ptr,int xsize)
{
for(int i=0;i<xsize;i++)
{
do
{
try
{
cout<<"grade["<<(i+1)<<"]:";
cin>>ptr[i];
if(ptr[i]<0 || ptr[i]>100)
{
throw ptr[i];
}
}
catch(double num)
{
cout<<ptr[i]<<" invalid... please re-enter the grade"<<endl;
}
}while(ptr[i]<0 || ptr[i]>100);
}
}
//method to check the minimun grade and return that values
double getElim(double *ptr,int xsize)
{
double min=ptr[0];
for(int i=1;i<xsize;i++)
{
if(min>ptr[i])
{
min=ptr[i];
}
}
return min;
}
void getTry()
{
cout<<"Do you want to try again?[y/n]";
}

