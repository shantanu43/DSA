/*
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 01= Implement a program to perform operations of array using array of objects
*/

#include <iostream>
using namespace std;

class Hospital	// Declaring class
{

private:	
    char name[100];		//class members
    int patino;
	int deadpati;

public:
    void read();	//Member function
    void display();
    int insert(int pos, int size, Hospital patient[]);
    int del(int pos, int size, Hospital patient[]);
    int update(int pos, int size, Hospital patient[]);
    
};

void Hospital::read()	//Function taking input
{
    
	cout << "\nEnter the name of the Hospital ::" << endl;
    cin >> name;
    cout << "\nEnter the patient number::" << endl;
    cin >> patino;
    cout << "\nEnter the number of dead patient in hospital::" << endl;
    cin >> deadpati;
    
};

void Hospital::display()	//Function displaying the information taken as input
{
	
    cout << "\nName of the hospital is: " << name;
    cout << "\nPatient number is: " << patino;
    cout << "\nNumber of dead patient in Hospital are:" << deadpati << endl;
    
}

int Hospital::insert(int pos, int size, Hospital patient[]) 	//Function for insertion
{
	
    pos--;
    size++;

    if (pos >= 0 || pos < size)
    {
        for (int i = size; i >= pos; i--)
        {
            patient[i] = patient[i - 1];
        }
    }
    else
    {
        cout << "\nEnter the correct position...!!";
    }
    patient[pos].read();
    cout << "\nAfter insertion the list is given as: " << endl;
    
	for (int i = 0; i < size; i++)
    {
        cout << "\nHospital " << (i + 1) << endl;
        patient[i].display();
    }
    
}

int Hospital::del(int pos, int size, Hospital patient[])	//function performing delete operation
{
    pos--;
    if (pos >= 0 || pos < size)
    {
        for (int i = pos; i < size; i++)
        {
            patient[i] = patient[i + 1];
        }
    }
    else
    {
        cout << "\nEnter the correct position...!!";
    }
    size--;
    cout << "\nAfter deletion the list is given as: " << endl;
    for (int i = 0; i < size; i++)
    {
        patient[i].display();
    }
}

int Hospital::update(int pos, int size, Hospital patient[])	//function performing update operation
{
    if (pos >= 0 || pos < size)
    {
        patient[pos - 1].read();
    }
    else
    {
        cout << "\nEnter the correct position...!!";
    }
    cout << "\n After updation the list is given as: " << endl;
    for (int i = 0; i < size; i++)
    {
        patient[i].display();
    }
}

int size;

int main()
{
    int pos;
    int c;
    string p;
    Hospital patient[50];	//declaring the size of array
    
    cout << "\nEnter the name of the city :" << endl;
    cin >> p;
    cout<< "\nEnter the data of covid hospital in : "<< p << endl;
    
    cout << "\n Enter the number of hospital in city:: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "\nHospital " << (i + 1) << endl;
        patient[i].read();
    }
    for (int j = 0; j < size; j++)
    {
        cout << "\nHospital " << (j + 1) << endl;
        patient[j].display();
    }
        cout << "\nOptions for operations are:\n1.Insert\n2.Delete\n3.Update" << endl;
        cout<<"\n Your choice is : "; 
		cin >> c ;
        
        switch (c)
        {
        case 1:
            //for Inserting the data 
            int pos;
            cout << "\nEnter the number of Hospital  on which you want to perform INSERT operation: ";
            cin >> pos;
            patient[pos].insert(pos, size, patient);
            break;

        case 2:
            //for deleting the data 
            cout << "\nEnter the number of Hospital on which you want to perform DELETE operation:";
            cin >> pos;
            patient[pos].del(pos, size, patient);
            break;

        case 3:
            //for updating the data
            cout << "\nEnter the number of Hospital on which you want to perform UPDATE operation:";
            cin >> pos;
            patient[pos].update(pos, size, patient);
            break;

        default:
            cout << " Invalid Input";
            break;
        }
        return 0;
}

/*
Enter the name of the city :
Dhule

Enter the data of covid hospital in : Dhule

 Enter the number of hospital in city:: 2

Hospital 1

Enter the name of the Hospital ::
Vignaharta

Enter the patient number::
12

Enter the number of dead patient in hospital::
2

Hospital 2

Enter the name of the Hospital ::
ram

Enter the patient number::
30

Enter the number of dead patient in hospital::
11

Hospital 1

Name of the hospital is: Vignaharta
Patient number is: 12
Number of dead patient in Hospital are:2

Hospital 2

Name of the hospital is: ram
Patient number is: 30
Number of dead patient in Hospital are:11

Options for operations are:
1.Insert
2.Delete
3.Update

Your choice is: 1

Enter the number of Hospital  on which you want to perform INSERT operation: 1

Enter the name of the Hospital ::
Central

Enter the patient number::
20

Enter the number of dead patient in hospital::
4

After insertion the list is given as:

Hospital 1

Name of the hospital is: Central
Patient number is: 20
Number of dead patient in Hospital are:4

Hospital 2

Name of the hospital is: Vignaharta
Patient number is: 12
Number of dead patient in Hospital are:2

Hospital 3

Name of the hospital is: ram
Patient number is: 30
Number of dead patient in Hospital are:11

*/

