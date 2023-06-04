/*
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 15= Design and implement program for parity checker of ASCII equivalence of given word
*/


#include<iostream>
#define max 100
using namespace std;

class Parity_Checker
{
	public:
	string str;
	int arr[max];
	void Get_string();
	void Even_Parity();
	void Odd_Parity();
};

void Parity_Checker::Get_string()
{
	cout<<"Enter String for parity checking:\n";
	cin>>str;
}

void Parity_Checker::Even_Parity()
{
	int i=0,j=0,val,count=0;
	int size=str.length();
	
	for(i=0;i<size;i++)
	{
		val=int(str[i]);
		while(val>0)
		{
		int n=val%2;
		arr[j]=n;
		val=val/2;
		j++;
		}
	}
	for(i=j-1;i>=0;i--)
	{
		cout<<arr[i];
		if(arr[i]==1)
		count++;
	}
	cout<<endl;
	if(count%2==0)
	cout<<"Given string has even parity..!"<<endl;
	else
	cout<<"Given string has Not even parity..!"<<endl;
}
void Parity_Checker::Odd_Parity()
{
	int i=0,j=0,val,count=0;
	int size=str.length();
	
	for(i=0;i<size;i++)
	{
		val=int(str[i]);
		
		while(val>0)
		{
			int n=val%2;
			arr[j]=n;
			val=val/2;
			j++;
		}
	}
	for(i=j-1;i>=0;i--)
	{
		cout<<arr[i];
		if(arr[i]==1)
		count++;
		
	}
	cout<<endl;
	
	if(count%2!=0)
	cout<<"Given string has Odd parity..!"<<endl;
	else
	cout<<"Given string has Not Odd parity..!"<<endl;
}

int main()
{
	Parity_Checker obj;
	int choice,flag=0;
	obj.Get_string();
	
	while(1)
	{
		cout<<"\nSelect from following: \n";
		cout<<"\t 1. for Even Parity"<<endl;
		cout<<"\t 2. for Odd Parity"<<endl;
		cout<<"\t 3. for Exit"<<endl;
		cout<<"Enter Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			obj.Even_Parity();
			break;
			
			case 2:
			obj.Odd_Parity();
			break;
			
			case 3:
			flag=1;
			break;
			
			default:
			cout<<"Enter Correct Choice...!!"<<endl;
			break;
		}
		if(flag==1)
		break;
	}
	return 0;
}

/*
OUTPUT

Enter String for parity checking:
shantanu

Select from following:
         1. for Even Parity
         2. for Odd Parity
         3. for Exit
Enter Choice:1
11101011101110110000111101001101110110000111010001110011
Given string has Not even parity..!

Select from following:
         1. for Even Parity
         2. for Odd Parity
         3. for Exit
Enter Choice:2
11101011101110110000111101001101110110000111010001110011
Given string has Odd parity..!

Select from following:
         1. for Even Parity
         2. for Odd Parity
         3. for Exit
Enter Choice:3
*/
