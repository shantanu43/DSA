/*
Name = Shantanu H Chaudhari
Batch= B1
Practical= 14
Design and develop a program using linear recurrence relations for various loan schemes of a bank.

*/
#include<iostream>
using namespace std;

		string name;                       //Declaring the Global variables
		int time;
		float amt;
		float rate;
		
class Loan                                 //Creating the Class Loan
{
	public:
		                                   //Defining Member Functions
		void getinfo();
		void home();
		void education();
		void gold();
		void car();
		void showinfo();
		void rateinfo();
		void amtcalc();

};

void Loan::getinfo()
{
	 cout<<"Enter the name of Customer: \n";
	 cin>>name;
	 cout<<"Enter the amount to deposit: \n";
	 cin>>amt;
	 cout<<"Enter the time duration(yrs): \n";
	 cin>>time;

}
void Loan::home()
{
	rate=10;
}
void Loan::education()
{
	rate=9;
}
void Loan::gold()
{
	rate=11;

}
void Loan::car()
{
	rate=12;
}

void Loan::showinfo()
{
	//cout<<"\nYOUR LOAN DETAILS "<<endl;
	cout<<"\nName: "<<name;
	cout<<"\nLoan amount: "<<amt;
	cout<<"\nTime Duration: "<<time<<"yrs";
	cout<<"\nInterest rate: "<<rate<<"%";
}

void Loan::rateinfo()
{
	cout<<"INTEREST RATE OF DIFFERENT LOANS"<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<"        HOME LOAN-		10%               "<<endl;
	cout<<"        EDUCATION LOAN-	9%          "<<endl;
	cout<<"        GOLD LOAN-		11%               "<<endl;
	cout<<"        CAR LOAN-		12%                "<<endl;
	cout<<"---------------------------------------------"<<endl;

}

void Loan::amtcalc()
{
	cout<<"\n LOAN AMOUNT CALCULATOR "<<endl;
	cout<<"\nEnter the Principle Amount: ";
	cin>>amt;
	cout<<"Enter the Interest Rate: ";
	cin>>rate;
	cout<<"Enter the time Duration(yrs): ";
	cin>>time;
}


float finalamt(int t,int amt,float rt)                             //Creating a Recursive Function
{
	if(t<=0)
	{
		return amt ;
	}
	else
	return (1+(rt/100))*finalamt(t-1,amt,rt) ;
}

                                                              //Initialisation of Main Function
int main()
{
	Loan l;                                                   //Creating Object Of Class Loan

	int opt;
	char ch;
	
	
	do{
	
		cout<<"\n--------------------------------------------------------------\n";
		cout<<"WELCOME TO MITAOE BANK"<<endl;
		cout<<"\nWhich loan do you want from the following options\n"<<endl;
		cout<<"1.HOME LOAN"<<endl;
		cout<<"2.EDUCATION LOAN"<<endl;
		cout<<"3.GOLD LOAN"<<endl;
		cout<<"4.CAR LOAN"<<endl;
		cout<<"5.INTEREST RATE INFORMATION"<<endl;
		cout<<"6.LOAN AMOUNT CALCULATOR"<<endl;
		cout<<"7.EXIT";
		cout<<"\n--------------------------------------------------------------\n";
		cout<<"\nEnter your Option:";
		cin>>opt;
		cout<<"\n--------------------------------------------------------------\n";
	
		switch(opt)                                               //Using Switch Cases
		{
			case 1:
				l.getinfo();
				l.home();
				cout<<"\nYOUR HOME LOAN DETAILS ARE AS FOLLOW \n";
				l.showinfo();
				cout<<"\nAmount after "<<time<< " yrs becomes:"<<finalamt(time,amt,rate);
	
				break;
	
			case 2:
				l.getinfo();
				l.education();
				cout<<"\nYOUR EDUCATION LOAN DETAILS ARE AS FOLLOW \n";
				l.showinfo();
				cout<<"\nAmount after "<<time<< " yrs becomes:"<<finalamt(time,amt,rate);
	
				break;
	
			case 3:
				l.getinfo();
				l.gold();
				cout<<"\nYOUR GOLD LOAN DETAILS ARE AS FOLLOW \n";
				l.showinfo();
				cout<<"\nAmount after "<<time<< " yrs becomes:"<<finalamt(time,amt,rate);
	
				break;
	
			case 4:
				l.getinfo();
				l.car();
				cout<<"\nYOUR CAR LOAN DETAILS ARE AS FOLLOW \n";
				l.showinfo();
				cout<<"\nAmount after "<<time<< " yrs becomes:"<<finalamt(time,amt,rate);
				break;
	
			case 5:
				l.rateinfo();
				break;
	
			case 6:
				l.amtcalc();
				cout<<"Amount after "<<time<< " yrs becomes:"<<finalamt(time,amt,rate);
			
				break;
	
			case 7:
				break;
	
	
			default:
				cout<<"\nInvalid Option !!!! \nPlease TRY AGAIN !!"<<endl;
				
	
		}
	cout<<"\n\nDo you Want to continue(y/n): ";
	cin>>ch;
	}
	while(ch=='y');

	
	cout<<"\n THANK YOU FOR VISITING !!!!";
	cout<<"\nPlease Visit Again !!";
	return 0;
	
}

