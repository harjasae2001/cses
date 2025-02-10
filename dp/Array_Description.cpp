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

int f(int i, int prev, vector<int>& arr, int m){
    if(i == arr.size())
        return 0;

    int zero = 0, one = 0, minusOne = 0;

    if(arr[i] == 0){
        if(prev != -1){
            
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;

    vector<int> arr(n, 0);

    for(int i=0; i<n; i++)
        cin>>arr[i];


    cout<<f(n-1, -1, arr, m);
}