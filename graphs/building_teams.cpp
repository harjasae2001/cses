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
 
bool dfs(int u, vector<int> adj[], vector<int> &vis, int color)
{
    
    vis[u] = color;
 
    for(auto it:adj[u]){
        // cout<<u<<" "<<it<<" "<<color<<endl;
        if(vis[it] == -1){
           if(dfs(it, adj, vis, 1-color) == false)
                return false;
                // return false;
        }
        else if(vis[it] == color){
            return false;
        }
    }
 
    return true;
 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
 
    vector<int> adj[n + 1];
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    vector<int> vis(n + 1, -1);
 
    // for(int i=1; i<=n; i++){
    //     cout<<i<<"->";
    //     for(auto it:adj[i])
    //         cout<<it<<" ";
 
    //     cout<<endl;
    // }
    
    bool ans = true;
    for(int i=1; i<=n; i++){
        if(vis[i] == -1){
            // cout<<i<<" "<<dfs(i, adj, vis, 0);
            ans = ans & dfs(i, adj, vis, 0);
        }
    }
 
    if(ans){
        for(int i=1; i<=n; i++)
            cout<<vis[i]+1<<" ";
    }
    else{
        cout<<"IMPOSSIBLE";
    }
 
}
