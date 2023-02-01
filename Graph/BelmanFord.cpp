///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;


const ll infLL = 1e18;
const int mx = 1e3+1;
vector<vector<int> > edges;
struct info{
    ll d; //long long has been typedef as ll
    int par;
}node[mx];

void INITIALIZE_SINGLE_SOURCE(int s,int n)
{
    for(int i=0;i<n;i++){
        node[i].d=1e18;
        node[i].par=-1;
    }
    node[s].d=0;
}

void RELAX(int u,int v,ll w)
{
    if(node[v].d>(node[u].d+w)){
        node[v].d=node[u].d+w;
        node[v].par=u;
    }
}
bool belmanFord ( int s, int n, int m )
{

    for ( int i = 1; i < n; i++ ) {

        for ( auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            RELAX(u,v,w);
        }
    }

    for ( auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(node[v].d>(node[u].d+w)){
            return false;
        }
    }

    return true;
}


int main()
{

	int t;
	cin >> t;

	while ( t-- ) {
	    edges.clear();
	    int n, m;
	    cin >> n >> m;

	    for ( int i = 0; i < m; i++ ) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        edges.push_back ( { u, v, w } );
	    }

	    if ( belmanFord ( 0, n, m ) == false ) {
	        cout << "possible\n";
	    }

	    else {
	        cout << "not possible\n";
	    }
	}


	return 0;
}