/*
OUTPUT

--------------------------------------------------------------
WELCOME TO MITAOE BANK

Which loan do you want from the following options

1.HOME LOAN
2.EDUCATION LOAN
3.GOLD LOAN
4.CAR LOAN
5.INTEREST RATE INFORMATION
6.LOAN AMOUNT CALCULATOR
7.EXIT
--------------------------------------------------------------

Enter your Option:1

--------------------------------------------------------------
Enter the name of Customer:
Ganesh
Enter the amount to deposit:
1000
Enter the time duration(yrs):
2

YOUR HOME LOAN DETAILS ARE AS FOLLOW

Name: Ganesh
Loan amount: 1000
Time Duration: 2yrs
Interest rate: 10%
Amount after 2 yrs becomes:1210

Do you Want to continue(y/n): y

--------------------------------------------------------------
WELCOME TO MITAOE BANK

Which loan do you want from the following options

1.HOME LOAN
2.EDUCATION LOAN
3.GOLD LOAN
4.CAR LOAN
5.INTEREST RATE INFORMATION
6.LOAN AMOUNT CALCULATOR
7.EXIT
--------------------------------------------------------------

Enter your Option:2

--------------------------------------------------------------
Enter the name of Customer:
Ram
Enter the amount to deposit:
2000
Enter the time duration(yrs):
3

YOUR EDUCATION LOAN DETAILS ARE AS FOLLOW

Name: Ram
Loan amount: 2000
Time Duration: 3yrs
Interest rate: 9%
Amount after 3 yrs becomes:2590.06

Do you Want to continue(y/n): y

--------------------------------------------------------------
WELCOME TO MITAOE BANK

Which loan do you want from the following options

1.HOME LOAN
2.EDUCATION LOAN
3.GOLD LOAN
4.CAR LOAN
5.INTEREST RATE INFORMATION
6.LOAN AMOUNT CALCULATOR
7.EXIT
--------------------------------------------------------------

Enter your Option:3

--------------------------------------------------------------
Enter the name of Customer:
kirti
Enter the amount to deposit:
5000
Enter the time duration(yrs):
2

YOUR GOLD LOAN DETAILS ARE AS FOLLOW

Name: kirti
Loan amount: 5000
Time Duration: 2yrs
Interest rate: 11%
Amount after 2 yrs becomes:6160.5

Do you Want to continue(y/n): y

--------------------------------------------------------------
WELCOME TO MITAOE BANK

Which loan do you want from the following options

1.HOME LOAN
2.EDUCATION LOAN
3.GOLD LOAN
4.CAR LOAN
5.INTEREST RATE INFORMATION
6.LOAN AMOUNT CALCULATOR
7.EXIT
--------------------------------------------------------------

Enter your Option:4

--------------------------------------------------------------
Enter the name of Customer:
bhavesh
Enter the amount to deposit:
2346
Enter the time duration(yrs):
4

YOUR CAR LOAN DETAILS ARE AS FOLLOW

Name: bhavesh
Loan amount: 2346
Time Duration: 4yrs
Interest rate: 12%
Amount after 4 yrs becomes:3691.48

Do you Want to continue(y/n): y

--------------------------------------------------------------
WELCOME TO MITAOE BANK

Which loan do you want from the following options

1.HOME LOAN
2.EDUCATION LOAN
3.GOLD LOAN
4.CAR LOAN
5.INTEREST RATE INFORMATION
6.LOAN AMOUNT CALCULATOR
7.EXIT
--------------------------------------------------------------

Enter your Option:5

--------------------------------------------------------------
INTEREST RATE OF DIFFERENT LOANS
---------------------------------------------
        HOME LOAN-              10%
        EDUCATION LOAN- 9%
        GOLD LOAN-              11%
        CAR LOAN-               12%
---------------------------------------------


Do you Want to continue(y/n): y

--------------------------------------------------------------
WELCOME TO MITAOE BANK

Which loan do you want from the following options

1.HOME LOAN
2.EDUCATION LOAN
3.GOLD LOAN
4.CAR LOAN
5.INTEREST RATE INFORMATION
6.LOAN AMOUNT CALCULATOR
7.EXIT
--------------------------------------------------------------

Enter your Option:6

--------------------------------------------------------------

 LOAN AMOUNT CALCULATOR

Enter the Principle Amount: 3000
Enter the Interest Rate: 12.4
Enter the time Duration(yrs): 3
Amount after 3 yrs becomes:4260.1
*/
