/*
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 02= Design and implement a program for sparse matrix operations
*/
#include<iostream>
using namespace std;

class sparsematrix
{
	const static int MAX=10; 	//Declaring max size
	int data[MAX][3],len;
	
	public:
		sparsematrix(int r,int c,int l) //Declaring parameterised constructor
		{								//Automatically called ,when object is created
		data[0][0]=r;	//No of rows
		data[0][1]=c;	//No of column
		data[0][2]=l; 	//No of non zero elements
		len=0;			//Declaring temp variable
		}
void insert(int r,int c,int val)	//Declaring insert function
{
	if(r > data[0][0] || c > data[0][1])	//This r & c are different from earlier r & c
	{
	cout<<"\n\n ERROR!!! ";
	}
	else
		data[len+1][0]=r; 		//storing row number
		data[len+1][1]=c;		//storing col number
		data[len+1][2]=val; 	//storing value 
		len++;					//len will increment by 1 untill if statement case is false.
}

void print()	//Declaring print function
{
	int i;
	cout<<"\n Dimension->"<<data[0][0]<<"x"<<data[0][1]<<"\n";
	cout<<"\nSparse Matrix \nRow\t Column\t Value\n";
	
	for(i=0;i<=len;i++)
	{
	cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<endl;
	}
}
void transpose(sparsematrix a)	//Declaring Transpose function for MULTIPLICATION purpose
{
	sparsematrix t(data[0][1],data[0][0],data[0][2]);  //storing in object of matrix t
	if(len>0)
	{
	for(int i=0;i<data[0][1];i++)
		{for(int j=1;j<=len;j++)
			
			{if(data[j][1]==i)
					
				t.len++;
				t.data[t.len][0]=data[j][1];	//Interchanging rows by column
				t.data[t.len][1]=data[j][0];
				t.data[t.len][2]=data[j][2];
			}
		}
	}
a.multiply(t);	//calling multiply function & accesssing matrix a
}

void transpose()
{
	sparsematrix t(data[0][1],data[0][0],data[0][2]);
	
	if(len>0) //checking whether matrix is empty or not
	{
		for(int i=0;i<data[0][1];i++)	//traversing in colm
		{
			for(int j=1;j<=len ;j++) //traversing in row
			{
				if(data[j][1]==i)	//for arranging elements in sorted order
				{
				t.len++;					// t is new matrix after transpose
				t.data[t.len][0]=data[j][1];  //storing new elements in new sparse matrix
				t.data[t.len][1]=data[j][0];
				t.data[t.len][2]=data[j][2];
				}
			}
		}
	}
t.print();		//calling print function
}

void add(sparsematrix b)
{
	int apos=1;
	int bpos=1;
	sparsematrix result(data[0][0],data[0][1],0);

	if(data[0][0]!=b.data[0][0] || data[0][1]!=b.data[0][1])
	{
	cout<<"\n\n MATRICES CANNOT BE ADDED! \n";
	}
	
	else
	{
		while(apos<=len && bpos<=b.len) //when apos & bpos is less than non zero element
		{
			//IF row no & col no are not equal then it will store that non zero no as it is in result matrix
			
			if(data[apos][0]>b.data[bpos][0] ||(data[apos][0]==b.data[bpos][0] && data[apos][1]>b.data[bpos][1]))
			{
				result.insert(b.data[bpos][0],b.data[bpos][1],b.data[bpos][2]); //storing in result matrix
				bpos++;
			} 
			
			else if(data[apos][0]<b.data[bpos][0] || (data[apos][0]==b.data[bpos][0] && data[apos][1]<b.data[bpos][1]))
			{
				result.insert(data[apos][0],data[apos][1],data[apos][2]);
				apos++;
			} 
			
			else
			{
				int addedval=data[apos][2]+b.data[bpos][2]; //adding non zero value
				if(addedval!=0) 
				result.insert(data[apos][0],data[apos][1],addedval);
				apos++;
				bpos++;
			}
		}
	}
result.data[0][2]=result.len; 	//putting total number of values in 0th row & 2nd col
result.print();
}

void multiply(sparsematrix t)
{
	int sum,t1,t2, t3=1;
	sparsematrix mresult(data[0][0],t.data[0][1],0);	//declaring object of type sparsematrix
	
	for(int i=0;i<data[0][0];i++)
	{
		for(int j=0;j<t.data[0][1];j++)
		{
			sum = 0;
			t1 = 1;
			t2 = 1;
			int flag1 = 0;	//initialising temporary variable
			int flag2 = 0;
			
			while(t1<=data[0][2])
			{
				if(data[t1][0] == i)
				{
					flag1 = 1; 
					break;
				}
				
				t1++;
			}
			while(t2<=t.data[0][2])
			{
				if(t.data[t2][0] == j)
				{
					flag2 = 1;
					break;
				}
				t2++;
			}
			if(flag1 == 1 && flag2 == 1)	
			{
				while(data[t1][0]==i && t.data[t2][0]==j)
				{
						if(data[t1][1] == t.data[t2][1])
						{
							sum = sum + data[t1][2] * t.data[t2][2]; 
							t1++;
							t2++;
						}
						else if(data[t1][1]< t.data[t2][1])
						{
							t1++;
						}
						else
						{
							t2++;
						}
				}
				if(sum>0)
				{
					mresult.insert(data[t3][0],t.data[t3][1],sum); 
					t3++;
				}
			}
		}
	}
	mresult.data[0][2] = t3-1; //puting number of total values in 0th row 2nd col
	mresult.print();			//calling print function
	}
};

