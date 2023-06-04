/*
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 12= Design and implement a program for survey information of sports using principle of inclusion
and exclusion.
*/

#include<iostream>
#include<conio.h>
using namespace std;

class inclusion	    //Declaring class
{
    public:
    int x=0 ;	//declaring the variables for intersection of 2 sets
    int y=0;	// for intersection of 3 set
    
    void union_sets(int A[100],int B[100],int C[100], int na, int nb, int nc, int i); //declaring member function defined outside class
    
	int intersection_2(int A[100],int B[100],int na,int nb)	
    {
       int i,j ;
       for(i=0;i<na;i++)
      
        for(j=0;j<nb;j++)               //intersection of 2 sets
        {
            if(A[i] == B[j])      // checking common elements in  array A and B
            
            {
                cout<< A[i]<<" ";        //printing common elements 
                x++;					// incrementing for checking next element
            }
        }
    
	}

	int intersection_3(int A[100],int B[100],int C[100],int na,int nb,int nc)
	{
		 int i,j,k;
		 for(i=0;i<na;i++)		//intersection of 3 sets
		                                     
		    for(j=0;j<nb;j++)
		     { 
				for(k=0;k<nc;k++)
		        {
		        if(A[i]== B[j] && A[i]== C[k])      // checking common elements of A,B & C    
		            {
		                cout<< A[i] <<" ";        //printing common elements
		                y++;					// incrementing for checking next element
		        	}
		        }
			}
	}
};

void inclusion :: union_sets(int A[100],int B[100],int C[100], int na, int nb, int nc, int i)   //union of A,B & C
{
	    cout<<" \nStudents playing football are ";                                   
	    for(i=0;i<na;i++)
	    {
	        cout <<A[i]<<",";           //printing elements of A
	    }
	    
	    cout<<" \nStudents playing cricket are ";
        for(i=0;i<nb;i++)
        { 
	     	cout <<B[i]<<",";      //printing elements of B
        }
        
        cout<<" \nStudents playing volleyball are ";
        for(i=0;i<nc;i++)       
		{
		    cout<<C[i]<<",";             // printing elements of C
		}

}

int main()
{
	
    int i, na, nb, nc, A[100], B[100], C[100],total ;
    inclusion a,b,c;	//creating object of type inclusion
    
    cout<<" This is games popularity finding portal which will give you information about popularity of games among students in this class "<<endl;
	cout<<" \nStudents in this class play football, cricket, volleyball"<<endl;
    cout<<" \nKindly enter the correct information to find popularity of the games"<<endl;
    
    cout<<"\n*******************************************************************************";
    cout<<"\nEnter total no. of students who play football: "; 
	cin>>na;														//Taking size 
    cout<<"\nEnter id of students who play football: "<<endl;
    
	for(i=0;i<na;i++)
    {
    	cout<<"Student no "<<i+1<<" id : \n";
        cin>> A[i];
    }
    
    cout<<"\n*******************************************************************************";
    cout<<"\nEnter total no. of students who play cricket: "; 
	cin>>nb;
    cout<<"\nEnter id of students who play cricket: "<<endl;
    
	for(i=0;i<nb;i++)
    {
        cout<<"Student no "<<i+1<<" id : \n";
		cin>> B[i];
    }
    
    cout<<"\n*******************************************************************************";
	cout<<"\nEnter total no. of students who play volleyball: "; 
	cin>>nc;
    cout<<"\nEnter id of students who play volleyball: "<<endl;
    
    for(i=0;i<nc;i++)
    {
        cout<<"Student no "<<i+1<<" id : \n";
		cin>> C[i];
    }
    cout<<"\n*******************************************************************************";
    
int ch;
int start=1;
while(start==1)
  {
    
    cout<<"\n1.Union of students ";
    cout<<"\n2.Students who play football & cricket";
    cout<<"\n3.Students who play cricket & volleyball ";
    cout<<"\n4.Students who play football & volleyball";
    cout<<"\n5.Students who play all the games";
    cout<<"\n6.Total no. of students who play \n";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
		{
		
		 case 1 :   
		   cout<<"Students who play minimum one game: ";
	       a.union_sets( A, B, C, na,nb,nc, i);
	       break;
	     
		 case 2 :  
		   cout<<"\n Students who play football & cricket: ";
	       a.intersection_2( A, B,na,nb);
	       break;
	     
		 case 3 :  
		   cout<<"\n Students who play cricket & volleyball: ";
	       b.intersection_2( B,C, nb,nc);
	       break;
	     
		 case 4 :  
		   cout<<"\n Students who play football & volleyball: ";
	       c.intersection_2( C,A ,nc,na);
	       break;
	     
		 case 5 :  
		   cout<<"\n Students who play all the games: ";
	       a.intersection_3( A, B, C,na,nb,nc);
	       break;
	     
		 case 6 :  
		   total= na+nb+nc-(a.x+b.x+c.x)+a.y;
	       cout<<endl<<"The total no. of students in class are: "<<total;
	       break;
	     
		 default :
		   cout<<"Please try again...";
		   break;  
	    }
	
	
	int p,q,r,total= na+nb+nc-(a.x+b.x+c.x)+a.y;
	p=(na*100)/total;
	q=(nb*100)/total;
	r=(nc*100)/total;
	
	if(na >= nb && na >= nc)
	{
		cout<<"\n\n"<< p<<"% of student like football";
		cout<<"\nFootball is most popular game";
	}
	
	if(nb >= na && nb >= nc)
	{
		cout<<"\n\n"<< q <<"% of student like cricket";
		cout<<"\ncricket is most popular game";
	}
	
	if(nc >= nb && nc >= na)
	{
		cout<<"\n\n"<< r <<"% of student like volleyball";
		cout<<"\nVolleyball is most popular game";
	}
	
    cout<<"\n\nTYPE 1 TO CONTINUE \n";
    cout<<"TYPE d TO EXIT ";
	cin>>start;  
   }
	return 0;
}

