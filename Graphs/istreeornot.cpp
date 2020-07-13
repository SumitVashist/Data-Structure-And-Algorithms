/*
check if we visit a node more than one path then 
it is more visited 

one corner case is that 
	you have to check that this is not  a parent 
 
	if visited node is the parent of current of the node you are currently visiting then
	we have to ignore that node
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
	
	list<int> *l;
	int V;	
public:
	Graph(int v)
	{
		this->V=v;
		 l =new list<int>[V];

	}
	void addEdge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x); 
	}

	bool istree()
	{
		bool *visited=new bool[V];
		int *parent=new int [V];
		queue<int >q;
		for(int i=0;i<V;i++)
		{	visited[i]=false;
			parent[i]=i;
		}
		int src=0;
		q.push(src);
		visited[src]=0;

		//pop out each node and visit its neighbour


		while(!q.empty())
		{

		int node=q.front();
		q.pop();
				for(int nbr:l[node])
				{
						if(visited[nbr]==true and parent[node]!=nbr)
						return false;
						else if(!visited[nbr])
						{
							visited[nbr]=true;
							parent[nbr]=node;
							q.push(nbr);
						}
				}

		}
		return true;
	}
};


int main()
{
		Graph g(4);
		g.addEdge(0,1);	
		g.addEdge(3,2);
		g.addEdge(1,2);	
		//g.addEdge(0,3);
		
		bool ans=g.istree();
		if(ans==true)
			cout<<"true";
		else
			cout<<"false";
	

	return 0;
}
