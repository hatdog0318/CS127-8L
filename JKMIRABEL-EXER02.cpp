//header file
#include <iostream>
#include <iomanip>
//using namespace
using namespace std;

//global declaration
int i;
const int size=10;
typedef double *pointers;//typedefinition used for miles per gallon pointer variables

//prototype
//for grade elimination
void getInput(double *input);
double getLow(double *low);
double getSum(double *sum);
//choices and try again
char getChoice(char *ch);//display the menu of choices and input the choice of the user

//miles per gallon
void MilesPerrGallon(double *ptr1,double *ptr2,int sz);
void MperG();

//main function
int main()
{
        //add only declaration here
        char choice, opt;
        char *chr;

        do{
                chr=&choice;
                opt=getChoice(chr);
                switch(*chr)
                {
                case '1':
                {
                        double grade[size];
                        double *ptr;
                        double *plow, *psum, *pave;
                        double gsum,glow;
                        double ave;

                        system("cls");
                        //add code here
                        //NOTE ALL CODES MUST USE pointer variables input,process and //output
                        
                        ptr = grade;
                        plow = &glow;
                        psum = &gsum;
                        pave = &ave;

                        cout<< "Choice[1]:Grade Elimination" << endl;
                        getInput(ptr);
                        *psum = getSum(ptr);
                        *plow = getLow(ptr);

                        //removing lowest quiz score and calculating average of 9 subjects
                        *pave = (gsum - glow)/(size - 1);

                        cout<< "sum = " << gsum << endl
                                << "lowest = " << glow << endl
                                << fixed << setprecision(2) << "average = " << ave << endl;

                }
                        break;

                case '2':
                        MperG();
                        break;
                
                case '3':
                        cout<<"goodbye for now....\n";
                        system("pause");
                        exit(1);
                        break;
                }

                do{     
                        cout << "Do you want to try again?[y/n]: ";
                        cin >> opt;
                }
                while(opt != 'y' && opt != 'n');        

        } while(opt == 'y');

        cout<<endl;
        system("pause");
        return 0;
}


///////////////////////////
char getChoice(char *ch)
{       
        char opt;
        system("cls");
        cout<< "\n<<<<<<<<<<MENU>>>>>>>>>>" << endl
                << "[1] score of 10 quizzes" << endl
                << "[2] mile per gallon" << endl
                << "[3] to quit" << endl
                << "enter your choice: ";

        cin>> opt;
        *ch = opt;

        return opt;     
}

//////////////////////////////


void getInput(double *input)
{       
        cout<< "enter " << size << " grades" << endl;
        for(i=0; i<size; i++){
                cout<< "grade[" << i << "]:";
                cin>> *(input+i);
        }
}
/////////////////////////////


double getSum(double *sum)
{
        double add=0;
        for(i=0; i<size; i++){
                add += *(sum+i);
        }
        return add;
}
////////////////////////////////


double getLow(double *low)
{
        double baba = *low;
        for(i=1; i<size; i++){
                if(baba > *(low+i)){
                        baba = *(low+i);
                }
        }
        return baba;
}
/////////////////////////


void MperG()
{
        int ctr;
        pointers milPtr,galPtr;
        int msize;
        system("cls");

        //add code here
        cout<< "COMPUTING FOR MPG : miles per gallon..." << endl
                << "Specify the size of the array: ";
        cin>> msize;

        while(msize < 5 || msize > 15){
                cout<< "size 5-15 only" << endl
                        << "Specify the size of the array: ";
                cin>> msize;      
        } 

        milPtr = new double[msize];
        galPtr = new double[msize];

        cout<< fixed << setprecision(2);

        cout<<"\nMILES\n";
        for(ctr=0;ctr<msize;ctr++)
        {
                //add code here
                bool ans=true;
                while(ans){
                        cout<< "miles[" << ctr << "]:";
                        cin>> milPtr[ctr];

                        try
                        {       
                                if(milPtr[ctr] < 100 || milPtr[ctr] > 250)
                                        throw(milPtr[ctr]);
                                else
                                        ans = false;
                        }//end try
                        catch(double e)
                        {
                                cout<< e << " is invalid!.. 100-250 only" << endl
                                        << "reenter a new value" << endl;

                        }//end catch
                //add code here
                }//end while
        }//loop for miles

        /*********************************************************/
        cout<<"\nGALLONS\n";
        for(ctr=0;ctr<msize;ctr++)
        {
                bool ans=true;
                while(ans){
                        cout<< "gallons[" << ctr << "]:";
                        cin>> galPtr[ctr];

                        try
                        {       
                                if(galPtr[ctr] < 5 || galPtr[ctr] > 25)
                                        throw(galPtr[ctr]);
                                else
                                        ans = false;
                        }//end try
                        catch(double e)
                        {
                                cout<< e << " is invalid!.. 5-25 only" << endl
                                        << "reenter a new value" << endl;

                        }//end catch
                }//end while
        }//loop for gallons

        MilesPerrGallon(milPtr,galPtr,msize);
}
////////////////////////


void MilesPerrGallon(double *ptr1,double *ptr2,int sz)
{
        double mpg[sz];
        pointers mpgPtr;
        int index;

        mpgPtr = mpg;
        
        cout<< left << fixed << setprecision(2)<< endl
                << setw(8) << "miles" << "/        "
                << setw(8) << "gallon" << "=       "
                << "MPG" << endl;

        for(index=0; index<sz; index++){
                *(mpgPtr+index) = *(ptr1+index) / *(ptr2+index);
                cout<< setw(8) << *(ptr1+index) << "/        "
                        << setw(8) << *(ptr2+index) << "=       "
                        << mpg[index] << endl;
        }       
}
