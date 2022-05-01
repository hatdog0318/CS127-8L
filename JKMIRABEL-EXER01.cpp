#include<iostream>
#include<iomanip>
using namespace std;
//global
int i, j;
int row,col;
const int sizeRow=4;
const int sizeCol=5;
char again;

//function
char getMenu(char ans); //returns the correct choice otherwise returns -1 if not.
void getInput(int list[],int dim); //input for both option 1 and 2
void getBubble(int list[],int dim); //perform the bubble sorting
void getSelect(int list[],int dim); //perform the selection sorting
void convert2DimSort(int list[],int dim); //convert one dimensional to 2-
void get2DOut(int list1[][sizeCol]); //displaying the values in ascending and 
void getHeap(int list3[],int dimen); //process heapyfication or heap sort 1-D
void heapArr(int arr[], int num, int i);
void tryAgain(); //repeating the arrays
int main()
{
int size=20; //add code here
int arr[20];
int list[20];
char choice;
char sagot;
while(true){
do{
cout<<"-------------Sorting-------------"<<endl;
cout<<"[1]bubble sort"<<endl;
cout<<"[2]selection sort"<<endl;
cout<<"[3]heap sort"<<endl;
cout<<"[4]QUIT"<<endl;
cout<<"---------------------------------"<<endl;
cout<<"Enter your choice: ";
cin>>choice;
sagot=getMenu(choice);
 }while(sagot==-1);
 
 
 switch(sagot)
 {
 case '1'://bubblesort
 //add code here
 {
 	cout<<"\nProcessing Bubble Sorting Technique...\n";
 getInput(list, size); //call getInput function
getBubble(list, size); //call getBubble function
convert2DimSort(list, size); //call convert2DimSort
 
 tryAgain();
 }
 break;
 
 case '2'://selection sort
 //add code here
 {
 cout<<"\nProcessing Selection Sorting Technique...\n";
 getInput(list, size); //call getInput function 
getSelect(list, size); //call getSelect function
convert2DimSort(list, size); //call convert2DimSort
tryAgain();
}
 break;
 
 case '3'://heapsort
 //add code here 
 { 
 int size=10;
 cout<<"\nProcessing Heap Sorting Technique...\n";
 cout<<"Enter 10 numbers\n";
for(i=1;i<=size;i++)
 {
cout<<"Enter Value of list["<<i<<"]: ";
cin>>arr[i];
 }
 
 cout<<endl<<"Heapyfied values..."<<endl;
 //add code here
for(i=1;i<=size;i++)
{
cout<<"Arr["<<i<<"] : "<<arr[i]<<endl;
}
tryAgain();
}
 break;
 case '4': cout<<"end of program.....\n";
 exit(1);
}
}
}
/////////////////////////////////
char getMenu(char ans) 
{
 //add code here
 
if(ans=='1'||ans=='2'||ans=='3'||ans =='4')
{return ans;}
else
{return -1;}
}
////////////////////////////////////
void getInput(int list[],int dim) 
{
 //add code here
 
cout<<"enter 20 elements: \n";
for(int i=0;i<20;i++)
{
cout<<"loc["<<i<<"]: ";
cin>>list[i];
}
}
//////////////////////////////////////
void convert2DimSort(int list[],int dim) 
{
 //add code here
 
 int inList[sizeRow][sizeCol]={};
 int pin=0;
 for(row=0;row<=sizeRow-1;row++)
 {
 for(col=0;col<=sizeCol-1;col++)
{
 inList[row][col]=list[pin];
 pin++;
}
 }
}
////////////////////////////////////////////////
void get2DOut(int list1[][sizeCol]) 
{
 cout<<"Ascending Order\n"; //add code here
 cout<<setw(7); 
 for(row=0;row<=sizeRow-1;row++)
{
 for(col = 0;col<=sizeCol-1;col++)
{ 
 cout<<list1[row][col]<<setw(7);
 }
 cout<<endl;
 }
 cout<<"Descending Order\n"; //add code here
 cout<<setw(7); 
 for(row = 0; row <= sizeRow-1; row++)
 {
 for(col = 0; col <= sizeCol-1; col++)
{
 cout<<list1[sizeRow-row-1][sizeCol-col-1]<<setw(7);
 
 }
 cout<<endl;
 }
}
////////////////////////////////////////////
void getBubble(int list[],int dim) 
{
 //solution to bubble sort
 //add code here
 
 int temp;
 for(row=1;row<dim;row++)
 {
 for(col=0;col<dim-row;col++)
 {
 if(list[col]>list[col+1])
 {
 temp=list[col];
 list[col]=list[col+1];
 list[col+1]=temp;
}
}
}
}
///////////////////////////////////////////////
void getSelect(int list[],int dim) 
{
 //solution to selection sort 
 //add code here
 int select,sSort,temp;
 for(i=0;i<dim-1;i++)
 select=i;
 for(sSort=i+1;sSort<dim;sSort++)
 {
 if(list[i]<list[select])
 {
 select=sSort;
}
temp=list[sSort];
 list[sSort]=list[select];
 list[select]=temp;
 }
}
//////////////////////////////////////////////
void getHeap(int list3[],int dimen)
{
 //add code here
 
 int num;
 for (int i = num / 2 - 1; i >= 0; i--)
 heapArr(list3, num, i);
 for (int i = num - 1; i >= 0; i--) 
 {
 swap(list3[0], list3[i]);
 heapArr(list3, i, 0);
 }
}
///////////////////////////////////////////////
void heapArr(int list3[], int num, int i)
{
 //add code here
 
 int temp;
int lSize = i;
 int l = 2 * i + 1;
 int r = 2 * i + 2;
 if (l < num && list3[l] > list3[lSize])
 lSize = l;
 if (r < num && list3[r] > list3[lSize])
 lSize = r;
 if (lSize != i) {
 swap(list3[i], list3[lSize]);
 heapArr(list3, num, lSize);
 }
}
//////////////////////////////////////
void tryAgain()
{ 
 //add code here
do
{
cout<<"Do you want to try again? y/n: ";
cin>>again;
again=toupper(again);
}while(again!='Y'&&again!='N');
}

