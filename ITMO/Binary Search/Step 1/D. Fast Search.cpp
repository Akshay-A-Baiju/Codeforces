// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
// Problem tags : lower bound, upper bound
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
#define ppi                 pair <int,pii>
#define pll                 pair <ll,ll>
#define ppl                 pair <ll,pll>
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

void solve()
{   
    ll n,k;
    cin>>n;
    vll v(n);
    scan_vector(v,n);
    sort(all(v));
    cin>>k;
    while (k--)
    {
        ll l,r,start,end,ans;
        cin>>l>>r;
        //lower bound of l
        ll lo=0,hi=n-1;
        while (hi-lo>1)
        {
            ll mid=(hi+lo)/2;
            if (v[mid]<l)
                lo=mid+1;
            else
                hi=mid;
        }
        if (v[lo]>=l)
            start=lo;
        else if (v[hi]>=l)
            start=hi;
        else
            start=n;
        //upper bound of r - 1
        lo=0;hi=n-1;
        while (hi-lo>1)
        {
            ll mid=(hi+lo)/2;
            if (v[mid]<=r)
                lo=mid+1;
            else
                hi=mid;
        }
        if (v[lo]>r)
            end=lo-1;
        else if (v[hi]>r)
            end=hi-1;
        else if (v[hi]==r)
            end=hi;
        else
            end=n-1;    //to counter cases when l and r both lies outside the vector range, hence ans = 0 = (n-1) - n + 1
        ans=end-start+1;
        cout<<ans<<" ";      
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
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
