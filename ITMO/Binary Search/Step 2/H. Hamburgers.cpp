// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
// Problem tags : advanced binary search
// TC : O(log(1e15))
// SC : O(1)

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define ms(a,x)             memset (a,x,sizeof(a))
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define umap                unordered_map
#define uset                unordered_set
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v,n)    for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9+7;

bool isHamPossible(ll h, ll &p, ll &q, ll &r, ll &a, ll &b, ll &c, ll &x, ll &y, ll&z, ll &rb)
{
    //predicate function: returns if 'h' hamburgers can be made using <='r' rubles or not
    ll reqb=max(0LL,(h*p)-a);
    ll reqs=max(0LL,(h*q)-b);
    ll reqc=max(0LL,(h*r)-c);
    ll rubles=(reqb*x)+(reqs*y)+(reqc*z);
    return rubles<=rb;
}

void solve()
{
    //using advanced binary search + predicate function    
    string s;
    cin>>s;
    ll a,b,c,x,y,z,rb;
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    cin>>rb;
    //counting no of B,S,C as p,q,r respectively
    ll p=0,q=0,r=0;
    for (auto &it: s)
    {
        if (it=='B')
            p++;
        else if (it=='S')
            q++;
        else
            r++;
    }
    //predicate function: isHamPossible returns TTTTFFFF
    //find the last occurence of T -> maximum number of Hamburgers
    ll lo=0,hi=1e15;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isHamPossible(mid,p,q,r,a,b,c,x,y,z,rb))
            lo=mid;
        else
            hi=mid-1;
    }
    if (isHamPossible(hi,p,q,r,a,b,c,x,y,z,rb))
        cout<<hi;
    else
        cout<<lo;
}

int main()
{
    clock_t clk = clock();
    sync;
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
        cout<<endl;
    }
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
