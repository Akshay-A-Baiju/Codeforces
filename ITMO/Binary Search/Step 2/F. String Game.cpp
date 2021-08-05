// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
// Problem tags : advanced binary search, logical
// TC : O(nlogn)
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

bool isPossible(string &t, string &p, vll &pos, ll x)
{
    ll n=t.size();
    vector <bool> canTake(n,true);
    for (ll i=0;i<=x;i++)
        canTake[pos[i]-1]=false;
    //check if string p can form sub sequence of string t, excluding the pos marked false
    //using 2 pointers
    ll i=0,j=0;
    while (i<n && j<p.size())
    {
        if (p[j]==t[i] && canTake[i])
            j++;
        i++;
    }
    return (j==p.size());
}

void solve()
{  
	//using advanced binary search with poredicate function  
    string t,p;
    cin>>t>>p;
    ll n=t.size();
    vll pos(n);
    scan_vector(pos,n);
    ll lo=0,hi=n-1;
    //predicate function : isPossible : returns T T T . . . T F . . . F for i from 0 to hi
    //edge case : F F F . . . . F, no deletion possible, eg: string t=p
    //we need to find the last position of T -> maximum letter that Petya can delete
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(t,p,pos,mid))
            lo=mid;
        else
            hi=mid;
    }
    if (isPossible(t,p,pos,hi))
        cout<<hi+1;
    else if (isPossible(t,p,pos,lo))
        cout<<lo+1;
    else			//no deletion possible
        cout<<0;
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
