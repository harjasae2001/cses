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

int dfs(int node, vector<vector<int>> &edges, vector<int> &dist, vector<int>& vis)
{   
    vis[node] = 1;
    int maxi = INT_MIN;
    for(auto i:edges[node])
    {
        if(!vis[i]){
            maxi = max(maxi, dfs(i, edges, dist, vis)+1);
        }
    }

    dist[node] = maxi;
    return dist[node];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    vector<vector<int>> edges(n);

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        // a--;
        // b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> dist(n,0);

    int ans = dfs(1, edges, dist);

    cout<<ans<<endl;
}