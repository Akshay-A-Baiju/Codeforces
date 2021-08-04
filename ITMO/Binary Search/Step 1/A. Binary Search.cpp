// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
// Problem tags : binary search
// TC : O(k*logn)
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

bool binary_search(vll &v, ll elem)
{
    ll lo=0,hi=v.size()-1;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (elem>v[mid])
            lo=mid+1;
        else
            hi=mid;
    }
    return (elem==v[lo] || elem==v[hi]);
}

void solve()
{    
    ll n,k;
    cin>>n>>k;
    vll v(n);
    scan_vector(v,n);
    while (k--)
    {
        ll x;
        cin>>x;
        if (binary_search(v,x))
            cout<<"YES\n";
        else
            cout<<"NO\n";
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
