// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
// Problem tags : advanced binary search
// TC : O(log(n*w) + log h)
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

bool comp(ll len,ll w,ll h,ll n)
{
    ll n1=len/w;
    ll n2=len/h;
    return (n1*n2>=n);
}

void solve()
{
    //advanced binary search using Predicate function
    ll w,h,n;
    cin>>w>>h>>n;
    ll hi=max(w*n,h);
    ll lo=1;
    //predicate function : comp will return : F F F . . . F T T . . . T for i=1 to hi
    //we need to find first occurence of T -> minimim square size to contain all rectangles
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (comp(mid,w,h,n))	//if the rectangles can fit in square of side mid
            hi=mid;
        else
            lo=mid+1;
    }
    if (comp(lo,w,h,n))
        cout<<lo;
    else
        cout<<hi;
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
