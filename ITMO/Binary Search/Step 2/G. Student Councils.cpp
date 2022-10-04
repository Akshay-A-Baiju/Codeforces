// Author: Akshay A Baiju
// Problem: G. Student Councils
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"   //not to be used in interactive problems
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.141592653589793238462

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;

bool isPossible(ll c, vector <ll> &v, ll &k)
{
    ll seats=0;
    for (auto &it: v)
        seats+=min(it,c);
    return (seats>=c*k);
}

void solve()
{
    ll k,n; cin>>k>>n;
    vector <ll> v(n);
    for (auto &it: v) cin>>it;
    // BS on Ans
    // TTTFFF
    ll lo=1,hi=1e15;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(mid,v,k))
            lo=mid;
        else
            hi=mid-1;
    }
    if (isPossible(hi,v,k))
        cout<<hi;
    else
        cout<<lo;
}

int main()
{
    sync;
    int t=1;
    // cin>>t;
    for (int test=1;test<=t;test++)
    {
        solve();
        cout<<endl;
    }
    return 0;
}