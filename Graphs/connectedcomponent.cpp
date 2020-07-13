#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T>> l;
	
public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);		
	}

	void dfss(T src,map<T,bool> &visited)
	{
		cout<<src<<" ";
		visited[src]=true;
		for(T nbr:l[src])
		{
			if(!visited[nbr])
			dfss(nbr,visited);
		}

	
	}


	void dfs()
	{
		map<T,bool>visited;
		for(auto p: l)
		{
			T node=p.first;
			visited[node]=false;

			}	
		int cnt=0;	
		for(auto p: l)
		{
			T node=p.first;
		//			visited[node]=false;
	

				if(!visited[node])
					{
					cout<<"component"<<cnt<<" -- >  ";
					dfss(node,visited);
					cnt++;
					cout<<endl;


	}
							
			
		
			}	
		
		
	}
};


int main()
{
		Graph<int>g;
		g.addEdge(0,1);	

		g.addEdge(1,2);
		g.addEdge(2,3);
		g.addEdge(0,3);
		g.addEdge(0,4);
		g.addEdge(5,6);
		g.addEdge(6,7);
		g.addEdge(8,8);
		
		
		g.dfs();

	return 0;
}