int main()
{
	int r,c,l,val,i,choice;
	
	cout<<"\n Enter No of Rows of Sparse Matrix 1 -> "; 
	cin>>r;
	cout<<"\n Enter No of Column of Sparse Matrix 1 -> "; 
	cin>>c;
	cout<<"\n Enter No of Non-Zeros elements in Sparse Matrix 1 -> "; 
	cin>>l;
	
	sparsematrix a(r,c,l);	//Creating a object "a" for sparse matrix 1
	
	for(i=0;i<l;i++)	//for loop run till number of non zero elements
	{
		cout<<"\n Enter Row no ->";
		cin>>r;
		cout<<"\nEnter column no ->";
		cin>>c;
		cout<<"\nEnter the value ->";
		cin>>val;
		a.insert(r,c,val); 		//Access insert function and store the values in object of matrix a
	}
	
	cout<<"\n\nSparse Matrix 1 - ";
	a.print();
	
	cout<<"\n Enter the No of Rows of Sparse Matrix 2-> ";
	cin>>r;
	cout<<"\n Enter No of Column of Sparse Matrix 2 ->";
	cin>>c;
	cout<<"\n Enter No of Non-Zeros elements in Sparse Matrix 2-> ";
	cin>>l;
	
	sparsematrix b(r,c,l);	//Creating a object "b" for sparse matrix 2
	
	for(i=0;i<l;i++)
	{
		cout<<"\nEnter Row no -> "; cin>>r;
		cout<<"\nEnter column no -> "; cin>>c;
		cout<<"\nEnter the value -> "; cin>>val;
		b.insert(r,c,val);
	}
	
	cout<<"\nSparse Matrix 2 \n";
	b.print();
	
do	// Do while loop
{
	cout<<endl;
	cout<<"\nEnter your Choice ! "<<" ";
	cout<<"\n 1-> Addition of Sparse Matrix ";
	cout<<"\n 2 ->Transpose of Sparse Matrix ";
	cout<<"\n 3 ->Multiplication of Sparse Matrix "; 
	cout<<"\n 4 ->EXIT ";
	cout<<"\nYour choice is: \n";
	cin>>choice;

	switch(choice)	//For menu driven program
	{
		case 1: 	//(Case for addition)
		
		cout<<"\nAddition of Sparse Matrix 1 & 2 ->"<<endl;
		a.add(b);
		break;
		
		
		case 2: // (case for Transpose)
		
		cout<<"\nTranspose of Sparse Matrix 1 ->"<<endl;
		a.transpose();
		cout<<endl;
		cout<<"\nTranspose of Sparse Matrix 2 ->"<<endl;
		b.transpose();
		cout<<endl;
		break;
		
		case 3:		// (case for multiplication)
		
		cout<<"\nMultiplication of Sparse Matrix 1 & 2 ->"<<endl; 
		b.transpose(a);		//calling transpose function & accessing with matrix b
		break; 
		
		case 4:
			cout<<"\nYou EXIT the program \nThank you !!";
			break;
		
		default:
		cout<<"\n\nError";	// Error if choice is >3
	}
}
while(choice!=4);
return 0;
}

/*
OUTPUT

Enter No of Rows of Sparse Matrix 1 -> 3

 Enter No of Column of Sparse Matrix 1 -> 3

 Enter No of Non-Zeros elements in Sparse Matrix 1 -> 3

 Enter Row no ->1

Enter column no ->2

Enter the value ->3

 Enter Row no ->2

Enter column no ->1

Enter the value ->6

 Enter Row no ->3

Enter column no ->2

Enter the value ->4


Sparse Matrix 1 -
 Dimension->3x3

Sparse Matrix
Row      Column  Value
3       3       3
1       2       3
2       1       6
3       2       4

 Enter the No of Rows of Sparse Matrix 2-> 3

 Enter No of Column of Sparse Matrix 2 ->3

 Enter No of Non-Zeros elements in Sparse Matrix 2-> 3

Enter Row no -> 1

Enter column no -> 2

Enter the value -> 8

Enter Row no -> 2

Enter column no -> 1

Enter the value -> 9

Enter Row no -> 3

Enter column no -> 2

Enter the value -> 5

Sparse Matrix 2

 Dimension->3x3

Sparse Matrix
Row      Column  Value
3       3       3
1       2       8
2       1       9
3       2       5


Enter your Choice !
 1-> Addition of Sparse Matrix
 2 ->Transpose of Sparse Matrix
 3 ->Multiplication of Sparse Matrix
Your choice is:
1

Addition of Sparse Matrix 1 & 2 ->

 Dimension->3x3

Sparse Matrix
Row      Column  Value
3       3       3
1       2       11
2       1       15
3       2       9


Enter your Choice !
 1-> Addition of Sparse Matrix
 2 ->Transpose of Sparse Matrix
 3 ->Multiplication of Sparse Matrix
Your choice is:
2

Transpose of Sparse Matrix 1 ->

 Dimension->3x3

Sparse Matrix
Row      Column  Value
3       3       3
1       2       6
2       1       3
2       3       4


Transpose of Sparse Matrix 2 ->

 Dimension->3x3

Sparse Matrix
Row      Column  Value
3       3       3
1       2       9
2       1       8
2       3       5



Enter your Choice !
 1-> Addition of Sparse Matrix
 2 ->Transpose of Sparse Matrix
 3 ->Multiplication of Sparse Matrix
Your choice is:
3

Multiplication of Sparse Matrix 1 & 2 ->

 Dimension->3x1

Sparse Matrix
Row      Column  Value
3       1       0


*/


