/******************************************************************************************************
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 06= Design and implement a menu driven program for expression conversion from infix to postfix,
			postfix to prefix expression and evaluation of postfix expression using stack.

******************************************************************************************************/


#include<iostream>  			
#include<string> 
#include<sstream> 
#include <stack>
#include <algorithm>

#define size 100 	//defining the size

using namespace std; 
class Stack				//Decaring class stack
{ 
    public: 
        string stack[size]; 
        int top;
        Stack()
        { 
            top = -1; 
        }
    bool Stack_full() 	
    { 
        if(top == size-1)   //Checking whether stack full or not
		return true; 
        else 
		return false; 
    } 
    bool Stack_empty()		
    { 
        if(top == -1) 		//If stack is empty then top will be equal to -1
		return true; 
        else 
		return false; 
    } 
    void push(string Str_1)   //function for pushing element into stack
    { 
        if(Stack_full()) 
        cout<<"Stack is full ";    
        else
        {
            top++; 
            stack[top] = Str_1; 
        }
    } 
    void push(char Str_1)
    { 
        if(Stack_full()) 
        cout<<"Stack is full "; 		
        else
        {
            top++; 
            stack[top] = Str_1; 
        }
    } 
    string pop()			//For deleting the element from stack
    { 
        string x = "Stack is empty "; 	//Showing stack is empty
        if(Stack_empty()) 
        { 
            top--; 
            return x; 
        } 
        else
        { 
            string Str_1 = stack[top]; 
            top--; 						//decreamenting the stack after deletion
            return Str_1; 
        }
    }
};
class Expression		//Declaring class expression
{ 
    public: 	
        string postfix; 
        string infix; 
        Stack Str_1; 
        bool isOperator(char x)   //Check operator
        { 
            if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' ) 
            { 
                return true; 
            } 
            else 
            { 
                return false; 
            }
        } 
    int precedence(string t)		//Declaring the precedence order
    {
        if(t == "+" || t == "-") 
		return 1; 
        else if( t == "*" || t == "/") 
		return 2; 
        else if(t == "^") 
		return 3; 
        else return 0; 
    } 
    void infix_to_postfix() 		//Function to convert from infix to postfix
    { 
        cout<<"Enter the infix expression: "; 
        cin>>infix; 
        string postfix; 
        
		for(int i = 0 ; i < infix.length() ; i++)		
        { 
            if((infix[i] >= 'a' && infix[i]<='z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
                postfix = postfix + infix[i]; 
            
			else if(infix[i] == '(') 
                Str_1.push("("); 
            
			else if(infix[i] == ')')
            {
                while( Str_1.top!= -1 && Str_1.stack[Str_1.top]!="(")
                { 
                    string t = Str_1.stack[Str_1.top]; 
                    Str_1.pop(); 
                    postfix = postfix + t; 
                } 
                if(Str_1.stack[Str_1.top] == "(")
                { 
                    string t = Str_1.stack[Str_1.top]; 
                    Str_1.pop(); 
                }
            } 
            else
            { 
                while(Str_1.top != -1 && precedence(string(1,infix[i])) <= precedence(Str_1.stack[Str_1.top]))
                { 
                    string t = Str_1.stack[Str_1.top]; 
                    Str_1.pop(); 
                    postfix = postfix + t; 
                } 
                Str_1.push(string(1,infix[i])); 
            }
        }
        while( Str_1.top != -1 )  //When the stack is not empty
        { 
            string t = Str_1.stack[Str_1.top]; 
            Str_1.pop(); 
            postfix = postfix + t; 
        } 
        cout<<"\nPostfix expression : "<<postfix<<endl; 		//Displaying postfix expression
    } 
    
    void postfix_to_prefix() 
    { 
        cout<<"\nEnter the postfix expression: "; 
        cin>>postfix; 
        
		for (int i = 0; i<postfix.length(); i++)     
        { 
            if(isOperator(postfix[i])) 
            { 
                string op1 = Str_1.pop(); 
                string op2 = Str_1.pop();string temp = postfix[i] + op2 + op1; 
                Str_1.push(temp); 
            } 
            else 
            { 
                Str_1.push(string(1,postfix[i])); 
            }
        }
        string prefix_ans = Str_1.pop(); 
        cout<<"\nPrefix expression : "<<prefix_ans<<endl; //Display prefix expression
    } 
    
    void postfix_evaluation() //Function for postfix evaluation
    { 
        char arr_1[100]; 
        int arr_2[100]; 
        int ctr = 0; 
        int i,j; 
        string postfix; 
        
		cout<<"\nEnter the postfix expression : ";   //Input Postfix expresssion
        cin>>postfix;
        
		for(i=0;i<postfix.length();i++)
        { 
            if(isOperator(postfix[i]))
            { 
                int ans; 
                int t2,t1; 
                string t_2 = Str_1.pop(); 
                string t_1 = Str_1.pop(); 
                stringstream change_2(t_2); 
                stringstream change_1(t_1); 
                change_2>>t2; 
                change_1>>t1; 
                
                if(postfix[i]=='+') ans = t1+t2; 
                else if(postfix[i]=='-') ans = t1-t2; 
                else if(postfix[i]=='/') ans = t1/t2; 
                else if (postfix[i]=='*') ans = t1*t2; 
                else if(postfix[i]=='^') ans = t1^t2; 
                ostringstream ans_1; 
                ans_1<<ans; 
                string ans__1 = ans_1.str(); 
                Str_1.push(ans__1);
            } 
            else
            { 
                if(isdigit(postfix[i]))
                { 
                    Str_1.push(string(1,postfix[i])); 
                }
            }
        } 
        string result = Str_1.pop(); 
        cout<<"\nThe answer of postfix evaluation : "<<result<<endl;  //Display the answer
    }



int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPrefix(stack <char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
	{
        if (infix[i] == '(') 
		{
            infix[i] = ')';
        }
        else if (infix[i] == ')') 
		{
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) 
	{
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
		{
            prefix += infix[i];
        }
        else if (infix[i] == '(') 
		{
            s.push(infix[i]);
        }
        else if (infix[i] == ')') 
		{
            while ((s.top() != '(') && (!s.empty())) 
			{
                prefix += s.top();
                s.pop();
            }

            if (s.top() == '(') 
			{
                s.pop();
            }
        }
        else if (isOperator(infix[i])) 
		{
            if (s.empty())
			{
                s.push(infix[i]);
            }
            else 
			{
                if (precedence(infix[i]) > precedence(s.top())) 
				{
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')) 
				{
                    while ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')) 
					{
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.top())) 
				{
                    s.push(infix[i]);
                }
                else 
				{
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top()))) 
					{
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.empty())  //checking if stack is empty or not
	{
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
  }

}; 

int main()
{ 
    Expression Exp1; 
    int ch, a=0; 
    do               
    { 
    	cout<<"Select an option from below : "<<endl<<"\n----------------------------------------------------------------";   
    	
        cout<<"\n1)Infix to Postfix\n2)Postfix Evaluation\n3)Postfix to Prefix\n4)Infix To Prefix "; 
        cout<<"\n---------------------------------------------------------------- ";
		cout<<" \n\nEnter your choice: ";
        cin>>ch; 
        
		switch(ch) 
        {
            case 1: 
                { 
                    Exp1.infix_to_postfix(); 
                    break; 
                } 
            case 2: 
                { 
                    Exp1.postfix_evaluation(); 
                    break; 
                }
            case 3: 
                { 
                    Exp1.postfix_to_prefix(); 
                    break; 
                } 
            
            case 4:
                {
                    
                    string infix, prefix;
                    
                    cout << "Enter Infix Expression :" << endl;
					cin >> infix;
					stack <char> stack;
					
					cout << "INFIX EXPRESSION : " << infix << endl;
					
					prefix = Exp1.InfixToPrefix(stack, infix);
					
					cout << endl<< "PREFIX EXPRESSION : " << prefix<<endl;
                    
					break;
                }
            default:
            	{
            		cout<<" \nInvalid choice!!!";
				}
        }
		cout<<"\nEnter 1 to continue..: ";     //Asking user whether he wants to run the code again
        cin>>a;         
        
    }while(a ==1); 
    
	return 0;       
    
}

/*
OUTPUT

Select an option from below :

----------------------------------------------------------------
1)Infix to Postfix
2)Postfix Evaluation
3)Postfix to Prefix
4)Infix To Prefix
----------------------------------------------------------------

Enter your choice: 1
Enter the infix expression: (a+b)*(c-d)

Postfix expression : ab+cd-*

Enter 1 to continue..: 1
Select an option from below :

----------------------------------------------------------------
1)Infix to Postfix
2)Postfix Evaluation
3)Postfix to Prefix
4)Infix To Prefix
----------------------------------------------------------------

Enter your choice: 2

Enter the postfix expression : 54+32-*

The answer of postfix evaluation : 9

Enter 1 to continue..: 1
Select an option from below :

----------------------------------------------------------------
1)Infix to Postfix
2)Postfix Evaluation
3)Postfix to Prefix
4)Infix To Prefix
----------------------------------------------------------------

Enter your choice: 3

Enter the postfix expression: ab+cd-*

Prefix expression : *+ab-cd

Enter 1 to continue..: 1
Select an option from below :

----------------------------------------------------------------
1)Infix to Postfix
2)Postfix Evaluation
3)Postfix to Prefix
4)Infix To Prefix
----------------------------------------------------------------

Enter your choice: 4
Enter Infix Expression :
(a+b)*(c-d)
INFIX EXPRESSION : (a+b)*(c-d)

PREFIX EXPRESSION : *+ab-cd


*/
