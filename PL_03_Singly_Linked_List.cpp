/************
Name-= Shantanu Hemantrao Chaudhari
Roll No= 86
Div= B1
Practical 03= Design and develop program for insertion, up-dating, searching, sorting, listing and deletion
operations using singly linked list for placement information system.
*************/

#include <iostream>
using namespace std;

class node
{
	public:
		int stud_no ,id;
		float cgpa;
		long long pkg;
		string stud_name,company,branch;
		node *next;
};
class stud
{
	public:
		node* head;
    
		float cgpa;
		long long pkg;
		int len,pos,stud_no ,old_carno;
		string stud_name,company,branch;
		
		stud()   // Default constructor 
		{
			head=NULL;
			len=0;		//temporary variable and it is counting total no of node created/deleted
		}
        
		// Member function declaration 
		void create();
		void display();
		void insert(int pos,int no,string name ,string stud_company,string branch,float stud_cgpa,long long stud_pkg);
		void search(int pos);
		void del(int pos);
		void update(int pos,int no,string name ,string stud_company,string branch,float stud_cgpa,long long stud_pkg);
		void sort();
};

void stud::create()		//first we make node= temp then connect it with node ppointer
{
	char c;
	node* pointer;
	
	do
	{
		node *temp=new node;	// create new node 
		          
	    cout<<"enter the student no : ";
		cin>>temp-> stud_no ;
		
		cout<<"enter the student name: ";
		cin>>temp->stud_name;
		
		cout<<"enter the student company : ";
		cin>>temp->company;
		
		cout<<"enter the branch of the student: ";
		cin>>temp->branch;
		
		cout<<"enter the cgpa of the student: ";
		cin>>temp->cgpa;
		
		cout<<"enter the pkg of the student : ";
		cin>>temp->pkg;
		
		temp->next=NULL;
		
		if(head==NULL)	//checking if it is 1st node or not
		{
			head=temp;	//for creating 1st node we are making head= temp
		}
		else	// NOW here head is not NULL because now head is temp hence it is not 1st node
		{
			pointer=head;	// making pointer as a head
			
			while(pointer->next!=NULL)
			{
				pointer=pointer->next;
			}
			pointer->next=temp;			
			
		}
		len++;	//counting number of nodes
		cout<<"\nDo you want to add more student details ? : ";
		cout<<"\nPress 'y' if yess & anyother for no : ";
		cin>>c;
		cout<<"\n";
		
	}while(c=='y');
	cout<<"Total no of student details are : "<<len<<endl;
	
}

void stud::display()       // display
{
	node *ptr;
	ptr=head;	//starting from ptr
	
	cout<<" Student details are as folllows"<<endl;
	while(ptr!=NULL)
	{
    cout<<"\n\nstudent no--->"<<ptr->stud_no <<endl;
    cout<<"student name--->"<<ptr->stud_name<<endl;
    cout<<"student company--->"<<ptr->company<<endl;
    cout<<"student branch--->"<<ptr->branch<<endl;
    cout<<"student pkg--->"<<ptr->pkg<<endl;
    cout<<"student cgpa--->"<<ptr->cgpa<<endl;
    ptr=ptr->next;
	}
}
void stud::insert(int pos,int no,string name ,string stud_company,string br,float stud_cgpa,long long stud_pkg)
{
	node *New,*ptr;
	New= new node;
	if(pos==1)       // insert at the start 
	{
		New-> stud_no =no;
		New->stud_name=name;
		New->company=stud_company;
		New->branch=br;
		New->cgpa=stud_cgpa;
		New->pkg=stud_pkg;
		
		New->next=head;		//connecting New node to start of linked list
		head= New;			//Making head to new
		len++;				//counting number of nodes
	}
	
	else if(pos>len)            // insert at the end 
	{	
		New-> stud_no =no;
		New->stud_name=name;
		New->company=stud_company;
		New->branch=br;
		New->cgpa=stud_cgpa;
		New->pkg=stud_pkg;
	
		ptr=head;		//Allocating ptr pointer to head
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next= New;
		len++;
	
	}
	else                 // insert at the middle 
	{
		New-> stud_no =no;
		New->stud_name=name;
		New->company=stud_company;
		New->branch=br;
		New->cgpa=stud_cgpa;
		New->pkg=stud_pkg;
		
	    ptr=head;
		
		for(int i=1;i<(pos-1);i++)
		{
			ptr=ptr->next;
			
		}
		
		New->next = ptr->next;
		ptr->next= New;
		len++;
		
	}
}
void stud::del(int pos)       // deletion by position
{
	node*temp=head;
	
	if(pos==1)            // deletion  at the start
	{
		if(head==NULL)
		{
		   	cout<<"List is empty !!!\n";
		
		}
		else if(temp==head)
		{
		    head=head->next;
	        delete temp;
	       
	        len--;
	    }
	
	}
	
	else if(pos==len)        // deletion at the end 
	{
	      node *temp,*prev;
	      temp=head;		//starting from head
	     
		  while(temp->next!=NULL)
	      {
	      	prev=temp;
	      	temp=temp->next;
		  }
		  if(temp==head)
		  {
		    head=NULL;
	     	delete temp;
		  }
		  else
		  {
		  	prev->next=NULL;
		  	delete temp;
		  }
		  
		  len--;
	}
	else                     // deletion at the middle
	{
		node *nextnode;
		temp=head;
	
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		nextnode=temp->next;
		temp->next=nextnode->next;	//linking nodes after deletion
		
		delete nextnode;
		len--;
		
	}
}
void stud::update(int pos,int no,string name ,string stud_company,string br,float stud_cgpa,long long stud_pkg)  
{
	node *temp,*ptr;
	ptr=head;
	
	while(ptr!=NULL)
	{
		if(ptr->stud_no ==pos)
		{
			ptr-> stud_no =no;
		    ptr->stud_name=name;
	    	ptr->company=company;
	    	ptr->branch=br;
	    	ptr->cgpa=stud_cgpa;
	    	ptr->pkg=pkg;
	    	
	    	break;
		}
		else
		{
			ptr=ptr->next;
		}

	}
}

