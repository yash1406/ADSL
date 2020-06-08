//============================================================================
// Name        : Assignment7.cpp
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
	int check[26],check1[26],chain[26],chain1[26];
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
			chain[i]=-1;
			chain1[i]=-1;
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
		cout<<chain[i]<<"\t";

		cout<<i<<":"<<arr[i]<<endl;
	}

}

void Dictionary::printR()
{
	int i;
	for(i=0;i<26;i++)
	{
		cout<<chain1[i]<<"\t";

		cout<<i<<":"<<arr1[i]<<endl;
	}

}

void Dictionary::insert()
{
	string str,temp;
	if(full())
	{
		cout<<"dictionary full\n";
		return;
	}

	int i,j,k,l,m,p;

	cout<<"enter name and phone number to insert\n";
	cin>>str>>k;

	key[n]=str;
	value[n]=k;
	n++;

	j=(int)str[0];
	p=j;
	i=j%97;


	while(check[i]!=0)
	{
		i=(i+1)%26;

	}
	arr[i]=str;
	check[i]=1;

	for(l=i+1; ;l=(l+1)%26)
	{
		temp=arr[l];
		m=(int)temp[0];
		if(m==p)
		{
			break;
		}
	}
	if(l!=i)
	{
		while(chain[l]!=-1)
		{
			l=chain[l];
		}
		chain[l]=i;
	}

	insertR(str,k);

}

void Dictionary::insertR(string str,int k)
{

	int i,j,l,m,p,a,b,c,d;

	string temp,s,str1,str2;


	j=(int)str[0];
	p=j;
	i=j%97;
	temp=arr1[i];
	a=i;
	if(check1[a]==0)
	{
		arr1[a]=str;
		check1[a]=1;

	}
	else
	{

		if(str[0]==temp[0])
		{

			while(check1[i]!=0)
			{
				i=(i+1)%26;

			}

			arr1[i]=str;
			check1[i]=1;

			for(l=i+1; ;l=(l+1)%26)
			{
				temp=arr1[l];
				m=(int)temp[0];
				if(m==p)
				{
					break;
				}
			}
			if(l!=i)
			{
				while(chain1[l]!=-1)
				{
					l=chain1[l];
				}

				chain1[l]=i;
			}

		}
		else
		{
			
			while(check1[i]!=0)
			{
				i=(i+1)%26;

			}


			c=chain1[a];
			str1=arr1[a];

			b=str1[0];
			b=b%97;

			while(b!=-1 && chain1[b]!=c)
			{
				d=b;
				b=chain1[b];
			}

			if(chain1[b]!=-1)
			{
				chain1[d]=chain1[a];
				chain1[chain1[b]]=i;
				chain1[a]=-1;

			}
			else
			{
 
				chain1[d]=i;
				chain1[a]=-1;

			}
			arr1[i]=arr1[a];
			arr1[a]=str;
			check1[i]=1;


		}

	}


}


void Dictionary::search()
{
	string str,temp,var;
	int i,j,k,flag=0,count=0,l=0;

		cout<<"enter name to search\n";
		cin>>str;


		j=(int)str[0];
		i=j%97;
		flag=i;
		temp=arr[i];
		while(temp[0]!=str[0])
		{

			i=(i+1)%26;
			temp=arr[i];
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

			while(i!=-1 && arr[i]!=str)
			{
				i=chain[i];
				count++;

			}
			if(i==-1)
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

			}


			cout<<"found\n"<<arr[i]<<":"<<value[j]<<endl;
			cout<<"no. of comparisons are "<<count+1<<endl;
		}


}

void Dictionary::searchR()
{
	string str,temp,var;
	int i,j,k,flag=0,count=0,l=0;

		cout<<"enter name to search\n";
		cin>>str;


		j=(int)str[0];
		i=j%97;
		flag=i;
		temp=arr[i];
		while(temp[0]!=str[0])
		{

			i=(i+1)%26;
			temp=arr1[i];
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

			while(i!=-1 && arr1[i]!=str)
			{
				i=chain[i];
				count++;

			}
			if(i==-1)
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

			}


			cout<<"found\n"<<arr[i]<<":"<<value[j]<<endl;
			cout<<"no. of comparisons are "<<count+1<<endl;
		}

}
void Dictionary::del()
{
	string str,temp,var;
	int i,j,k,flag=0,count=0,l=0,m;

		cout<<"enter name to delete\n";
		cin>>str;


		j=(int)str[0];
		i=j%97;
		flag=i;
		temp=arr[i];
		while(temp[0]!=str[0])
		{

			i=(i+1)%26;
			temp=arr[i];
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
			m=i;
			while(i!=-1 && arr[i]!=str)
			{
				m=i;
				i=chain[i];
				count++;

			}
			if(i==-1)
			{

				cout<<"not found\n";
			}
			else
			{

				int q,p=i;
				for(q=i;chain[q]!=-1;q=chain[q])
				{
					p=q;
					arr[q]=arr[chain[q]];


				}
				arr[q]="";
				chain[p]=-1;
				cout<<"deleted\n";

			}



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
				int q,p=i;
				for(q=i;chain1[q]!=-1;q=chain1[q])
				{
					p=q;
					arr1[q]=arr1[chain1[q]];


				}
				arr1[q]="";
				chain1[p]=-1;
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
