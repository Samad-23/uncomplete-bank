#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;

string adminName;
string adminNumber;
string adminFather;
string adminCity;
string adminPin;
string adminUsername;

string v_adminUsername;
string v_adminPin;

void header();
void loginPage();
void chooseoption();
void exitt();
void menu();
void adminAccount();
void signIn();
void signInAsAdmin();
void adminMenu();
void userAccount();

class clients{
	string name[50];
	int pin[50];
	string accountType[50];
	string balance[50];
	string phoneNumber[50];
	static int userCount;
public:
	clients(){ 
		userCount++ ;
	}
	
	void getValues(); 
};
int clients :: userCount = 0;

void clients :: getValues(){
	    cin.ignore();
		cout<<" Enter name of client       : ";
		getline(cin, name[userCount] );
		cout<<" Set the pin (4-digit)      : ";
		cin>>pin[userCount];
		cout<<" Enter account type (salary/current) : ";
		cin>>accountType[userCount];
		cout<<" Enter the starting balance  : ";
		cin>>balance[userCount];
		cout<<" Enter phone number (without space)  : ";
		cin>>phoneNumber[userCount];
		
		cout<<endl<<" User Account Created Successfully !!!!";
		cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	    cout<<" Pres any key to go back....";
		
	    
	    ofstream file2("userfile.txt");
	    file2<<" ACC No.  | NAME        | PIN   | ACC TYPE  | BALANCE    | PHONE No: "<<endl;
	    file2<<"---------------------------------------------------------------------"<<endl;
	
	    file2<<" "<<left<<setw(10)<<userCount<<setw(14)<<name[userCount];
		file2<<setw(8)<<pin[userCount];
		file2<<setw(12)<<accountType[userCount];
		file2<<setw(13)<<balance[userCount];
		file2<<setw(12)<<phoneNumber[userCount];
	    
	    file2.close();
}
	
int main(){
start:	
	header();
	loginPage();
	
	int option;
	cin >> option;
	
start2:
		if(option == 1)
		{
//			if(adminPin != " ")
//			{
//			
//			    cout<<"\n The Admin account already exists.."<<endl;
//			    cout<<" Choose an option : ";
//				goto start;
//		    }
//			else 
			{
				adminAccount();
				goto start;
			}
		}
    	else if(option == 2)
		{
		start4:
			menu();
			cin>>option;
				switch (option)
				{
					case 1:
							signInAsAdmin();
							goto start4;    
//					case 2:
					case 3: 
					        goto start; 
							
				}	     
		}		   
		    
	else if(option == 3)
    {
		exitt(); 
    }
	
	else 
	{
		cout<<"\n Invalid choice.."<<endl;
		cout<<" Try again : ";
		cin>>option;
		goto start2;
	}
	return 0;
}

void header()
{
	system("cls");
	cout<<"       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"       ~~~~~~~~~~~~~~~~~~~~~~~~~BANK MANAGMENT SYSTEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void loginPage(){
	 
	 
	cout<<"\n\n     HEY! WELCOME.."<<endl; 
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	cout<<"  1. Create an Admin Account"<<endl;
	cout<<"  2. Sign in "<<endl;
	cout<<"  3. Exit"<<endl;
	
	cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<" choose any option: ";
}

void menu(){
//	system("cls");
	
	header();
	cout<<"\n\n   Sign in "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	cout<<"  1. Sign in as Admin "<<endl;
	cout<<"  2. Sign in as user "<<endl;
	cout<<"  3. Back"<<endl;
	
	
	cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"choose any option: ";
}

void exitt(){
	cout<< "\n Thankyou for using this system.. \n";
	exit(0);
}

void adminAccount(){
	system("cls");
	header();
	
	cout<<"\n\n   Creating an Admin Account  --  <One Time Process>"<<endl;
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	
	cout<<" Full Name         : ";
	cin.ignore();                         //without this, getline function is not working
	getline(cin, adminName);
	cout<<" Father's Name     : ";
	getline(cin, adminFather);
	cout<<" Phone Number      : ";
	getline(cin, adminNumber);
	cout<<" Current City      : ";
	getline(cin, adminCity);
	cout<<" Username          : ";
	getline(cin, adminUsername);
	cout<<" Set Pin (4 digit) : ";
	getline(cin, adminPin);
	
	ofstream adminfile("adminfile.txt");
	adminfile<<adminUsername<<endl;
    adminfile<<adminPin<<endl;

	adminfile<<adminName<<endl;
	adminfile<<adminFather<<endl;
	adminfile<<adminNumber<<endl;
	adminfile<<adminCity<<endl;
	adminfile.close();
	cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<" Created an admin account..!!  ";
	
	char a;
	cout<<"\n Enter any key to go back...  ";
	getch();
}

void signInAsAdmin()
{
system("cls");
	header();
	
	cout<<"\n\n   Sign in as Admin "<<endl;
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	
	ifstream adminfile("adminfile.txt");

	getline(adminfile, adminUsername);
	getline(adminfile, adminPin);

start3:	
	cin.ignore();
	cout<<" Enter Username  : ";
	getline(cin, v_adminUsername);
	cout<<" Enter Password  : ";
	getline(cin, v_adminPin);
	
//	if(adminUsername.compare(v_adminUsername) == 0 && adminPin.compare(v_adminPin) == 0)
	    if(adminUsername == v_adminUsername && adminPin == v_adminPin)
		{
			adminMenu();
		}
		else
		{
			cout<<"\n Incorrect Username or Password."<<endl;
		
    c1:		
			cout<<" 1. Try again "<<endl;
			cout<<" 2. Go back "<<endl<<"    -> ";
	    	int a;
			cin>>a;
		if(a==1)
				goto start3;
		else if(a==2)
		    { }
		else
		{
			cout<<" Invalid Choice : "<<endl;
			goto c1;
		}		
	}
}

void adminMenu()
{
	system("cls");
	header();
	
	cout<<"\n\n   Admin Menu "<<endl;
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	cout<<" 1. Create a user account. "<<endl;
	cout<<" 2. Close an existing account."<<endl;
	cout<<" 3. View a specific user's details."<<endl;
	cout<<" 4. View all user's details."<<endl;
    cout<<" 5. Update an existing account."<<endl;
	cout<<" 6. Check Total amount present in bank."<<endl;
	cout<<" 7. Go back.";	
	
	cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"choose any option: ";
   	
	int a;
	string b;
	cin>>a;
		if(a==1)
		{
			userAccount();                   ///////////
			adminMenu();
		}
		else if(a == 4)
		{
			ifstream file2("userfile.txt");
			while(getline(file2, b));
			{
			
				
			}
			getch();
		}
    
}

void userAccount(){
	system("cls");
	header();
	
	cout<<"\n\n   Create a user account "<<endl;
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
	clients c;
	c.getValues();
	
	getch();
}
