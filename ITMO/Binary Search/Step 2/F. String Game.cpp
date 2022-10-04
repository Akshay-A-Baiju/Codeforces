// Author: Akshay A Baiju
// Problem: F. String Game
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F

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

bool isPossible(ll ind, vector <ll> &v, string &t, string &p)
{
    ll n=t.length(),m=p.length();
    set <ll> donTake;
    for (ll i=0;i<=ind;i++) donTake.insert(v[i]-1);
    bool ok=true;
    ll i=0,j=0;
    while (i<n && j<m)
    {
        if (donTake.find(i)!=donTake.end())
        {
            i++;
            continue;
        }
        if (t[i]==p[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    return j==m;
}

void solve()
{
    string t,p; cin>>t>>p;
    ll n=t.length();
    vector <ll> v(n);
    for (auto &it: v) cin>>it;
    // BS on index
    // TTTFFF
    ll lo=0,hi=n-1;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(mid,v,t,p))
            lo=mid;
        else
            hi=mid-1;
    }
    ll ind;
    if (isPossible(hi,v,t,p))
        ind=hi;
    else if (isPossible(lo,v,t,p))
        ind=lo;
    else
        ind=-1;
    ll ans=ind+1;
    cout<<ans;
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