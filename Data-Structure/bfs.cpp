#include<iostream>
#include<vector>
#include <queue>
using namespace std;

struct edge{
	int e;
};
//#define inf 100000001;

void bfs(vector<edge>v[],int s,int m,int n){
	int d[n]={0};
	queue<edge> q;
	q.push((edge){s});
	while(!q.empty()){
		edge f=q.front();
		if(d[f.e]==0){
  		cout<<f.e<<endl;
  		d[f.e]=1;
  		}
		q.pop();
		for(int i=0;i<v[f.e].size();i++){
	  		edge k=v[f.e][i];
	  		if(d[k.e]==0){
	  			q.push(k);
	  		}

		}

    	}
}
int main(){
    int n,m; cin>>n; cin>>m;
    int u,v,w;
	vector<edge> vec[n+1];
	for(int i=0;i<m;i++){
	    cin>>u>>v;
	     vec[u].push_back((edge){v});
	     vec[v].push_back((edge){u});
	}
	int s; cin>>s;
	bfs(vec,s,m,n);
    return 0;
}
