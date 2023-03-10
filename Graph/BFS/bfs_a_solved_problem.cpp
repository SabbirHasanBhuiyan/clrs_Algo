//Bismillah
/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
*/
#include<bits/stdc++.h>
using namespace std;

const int mx=1e4+1;
struct info{
    int color;
    int d;
    int par;
}node[mx];
vector<int> adj[mx];
void bfs(vector<int> adj[],int s,int n)
{
    for(int i=1;i<=n;i++){
        node[i].color=1;
        node[i].d=1e9;
        node[i].par=-1;
    }

    node[s].color=2; //2 indicates gray
    node[s].d=0;
    node[s].par=-1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &v: adj[u]){
            if(node[v].color==1){
                node[v].color=2;
                node[v].d=node[u].d+1;
                node[v].par=u;
                q.push(v);
            }
        }

        node[u].color=3;
    }
}
int main()
{

    int n,e,u,v,t;
    cin>>t;
    while(t--){
        cin>>n>>e;
        for(int i=1;i<=n;i++)   adj[i].clear();
        for(int i=1;i<=e;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(adj,1,n);
        cout<<node[n].d<<endl;

    }

    return 0;
}
