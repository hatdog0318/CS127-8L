#include<iostream> 
#include<iomanip> 
#include<cstring> 
#include<algorithm> 
#include<cstdlib> 
using namespace std; 
#include<conio.h> 
#include<windows.h>
string sort(string str);//reaaranging the orders of string to test if its anagram
bool areAnagrams(string str1,string str2);//process the strgin if anagram anf returns the value 1 or 0
string RemSpacePunct(string str);//function that removes space and punctation in aa string
////////////////////////////////
void palindrome(char sal[120]);//testing whether the c-string value is palindrome or not 
void password();//asking the user to enter the password
char menu();//displaying choices a,b, and c then returns the answer 
void quit();//asking the user if he/she wants to quit
string EnterPassword();//processing if the password is correct and diplaying it with "*" sign

int main()
{
	char let, ans;
	//other declared varaibles
	char sal[120];//temporary storage
	char nav_saved;//save navagation process
	string str, strb;//string one, string bool(true/false) returned
	//Functions
	//ENTERING THE PASSWORD
	password();
	//DISPLAYING CHOICES
	do{
		ans = menu();
		ans = tolower(ans);
		if(!(ans == 'a'||ans == 'b'||ans == 'c'))
	{
		cout<<endl<<"Invalid choice... ";
		system("choice /d y /t 1 > nul");//timer}
	}while(!(ans == 'a'||ans == 'b'||ans == 'c'));
	//FURTHER CONDITION
	cin.sync(); //discards all unread characters from the input buffer
	//NAVAGATION
	switch(ans)
	{
		case 'a':
		{
		palindrome(sal);
		//save navagation
		nav_saved = 'a';
		}
		break;
		case 'b':
		{
		//display & function
		system("cls");
		cout<<"[b] Check if strings are Anagram"<<endl
			<<"Testing wheter the following strings areanagrams: "<<endl;
		cout<<"Enter string 1: ";
		getline(cin,str);
		//function
		sort(str);//get string 1, input string 2, sort anagrams, check anagrams
		//save navagation
		nav_saved = 'b';
		}
		break;
		
		case 'c':
		{
		//go to quit
		quit();
		}
		break;	
	}
	do{
		cout<<"Do you want to try again[y/n]"<<endl
		<<"Choice: ";
		cin>>let;
		
		let=tolower(let);
	}while(let!='n'&&let!='y');
	if(let=='y')
	{
		if(nav_saved == 'a'){
	do{
		cin.sync(); //discards all unread characters from the input buffer
		palindrome(sal);
	do{
		cout<<"Do you want to try again[y/n]"<<endl
		<<"Choice: ";
 		cin>>let;
 		let=tolower(let);
		}while(let!='n'&&let!='y');
		if(let == 'n')
 		main();
 	 }while(true);
 		}
		else
 		{
 			do{
 				cin.sync(); //discards all unread characters from the input buffer
				//display & function
				system("cls");
				cout<<"[b] Check if strings are Anagram"<<endl
				<<"Testing wheter the following strings are anagrams: "<<endl;
				cout<<"Enter string 1: ";
				getline(cin,str);
				//function
				sort(str); //get string 1, input string 2, sort anagrams, check anagrams
				do{
					cout<<"Do you want to try again [y/n]"<<endl
					<<"Choice: ";
 					cin>>let;
					let=tolower(let);
				}while(let!='n'&&let!='y');
				if(let == 'n')
				main();
			}while(true);
 		}
		}
				else
				main();	
				system("pause");
				return 0;
			}while(true);
}//end main	
////////////////////////////////////////////////////// 
void quit()
{
	//declared varaible
char let;
do{
system("cls");
cout<<"Do you want to quit now? [y/n]"<<endl
<<"Choice: ";
 cin>>let;
let=tolower(let);
}while(let!='n'&&let!='y');
if(let == 'n')
 main();
else
 exit(0);
}
///////////////////////
string EnterPassword()
{
	//declared variables
int passSize=0, pctr; //password size, counter
char tempPassword; //temporary password
char PassStorage[20]; //password storage
string password, userInput; //password condition, user inputed password
string mainPassword("exer_03"); //USER DEFINED PASSWORD
//==================================================================//
//==================================================================//
//function
//counter
pctr = 0;
//loop (entering password, display *)
do{
tempPassword = getch();
if((tempPassword >= 97 && tempPassword <= 122) // a to z
 ||(tempPassword >= 65 && tempPassword <= 90) // A to Z
 ||(tempPassword >= 48 && tempPassword <= 57) // 0 to 9
 ||(tempPassword >= 33 && tempPassword <= 47) // ! to /
 ||(tempPassword >= 58 && tempPassword <= 64) // : to @
 ||(tempPassword >= 91 && tempPassword <= 96) // [ to `
 ||(tempPassword >= 123 && tempPassword <= 126)) // { to ~
 {
PassStorage[pctr] = tempPassword;
++pctr;
cout<<"*";
 }
 if((tempPassword == 8 && pctr >= 1)||(pctr >= 20)) //if backspace is pressed or reached 20 characters
 {
cout<<"\b \b";
--pctr;
PassStorage[pctr] = '\b';
 }
 if(tempPassword == 13) //if enter is pressed
 {
PassStorage[pctr] = '\0';
break; //break the loop
 }
}while(true);
//store the password from char array to string
userInput = PassStorage;
//processing
if(userInput == mainPassword)
 password = "correct";
else
 password = "incorrect";
//return (processed password condition) for validation	
	return password;
}
//////////////////////////////////////////////////// 
char menu()
{
	
//declared variable
char choice; //choice
//display
system("cls");
cout<<"========================================"<<endl
<<"[a] Check the palindrome"<<endl
<<"[b] Testing if strings are Anagrams"<<endl
<<"[c] Quit"<<endl
<<"========================================"<<endl
<<"Your choice: ";
 //input your choice
 cin>>choice;
//return choice
return choice;
}
////////////////////////////////// 
void password()
{
//declared varaibles
string check_password; //for password validation
int password_trycount; //counter for limiting incorrect password tries
//function
do{
//display
system("cls");
cout<<"enter password: ";
check_password = EnterPassword();
//validation
if(check_password == "incorrect")
 {
if(password_trycount<5)
{
cout<<endl<<endl<<"sorry incorrect password...";
cout<<endl<<"you have "<<5-password_trycount<<" more try left...";
system("choice /d y /t 1 > nul"); //timer 
password_trycount++;
}
else
 {
cout<<endl<<endl<<"sorry incorrect password...";
cout<<endl<<"you have reached the maximum attempt of password..."<<endl;
exit(0);
 }
 }
else //if password is correct
 break; //go to menu
}while(true);
}
//////////////////////////////////////////////////////////////// 
string sort(string str)
{
	//declared varaibles
int ctr; //counter
string str1, str2; //strings for anagrams (ordinary)
string rsp_str1, rsp_str2; //strings for anagrams(with removed spaces and punction)
string converted_str1, converted_str2; //strings for anagrams (switch to lowercase)
string sstr1, sstr2; //saved strings for anagrams
 //counters
 int i, flag = 0, x[26] = {0}, y[26] = {0};
 //condition (universal)
 str1 = str; //copy string one from main
 rsp_str1 = RemSpacePunct(str); //remove space and punctuation
 //cout<<rsp_str1;
 
 cin.sync(); //discards all unread characters from the input buffer
 //user inputs string 2
 cout<<"Enter String 2: ";
 getline(cin,str2);
 
 //condition (universal)
 rsp_str2 = RemSpacePunct(str2); //remove space and punctuation
 //cout<<rsp_str2;
 //copy for later display
 sstr1 = str1;
 sstr2 = str2;
//Avoid Case Sensitive for Palindrome (UNIVERSAL FOR STRING 1 AND 2)
 for(ctr = 0; ctr < rsp_str1.length(); ctr++)
 {
 rsp_str1[ctr] = tolower(rsp_str1[ctr]);
 }
 for(ctr = 0; ctr < rsp_str2.length(); ctr++)
 {
 rsp_str2[ctr] = tolower(rsp_str2[ctr]);
 }
//cout<<"Words: "<<endl;
//cout<<rsp_str1<<endl;
//cout<<rsp_str2;
 //copy for validation
 str1 = rsp_str1;
 str2 = rsp_str2;
//==================================================================//
//==================================================================//
 //sort both the strings 
 sort(str1.begin(), str1.end()); 
 sort(str2.begin(), str2.end());
 
 //==================================================================//
 //==================================================================//
//cout<<"Words: "<<endl;
//cout<<rsp_str1<<endl;
//cout<<rsp_str2;
//display
 system("cls");
 cout<<"[b] Check if strings are Anagram"<<endl
 <<"Testing wheter the following strings are anagrams: "<<endl
 <<"String 1: "<<sstr1<<endl
 <<"String 2: "<<sstr2<<endl;
//validation (if true or false)
if (areAnagrams(str1, str2))
 cout <<"They are anagrams!"; 
 else
 cout <<"They are NOT anagrams."; 
cout<<endl<<endl;
return str;
}
//////////////////////////////
bool areAnagrams(string str1,string str2)
{
// Get lengths of both strings 
 int n1 = str1.length(); 
 int n2 = str2.length(); 
 
 //==================================================================//
 //==================================================================//
 
// If length of both strings is not same, then they 
 // cannot be anagram
 if (n1 != n2) 
 return false; 
 
 // Compare sorted strings 
 for (int i = 0; i < n1; i++) 
 if (str1[i] != str2[i]) 
 return false;
 
 return true;
}
//////////////////////////////
string RemSpacePunct(string str)
{
	//function
for (int i = 0; i < str.size(); i++)
 {
 if ( str[i] == ' ' // space
|| (str[i] >= 33 && str[i] <= 47) // ! to /
|| (str[i] >= 58 && str[i] <= 64) // : to @
|| (str[i] >= 91 && str[i] <= 96) // [ to `
|| (str[i] >= 123 && str[i] <= 126)) // { to ~
 {
 str.erase(i, 1); // remove ith char from string
 i--; // reduce i with one so you don't miss any char
 }
 }
 
 return str;
 
}
/////////////////////////////// 
void palindrome(char sal[120])
{
//declared variables
char temp; //temporary character
int ctr, x, y; //counters
string word; //user word
string rsp_word; //value for removed space and punctuation
string rev_word; //reversed word
string converted_rsp, converted_rev; //converted original and reverse word
//dispaly & function
do{
system("cls");
cout<<"[a] Check the palindrome"<<endl
<<"Input the word: ";
 getline(cin,word); //get user word
 rsp_word = RemSpacePunct(word); //remove space and punctuation
 
 if(rsp_word == "")
 {
 cout<<endl<<"You either input an invalid character or its empty.Please try again!";
 system("choice /d y /t 2 > nul"); //timer 
 }
 }while(rsp_word == "");
 
 //Avoid Case Sensitive for Palindrome (FOR ORIGNIAL WORD)
 converted_rsp = rsp_word;
 for(ctr = 0; ctr < converted_rsp.length(); ctr++)
 {
 converted_rsp[ctr] = tolower(converted_rsp[ctr]);
 }
 
 //convert string to char
 sal[rsp_word.size() + 1];
strcpy(sal, rsp_word.c_str());
//==================================================================//
 //==================================================================//
 
 //reversing the word
 y = strlen(sal) - 1;
 for (x = 0; x < y; x++,y--)
 {
 temp = sal[x];
 sal[x] = sal[y];
 sal[y] = temp;
 }
 rev_word = sal;
 
 //==================================================================//
 //==================================================================//
 
 //Avoid Case Sensitive for Palindrome (FOR ORIGNIAL WORD)
 converted_rev = rev_word;
 for(ctr = 0; ctr < converted_rev.length(); ctr++)
 {
 converted_rev[ctr] = tolower(converted_rev[ctr]);
 }
 
 //display
 system("cls");
cout<<"[a] Check the palindrome"<<endl
<<"Input the word: "<<rsp_word<<endl
 <<"In Reverse Order: "<<rev_word<<endl;
 
 if(converted_rsp==converted_rev)
 cout<<"The word is palindrome!";
 else
 cout<<"The word is not a palindrome.";
 cout<<endl<<endl;
}
