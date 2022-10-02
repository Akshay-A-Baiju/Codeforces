// Author: Akshay A Baiju
// Problem: D. Fast search
// URL: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

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
    ll n; cin>>n;
    vector <ll> v(n);
    for (auto &it: v)
        cin>>it;
    sort(v.begin(),v.end());
    ll k; cin>>k;
    while (k--)
    {
        ll l,r; cin>>l>>r;
        // find lower bound index of l
        ll ind_l,ind_r;
        ll lo=0,hi=n-1;
        while (hi-lo>1)
        {
            ll mid=(hi+lo)/2;
            if (v[mid]<l)
                lo=mid+1;
            else
                hi=mid;
        }
        if (v[lo]>=l)
            ind_l=lo;
        else if (v[hi]>=l)
            ind_l=hi;
        else
        {
            // no element in range [l,r]
            cout<<0<<" ";
            continue;
        }
        // find upper bound index of r - 1
        lo=0,hi=n-1;
        while (hi-lo>1)
        {
            ll mid=(hi+lo)/2;
            if (v[mid]<=r)
                lo=mid+1;
            else
                hi=mid;
        }
        if (v[lo]>r)
            ind_r=lo;
        else if (v[hi]>r)
            ind_r=hi;
        else
            ind_r=n;
        ind_r--;
        ll ans=ind_r-ind_l+1;
        cout<<ans<<" ";
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