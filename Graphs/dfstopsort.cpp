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
	}

	void topsort()
	{
		//	
		int* indegree=new int[V];
		for(int i=0;i<V;i++)
		{
			indegree[i]=0;
         }
		//update indegree by traverersing by x->y //array of pointers 
		for(int i=0;i<V;i++)
		{
			
			for(auto y:l[i])
			{
				indegree[y]++;
			}
		}
		

		queue<int >q;

		//1. apply bfs
		//2. find nodes with 0 indegree

		for(int i=0;i<V;i++)
		{
			if(indegree[i]==0)
			{
				q.push(i);
				//cout<<" q : "<<i<<"\n";
			}

		}
		while(!q.empty())
		{
			int node=q.front();
			cout<<node<<"  ";
			q.pop();

			//iterate over neighbour of that node and reduce theie indegree
			for(int n:l[node])
			{
				indegree[n]--;
				if(indegree[n]==0){
					q.push(n);
					//cout<<" q : "<<n <<endl;
				}

			}


		}

	}

};


int main()
{
		Graph g(6);
		g.addEdge(0,2);	
		g.addEdge(1,2);
		g.addEdge(2,3);	
		g.addEdge(2,5);
		g.addEdge(1,4);	
		g.addEdge(4,5);
		g.addEdge(3,5);
		
		g.topsort();

	return 0;
}