void stud::search(int no)   // search
{
	node *ptr;
	int n=0;
	ptr=head;
	
	while(ptr!=NULL)
	{
		if(ptr-> stud_no ==no)       // search by info
		{
			cout<<"student details are present in the list \n ";
			n++;
			break;
		}
		else
		{
			ptr=ptr->next;
		}
	}
	if(n==0)
	{
		cout<<" student details are not found \n";
	}
}

void stud::sort()      // sorting 
{
	node *curr,*prev;
	int temp;
	long long stud_pkg;
	float cgpa;
	string stud_company,stud_branch,name;
	
	for(int i=0;i<len;i++)
	{
		prev=head;
		curr=head->next;
		while(curr!=NULL)
		{
			if(curr->cgpa < prev->cgpa)  // sorting by cgpa of the student
			{
				temp=curr-> stud_no ;
				curr-> stud_no =prev->stud_no ;
				prev-> stud_no =temp;
				
				name=curr->stud_name;
				curr->stud_name=prev->stud_name;
				prev->stud_name=name;
				
				stud_company=curr->company;
				curr->company=prev->company;
				prev->company=stud_company;
				
	
				stud_branch=curr->branch;
				curr->branch=prev->branch;
				prev->branch=stud_branch;

				cgpa=curr->cgpa;
				curr->cgpa=prev->cgpa;
				prev->cgpa=cgpa;
				
				stud_pkg=curr->pkg;
				curr->pkg=prev->pkg;
				prev->pkg=stud_pkg;
				
				prev=curr;
				curr=curr->next;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
	}
}

int main()
{
	int pos,id,choice,begin=1,old_id,no;
	string name, stud_company, br;
	float stud_cgpa;
	long long stud_pkg;
	stud s1;	// s1 is object of class stud
	
	cout<<"\n**  Student Placement information details  ***\n";
	cout<<"\n";
	cout<<"Create ---> 1 \nDisplay ---> 2 \nInsertion ---> 3 \nUpdate ---> 4 \nDetete ---> 5 \nSearch ---> 6\nSort ---> 7\n";
	cout<<"\n";
	
    while(begin==1)
	{
		cout<<"Enter your choice of operation : ";
	    cin>>choice;
	    
		switch(choice)
		{
			
			case 1:  // create 
				{
					s1.create();
				    s1.display();  
	                cout<<"\n\n";
				}
				break;
			case 2:
				{
					s1.display();  
	                cout<<"\n\n";
				}
				break;
			case 3:  // insert 
				{   
				    cout<<"At what position you want to insert : ";
				    cin>>pos;
				    
	                cout<<"Enter student no: : ";
					cin>>no;
				    
					cout<<"Enter student name  : ";
				    cin>>name;
				    
					cout<<"Enter student company: ";
					cin>>stud_company;
				    
				    cout<<"Enter student branch: ";
				    cin>>br;
				    
				    cout<<"Enter student cgpa : ";
				    cin>>stud_cgpa;
				    
					cout<<"Enter student pkg ";
				    cin>>stud_pkg;
	
	                s1.insert(pos,no,name,stud_company,br,stud_cgpa,stud_pkg);
	               
	                s1.display();  
	                cout<<"\n\n";
	               
	                cout<<"\n Insersion is successfull !!! \n";
					
				}
				break;
				
			case 4:  // update
				{
			
					cout<<"Enter position of the student : ";
					cin>>pos;
					
	                cout<<"Enter the new student no: ";
					cin>>no;

					cout<<"Enter the student name : ";
				    cin>>name;
					
					cout<<"Enter the student company: ";
					cin>>stud_company;
					
					cout<<"Enter the student branch : ";
					cin>>br;
				    
				    cout<<"Enter the student pkg: ";
				    cin>>stud_pkg;
				    
				    cout<<"Enter the student cgpa : ";
				    cin>>stud_cgpa;
				  
	                s1.update(pos,no,name,stud_company,br,stud_cgpa,stud_pkg);
	                cout<<"\n Details has been updated successfully"<<endl;
	                
					s1.display();  
	                cout<<"\n\n";
	               
				}
				break;
				
			case 5:  // delete
				{
					cout<<"Enter position : ";
	                cin>>pos;
	                s1.del(pos);
	                cout<<"\n Details has been deleted successfully !!"<<endl;
	                s1.display();  
	                cout<<"\n\n";
	                
				}
				break;
				
			case 6:  // search
				{
					cout<<"Enter the student no: ";
	                cin>>no;
	
	                s1.search(no);
					
				}
				break;
				
			case 7:  // sorting
				{
					s1.sort();
				
	        		cout<<"---------the details have been sorted according to the cgpa of the student----------"<<endl;
	                s1.display();  
	                cout<<"\n\n";
				}
				break;
				
			default:
				cout<<"you have enterd the wrong choice"<<endl;

		}
		cout<<"enter 1 to continue"<<endl;
		cin>>begin;
		
	}	
	cout<<"thankyou !!";
	return 0;
}

/*
OUTPUT


**  Student Placement information details  ***

Create ---> 1
Display ---> 2
Insertion ---> 3
Update ---> 4
Detete ---> 5
Search ---> 6
Sort ---> 7

Enter your choice of operation : 1
enter the student no : 101
enter the student name: shantanu
enter the student company : TCS
enter the branch of the student: Comp
enter the cgpa of the student: 9
enter the pkg of the student : 12

Do you want to add more student details ? :
Press 'y' if yess & anyother for no : y

enter the student no : 102
enter the student name: vikas
enter the student company : Wipro
enter the branch of the student: Comp
enter the cgpa of the student: 9
enter the pkg of the student : 10

Do you want to add more student details ? :
Press 'y' if yess & anyother for no : y

enter the student no : 103
enter the student name: Bhavesh
enter the student company : Infosys
enter the branch of the student: Comp
enter the cgpa of the student: 9
enter the pkg of the student : 11

Do you want to add more student details ? :
Press 'y' if yess & anyother for no : n

Total no of student details are : 3
 Student details are as folllows


student no--->101
student name--->shantanu
student company--->TCS
student branch--->Comp
student pkg--->12
student cgpa--->9


student no--->102
student name--->vikas
student company--->Wipro
student branch--->Comp
student pkg--->10
student cgpa--->9


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


enter 1 to continue
1
Enter your choice of operation : 2
 Student details are as folllows


student no--->101
student name--->shantanu
student company--->TCS
student branch--->Comp
student pkg--->12
student cgpa--->9


student no--->102
student name--->vikas
student company--->Wipro
student branch--->Comp
student pkg--->10
student cgpa--->9


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


enter 1 to continue
1
Enter your choice of operation : 3
At what position you want to insert : 4
Enter student no: : 104
Enter student name  : kartik
Enter student company: Congnizent
Enter student branch: IT
Enter student cgpa : 8
Enter student pkg 11
 Student details are as folllows


student no--->101
student name--->shantanu
student company--->TCS
student branch--->Comp
student pkg--->12
student cgpa--->9


student no--->102
student name--->vikas
student company--->Wipro
student branch--->Comp
student pkg--->10
student cgpa--->9


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


student no--->4
student name--->kartik
student company--->Congnizent
student branch--->IT
student pkg--->11
student cgpa--->8



 Insersion is successfull !!!
enter 1 to continue
1
Enter your choice of operation : 4
Enter position of the student : 2
Enter the new student no: 105
Enter the student name : Chinmay
Enter the student company: Amazon
Enter the student branch : Comp
Enter the student pkg: 10
Enter the student cgpa : 9

 Details has been updated successfully
 Student details are as folllows


student no--->101
student name--->shantanu
student company--->TCS
student branch--->Comp
student pkg--->12
student cgpa--->9


student no--->102
student name--->vikas
student company--->Wipro
student branch--->Comp
student pkg--->10
student cgpa--->9


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


student no--->4
student name--->kartik
student company--->Congnizent
student branch--->IT
student pkg--->11
student cgpa--->8


enter 1 to continue
1
Enter your choice of operation : 5
Enter position : 1

 Details has been deleted successfully !!
 Student details are as folllows


student no--->102
student name--->vikas
student company--->Wipro
student branch--->Comp
student pkg--->10
student cgpa--->9


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


student no--->4
student name--->kartik
student company--->Congnizent
student branch--->IT
student pkg--->11
student cgpa--->8


enter 1 to continue
1
Enter your choice of operation : 5
Enter position : 1

 Details has been deleted successfully !!
 Student details are as folllows


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


student no--->4
student name--->kartik
student company--->Congnizent
student branch--->IT
student pkg--->11
student cgpa--->8


enter 1 to continue
1
Enter your choice of operation : 6
Enter the student no: 103
student details are present in the list
 enter 1 to continue
1
Enter your choice of operation : 7
---------the details have been sorted according to the cgpa of the student----------
 Student details are as folllows


student no--->4
student name--->kartik
student company--->Congnizent
student branch--->IT
student pkg--->11
student cgpa--->8


student no--->103
student name--->Bhavesh
student company--->Infosys
student branch--->Comp
student pkg--->11
student cgpa--->9


*/
