#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define inf 1000000;
/*
class edge{
protected:
	int e;
	int w;
};*/

struct edge{
	int v,w;
};
bool operator <( edge a, edge b ) {
	return a.w < b.w;
}
class Graph
{   
	int u,v;
    int V;                                     // No. of vertices
    vector<edge> *adj;              //adjecentry list
    
public:
    Graph(int V);                            // Constructor
    void addEdge(int u, int v, int w);       // function to add an edge to graph
    int dijkstra(int s,int t);
    int bellman_ford(int s,int t,int m);
};


Graph::Graph(int V){
	this->V =V;
    adj = new vector<edge> [V];
    //edge ee;
}

void Graph::addEdge(int u, int v, int w)
{
	this->u=u;
	this->v=v;
	//this->w=w;
    adj[u].push_back(edge{v,w}); // Add w to v’s list.
    adj[v].push_back(edge{u,w});
}

int Graph::dijkstra(int s,int t){ 
	int dist[this->V],i;
	for(int i=0;i<V;i++)
		  dist[i]=inf;
	priority_queue<edge> q;
	q.push(edge{s,0});
	dist[s] = 0;
	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();

		for ( i = 0; i < adj[ p.v ].size(); ++i ) {
			edge k = adj[ p.v ][ i ];
			//cout<<i;
			if ( dist[ p.v ] + k.w < dist[ k.v ] ) {
				dist[ k.v ] = dist[ p.v ] + k.w;
				q.push( k );
			}
		}
     }cout<<dist[t];
}
/*
int Graph::bellman_ford(int s,int t,int m){
	int dist[this->V];
	for(int i=0;i<V;i++)
		dist[i]=inf;
	dist[s]=0;
	int E=m;
	  for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = adj[j].v;
            int v = adj[j].w;
            int weight = graph->adj[j].weight;
            if (dist[u] != inf && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }cout<<dist[t];
}
*/
/*
int main(){
	int n,m; cin>>n>>m;
	Graph g(n);int u,v,w;
	for (int i = 0; i < m; ++i ) {
			cin>>u>>v>>w;
			g.addEdge(u,v,w);

		}
		int s,t;
		cin>>s>>t;
		g.dijkstra(s,t,m);

}
*/
