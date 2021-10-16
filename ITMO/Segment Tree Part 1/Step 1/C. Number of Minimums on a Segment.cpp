// Author : Akshay A Baiju
// Problem link : https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
// Contest : CF EDU, Segment Tree Part 1, Step 1
// Problem tags : segment tree
// TC : O(n+mlogn)
// SC : O(n)

#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll                  long long
#define ull                 unsigned long long
#define vi                  vector <int>
#define vll                 vector <ll>
#define vvll                vector <vll>
#define pii                 pair <int,int>
#define pll                 pair <ll,ll>
#define vpll                vector <pll>
#define ms(a,x)             memset (a,x,sizeof(a))
#define rep(i,a,n)          for (int i=a;i<n;i++)
#define rrep(i,n,a)         for (int i=n;i>=a;i--)
#define pb                  push_back
#define pf                  push_front
#define ppb                 pop_back
#define ff                  first
#define ss                  second
#define ins                 insert
#define umap                unordered_map
#define uset                unordered_set
#define YY		            cout<<"YES"
#define NN		            cout<<"NO"
#define all(v)              v.begin(), v.end()
#define desc()              greater <ll>()
#define endl                "\n"   //not to be used in interactive problems
#define scan_vector(v)      for (auto &it: v) { cin>>it; }
#define print_vector(v)     for (auto &it: v) { cout<<it<<" "; } cout<<endl;
#define print_map(mp)       for (auto &pr: mp) { cout<<pr.first<<" "<<pr.second<<endl; }
#define sync                ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define oset		        tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
    #define debug(x)	    cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
    #define debug(x)
#endif

const int M = 1e9+7;
const int N = 1e5+7;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

vector <pll> sgtree(4*N,{LLONG_MAX,0});

pll calculate_min(pll left, pll right)
{
    pll res;
    if (left.ff==right.ff)
        res={left.ff,left.ss+right.ss};
    else if (left.ff<right.ff)
        res=left;
    else
        res=right;
    return res;
}

void build_sgtree(vll &v, ll ind, ll lo, ll hi)
{
    if (lo==hi)
    {
        sgtree[ind]={v[lo],1};
        return;
    }
    //partition into 2 segments
    ll mid=(hi+lo)/2;
    build_sgtree(v,2*ind+1,lo,mid);
    build_sgtree(v,2*ind+2,mid+1,hi);
    sgtree[ind]=calculate_min(sgtree[2*ind+1],sgtree[2*ind+2]);
}

void update(ll ind, ll lo, ll hi, ll pos, ll val)
{
    if (hi<pos || lo>pos)
        return;
    if (lo!=hi)
    {
        //partition into 2 segments
        ll mid=(hi+lo)/2;
        update(2*ind+1,lo,mid,pos,val);
        update(2*ind+2,mid+1,hi,pos,val);
        sgtree[ind]=calculate_min(sgtree[2*ind+1],sgtree[2*ind+2]);
    }
    else
        sgtree[ind]={val,1};
}

pll query(ll ind, ll lo, ll hi, ll l, ll r)
{
    //3 cases
    if (lo>=l && hi<=r)     //full overlap
        return sgtree[ind];
    else if (hi<l || lo>r)  //no overlap
        return {LLONG_MAX,0};
    else                    //partial overlap
    {
        //partition into 2 segments
        ll mid=(hi+lo)/2;
        pll left=query(2*ind+1,lo,mid,l,r);
        pll right=query(2*ind+2,mid+1,hi,l,r);
        pll res=calculate_min(left,right);
        return res;
    }
}

void solve()
{
    ll n,m;     cin>>n>>m;
    vll v(n);   scan_vector(v);
    build_sgtree(v,0,0,n-1);
    while (m--)
    {
        ll op;  cin>>op;
        if (op==1)
        {
            ll pos,val;     cin>>pos>>val;
            //update vector
            v[pos]=val;
            //update segment tree
            update(0,0,n-1,pos,val);
        }
        else
        {
            ll l,r;         cin>>l>>r;
            pll res = query(0,0,n-1,l,r-1);
            cout<<res.ff<<" "<<res.ss<<endl;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
        // freopen("error.txt","w",stderr);
        clock_t clk = clock();
    #endif
    sync;
    int t=1;
    // cin>>t;
    for (int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        solve();
        cout<<endl;
    }
    #ifndef ONLINE_JUDGE
        cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
    #endif
    return 0;
}
