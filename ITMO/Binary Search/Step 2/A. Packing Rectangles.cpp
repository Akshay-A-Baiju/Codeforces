// Author: Akshay A Baiju
// Problem: A. Packing Rectangles
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

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

bool isPossible(ll side, ll &w, ll &h, ll &n)
{
    ll a=side/w;
    ll b=side/h;
    ll rect_cnt=a*b;
    return rect_cnt>=n;
}

void solve()
{
    ll w,h,n; cin>>w>>h>>n;
    // BS on Ans
    // FFFTTT
    ll lo=0,hi=max(w*n,h);
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(mid,w,h,n))
            hi=mid;
        else
            lo=mid+1;
    }
    if (isPossible(lo,w,h,n))
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