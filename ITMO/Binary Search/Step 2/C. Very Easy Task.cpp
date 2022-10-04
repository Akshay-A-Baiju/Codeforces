// Author: Akshay A Baiju
// Problem: C. Very Easy Task
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C

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

bool isPossible(ll time, ll &n, ll &x, ll &y)
{
    time-=min(x,y);
    ll copies=1;
    copies+=time/x;
    copies+=time/y;
    return copies>=n;
}

void solve()
{
    ll n,x,y; cin>>n>>x>>y;
    // BS on Ans
    // FFFTTT
    ll lo=min(x,y),hi=n*max(x,y);
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(mid,n,x,y))
            hi=mid;
        else
            lo=mid+1;
    }
    if (isPossible(lo,n,x,y))
        cout<<lo;
    else
        cout<<hi;
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