//============================================================================
// Name        : assgn2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Tree;
class node
{
	string key,value;
	node *l,*r;

public:
	node(string var,string var1)
	{
		key=var;
		value=var1;
		l=r=NULL;
	}
	friend class BTree;
};

class BTree
{
	node *root;
	node *stack[40];
public:
	BTree()
	{
		root=NULL;
	}

	void create();
	node* insert(node*,string,string);
	void ascending();
	void mirror(node*);
	void update();
	void getparent();
	void del(node*,node*);
	node* get(node *T1);
	int height1(node*);
	void mir()
	{
		mirror(root);
	}
	void height()
	{
		int y;
		y=height1(root);
		cout<<"\nmaximum number of comparisons are "<<y+1;

	}

	void operator =(BTree &T1);
};

void BTree::operator =(BTree &T1)
{
	if(T1.root!=NULL)
		root=get(T1.root);
}

node* BTree::get(node *T1)
{
	node *p;
	p=new node(T1->key,T1->value);
	if(T1->l!=NULL)
	{
		p->l=get(T1->l);
	}
	if(T1->r!=NULL)
	{
		p->r=get(T1->r);
	}
	return p;

}

void BTree::create()
{
	string a,b;

		cout<<"enter key or s to stop\n";
		//cin.ignore();
		cin>>a;

		cout<<"enter meaning of key\n";
		//cin.ignore();
		cin>>b;
		root=insert(root,a,b);


}

node* BTree::insert(node *T,string a,string b)
{
	if(T==NULL)
		return new node(a,b);
	if(a < T->key)
		T->l=insert(T->l,a,b);
	else
		T->r=insert(T->r,a,b);

	return T;
}

void BTree::mirror(node *T)
{
	node *temp;
	if(T!=NULL)
	{
		temp=T->l;
		T->l=T->r;
		T->r=temp;
		mirror(T->l);
		mirror(T->r);
	}


}

void BTree::ascending()
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
		cout<<T->key<<":"<<T->value<<endl;
		T=T->r;

	}

}

void BTree::update()
{
	node *T=root;
	string a;
	cout<<"enter key to update\n";
	cin>>a;
	while(T!=NULL && T->key!=a)
	{

		if(a<T->key)
			T=T->l;
		else
			T=T->r;
	}
	if(T==NULL)
	{
		cout<<"not found\n";
		return;
	}

	cout<<"enter value for updation\n";
	cin>>T->value;

}

void BTree::getparent()
{
	node *T=root,*p=root;
	string x;
	cout<<"enter key to delete\n";
	cin>>x;

	while(T!=NULL && T->key!=x)
	{
		p=T;
		if(T->key > x)
		{
			T=T->l;
		}
		if(T->key < x)
		{
			T=T->r;
		}


	}
	if(T==NULL)
		cout<<"no such element\n";


	if(T!=NULL)
	{
		//cout<<p->key<<T->key;
		del(p,T);
	}


}

void BTree::del(node *parent,node *child)
{
	node *cs;
	if(child->l!=NULL && child->r!=NULL)
	{
		cs=child->r;
		if(cs->l==NULL)
		{
			parent=child;
		}
		while(cs->l!=NULL)
		{
			parent=cs;
			cs=cs->l;
		}
		child->key=cs->key;
		child->value=cs->value;
		child=cs;

	}
	if(child->l==NULL && child->r==NULL)
	{
		if(parent->l==child)
		{
			parent->l=NULL;
		}
		else
		{
			parent->r=NULL;
		}
		delete child;

		return;

	}
	if(child->l!=NULL && child->r==NULL)
	{
		if(parent->l==child)
		{
			parent->l=child->l;
		}
		else
		{
			parent->r=child->l;
		}
		delete child;
		return;

	}
	if(child->r!=NULL && child->l==NULL)
	{
		if(parent->l==child)
		{
			parent->l=child->r;
		}
		else
		{
			parent->r=child->r;
		}
		delete child;
		return;

	}



}

int BTree::height1(node *T)
{
	int a1,a2;
	if(T==NULL)
		return 0;
	if(T->l==NULL && T->r==NULL)
		return 0;

	a1=height1(T->l);
	a2=height1(T->r);

	if(a1>a2)
		return a1+1;

	return a2+1;;
}


int main()
{
	BTree b,b1;

	int ch;

	do
	{
		cout<<"\n1:create\n2:display in ascending-order\n3:display in descending-order\n4:update\n5:copy\n6:delete\n";
		cout<<"7:max comparisons\n8:exit\n";
		cin>>ch;

		switch(ch)
		{
		case 1:b.create();
			break;
		case 2:b.ascending();
			break;
		case 3:b.mir();
				b.ascending();
				b.mir();
			break;
		case 4:b.update();
			break;
		case 5:b1=b;
			b1.ascending();
			break;
		case 6:b.getparent();
			break;
		case 7:b.height();
			break;
		case 8:ch=0;
		}

	}while(ch);


	return 0;
}
