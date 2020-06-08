//============================================================================
// Name        : assgn3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define MAX 30
using namespace std;

class TBT;
class node
{
	int data;
	int lbit,rbit;
	node *l,*r;
public:
	node()
	{

	}
	friend class TBT;
};


class Queue
{
public:
    node* arr[MAX];
    int rear,front;

    Queue()
    {
        rear=front=-1;
    }

    void enque(node* temp)
    {
        int i;

        if(!full())
        {
            if(empty())
            {
                rear=front=0;
                arr[rear]=temp;

            }
            else
            {

                rear++;
                arr[rear]=temp;

            }
        }
       else
        {
            cout<<"queue is full\n";
        }
    }


    node* deque()
    {

        int i;
        node *var;
        if(!empty())
        {

            if(front==rear)
            {

                var=arr[front];
                front=rear=-1;

            }

            else
            {
                var=arr[front];
                front++;

            }
            return var;
        }

        else
        {
            cout<<"queue is empty\n";
        }
    }



    int full()
    {
        if(rear==MAX-1)
        {
            return 1;
        }
        return 0;
    }


    int empty()
    {
        if(rear==-1)
        {
            return 1;
        }
        return 0;
    }



};


class TBT
{
	node *head;
public:
	node* getnode();
	void create();
	void Linsert(node*,node*);
	void Rinsert(node*,node*);
	node *in_succ(node*);
	void inorder();
	void preorder();
	void search(int);
	void del(node*,node*);



};

node* TBT::getnode()
{
	return new node();

}

void TBT::create()
{
Queue Q;
int y;
node *temp,*x;
	head=getnode();
	head->data=0;
	head->lbit=head->rbit=0;
	head->l=head->r=head;

	Q.enque(head);
	while(!Q.empty())
	{
		temp=Q.deque();
		cout<<"enter left data for "<<temp->data<<endl;
		cin>>y;
		if(y!=0)
		{
			x=getnode();
			x->data=y;
			Linsert(temp,x);
			Q.enque(x);

		}

		if(temp!=head)
		{
			cout<<"enter right data for "<<temp->data<<endl;
			cin>>y;
			if(y!=0)
			{
				x=getnode();
				x->data=y;
				Rinsert(temp,x);
				Q.enque(x);

			}


		}
	}


}

void TBT::Rinsert(node *s,node *t)
{
	t->r=s->r;
	t->rbit=s->rbit;
	t->l=s;
	t->lbit=0;
	s->r=t;
	s->rbit=1;

}

void TBT::Linsert(node *s,node *t)
{
	t->l=s->l;
	t->lbit=s->lbit;
	t->r=s;
	t->rbit=0;
	s->l=t;
	s->lbit=1;

}

node* TBT::in_succ(node *x)
{
	if(x->rbit==0)
		return x->r;
	x=x->r;
	while(x->lbit==1)
	{
		x=x->l;
	}

return x;


}

void TBT::inorder()
{
	node *T=head;
	T=T->l;
	while(T->lbit==1)
		T=T->l;

	while(T!=head)
	{
		cout<<T->data<<"\t";
		T=in_succ(T);

	}
	cout<<endl;
}

void TBT::preorder()
{
	int flag=1;
	node *x;
	x=head->l;
	while(x!=head)
	{
		while(flag!=0)
		{
			cout<<x->data<<"\t";
			if(x->lbit==1)
				x=x->l;
			else
				break;
		}
		flag=x->rbit;
		x=x->r;
	}
	cout<<endl;
}

void TBT::search(int z)
{
	node *p,*q,*s;
	q=head;
	p=head->l;

		while(p->lbit==1)
		{

			p=p->l;
		}

		while(p!=head && p->data!=z)
		{

			p=in_succ(p);
		}
		s=p;
		if(p->lbit==0)
		{
			q=p->l;
		}
		while(s->rbit==1)
		{
			s=s->r;

		}
		q=s->r;


	if(p==head)
	{
		cout<<"no such element\n";
		return;
	}
	cout<<q->data<<p->data;
	del(q,p);
}

void TBT::del(node *parent,node *child)
{

	node *cs;
	if(child->lbit==1 && child->rbit==1)
	{
		parent =child;
		cs=child->r;
		while(cs->lbit!=0)
		{
			parent=cs;
			cs=cs->l;
		}
		child->data=cs->data;
		child=cs;

	}
	if(child->lbit==0 && child->rbit==0)
	{
		//cout<<"hi\n";
		if(parent->r==child)
		{
			parent->r=child->r;
			parent->rbit=child->rbit;
		}
		else
		{
			parent->l=child->l;
			parent->lbit=child->lbit;
		}
		delete child;
		return;

	}
	if(child->lbit==1 && child->rbit==0)
	{
		if(parent->l==child)
		{
			parent->l=child->l;
			parent=parent->l;
		}
		else
		{
			parent->r=child->l;
			parent=parent->r;
		}
		while(parent->rbit==1)
		{
			parent=parent->r;
		}
			parent->r=child->r;

		delete child;
		return;

	}
	if(child->lbit==0 && child->rbit==1)
	{
		if(parent->l==child)
		{
			parent->l=child->r;
			parent=parent->l;
		}
		else
		{
			parent->r=child->r;
			parent=parent->r;
		}
		while(parent->lbit==1)
		{
			parent=parent->l;
		}
			parent->l=child->l;

		delete child;
		return;

	}


}

int main()
{
	TBT b;

	int ch,e;

	do
	{
		cout<<"\n1:create\n2:display inorder\n3:display preorder\n4:delete\n5:exit\n";

		cin>>ch;

		switch(ch)
		{
		case 1:b.create();
			break;
		case 2:b.inorder();
			break;
		case 3:b.preorder();
			break;
		case 4:cout<<"enter data to delete\n";
				cin>>e;
				b.search(e);
			break;
		case 5:ch=0;
		}

	}while(ch);



	return 0;
}
