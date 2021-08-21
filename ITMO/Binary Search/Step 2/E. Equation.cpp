// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
// Problem tags : advanced binary search
// TC : O(log(1e5))
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
double eps = 1e-8;

bool isPossible(double x, double &c)    //predicate function, returns if x^2+sqrt(x) >= c or not
{
    double ans=(x*x)+sqrt(x);
    return ans>=c;
}

void solve()
{  
    //using advanced binary search + predicate function  
    double c;
    cin>>c;
    //predicate function: isPossible returns FFFFTTTT
    //find the first occurence of T -> closest x
    double lo=0,hi=100000;
    while (hi-lo>eps)
    {
        double mid=(hi+lo)/2;
        //cout<<mid<<endl;
        if (isPossible(mid,c))
            hi=mid;
        else
            lo=mid+eps;
    }
    if (isPossible(lo,c))
        cout<<fixed<<setprecision(7)<<lo;
    else
        cout<<fixed<<setprecision(7)<<hi;
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
