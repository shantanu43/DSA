/*
Name= Shantanu H. Chaudhari
Roll No.= 86
Div= B1
Practical 10= Design and implement a menu driven program for implementing insertion sort and quick sort for
population of a town
*/


#include<bits/stdc++.h>
using namespace std;
# define max 20

class population
{
	public:
	string name;
	int pop;
};
class sorting
{
	public:
	int size;
	population data[max];
	void insertion_sort();
	void quick_sort(int l,int r);
	int partition(int l,int r);
	void merge(int l,int mid,int r);
	void merge_sort(int l,int r);
	void input();
	void display();
};
int sorting::partition(int l,int r)
{
	int i=l;
	int pivot=data[l].pop;
	int j=r;
	while(i<j)
	{
		while(data[i].pop<=pivot)
		{
		i++;
		}
		while(data[j].pop>pivot)
		{
		j--;
		}
		if(i<j)
		{
		int temp=data[i].pop;
		data[i].pop=data[j].pop;
		data[j].pop=temp;
		// swap(data[i],data[j]);
		}
	}
	
	int t=data[j].pop;
	data[j].pop=data[l].pop;
	data[l].pop=t;
	// swap(data[j],data[l]);
	return j;
}

void sorting::merge(int l,int mid,int r)
{
	int n1=mid-l+1;
	int n2=r-mid;
	int arr1[n1];
	int arr2[n2];
	for(int i=0;i<n1;i++)
	{
	arr1[i]=data[l+i].pop;
	}
	for(int j=0;j<n2;j++)
	{
	arr2[j]=data[mid+1+j].pop;
	}
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2)
	{
		if(arr1[i]<arr2[j])
		{
		data[k].pop=arr1[i];
		i++;
		k++;
		}
		else{
		data[k].pop=arr2[j];
		k++;
		j++;
		}
	}
	while(i<n1)
	{
		data[k].pop=arr1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
	data[k].pop=arr2[j];
	j++;
	k++;
	}
}

void sorting::quick_sort(int l,int r)
{
	if(l>r)
	{
	return;
	}
	int pivot=partition(l,r);
	quick_sort(l,pivot-1);
	quick_sort(pivot+1,r);
}

void sorting::merge_sort(int l,int r)
{
	if(l<r)
	{
	int mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merge(l,mid,r);
	}
}
void sorting::input()
{
	cout<<"enter the size of the data"<<endl;
	cin>>size;
	for(int i=0;i<size;i++)
	{
	cout<<"enter the name of the city"<<endl;
	cin>>data[i].name;
	cout<<"enter the population of the city"<<endl;
	cin>>data[i].pop;
	}
}
void sorting::display()
{
	cout<<"------displaying the population --------"<<endl;
	for(int i=0;i<size;i++)
	{
	cout<<"city name:"<<data[i].name<<endl;
	cout<<"population size:"<<data[i].pop<<endl;
	}
}

void sorting::insertion_sort()
{
	for(int i=0;i<size;i++)
	{
		int current=data[i].pop;
		int j=i-1;
		while(j>=0 && current<data[j].pop)
		{
		data[j+1].pop=data[j].pop;
		j--;
		}
		data[j+1].pop=current;
	}
}
int main()
{
	sorting s1;
	int choice;
	while(1)
	{
		cout<<"\n1.insertion_sort\n2.quick_sort\n3.merge_sort"<<endl;
		cout<<"enter the choice"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1:
			s1.input();
			s1.insertion_sort();
			cout<<"the data has been sorted using insertion sort"<<endl;
			s1.display();
			break;
			
			case 2:
			s1.input();
			s1.quick_sort(0,s1.size-1);
			cout<<"the data has been sorted using quick sort"<<endl;
			s1.display();
			break;
			
			case 3:
			s1.input();
			s1.merge_sort(0,s1.size-1);
			cout<<"the data has been sorted using merge sort"<<endl;
			s1.display();
			break;
			
			default:
			cout<<"enter the valid choice"<<endl;
			break;
		}
		char ch;
		cout<<"do you want to continue"<<endl;
		cin>>ch;
		
		if(ch=='y')
		{
		continue;
		}
		else
		{
		break;
		}
	}
	return 0;
}

/*
OUTPUT

1.insertion_sort
2.quick_sort
3.merge_sort
enter the choice
1
enter the size of the data
3
enter the name of the city
pune
enter the population of the city
2000000
enter the name of the city
dhule
enter the population of the city
30000
enter the name of the city
mumbai
enter the population of the city
1000000
the data has been sorted using insertion sort
------displaying the population --------
city name:pune
population size:30000
city name:dhule
population size:1000000
city name:mumbai
population size:2000000
do you want to continue
1

1.insertion_sort
2.quick_sort
3.merge_sort
enter the choice
2
enter the size of the data
3
enter the name of the city
pune
enter the population of the city
400000
enter the name of the city
nashik
enter the population of the city
300000
enter the name of the city
mumbai
enter the population of the city
200000
the data has been sorted using quick sort
------displaying the population --------
city name:pune
population size:200000
city name:nashik
population size:300000
city name:mumbai
population size:400000
do you want to continue
1


1.insertion_sort
2.quick_sort
3.merge_sort
enter the choice
3
enter the size of the data
3
enter the name of the city
nashik
enter the population of the city
65322
enter the name of the city
dhule
enter the population of the city
64598
enter the name of the city
satara
enter the population of the city
20005
the data has been sorted using merge sort
------displaying the population --------
city name:nashik
population size:20005
city name:dhule
population size:64598
city name:satara
population size:65322
do you want to continue
*/
