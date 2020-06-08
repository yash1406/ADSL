//============================================================================
// Name        : SLL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class SLL;
class node
{
	int data;
	node *next;
public:

	node(int x)
	{
		data=x;
		next=NULL;

	}
	friend class SLL;
};

class SLL
{
	node *start;
public:

	SLL()
	{
		start=NULL;
	}

	void display();
	void insertatbeg(int);
	void insertatend(int);
	void insert();
	int del();
	int count();
	int delatbeg();
	int delatend();
	void insertnumber();
	void retrieve();

};

inline void SLL::display()
{
	node *p;
	p=start;
	if(start!=NULL)
	{
		cout<<"List:\n";
		while(p!=NULL)
		{
			cout<<p->data<<"\t";
			p=p->next;
		}
		cout<<endl;

	}
	else
	{
		cout<<"empty list\n";
	}

}

inline void SLL::insertatbeg(int x)
{
	node *p;

	if(start==NULL)
	{

		start=new node(x);

	}

	else
	{

		p=new node(x);
		p->next=start;
		start=p;

	}
}

inline void SLL::insertatend(int x)
{
	node *p,*q;


	if(start==NULL)
	{

		start=new node(x);

	}
	else
	{
		q=start;

		p=new node(x);

		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;


	}

}

void SLL::insert()
{
	node *p;
	int x,pos;
	cout<<"enter data\n";
	cin>>x;
	cout<<"enter position\n";
	cin>>pos;
	p=new node(x);
	if(pos==1)
	{
		p->next=start;
		start=p;

	}
	else
	{
		node *q;
		q=start;
		int i;
		if(pos>0 && pos<=count()+1)
		{
			for(i=1;i<pos-1;i++)
			{
				q=q->next;
			}
			p->next=q->next;
			q->next=p;

		}
		else
		{
			cout<<"invalid position\n";
		}

	}


}

inline int SLL::count()
{
	int i=0;
	node *p=start;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}

	return i;
}

int SLL::del()
{
	int x;
	node *p=start;

	if(start!=NULL)
	{
		cout<<"enter value to delete\n";
		cin>>x;
		if(start->data==x)
		{
			start=start->next;
			delete p;
			return x;
		}
		else
		{
			while(p->next!=NULL && p->next->data!=x)
			{
				p=p->next;
			}
			if(p->next==NULL)
			{
				cout<<"not found\n";
				return -1;
			}
			p->next=p->next->next;
			node *q;
			q=p->next;
			delete q;
			return x;
		}
	}
	else
	{
		cout<<"empty list\n";
	}
}

int SLL::delatbeg()
{
	int i;
	if(start!=NULL)
	{
		node *p=start;
		i=start->data;
		start=start->next;
		return i;
	}
	else
	{
		cout<<"empty\n";
	}
}

int SLL::delatend()
{
	int i;
	if(start!=NULL)
	{
		node *p=start,*q;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		delete p;
		return i;
	}
	else
	{
		cout<<"empty\n";
	}
}

void SLL::insertnumber()
{
	int n,x;
	cout<<"enter number\n";
	cin>>n;
	x=n;
	while(x>0)
	{
		insertatbeg(x%10);
		x=x/10;
	}
	display();
}

void SLL::retrieve()
{
	int i=1;
	int n=0;
	node *p=start;
	while(p!=NULL)
	{
		n=n+(p->data*i);
		p=p->next;
		i=i*10;
	}
	cout<<n<<endl;
}


int main()
{
	SLL s;
	int ch,i,x;

	do{
		cout<<"\n1:display\n2:insert at beg\n3:insert at end\n4:insert by position\n5:delete\n6:del at beg\n7:del at end\n8:exit\n9:insert number\n10:retrieve number\n";
		cin>>ch;

		switch(ch)
		{
			case 1:s.display();
				break;
			case 2:cout<<"enter data\n";
				cin>>x;
				s.insertatbeg(x);
				break;
			case 3:
				cout<<"enter data\n";
				cin>>x;
				s.insertatend(x);
				break;
			case 4:s.insert();
				break;
			case 5:i=s.del();
				break;
			case 6:i=s.delatbeg();
				break;
			case 7:i=s.delatend();
				break;

			case 8:ch=0;
				break;
			case 9:s.insertnumber();
			break;
			case 10:s.retrieve();

		}

	}while(ch);






	return 0;
}
