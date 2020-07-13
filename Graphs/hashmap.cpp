#include<bits/stdc++.h>
using namespace std;



class Graph{
    map<string ,list<pair<string,int>>>l;

	public:

		void addEdge(string u,string v,bool bidir,int wt=0)
		{
                l[u].push_back(make_pair(v,wt));
                if(bidir==true)
                    l[v].push_back(make_pair(u,wt));
		}


        void print()
        {
            for(auto p : l)
                {
                string c=p.first;
                list<pair<string ,int>>nb=p.second;               // for(int vertex:l[i])
                for(auto n:nb)
                    {
                        cout<<n.first<<" "<<n.second<<",";

                    }
                cout<<endl;
            }


        }
};



int main()
{
	Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",true,50);
    //g.addEdge("C","D",30);
    g.addEdge("D","A",false,20);

    g.print();



	return 0;
}
