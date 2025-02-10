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

// int f(int i, int j, string &s, string &t)
// {
//     if (i == s.size() || j == t.size())
//         return 0;
//     if (s[i] == t[j])
//         return 1 + f(i + 1, j + 1, s, t);
//     return max(f(i + 1, j, s, t), f(i, j + 1, s, t));
// }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

    // cout << f(0, 0, s, t);

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = t.size() - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    // for(auto it: dp){
    //     for(auto it1: it){
    //         cout<<it1<<" ";
    //     }
    //     cout<<endl;
    // }

    string ans = "";

    for(int i=s.size()-1; i>=1;){
        for(int j=t.size()-1; j>=1;){
           if(dp[i][j] == dp[i-1][j-1] + 1 && dp[i][j] != max(dp[i][j-1], dp[i-1][j])){
               ans += s[i];
               i--;
               j--;
           }
           else{
                j--;
           }

        }
    }
    
    cout<<ans;

    return 0;
}