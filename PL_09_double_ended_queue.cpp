/*
Name= Shantanu Chaudhari
Roll No= 86
Title= Design and implement a program for double ended queue and its operations for a shopping mall.

*/

#include<iostream>
#define size 10
using namespace std;


class items
{
    public:
        string name[size];
        float price[size];
        int front, rear, quantity[size];


    items()
    {
        front = -1;	 //queue is empty
        rear = -1;
    }

    void newitem(int index);
    bool EmptyRear();
    bool EmptyFront();
    void insertRear();
    void insertFront();
    void deleteRear();
    void deleteFront();
    void display();
};

void items :: newitem(int index)	//taking input in the queue
{
    cout << "Enter Item Name : ";
    cin >> name[index];
    cout << "Enter Price : ";
    cin >> price[index];
    cout << "Enter Quantity : ";
    cin >> quantity[index];
}

bool items :: EmptyRear()
{
    if(rear != size - 1)	//if (rear = size -1) then we can not insert data and it is overflow condition
        return true;
    else
        return false;
}

bool items :: EmptyFront()
{
    if(front != -1)
        return true;
    else
        return false;
}

void items :: insertRear()
{
    if(EmptyRear())
    {
        rear++;
        newitem(rear);
    }
    else
        cout << "Queue is full from rear." << endl;
}

void items :: insertFront()
{
    if(EmptyFront())
    {
        newitem(front);
        front--;
    }
    else
        cout << "Queue is full from front." << endl;
}

void items :: deleteFront()
{
    if(front == rear)
    {
    	cout << "There is nothing in queue to delete." << endl;
	}
    else
    {
        front++;
        cout << name[front] << " is deleted successfully." <<endl;
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void items :: deleteRear()
{
    if(front == rear)
    {
    	cout << "There is nothing in queue to delete." << endl;
	}
    else
    {
        cout << name[rear] << " is deleted successfully." <<endl;
        rear--;
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void items :: display ()
{
    cout << "\tName\tPrice\tQuantity"<<endl;
    cout<<"------------------------------------------\n";
    int j = 0;
    for(int i=front; i < rear; )
    {
        i++;j++;
        cout << j << ". " <<"\t"<< name[i] << "\t" << price[i] << "\t " << quantity[i]<< endl;
    }
}


int main()
{
    items obj;
    int choice,y;

    do
    {
        cout << "\n1. Add new item at last of list\n2. Add item at start of list\n3. Delete item from last of list\n4. Delete item from start of list\n5. Display List" << endl;
        cout << "Enter choice of operation : ";
        cin  >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                obj.insertRear();
                break;

            case 2:
                obj.insertFront();
                break;

            case 3:
                obj.deleteRear();
                break;

            case 4:
                obj.deleteFront();
                break;
            
            case 5:
                obj.display();
                break;

            default:
                cout << "Invalid Choice !!" << endl;
        }
        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"\nDo you want to continue? \n 1.yes \n 2.No \n";
        cin>>y;
    }
    while(y==1);
   cout<<"\nThank you for using our service !";
}

/*
1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 1

Enter Item Name : shirt
Enter Price : 500
Enter Quantity : 2

--------------------------------------------------------------------------

Do you want to continue?
 1.yes
 2.No
1

1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 1

Enter Item Name : cap
Enter Price : 100
Enter Quantity : 2

--------------------------------------------------------------------------

Do you want to continue?
 1.yes
 2.No
1

1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 4

shirt is deleted successfully.

--------------------------------------------------------------------------

Do you want to continue?
 1.yes
 2.No
1

1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 2

Enter Item Name : bag
Enter Price : 200
Enter Quantity : 3

--------------------------------------------------------------------------

Do you want to continue?
 1.yes
 2.No
1

1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 5

        Name    Price   Quantity
------------------------------------------
1.      bag     200      3
2.      cap     100      2

--------------------------------------------------------------------------

Do you want to continue?
 1.yes
 2.No
1

1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 1

Enter Item Name : book
Enter Price : 300
Enter Quantity : 1

--------------------------------------------------------------------------

Do you want to continue?
 1.yes
 2.No
1

1. Add new item at last of list
2. Add item at start of list
3. Delete item from last of list
4. Delete item from start of list
5. Display List
Enter choice of operation : 5

        Name    Price   Quantity
------------------------------------------
1.      bag     200      3
2.      cap     100      2
3.      book    300      1

--------------------------------------------------------------------------
*/
