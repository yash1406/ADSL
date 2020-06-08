//============================================================================
// Name        : assign4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Graph;
class node
{
	int data;
	int time;
	node *next;
	string name;
public:
	node(int x,int y,string z)
{
		data=x;
		time=y;
		name=z;
		next=NULL;
}
	friend class Graph;

};
class Graph
{
	node *head[20];
	int n;
	int visit[20];
public:
	Graph()
{
		int i;
		for(i=1;i<=19;i++)
		{
			head[i]=NULL;
			visit[i]=0;
		}

}
	void create_graph();
	void DFS(int);
	void add_edge();
	void del();
	void degree();
	void clear();
	void print();
	void del_vertex();
	void add_vertex();


};

void Graph::create_graph()
{
	int i,j,no,k,v;
	string st,s;
	node *p,*temp,*q;
	cout<<"ENTER NO. OF CITIES\n";
	cin>>n;

	for(i=1;i<=n;i++)
	{
		head[i]=new node(i,0,"");
	}

	for(i=1;i<=n;i++)
	{
		cout<<"enter city name for id "<<i<<endl;
		cin>>s;
		head[i]->name=s;

		p=head[i];
		cout<<"enter no. of adjacent cities to "<<head[i]->name<<endl;
		cin>>no;
		if(no==0)
		{
			head[i]->next=NULL;
		}
		else
		{
			for(j=0;j<no;j++)
			{
				cout<<"enter city-id, time required from "<<head[i]->name<<" and city name"<<endl;
				cin>>v>>k>>st;

				if(v<1 || v>n)
				{
					cout<<"invalid city\n";
					j--;
				}

				else
				{
					temp=new node(v,k,st);
					p->next=temp;
					p=temp;
					q=head[v];
					while(q->next!=NULL)
					{
						q=q->next;
					}
					q->next=new node(i,k,head[i]->name);


				}

			}
		}

	}
	for(i=0;i<=n;i++)
	{

		visit[i]=0;
	}

}

void Graph::clear()
{
	int i;
	for(i=1;i<=19;i++)
	{

		visit[i]=0;
	}

}


void Graph::print()
{
	int i;
	for(i=1;i<=n;i++)
	{

		if(visit[i]==0 && head[i]!=NULL)
		{
			DFS(i);
		}
	}
}



void Graph::DFS(int v)
{
	node *temp;
	int t;
	visit[v]=1;
	cout<<head[v]->name<<"\t";
	temp=head[v]->next;


	while(temp!=NULL)
	{
		t=temp->data;

		if(visit[t]==0)
		{

			DFS(t);

		}
		temp=temp->next;
	}
}

void Graph::add_vertex()
{
	string s,t;
	int id,v,k,j,i;
	node *temp,*p;

	cout<<"enter city name and its id\n";
	cin>>s>>id;


	head[id]=new node(id,0,s);
	n=n+1;

	cout<<"enter no. of adjacent cities to "<<s<<endl;
	cin>>j;


	for(i=1;i<=j;i++)
	{
		cout<<"enter city-id, time required from "<<head[id]->name<<" and city name"<<endl;
		cin>>v>>k>>t;
		if(v<1 || v>n-1)
		{
			cout<<"invalid city\n";
			i--;
		}


		temp=new node(v,k,t);
		p=head[id];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;



		p=head[v];
		temp=new node(id,k,head[id]->name);
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;



	}

}

void Graph::add_edge()
{
	string s,t;
	int id,v,k;
	node *temp,*p;
a:
	cout<<"enter edge which you want to add\n";
	cin>>id>>v;
	cout<<"enter distance between them\n";
	cin>>k;
	if(id<1 || id>n || v<1 || v>n)
	{
		cout<<"invalid city\n";
		goto a;
	}


	temp=new node(v,k,head[v]->name);
	p=head[id];
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;


	p=head[v];
	temp=new node(id,k,head[id]->name);
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;


}

void Graph::del()
{
	string s,t;
	int id,v,k;
	node *temp,*p;
	cout<<"enter edge u want to delete\n";
	cin>>v>>k;

	p=head[v];
	while(p->data!=k)
	{
		temp=p;
		p=p->next;
	}
	temp->next=p->next;
	delete p;

	p=head[k];
		while(p->data!=v)
		{
			temp=p;
			p=p->next;
		}
		temp->next=p->next;
		delete p;

}

void Graph::del_vertex()
{

	string s,t;
	int id,v,k,i;
	node *temp,*p;
	cout<<"enter city id want to delete\n";
	cin>>id;

	for(i=1;i<=n;i++)
	{
		p=head[i];
		temp=p;
		while(p!=NULL && p->data!=id)
		{
			temp=p;
			p=p->next;
		}
		if(p!=NULL)
		{
			temp->next=p->next;
			delete p;

		}


	}
	head[id]=NULL;
	if(id==n)
	{
		n=n-1;

	}




}

void Graph::degree()
{
	node *p;

	int i,count=0;;
	for(i=1;i<=n;i++)
	{
		count=0;
		p=head[i];
		while(p!=NULL)
		{
			p=p->next;
			count++;
		}
		if(head[i]!=NULL)
		{
			cout<<"degree of "<<head[i]->name<<" is "<<count-1;
		}

	}



}




int main()
{
	Graph g;
	int ch,i;

	do
	{
		cout<<"\n1:create\n2:DFS\n3:add edge\n4:delete edge\n5:degree\n6:exit\n7:delete vertex\n8:add vertex\n";
		cin>>ch;
		switch(ch)
		{
		case 1:g.create_graph();
			break;
		case 2:g.clear();
			g.print();
			break;
		case 3:g.add_edge();
			break;
		case 4:g.del();
			break;
		case 5:g.degree();
			break;
		case 6:ch=0;
			break;
		case 7:g.del_vertex();
			break;
		case 8:g.add_vertex();


		}

	}while(ch);

	return 0;
}
