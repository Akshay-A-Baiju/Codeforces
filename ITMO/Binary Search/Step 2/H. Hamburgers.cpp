// Author: Akshay A Baiju
// Problem: H. Hamburgers
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H

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

bool isPossible(ll n, string &str, ll &nb, ll &ns, ll &nc, ll &pb, ll &ps, ll &pc, ll &r)
{
    ll b=0,s=0,c=0;
    for (auto &it: str)
    {
        if (it=='B') b++;
        else if (it=='S') s++;
        else c++;
    }
    ll reqd_b=b*n,reqd_s=s*n,reqd_c=c*n;
    ll rubles=0;
    if (nb<reqd_b) rubles+=(reqd_b-nb)*pb;
    if (ns<reqd_s) rubles+=(reqd_s-ns)*ps;
    if (nc<reqd_c) rubles+=(reqd_c-nc)*pc;
    return rubles<=r;
}

void solve()
{
    string s; cin>>s;
    ll nb,ns,nc; cin>>nb>>ns>>nc;
    ll pb,ps,pc; cin>>pb>>ps>>pc;
    ll r; cin>>r;
    // BS on Ans
    // TTTFFF
    ll lo=0,hi=1e15;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(mid,s,nb,ns,nc,pb,ps,pc,r))
            lo=mid;
        else
            hi=mid-1;
    }
    if (isPossible(hi,s,nb,ns,nc,pb,ps,pc,r))
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
