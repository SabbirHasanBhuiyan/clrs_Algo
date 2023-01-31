#include <bits/stdc++.h>
using namespace std;

const int mx=1e5+1;
struct info{
    int color;
    int par;
    int d;
    int f;
}node[mx];
vector<int> adj[mx];

int Time;


void DFS_VISIT(vector<int> adj[],int u)
{
    Time=Time+1;
    node[u].d=Time;
    node[u].color=2; //2 implies gray

    for(auto &v: adj[u]){
        if(node[v].color==1){    //1 implies white
            node[v].par=u;
            DFS_VISIT(adj,v);
        }
    }

    node[u].color=3; //3 implies black
    Time=Time+1;
    node[u].f=Time;
}

void DFS(vector<int> adj[],int n)
{
    for(int i=1;i<=n;i++){
        node[i].color=1; //1 implies white
        node[i].par=-1;
    }
    Time=0;
    for(int i=1;i<=n;i++){
        if(node[i].color==1){
            DFS_VISIT(adj,i);
        }
    }
}


int main() {

    int n,m,u,v;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    DFS(adj,n);

    return 0;
}
