// Author: Akshay A Baiju
// Problem: B. Closest to the Left
// URL: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

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

void solve()
{
    ll n,k; cin>>n>>k;
    vector <ll> v(n);
    for (auto &it: v)
        cin>>it;
    while (k--)
    {
        ll x; cin>>x;
        ll lo=0,hi=n-1;
        while (hi-lo>1)
        {
            ll mid=(hi+lo)/2;
            if (v[mid]>x)
                hi=mid-1;
            else
                lo=mid;
        }
        if (v[hi]<=x)
            cout<<hi+1<<endl;
        else if (v[lo]<=x)
            cout<<lo+1<<endl;
        else
            cout<<0<<endl;
    }
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