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

int f(int i, int pl, vector<int>& p, vector<int>& n){
    // if(i < 0)
    //     return INT_MAX;
    // if(pl == 0)
    //     return 0;

    if(pl < 0)
        return INT_MAX;

    if(i == 0){
        if(pl >= p[0])
            return n[0];

        return INT_MAX;
    }

    int pick, notPick;
    // if(pl >= p[i])
        pick = f(i-1, pl-p[i], p, n) + n[i];
    
    notPick = f(i-1, pl, p, n);
    return max(pick, notPick);

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin>>n>>x;

    vector<int> price(n, 0), nop(n, 0);

    for(int i=0; i<n; i++)
        cin>>price[i];

    for(int i=0; i<n; i++)
        cin>>nop[i];

    vector

    cout<<f(n-1, x, price, nop, dp);
}