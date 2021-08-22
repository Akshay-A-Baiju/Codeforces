// Author : Akshay A Baiju
// Problem link : https://codeforces.com/contest/630/problem/I
// Problem tags : math
// TC : O(1)
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

ll binExp(ll base, ll exp)
{
    ll res=1;
    while (exp)
    {
        if (exp&1)
            res=res*base;
        base=base*base;
        exp>>=1;
    }
    return res;
}

void solve()
{    
    ll n;
    cin>>n;
    if (n==3)
    {
        cout<<24;
        return;
    } 
    //2cases: 1. succesive n cars at end
    //        2. successive n cars in middle
    
    //case 1
    ll p1=2*4*3*binExp(4,n-3);
    //case 2
    ll p2=((2*n-4)-n+1)*4*9*binExp(4,n-4);
    ll ans=p1+p2;
    cout<<ans;
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
