//Bismillah
/*
https://cses.fi/problemset/task/1671/
you can read this statement
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx=1e5+1;
struct info{
    ll d;
    ll par;
}node[mx];

vector<pair<ll,ll> > adj[mx];
void INITIALIZE_SINGLE_SOURCE(int s,int n)
{
    for(int i=1;i<=n;i++){
        node[i].d=1e18;
        node[i].par=-1;
    }
    node[s].d=0;
    node[s].par=-1;
}

void dijkstra(int s,int n)
{
    INITIALIZE_SINGLE_SOURCE(s,n);

    priority_queue<int,vector<int> , greater<int>>pq;

    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> ,greater<pair<ll,ll>> >q;
    q.push({0,s});

    while(!q.empty()){
        auto temp=q.top();
        ll u=temp.second;
        ll curD=temp.first;
        q.pop();
        if(curD!=node[u].d) continue;

        for(auto &x: adj[u]){
            ll v=x.first;
            ll w=x.second;
            if((curD+w)<node[v].d){
                node[v].d=curD+w;
                node[v].par=u;
                q.push({node[v].d,v});
            }
        }

    }
}
int main()
{
/*
https://cses.fi/problemset/result/5384345/
you can submit soln to this problem
*/
    ll n,m,u,v,t,w;

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
     //   adj[v].push_back({u,w}); cancel it for undirected graph
    }

    dijkstra(1,n);

    for(int i=1;i<=n;i++){
        cout<<node[i].d<<" ";
    }

    cout<<endl;

    return 0;
}

