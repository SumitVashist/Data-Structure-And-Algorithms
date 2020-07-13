#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T>> l;
	
public:
	void addEdge(string x, string y)
	{
		l[x].push_back(y);
		//l[y].push_back(x);		
	}

	void dfss(T src,map<T,bool> &visited,list<T>&ord)
	{
		//cout<<src<<" ";
		visited[src]=true;

		for(T nbr:l[src])
		{
			if(!visited[nbr])
			dfss(nbr,visited,ord);
		}
		ord.push_front(src);
		return;
	}


	void dfs()
	{
		map<T,bool>visited;
		list<T>ord;
		for(auto p: l)
		{
			T node=p.first;
			visited[node]=false;

			}	


		for(auto p: l)
		{
			T node=p.first;
				if(!visited[node])
					{
					dfss(node,visited,ord);
					cout<<endl;


	           }
							
			}	

		for(auto node: ord	)
			cout<<node<<endl;
		
		
	}
};


int main()
{
		Graph<string>g;
		//g.addEdge(0,1);	

		g.addEdge("python","datapre");
		g.addEdge("python","pytorch");
		g.addEdge("python","ml");
		g.addEdge("datapre","ml");
		g.addEdge("pytorch","ml");
		g.addEdge("ml","dl");
		g.addEdge("dl","face");
		g.addEdge("dataset","face");		
		
		g.dfs();

	return 0;
}
