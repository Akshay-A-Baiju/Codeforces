// Author: Akshay A Baiju
// Problem: D. Children Holiday
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"   //not to be used in interactive problems
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.141592653589793238462

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;

bool isPossible(ll tm, ll &m, vector <ll> &t, vector <ll> &z, vector <ll> &y)
{
    ll loons=0;
    ll n=t.size();
    for (ll i=0;i<n;i++)
    {
        // no of full rounds
        ll fullRoundTime=t[i]*z[i]+y[i];
        ll fullRounds=tm/fullRoundTime;
        loons+=fullRounds*z[i];
        // no of partial rounds
        ll timeLeft=tm%fullRoundTime;
        ll addLoons=min(z[i],timeLeft/t[i]);
        loons+=addLoons;
    }
    return loons>=m;
}

void solve()
{
    ll m,n; cin>>m>>n;
    vector <ll> t(n),z(n),y(n);
    for (ll i=0;i<n;i++)
        cin>>t[i]>>z[i]>>y[i];
    // BS on Ans
    // FFFTTT
    ll lo=0,hi=1e15;
    while (hi-lo>1)
    {
        ll mid=(hi+lo)/2;
        if (isPossible(mid,m,t,z,y))
            hi=mid;
        else
            lo=mid+1;
    }
    ll ans;
    if (isPossible(lo,m,t,z,y))
        ans=lo;
    else
        ans=hi;
    vector <ll> organizer(n);
    ll cnt=0;
    for (ll i=0;i<n;i++)
    {
        // no of full rounds
        ll fullRoundTime=t[i]*z[i]+y[i];
        ll fullRounds=ans/fullRoundTime;
        ll loon=fullRounds*z[i];
        // no of partial rounds
        ll timeLeft=ans%fullRoundTime;
        ll addLoons=min(z[i],timeLeft/t[i]);
        loon+=addLoons;
        // no of loons inflated = min(max loon inflated by current organizer, no of loons to be inflated)
        loon=min(loon,m-cnt);
        cnt+=loon;
        organizer[i]=loon;
    }
    cout<<ans<<endl;
    for (auto &it: organizer) cout<<it<<" ";
}

int main()
{
    sync;
    int t=1;
    // cin>>t;
    for (int test=1;test<=t;test++)
    {
        solve();
        cout<<endl;
    }
    return 0;
}