//============================================================================
// Name        : assignment8(a).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
	int data;
	node *l,*r;
public:
	node(int i)
{
		data=i;
}
	friend class OBST;
};


class OBST
{
	float p[20],q[20],w[20][20],c[20][20],r[20][20];
	int n;
	node *root;
	node *stack[40];
	string inp[20];

public:
	OBST()
		{
			int i,j;
			for(i=0;i<20;i++)
			{
				for(j=0;j<20;j++)
				{
					w[i][j]=c[i][j]=r[i][j]=0;
					inp[j]='a';
				}
			}
		}

	void create();
	node* create_tree(int,int);
	void ascending();

};

void OBST::create()
{
	int i,j,k,m,i1,sum1,min=9999;
	cout<<"enter no. of vertices\n";
	cin>>n;
	cout<<"enter vertices\n";
		for(i=1;i<=n;i++)
		{
			cin>>inp[i];
		}
	cout<<"enter probabilities of successes\n";
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
	}

	cout<<"enter probabilities of unsuccessful search\n";
	for(i=0;i<=n;i++)
	{
		cin>>q[i];
	}

	for(i=0;i<n;i++)
	{
		w[i][i]=q[i];
		r[i][i]=c[i][i]=0;

		w[i][i+1]=q[i]+q[i+1]+p[i+1];
		r[i][i+1]=i+1;
		c[i][i+1]=w[i][i+1];


	}
	w[n][n]=q[n];
	r[n][n]=c[n][n]=0;

	for(m=2;m<=n;m++)
	{
		for(i=0;i<=n-m;i++)
		{
			j=i+m;
			min=9999;
			w[i][j]=w[i][j-1]+p[j]+q[j];

			for(i1=i+1;i1<j;i1++)
			{
				sum1=c[i][i1-1]+c[i1][j];
				if(sum1<min)
				{
					min=sum1;
					k=i1;
				}
			}
			c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
			r[i][j]=k;

		}
	}
	cout<<"w"<<endl;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cout<<w[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"c"<<endl;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"r"<<endl;
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=n;j++)
				{
					cout<<r[i][j]<<"\t";
				}
				cout<<endl;
			}
			cout<<endl;

	root=create_tree(0,n);
}


node* OBST::create_tree(int i,int j)
{
	int k;
	node *t;
	if(i!=j)
	{
		k=r[i][j];

			t=new node(k);
			t->l=create_tree(i,k-1);
			t->r=create_tree(k,j);
			return t;


	}
	else
	{
		return NULL;
	}


}

void OBST::ascending()
{
	int i=0;
	node *T=root;
	if(root==NULL)
		return;
	while(1)
	{
		while(T!=NULL)
		{
			i=i+1;
			stack[i]=T;
			T=T->l;

		}
		if(i==0)
		{
			return;
		}
		T=stack[i];
		i=i-1;
		cout<<inp[T->data]<<"\t";
		T=T->r;

	}

}


int main() {

	OBST b,b1;

	int ch;

	do
	{
		cout<<"\n1:create\n2:print tree\n";

		cin>>ch;

		switch(ch)
		{
		case 1:b.create();
			break;
		case 2:b.ascending();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:ch=0;
			break;
		}

	}while(ch);



	return 0;
}
