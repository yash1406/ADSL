//============================================================================
// Name        : Assignment6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Dictionary
{
	string arr[26],arr1[26];
	int check[26],check1[26];
	string key[50];
	int value[50];
	int n;


public:
	Dictionary()
{
		int i;
		n=0;
		for(i=0;i<26;i++)
		{
			check[i]=0;
			check1[i]=0;
		}
}
	void insert();
	void search();
	void del();
	void print();
	int full();

	void insertR(string,int);
	void searchR();
	void delR(string);
	void printR();
	int fullR();


};

int Dictionary::full()
{
	int i;
	for(i=0;i<26;i++)
	{
		if(check[i]==0)
			return 0;
	}
	return 1;
}

int Dictionary::fullR()
{
	int i;
	for(i=0;i<26;i++)
	{
		if(check1[i]==0)
			return 0;
	}
	return 1;
}


void Dictionary::print()
{
	int i;
	for(i=0;i<26;i++)
	{
		cout<<i<<":"<<arr[i]<<endl;
	}

}

void Dictionary::printR()
{
	int i;
	for(i=0;i<26;i++)
	{
		cout<<i<<":"<<arr1[i]<<endl;
	}

}

void Dictionary::insert()
{
	string str;
	if(full())
	{
		cout<<"dictionary full\n";
		return;
	}

	int i,j,k;

	cout<<"enter name and phone number to insert\n";
	cin>>str>>k;

	key[n]=str;
	value[n]=k;
	n++;

	j=(int)str[0];
	i=j%97;

	while(check[i]!=0)
	{
		i=(i+1)%26;

	}
	arr[i]=str;
	check[i]=1;

	insertR(str,k);

}

void Dictionary::insertR(string str,int k)
{
	int i,j,m;
	string temp,s;


		j=(int)str[0];
		i=j%97;
		temp=arr1[i];

		if(check1[i]!=0 && temp[0]!=str[0])
		{
			s=arr1[i];
			arr1[i]=str;
			while(check1[i]!=0)
				{
					i=(i+1)%26;

				}
			arr1[i]=s;
			check1[i]=1;

		}
		else
		{
			while(check1[i]!=0)
			{
				i=(i+1)%26;

			}
					arr1[i]=str;
					check1[i]=1;
		}

}


void Dictionary::search()
{
	string str;
	int i,j,k,flag=0,count=0,l=0;

		cout<<"enter name to search\n";
		cin>>str;


		j=(int)str[0];
		i=j%97;
		flag=i;

		while(arr[i]!=str)
		{
			i=(i+1)%26;
			count++;
			if(i==flag)
			{
				l=1;
				break;
			}
		}
		if(l==1)
		{
			cout<<"not found\n";
		}
		else
		{
			for(j=0;j<26;j++)
			{
				if(arr[i]==key[j])
				{
					break;
				}
			}
			cout<<"found\n"<<arr[i]<<":"<<value[j]<<endl;
			cout<<"no. of comparisons are "<<count<<endl;
		}

}

void Dictionary::searchR()
{

	string str;
	int i,j,k,flag=0,count=0,l=0;

		cout<<"enter name to search\n";
		cin>>str;


		j=(int)str[0];
		i=j%97;
		flag=i;

		while(arr1[i]!=str)
		{
			i=(i+1)%26;
			count++;
			if(i==flag)
			{
				l=1;
				break;
			}
		}
		if(l==1)
		{
			cout<<"not found\n";
		}
		else
		{
			for(j=0;j<26;j++)
			{
				if(arr1[i]==key[j])
				{
					break;
				}
			}
			cout<<"found\n"<<arr1[i]<<":"<<value[j]<<endl;
			cout<<"no. of comparisons are "<<count<<endl;
		}


}
void Dictionary::del()
{
	string str;
	int i,j,k,flag=0,l=0;

		cout<<"enter name to delete\n";
		cin>>str;


		j=(int)str[0];
		i=j%97;
		flag=i;

		while(arr[i]!=str)
		{
			i=(i+1)%26;
			if(i==flag)
			{
				l=1;
				break;
			}
		}
		if(l==1)
		{


			cout<<"not found\n";
		}
		else
		{
			check[i]=0;
			arr[i]="";
			cout<<"deleted\n";
		}

		delR(str);


}

void Dictionary::delR(string str)
{

	int i,j,k,flag=0,l=0;



		j=(int)str[0];
		i=j%97;
		flag=i;

		while(arr1[i]!=str)
		{
			i=(i+1)%26;
			if(i==flag)
			{
				l=1;
				break;
			}
		}
		if(l==1)
		{


			cout<<"not found\n";
		}
		else
		{
			check1[i]=0;
			arr1[i]="";
			cout<<"deleted\n";
		}




}

int main() {

	Dictionary d;

	int ch;

	do
	{
		cout<<"\n1:insert\n2:search\n3:delete\n4:exit\n5:print\n6:print with replacement\n7:search(with replacement)\n";

		cin>>ch;

		switch(ch)
		{
		case 1:d.insert();
			break;
		case 2:d.search();
			break;
		case 3:d.del();
			break;
		case 4:ch=0;
			break;
		case 5:d.print();
			break;
		case 6:d.printR();
			break;
		case 7:d.searchR();
			break;

		}

	}while(ch);

	return 0;
}
