// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
// Problem tags : advanced binary search, logical
// TC : O(n*log(1e12))
// SC : O(n)

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

void print_inflated(ll time, vll &t, vll &z, vll &y, ll &m)
{
    //edge case : since we checked loon>=m, but we need loons==m, so after 'm' loons are inflated, the rest assistants inflates 0 loons
    ll n=t.size();
    for (ll i=0;i<n;i++)
    {
        ll round=time/(z[i]*t[i]+y[i]);     //complete rounds of work of inflating 'z' ballons and taking 'y' sec rest
        ll loons_in_round=z[i]*round;
        ll extra=time%(z[i]*t[i]+y[i]);     //extra time (not a complete round) 
        ll loons_in_extra=min(extra/t[i], z[i]);
        cout<<min(m,loons_in_round+loons_in_extra)<<" ";
        m-=loons_in_round+loons_in_extra;
        if (m<0)
            m=0;
    }
}

bool canInflate(ll time, vll &t, vll &z, vll &y, ll &m)
{
    ll ballon=0;
    ll n=t.size();
    for (ll i=0;i<n && ballon<m;i++)
    {
        ll round=time/(z[i]*t[i]+y[i]);     //complete rounds of work of inflating 'z' ballons and taking 'y' sec rest
        ll loons_in_round=z[i]*round;
        ll extra=time%(z[i]*t[i]+y[i]);     //extra time (not a complete round) 
        ll loons_in_extra=min(extra/t[i], z[i]);
        ballon+=loons_in_round+loons_in_extra;
    }
    return ballon>=m;
}

void solve()
{ 
	//advanced binary search using predicate function  
    ll n,m;
    cin>>m>>n;
    vll t(n),z(n),y(n);
    for (ll i=0;i<n;i++)
        cin>>t[i]>>z[i]>>y[i];
    ll lo=0,hi=1e12;
    //predicate function : canInflate returns F F F . . . F T T . . . T T for i from 0 to hi
    //find the first occurence of T -> minimum time to inflate 'm' ballons
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (canInflate(mid,t,z,y,m))
            hi=mid;
        else
            lo=mid+1;
    }
    //edge case : since we checked loon>=m, but we need loons==m, so after 'm' loons are inflated, the rest assistants inflates 0 loons
    if (canInflate(lo,t,z,y,m))
    {
        cout<<lo<<endl;
        print_inflated(lo,t,z,y,m);
    }
    else
    {
        cout<<hi<<endl;
        print_inflated(hi,t,z,y,m);
    }
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
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}   
