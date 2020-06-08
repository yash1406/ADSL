//============================================================================
// Name        : Assignment8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class AVL;
class node
{
	string key,value;
	node *l,*r;
	int bf;

public:
	node(string var,string var1)
	{
		key=var;
		value=var1;
		l=r=NULL;
		bf=0;
	}
	friend class AVL;
};

class AVL
{
	node *root;
	node *stack[40];
	bool *d;
public:
	AVL()
	{
		root=NULL;
	}

	void create();
	node* insert(node*,string,string);
	void ascending();
	void descending();
 	node* get(node *T1);
	int height1(node*);
	void update();
	void inorder(node*);
	node* del(node*,string);
	void in()
	{
		inorder(root);
	}

	void height()
	{
		int y;
		y=height1(root);
		cout<<"\nmaximum number of comparisons are "<<y+1;

	}
	void del1()
	{
		string i;
		cout<<"enter key to delete\n";
		cin>>i;
		root=del(root,i);
	}



};

void AVL::inorder(node *T)
{

	if(T!=NULL)
	{
		inorder(T->l);
		cout<<T->key<<":"<<T->value<<endl;
		inorder(T->r);
	}


}

void AVL::create()
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

node* AVL::insert(node *T,string e,string f)
{
	node *a,*b,*c;
	if(T==NULL)
	{
		T=new node(e,f);
		*d=true;
		return T;


	}

	if(e < T->key)
	{
		T->l=insert(T->l,e,f);
		if(*d)
		{
			switch(T->bf)
			{
				case 0:T->bf=1;
					break;
				case -1:T->bf=0;
				*d=false;
				break;
				case 1:b=T->l;
				a=T;
				if(b->bf==1)
				{
					a->l=b->r;
					b->r=a;
					a->bf=b->bf=0;
					T=b;
				}
				else
				{
					c=b->r;
					b->r=c->l;
					a->l=c->r;
					c->l=b;
					c->r=a;
					switch(c->bf)
					{
						case 1:a->bf=-1;
							b->bf=0;
							break;
						case 0:b->bf=a->bf=0;
							break;
						case -1:b->bf=1;
							a->bf=0;
							break;
					}
					c->bf=0;
					T=c;
					*d=false;
				}
				break;


			}
		}
	}

	else
	{
		T->r=insert(T->r,e,f);

				if(*d)
				{
					switch(T->bf)
					{
						case 0:T->bf=-1;
							break;
						case 1:T->bf=0;
							*d=false;
							break;
						case -1:b=T->r;
						a=T;
						if(b->bf==-1)
						{
							a->r=b->l;
							b->l=a;
							a->bf=b->bf=0;
							T=b;
						}
						else
						{
							c=b->l;
							b->l=c->r;
							a->r=c->l;
							c->r=b;
							c->l=a;
							switch(c->bf)
							{
								case 1:a->bf=0;
									b->bf=-1;
									break;
								case 0:b->bf=a->bf=0;
									break;
								case -1:b->bf=1;
									a->bf=0;
									break;
							}
							c->bf=0;
							T=c;
							*d=false;
						}
						break;


					}
				}

	}

	return T;
}

void AVL::update()
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

int AVL::height1(node *T)
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

void AVL::ascending()
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

void AVL::descending()
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
				T=T->r;

			}
			if(i==0)
			{
				return;
			}
			T=stack[i];
			i=i-1;
			cout<<T->key<<":"<<T->value<<endl;
			T=T->l;
		}

}

node* AVL::del(node* T,string key)
{
	node *a,*b,*c;
	if(T==NULL)
	{
		cout<<"not found";
		return T;
	}

	if(key <T->key)
	{
		T->l=del(T->l,key);
		if(*d)
				{
					switch(T->bf)
					{
						case 0:T->bf=1;
							break;
						case -1:T->bf=0;
						*d=false;
						break;
						case 1:b=T->l;
						a=T;
						if(b->bf==1)
						{
							a->l=b->r;
							b->r=a;
							a->bf=b->bf=0;
							T=b;
						}
						else
						{
							c=b->r;
							b->r=c->l;
							a->l=c->r;
							c->l=b;
							c->r=a;
							switch(c->bf)
							{
								case 1:a->bf=-1;
									b->bf=0;
									break;
								case 0:b->bf=a->bf=0;
									break;
								case -1:b->bf=1;
									a->bf=0;
									break;
							}
							c->bf=0;
							T=c;
							*d=false;
						}
						break;


					}
				}

	}

	if(key >T->key)
	{
		T->r=del(T->r,key);

		if(*d)
						{
							switch(T->bf)
							{
								case 0:T->bf=-1;
									break;
								case 1:T->bf=0;
									*d=false;
									break;
								case -1:b=T->r;
								a=T;
								if(b->bf==-1)
								{
									a->r=b->l;
									b->l=a;
									a->bf=b->bf=0;
									T=b;
								}
								else
								{
									c=b->l;
									b->l=c->r;
									a->r=c->l;
									c->r=b;
									c->l=a;
									switch(c->bf)
									{
										case 1:a->bf=0;
											b->bf=-1;
											break;
										case 0:b->bf=a->bf=0;
											break;
										case -1:b->bf=1;
											a->bf=0;
											break;
									}
									c->bf=0;
									T=c;
									*d=false;
								}
								break;


							}
						}
	}

	if(T->l==NULL && T->r==NULL)
	{
		delete T;
		*d=true;
		return NULL;
	}

	node *p;
	if(T->r==NULL)
	{
		p=T->l;
		*d=true;
		delete T;
		return p;

	}
	*d=true;
	p=T->r;
	while(p->l!=NULL)
	{
		p=p->l;
	}
	T->key=p->key;
	T->value=p->value;
	T->r=del(T->r,p->key);
	if(*d)
					{
						switch(T->bf)
						{
							case 0:T->bf=-1;
								break;
							case 1:T->bf=0;
								*d=false;
								break;
							case -1:b=T->r;
							a=T;
							if(b->bf==-1)
							{
								a->r=b->l;
								b->l=a;
								a->bf=b->bf=0;
								T=b;
							}
							else
							{
								c=b->l;
								b->l=c->r;
								a->r=c->l;
								c->r=b;
								c->l=a;
								switch(c->bf)
								{
									case 1:a->bf=0;
										b->bf=-1;
										break;
									case 0:b->bf=a->bf=0;
										break;
									case -1:b->bf=1;
										a->bf=0;
										break;
								}
								c->bf=0;
								T=c;
								*d=false;
							}
							break;


						}
					}


}


int main() {

	AVL b,b1;

	int ch;

	do
	{
		cout<<"\n1:create\n2:display in ascending-order\n3:display in descending-order\n4:update\n5:max comparisons\n6:delete\n7:exit\n";

		cin>>ch;

		switch(ch)
		{
		case 1:b.create();
			break;
		case 2:b.ascending();
			break;
		case 3:b.descending();
			break;
		case 4:b.update();
			break;
		case 5:b.height();
			break;
		case 6:b.del();
			break;
		case 7:ch=0;
			break;
		}

	}while(ch);



	return 0;
}
