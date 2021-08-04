// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
// Problem tags : advanced binary search, logical, classical
// TC : O(n*log(1e16))
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
const int M = 1e8;	    //needed 6 digit precision, therefore multiplying all ropes, hi, lo by M (to avoid precision errors of double), then dividing the answer by 6 using setprecision(6)
//double eps=1e-6;

bool possible(ll l,vll &rope, ll &k)
{
    ll count=0;
    for (ll i=0;i<rope.size() && count<k;i++)
        count+=rope[i]/l;
    return count>=k;
}

void solve()
{ 
	//advanced binary search using predicate function
    ll n,k;
    cin>>n>>k;
    vll rope(n);
    scan_vector(rope,n);
    for (auto &it: rope)
        it*=M;
    ll lo=0,hi=1e8*M;
    //predicate function: possible will return : T T . . . T F F . . . F for i from 1 to hi
    //find the last occurence of T -> maximum rope length
    while (hi-lo>1) 
    {
        ll mid=(hi+lo)/2;
        if (possible(mid,rope,k))
            lo=mid;
        else
            hi=mid-1;
    }
    if (possible(hi,rope,k))
        cout<<fixed<<setprecision(6)<<(1.0*hi/M);
    else
        cout<<fixed<<setprecision(6)<<(1.0*lo/M);
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
