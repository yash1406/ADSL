//============================================================================
// Name        : assgn1.cpp
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
	int data;
	node *l,*r;

public:
	node(int x)
	{
		data=x;
		l=r=NULL;
	}
	friend class Tree;
};

class Tree
{
	node *root;
	node* stack[30];

public:
	Tree()
	{
		root=NULL;

	}

	void create(int);
	node* insert(node*,int);
	void inorder(node *);
	void preorder(node *);
	void pre();
	void postorder(node *);
	void post();
	void mirror(node *);
	int height1(node *);
	int leaves(node*);
	int total(node*);
	void del(node*);
	void leaf()
	{
		int y;
		y=leaves(root);
		cout<<"\nno. of leaves are "<<y;
	}
	void height()
	{
		int y;
		y=height1(root);
		cout<<"\nheight of binary tree is "<<y;

	}

	void inter()
	{
		int y;
		y=total(root);
		cout<<"\nno. of internal nodes are "<<y-1-leaves(root);

	}
	void delete1()
	{
		del(root);
		root=NULL;
		cout<<"\nall nodes are deleted\n";
	}


	void send()
	{
		if(root!=NULL)
			inorder(root);
		else
			cout<<"empty\n";
	}
	void sendpre()
	{
		if(root!=NULL)
			preorder(root);
		else
			cout<<"empty\n";
	}
	void sendpost()
	{
		if(root!=NULL)
			postorder(root);
		else
			cout<<"empty\n";
	}
	void mir()
	{
		mirror(root);
	}

	node* get(node *);
    void operator =(Tree &T1);
};

void Tree::operator =(Tree &T1)
{
	root=get(T1.root);
}

node* Tree::get(node *T1)
{
	node *p;
	p=new node(T1->data);
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

void Tree::create(int x)
{
	if(root==NULL)
	{
		root=new node(x);
	}
	else
	{
		root=insert(root,x);
	}
}

node* Tree::insert(node *T,int x)
{
	char ch;
	if(T==NULL)
	{
		T=new node(x);
		return T;
	}
	else
	{
		cout<<"Do u want to insert in l/r side of "<<T->data<<endl;
		cin>>ch;
		if(ch=='L' || ch=='l')
		{
			T->l=insert(T->l,x);

		}
		else
		{
			T->r=insert(T->r,x);
		}
		return T;
	}
}

void Tree::inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->l);
		cout<<T->data<<"\t";
		inorder(T->r);
	}

}

void Tree::preorder(node *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<"\t";
		preorder(T->l);
		preorder(T->r);
	}

}

void Tree::pre()
{
	int i=0;
	node *T=root;
	while(1)
	{
		while(T!=NULL)
		{
			cout<<T->data<<"\t";
			if(T->r!=NULL)
			{
				i=i+1;
				stack[i]=T->r;
			}
			T=T->l;
		}
		if(i==0)
		{
			return;
		}
		T=stack[i];
		i=i-1;

	}

}
void Tree::postorder(node *T)
{
	if(T!=NULL)
	{

		postorder(T->l);
		postorder(T->r);
		cout<<T->data<<"\t";
	}

}

void Tree::post()
{
	node *T=root;
	int i=0;

	while(1)
	{
		while(T!=NULL)
		{
			i=i+1;
			stack[i]=T;
			if(T->r!=NULL)
			{
				i=i+1;
				stack[i]=T->r;
				i=i+1;
				stack[i]=NULL;

			}
			T=T->l;

		}
		if(i==0)
			return;
		while(stack[i]!=NULL && i!=0)
		{
			T=stack[i];
			cout<<T->data<<"\t";
			i=i-1;
		}
		if(i!=0)
			i=i-1;
		if(i==0)
			return;
		T=stack[i];
		i=i-1;

	}

}
void Tree::mirror(node *T)
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

int Tree::height1(node *T)
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

int Tree::leaves(node *T)
{
	int a1,a2;
	if(T==NULL)
		return 0;
	if(T->l==NULL && T->r==NULL)
	{
		return 1;
	}
	a1=leaves(T->l);
	a2=leaves(T->r);
	return a1+a2;
}

int Tree::total(node *T)
{
	if(T==NULL)
	{
		return 0;
	}
	return 1+total(T->l)+total(T->r);
}

void Tree::del(node *T)
{
	if(T!=NULL)
	{

		del(T->l);
		del(T->r);
		delete T;
	}

}

int main()
{
	int y;
	int ch;
	Tree t,t1;

	do
	{
		cout<<"\n1:create\n2:inorder\n3:preorder non-recursive\n4:preorder\n5:postorder\n6:postorder non-recursive\n";
		cout<<"7:mirror\n8:height\n9:delete all nodes\n10:copy\n11:leaves\n12:internal nodes\n13:exit\n";
		cin>>ch;

		switch(ch)
		{
		case 1:cout<<"enter data\t";
			cin>>y;
			t.create(y);
			break;
		case 2:t.send();
			break;
		case 3:t.pre();
			break;
		case 4:t.sendpre();
			break;
		case 5:t.sendpost();
			break;
		case 6:t.post();
			break;
		case 7:t.mir();
			break;
		case 8:t.height();
			break;
		case 9:t.delete1();
			break;
		case 10:t1=t;
			t1.sendpre();
			break;
		case 11:t.leaf();
			break;
		case 12:t.inter();
			break;
		case 13:ch=0;

		}
	}while(ch);





	return 0;
}
