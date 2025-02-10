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

    vector<vector<char>> grid(n, vector<char>(m, '.'));
   queue<pair<pair<long, long>, long>> q;
                pair<long, long> p;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];

            if(grid[i][j] == 'A'){
                p.first = i;
                p.second = j;
                q.push({p, 0});
            }

        }
    }
    
    // cout<<p.first<<" "<<p.second;
    bool ans = true;
    vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> pathDir(n, vector<char>(m, '#'));
    vector<vector<long>> vis(n, vector<long>(m, 0));
    
    string dir = "DRUL";
    int cnt = -1;
    int startC, startR;
    while(!q.empty()){
        auto front = q.front();
        q.pop();

        long r = front.first.first;
        long c = front.first.second;
        long d = front.second;
        // string str = front.second.second;
        
        
        // cout<<r<<" "<<c<<" "<<d<<" "<<str<<endl;


        if(grid[r][c] == 'B'){
            // cout<<"here";
            cout<<"YES"<<endl;
            cout<<d<<endl;
            cnt = d;
            startR = r;
            startC = c;
            // cout<<str<<endl;
            ans = false;
            break;
        }

        if(r + 1 < n && grid[r+1][c] != '#' && !vis[r+1][c]){
            vis[r+1][c] = 1;
            q.push({{r+1, c}, d+1});
            path[r+1][c] = {r, c};
            pathDir[r+1][c] = dir[0];
        }
        if(c + 1 < m && grid[r][c+1] != '#' && !vis[r][c+1]){
            vis[r][c+1] = 1;
            q.push({{r, c+1}, d+1});
            path[r][c+1] = {r, c};
            pathDir[r][c+1] = dir[1];
        }
        if(r -1  >= 0 && grid[r-1][c] != '#' && !vis[r-1][c]){
            vis[r-1][c] = 1;
            q.push({{r-1, c}, d+1});
            path[r-1][c] = {r, c};
            pathDir[r-1][c] = dir[2];
        }
        if(c - 1 >= 0 && grid[r][c-1] != '#' && !vis[r][c-1]){
            vis[r][c-1] = 1;
            q.push({{r, c-1}, d+1});
            path[r][c-1] = {r,c};
            pathDir[r][c-1] = dir[3];
        }

    }
    // path[p.first][p.second] = {-1, -1};
    
    // for(auto it:path){
    //     for(auto i:it){
    //         cout<<"{"<<i.first<<","<<i.second<<"} ";
    //     }
    //     cout<<endl;
    // }
    
    // for(auto it:pathDir){
    //     for(auto i:it){
    //         cout<<i;
    //     }
    //     cout<<endl;
    // }
    if(ans)
        cout<<"NO";
    else{
        string str = "";
        while(pathDir[startR][startC] != '#' && cnt--){
            // cout<<startR<<" "<<startC<<" "<<pathDir[startR][startC]<<endl;
            // cout<<path[startR][startC].first<<" "<<path[startR][startC].second<<endl;
            
            str += pathDir[startR][startC];
            int nstartR = path[startR][startC].first;
            int nstartC = path[startR][startC].second;
            startR = nstartR;
            startC = nstartC;
        }
        // str+= pathDir[startR][startC];
        reverse(str.begin(), str.end());

        cout<<str<<endl;
    }

    
}