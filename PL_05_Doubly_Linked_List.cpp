/**************************************************************************************************************
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 05 = Design and implement a program for sorting two given lists and merging these two sorted lists of
marks scored for technical skill examination of recruitment cell using doubly linked list.

**************************************************************************************************************/

#include<iostream>
using namespace std;

class node
{
	public:
	int roll_No;
	float marks;
	node *prev, *next;
};

class marks_list
{
	public:
	node *head;
	int length;
	
	marks_list()
	{
	head=NULL;
	length=0;
	}
	
	void create();
	void display();
	void sort();
	void merge(marks_list l1, marks_list l2);	

};

void marks_list :: create()
{
	int size,roll_No;
	float marks;
	node *curr;
	
	cout<<"Enter size of batch: ";
	cin>> size;
	length= size;
	
	for(int i=0; i<size; i++)
	{
		cout<<"Enter Roll No of Student "<<i+1<<" : ";
		cin>>roll_No;
		
		cout<<"Enter Marks of Student "<<i+1<<" : ";
		cin>>marks;
		
		node *new_node = new node;			//creating new node
		new_node->roll_No =roll_No;			//inserting values
		new_node->marks =marks;
		
		new_node->prev =NULL;
		new_node->next =NULL;
		
		if(head==NULL)
		{
			head=new_node;
			curr=new_node;
		}
		else
		{
			curr ->next = new_node;
			new_node ->prev = curr;
			curr = new_node;
		}
	}
}

void marks_list :: display()
{
	node *temp = head;
	
	while(temp!=NULL)
	{
		cout<<"Roll No: "<<temp -> roll_No <<endl;
		cout<<"Marks: "<<temp -> marks <<endl;
		temp = temp->next;
	}
}

void marks_list :: sort()		//bubble sort
{
	node *h, *temp, *p1,*p2;
	int i,j;
	
	for(i=0;i<length;i++)
	{
		h = head;
		
		while(h->next!= NULL)
		{
			
			if(h->marks < h->next->marks)
			{
				p1=h;
				p2=h->next;
				temp= p2->next;
				
				if(p1->prev!=NULL)
				{
					p1->prev->next=p2;
				}
				else
				{
					head=p2;
				}
				p2->next=p1;
				p2->prev=p1->prev;
				p1->next=temp;
				p1->prev=p2;
				
				if(temp!=NULL)
				{
					temp->prev=p1;
				}
				h=p2;
			}
			h=h->next;
		}
		
	}
}

void marks_list :: merge( marks_list l1, marks_list l2)
{
	node*p = l1.head;
	node*q = l2.head;
	length = l1.length + l2.length;
	node*r = NULL;
	
	if(p == NULL)
	{
		head=q;
	}
	
	else if(q == NULL)
	{
		head = p;
	}
	
	else if(p!= NULL && q!= NULL)	//if both list are not empty
	{
		if(p->marks < q->marks)
		{
			r = p;
			p = p->next;
		}
		else
		{
			r = q;
			q = q->next;
		}
		head=r;
	}
	
	while(p!=NULL && q!=NULL)
	{
		if(p->marks <= q->marks)
		{
			r->next=p;
			p->prev=r;
			r=p;
			p=p->next;
		}
		else if(p->marks > q->marks)
		{
			r->next=q;
			q->prev=r;
			r=q;
			q=q->next;
		}
	}

	if(p==NULL)
	{
	r->next=q;
	q->prev=r;
	}

	else if(q==NULL)
	{
	r->next=p;
	p->prev=r;
	}
	
}

int main()
{
	marks_list l1,l2,l3;
	
	cout<<"\nMarkslist 1: ";
	l1.create();
	l1.sort();
	
	cout<<"\nSorted Markslist 1 : \n";
	l1.display();
	
	cout<<"\nMarkslist 2: ";
	l2.create();
	l2.sort();
	
	cout<<"\nSorted Markslist 2: \n";
	l2.display();
	
	l3.merge(l1,l2);
	l3.sort();
	
	cout<<"----------------------------------------------------------------";
	cout<<"\nFinal sorted list after Merging two sorted lists- \n\n";
	l3.display();
	cout<<"----------------------------------------------------------------";
}

//output
/*

Markslist 1: Enter size of batch: 3
Enter Roll No of Student 1 : 3
Enter Marks of Student 1 : 2
Enter Roll No of Student 2 : 5
Enter Marks of Student 2 : 4
Enter Roll No of Student 3 : 6
Enter Marks of Student 3 : 1

Sorted Markslist 1 :
Roll No: 5
Marks: 4
Roll No: 3
Marks: 2
Roll No: 6
Marks: 1

Markslist 2: Enter size of batch: 3
Enter Roll No of Student 1 : 4
Enter Marks of Student 1 : 5
Enter Roll No of Student 2 : 9
Enter Marks of Student 2 : 6
Enter Roll No of Student 3 : 8
Enter Marks of Student 3 : 4

Sorted Markslist 2:
Roll No: 9
Marks: 6
Roll No: 4
Marks: 5
Roll No: 8
Marks: 4
----------------------------------------------------------------
Final sorted list after Merging two sorted lists-

Roll No: 9
Marks: 6
Roll No: 4
Marks: 5
Roll No: 5
Marks: 4
Roll No: 8
Marks: 4
Roll No: 3
Marks: 2
Roll No: 6
Marks: 1
----------------------------------------------------------------
--------------------------------
*/