/*
OUTPUT

This is games popularity finding portal which will give you information about popularity of games among students in this class

Students in this class play football, cricket, volleyball

Kindly enter the correct information to find popularity of the games

*******************************************************************************
Enter total no. of students who play football: 3

Enter id of students who play football:
Student no 1 id :
2
Student no 2 id :
3
Student no 3 id :
4

*******************************************************************************
Enter total no. of students who play cricket: 4

Enter id of students who play cricket:
Student no 1 id :
5
Student no 2 id :
2
Student no 3 id :
3
Student no 4 id :
1

*******************************************************************************
Enter total no. of students who play volleyball: 5

Enter id of students who play volleyball:
Student no 1 id :
2
Student no 2 id :
6
Student no 3 id :
8
Student no 4 id :
9
Student no 5 id :
4

*******************************************************************************
1.Union of students
2.Students who play football & cricket
3.Students who play cricket & volleyball
4.Students who play football & volleyball
5.Students who play all the games
6.Total no. of students who play

Enter your choice: 1
Students who play minimum one game:
Students playing football are 2,3,4,
Students playing cricket are 5,2,3,1,
Students playing volleyball are 2,6,8,9,4,

41% of student like volleyball
Volleyball is most popular game

TYPE 1 TO CONTINUE
TYPE d TO EXIT 1

1.Union of students
2.Students who play football & cricket
3.Students who play cricket & volleyball
4.Students who play football & volleyball
5.Students who play all the games
6.Total no. of students who play

Enter your choice: 2

 Students who play football & cricket: 2 3

50% of student like volleyball
Volleyball is most popular game

TYPE 1 TO CONTINUE
TYPE d TO EXIT 1

1.Union of students
2.Students who play football & cricket
3.Students who play cricket & volleyball
4.Students who play football & volleyball
5.Students who play all the games
6.Total no. of students who play

Enter your choice: 3

 Students who play cricket & volleyball: 2

55% of student like volleyball
Volleyball is most popular game

TYPE 1 TO CONTINUE
TYPE d TO EXIT 1

1.Union of students
2.Students who play football & cricket
3.Students who play cricket & volleyball
4.Students who play football & volleyball
5.Students who play all the games
6.Total no. of students who play

Enter your choice: 4

 Students who play football & volleyball: 2 4

71% of student like volleyball
Volleyball is most popular game

TYPE 1 TO CONTINUE
TYPE d TO EXIT 1

1.Union of students
2.Students who play football & cricket
3.Students who play cricket & volleyball
4.Students who play football & volleyball
5.Students who play all the games
6.Total no. of students who play

Enter your choice: 5

 Students who play all the games: 2

62% of student like volleyball
Volleyball is most popular game

TYPE 1 TO CONTINUE
TYPE d TO EXIT 1

1.Union of students
2.Students who play football & cricket
3.Students who play cricket & volleyball
4.Students who play football & volleyball
5.Students who play all the games
6.Total no. of students who play

Enter your choice: 6

The total no. of students in class are: 8

62% of student like volleyball
Volleyball is most popular game

*/

