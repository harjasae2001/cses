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

int dfs(int start, vector<int> adj[],int end){
    int size = 1;
    for(auto it: adj[start]){
        if(it == end){
            return 1;
        }
        else{
            return 1 + dfs(it, adj, end);
        }
    }

    return size;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   int n,m;
   cin>>n>>m;

   vector<int> adj[n+1];

   for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
   }


   for(int i=1; i<=n; i++){
        int sz = dfs(i, adj, i);
        if(sz > 3){
        cout<<i<<" "<<sz<<endl;
            // dfs(i, adj, vis);
        }
   }
}