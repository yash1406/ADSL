//============================================================================
// Name        : assignment9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Set
{
public:
	Set()
{
		n=0;
}

	int arr[100];
	int n;

	void add(int a);
	void remove(int a);

	void contains(int a);
	void print();
	int size();

	void union1(Set a,Set b);
	void inter(Set a,Set b);
	void difference(Set a,Set b);

	void create();
	void subset(Set a);



};


void Set::create()
{
	int i,j,k;
	cout<<"enter no. of elements of 2nd set\n";
	cin>>j;
	n=0;
	cout<<"enter elements of set\n";
	for(i=0;i<j;i++)
	{
		cin>>arr[n];
		n++;
	}

}

void Set::add(int a)
{
	int flag=0,i,j;

	for(i=0;i<n;i++)
	{
		if(arr[i]==a)
		{
			flag=1;
			break;
		}
	}

	if(flag==0)
	{
		arr[n]=a;
		n++;
	}

	else
	{
		cout<<"element already present\n";
	}


}

void Set::remove(int a)
{
	int flag=0,i,j;

	for(i=0;i<n;i++)
	{
		if(arr[i]==a)
		{
			j=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"element not present\n";

	}
	else
	{
		for(i=j;i<n-1;i++)
		{
			arr[i]=arr[i+1];
		}

		n--;

	}


}
void Set::contains(int a)
{
	int flag=0,i,j;

	for(i=0;i<n;i++)
	{
		if(arr[i]==a)
		{
			j=i;
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"element not present\n";

	}
	else
	{

		cout<<"element present\n";

	}


}

void Set::print()
{
	int i;

	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}

	cout<<endl;

}

int Set::size()
{
	return n;
}

void Set::union1(Set d,Set d1)
{
	int i,j,k,flag=0;
	n=0;
	for(i=0;i<d.n;i++)
	{
		arr[n]=d.arr[i];
		n++;
	}

	for(j=0;j<d1.n;j++)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]==d1.arr[j])
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			arr[n]=d1.arr[j];
			n++;
		}

	}


}

void Set::inter(Set d,Set d1)
{
	int i,j,k,flag=0;;
	n=0;

	if(d.n!=0 || d1.n!=0)
	{
		for(i=0;i<d.n;i++)
		{
			flag=0;
			for(j=0;j<d1.n;j++)
			{
				if(d.arr[i]==d1.arr[j])
				{
					flag=1;
					break;
				}


			}
			if(flag==1)
			{
				arr[n]=d.arr[i];
				n++;
			}
		}
	}

}


void Set::difference(Set d,Set d3)
{
	int i,j,k;
	n=0;
	for(i=0;i<d.n;i++)
	{
		arr[n]=d.arr[i];
		n++;

	}
	
	for(i=0;i<d3.n;i++)
	{
		
		remove(d3.arr[i]);
		

	}

}


void Set::subset(Set d)
{
	int flag=0,i,j,k;

	for(k=0;k<n;k++)
	{
		
		for(i=0;i<d.n;i++)
		{
			if(d.arr[i]==arr[k])
			{
				
				flag++;
				break;
			}
		}


	}
	if(flag==n)
	{
		cout<<"it is a subset\n";
	}
	else
	{
		cout<<"not a subset\n";
			

	}



}


int main() {


	Set d,d1,d2,d3,d4,d5;

	int ch,a,b,ch1;

	do
	{
		cout<<"\n1:add\n2:remove\n3:search\n4:size\n5:print\n6:enter 2nd set\n7:union\n8:intersection\n9:difference\n10:subset\n11:exit\n";

		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"enter element\n";
				cin>>a;
				d.add(a);

			break;
		case 2:cout<<"enter element\n";
				cin>>a;
				d.remove(a);

			break;
		case 3:cout<<"enter element\n";
				cin>>a;
				d.contains(a);

			break;
		case 4:cout<<"size is "<<d.size()<<endl;
			break;
		case 5:d.print();
			break;
		case 6:d1.create();
			break;
		case 7:d2.union1(d,d1);
				d2.print();
			break;
		case 8:d3.inter(d,d1);
				d3.print();
			break;
		case 9:
				d3.inter(d,d1);
				d4.difference(d,d3);
				d4.print();
			break;
		case 10:d5.create();
				d5.subset(d);

			break;
		case 11:ch=0;

		}

	}while(ch);





	return 0;
}
