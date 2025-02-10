#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7;
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

    }


    vector<int> vis(n+1);
    int size = 0
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            size++;
            dfs(i, adj, vis);
        }
    }


    cout<<size<<endl;

    for(int )
}