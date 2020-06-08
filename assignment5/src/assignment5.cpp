//============================================================================
// Name        : assignment5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Graph
{
	int adj[20][20],G[20][20],result[20][20];
	int n;
	int visit[20];

public:

	Graph()
	{
		int i;
		for(i=0;i<=19;i++)
		{

			visit[i]=0;
		}

	}
	void create_graph();
 	void print();
 	void kruskal();
 	void prims(int);
 	void DFS(int v);
 	void clear();


};

void Graph::create_graph()
{
	int max,origin,destin,i,j,weight;
	for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			adj[i][j]=0;
			G[i][j]=0;
			result[i][j]=0;
			visit[i]=0;

		}

	}

	cout<<"enter no. of vertices\n";
	cin>>n;

	max=((n*(n-1))/2);

	for(i=1;i<=max;i++)
	{
		cout<<"enter origin and destination\n";
		cin>>origin>>destin;

		if(origin<0 || destin<0)
		{
			break;
		}
		cout<<"enter weight of edge\n";
		cin>>weight;

		if(origin>=n || destin>=n || origin<0 || destin<0 )
		{
			cout<<"invalid edge\n";
			i--;
		}
		else
		{
			adj[origin][destin]=adj[destin][origin]=weight;
			G[origin][destin]=G[destin][origin]=weight;
		}
	}



}

void Graph::clear()
{
	int max,origin,destin,i,j,weight;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			G[i][j]=adj[i][j];

			result[i][j]=0;
			visit[i]=0;

		}

	}

}

void Graph::DFS(int v)
{
	int j;

	visit[v]=1;
	cout<<v<<"\t";
	for(j=0;j<n;j++)
	{
		if(adj[v][j]!=0 && visit[j]==0)
		{
			DFS(j);
		}
	}

}


void Graph::kruskal()
{
	int min=9999,wt_t=0,count=0,father[20],i,j,temp,t,t1,temp1,root_t,root_t1;

	for(i=0;i<=19;i++)
	{
		father[i]=-1;
	}

	while(count < n-1)
	{

		min=9999;

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(min > G[i][j] && G[i][j]!=0)
				{
					min=G[i][j];
					temp=i;
					temp1=j;
				}
			}
		}

		t=temp;
		t1=temp1;

		G[temp][temp1]=G[temp1][temp]=0;
		while(temp >= 0)
		{
			root_t=temp;
			temp=father[temp];
		}
		while(temp1 >= 0)
		{
			root_t1=temp1;
			temp1=father[temp1];
		}

		if(root_t!=root_t1)
		{
			result[t][t1]=result[t1][t]=min;
			wt_t=wt_t+min;
			father[root_t1]=root_t;
			count++;
		}


	}

	cout<<"cost of MST is "<<wt_t<<endl;



}


void Graph::prims(int v1)
{
	int min=9999,wt_t=0,count=0,father[20],i,j,temp,t,t1,temp1,root_t,root_t1,count1=0,arr[20],v2;

	for(i=0;i<=19;i++)
	{
		father[i]=-1;
		arr[i]=0;
	}

	arr[count1]=v1;
	count1++;
	while(count < n-1)
	{

		min=9999;

		for(v1=0;v1<count1;v1++)
		{
			for(v2=0;v2<n;v2++)
			{
				if(G[arr[v1]][v2]!=0 && min > G[arr[v1]][v2] )
				{
					min=G[arr[v1]][v2];
					temp=arr[v1];
					temp1=v2;
				}
			}
		}

		t=temp;
		t1=temp1;

		G[temp][temp1]=G[temp1][temp]=0;
		while(temp >= 0)
		{
			root_t=temp;
			temp=father[temp];
		}
		while(temp1 >= 0)
		{
			root_t1=temp1;
			temp1=father[temp1];
		}

		if(root_t!=root_t1)
		{
			result[t][t1]=result[t1][t]=min;
			wt_t=wt_t+min;
			father[root_t1]=root_t;
			count++;
			arr[count1]=t1;
			count1++;
		}


	}

	cout<<"cost of MST is "<<wt_t<<endl;



}


int main() {
	Graph g;
	int ch,i;

	do
	{
		cout<<"\n1:create\n2:cost of MST(kruskal)\n3:print\n4:cost of MST(prims)\n5:exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:g.create_graph();
			break;
		case 2:g.kruskal();
			break;
		case 3:g.DFS(0);
			break;
		case 4:g.clear();
				g.prims(0);
			break;
		case 5:ch=0;
			break;
		case 6:
			break;


		}

	}while(ch);


	return 0;
}
