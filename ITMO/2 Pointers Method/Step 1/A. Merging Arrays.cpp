// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
// Problem tags : 2-pointer, easy
// TC : O(n+m)
// SC : O(n+m)

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

void solve()
{   
    //merge 2 arrays using 2-pointers  
    ll n,m;
    cin>>n>>m;
    vll a(n),b(m),c(n+m);
    scan_vector(a,n);
    scan_vector(b,m);
    ll i=0;     //iterate over a
    ll j=0;     //iterate over b
    while (i<n && j<m)
    {
        if (a[i]<b[j])
        {
            c[i+j]=a[i];
            i++;
        }
        else
        {
            c[i+j]=b[j];
            j++;
        }
    }
    //enter the rest array contents
    while (i<n)
    {
        c[i+j]=a[i];
        i++;
    }
    while (j<m)
    {
        c[i+j]=b[j];
        j++;
    }
    print_vector(c);
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
