#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class graph
{
    public: 
    // iniitialising a map for storing all the values and edges
    unordered_map<T,list<T>> adj;
    // node and edges for typename t
    void addEdge( T node ,T edge, bool direction )
    {
        adj[node].push_back( edge );
        // condition for undirected graph
        if( direction == 0 )
        {
            adj[edge].push_back(node);
        }
    }
    void printEdges()
    {
        for( auto idx: adj )
        {
            cout<<idx.first<<"-> ";
            for( auto edge : idx.second )
            {
                cout<<edge<<" "; 
            }
            cout<<endl;
        }
    }          
};
int main()
{
    graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,0,0);
    g.addEdge(1,3,0);
    g.printEdges();
    return 0;
}