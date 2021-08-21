// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
// Problem tags : advanced binary search
// TC : O(nlog(1e12))
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
 
bool possibleXcouncil(ll num, vll &a, ll &k)    //returns if possible to create 'num' councils having k different students in each
{
    ll seats = num*k;
    ll filled=0;
    for (auto &it: a)
        filled+=min(num,it);
    return filled>=seats;                       //if possible, filled seats is greater than seats = num*k
}
 
void solve()
{ 
    //advanced binary search using predicate function   
    ll k,n;
    cin>>k>>n;
    vll a(n);
    scan_vector(a,n);
    //predicate function, possibleXcouncil returns T T T T F F F 
    //find the last occurence of T -> maximum possible councils
    ll lo=1,hi=1e12;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (possibleXcouncil(mid,a,k))
            lo=mid;
        else
            hi=mid-1;
    }
    if (possibleXcouncil(hi,a,k))
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
    cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
