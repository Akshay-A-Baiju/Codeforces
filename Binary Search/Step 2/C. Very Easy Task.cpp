// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
// Problem tags : advanced binary search, logical
// TC : O(n + log(1e10))
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

bool possibleNcopies(ll time, ll &n, ll &x, ll &y)
{
    if (time<x) //as minimum time 'x' is required ot make 1 copy, then both printers can work continuously
        return false;
    else
    {
        ll copies1=time/x;
        ll copies2=(time-x)/y;
        return (copies1+copies2>=n);
    }
}

void solve()
{ 
	//advanced binary search using predicate functions   
    ll n,x,y;
    cin>>n>>x>>y;
    if (x>y)
        swap(x,y);  //making x<y for easier calculation
    ll lo=0,hi=1e12;
    //predicate function : possibleNcopies returns : F F . . . F T T . . . T for i = 0 to hi
    //find the first occurence of T -> minimum time to get N copies
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (possibleNcopies(mid,n,x,y))
            hi=mid;
        else
            lo=mid+1;
    }
    if (possibleNcopies(lo,n,x,y))
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
