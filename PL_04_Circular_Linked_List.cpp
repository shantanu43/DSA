/*
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 4= Design and develop program for polynomial addition, multiplication operations for disease
information using circular linked list
*/

#include<iostream>
#include<string>
using namespace std;

class node
{
   public:
          
		int patients;
        int day;
        node *next;
          
};

class rate
{
        node *head;
       
	    public:
        
		rate()
        {
          head = NULL;
        }
		
		void create();
		void display();
		void add(rate p1, rate p2);
		void sorted_create(node *temp);
		void multiply(rate p1,rate p2);
};

void rate::create()
{
  int choice;
  
  node *temp = NULL;
  node *p    = NULL;
  
  do
    {
      temp = new(node);
      
      cout<<"\nEnter number of patients: ";
      cin>>temp->patients;
      
      cout<<"Enter day number: ";
      cin>>temp->day;
      
      if(head == NULL)
      {
         head = temp;
         temp->next = head;
         p = head;
      }
      else
       {
	        while(p->next != head) //pointer p will traverse
	        {
	           p = p->next;
	        }
	        
	        p->next = temp;
	        temp->next = head;
	        p = temp;
    	}
     
	 cout<<"\nPress 1 to continue: ";
	 cout<<"\nAny key to exit ";
	 cout<<"\nYour input is : ";
     cin>>choice;
	
	}while(choice == 1);

}

void rate::display()
{
   node *p = NULL;
   p= head;
   
   do
   {
     cout<<p->patients<<"X^"<<p->day<<" + ";
     p= p->next;
   }
   while(p->next != head);
   
   cout<<p->patients<<"X^"<<p->day<<" = 0";
}

void rate::sorted_create(node *temp)	// t3 is passed as temp pointer as a parameter
{										// temp= t3
   node *p;

   if(head == NULL)
   
      head = temp;
      
   else
   {
      if(temp->day >head->day)
     {
        temp->next =head;
        p=head;
        
        while(p->next != head)
        {
          p = p->next;
        }
        p->next = temp;
        head = temp;
      }
      else
      {
         if(temp->day == head->day)	//if exponenet are same then we are adding the coefficient
         {
            head->patients += temp->patients;
         }
         
         else
         {
          p=head;
          int f=1;
          
          while(1)
          {
	            if(p->day == temp->day)
	            {
	              p->patients += temp->patients;
	              f = 2;
	               break;
	            }
	            
	            else if(p->day < temp->day || p->next == head)
	             {
	               f = 1;
	                break;
	             }
	             p = p->next;
          }
            if (f==1)
            {
               temp->next = p->next;
               p->next = temp;
            }
        }
      }
   }
}

void rate::add(rate p1, rate p2)  //d1 & d2 are replaced by p1 & p2
{
   node *t1, *t2, *t3;
   head = NULL;
   t1 = p1.head;		//t1 & t2 are polynomial pointing to head of the polynomial P1 & P2
   t2 = p2.head;
   
   if(p1.head == NULL && p2.head == NULL)
   {
      cout<<"Polynomial Lists are empty";
      return;
   }
   
   do
   {
     t3 = new node;					//t3 is new node where resulting polynomial will be stored
     t3->patients = t2->patients;
     t3->day = t2->day;
     
	 t3->next = t3;		//As it is a CLL we ll connect t3 next with start of the node
     sorted_create(t3);
     t2 = t2->next;
     
    }while(t2 != p2.head);
    
   do
   {
     t3 = new node;
     t3->patients = t1->patients;
     t3->day = t1->day;
     
	 t3->next = t3;
     sorted_create(t3);
     t1 = t1->next;
     
   }while(t1 != p1.head);

    display();
    
}


void rate::multiply(rate p1, rate p2)
{
   node *t1, *t2;
   node *t3;
   head = NULL;
   
   t1 = p1.head;
   t2 = p2.head;
   
   if(p1.head == NULL && p2.head == NULL)
   {
     cout<<"Polynomial Lists are empty";
    return;
   }
   
   do
   {
     t2 = p2.head;
     do
	 {
         t3 = new node;
         t3->patients = t1->patients * t2->patients;
         t3->day = t1->day + t2->day;
         t3->next = t3;
         sorted_create(t3);
         t2 = t2->next;
     }while(t2 != p2.head);
    t1 = t1->next;
    
	}
	while(t1 != p1.head);
    display();
}

int main()
{
   rate d1,d2,d3,d4;
   
   cout<<"Enter data of sector 1 : ";
   d1.create();
   
   cout<<"\nEnter data of sector 2 : ";
   d2.create();
   
   cout<<"\nDisease infection rate in sector 1 is: ";
   d1.display();
   
   cout<<"\nDisease infection rate in sector 2 is: ";
   d2.display();
   
   cout<<"\nThe Addition of infection rate is: ";
   d3.add(d1,d2);
   
   cout<<"\nThe multiplication of infection rate is: ";
   d4.multiply(d1,d2);
   
   return 0;
}

/*

Enter data of sector 1 :
Enter number of patients: 3
Enter day number: 2

Press 1 to continue:
Any key to exit
Your input is : 1

Enter number of patients: 2
Enter day number: 4

Press 1 to continue:
Any key to exit
Your input is : 1

Enter number of patients: 6
Enter day number: 3

Press 1 to continue:
Any key to exit
Your input is : 5

Enter data of sector 2 :
Enter number of patients: 2
Enter day number: 4

Press 1 to continue:
Any key to exit
Your input is : 1

Enter number of patients: 3
Enter day number: 5

Press 1 to continue:
Any key to exit
Your input is : 5

Disease infection rate in sector 1 is: 3X^2 + 2X^4 + 6X^3 = 0
Disease infection rate in sector 2 is: 2X^4 + 3X^5 = 0
The Addition of infection rate is: 3X^5 + 4X^4 + 3X^2 + 6X^3 = 0
The multiplication of infection rate is: 6X^9 + 22X^8 + 21X^7 + 6X^6 = 0

*/
