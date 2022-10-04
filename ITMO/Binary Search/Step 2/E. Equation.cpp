// Author: Akshay A Baiju
// Problem: E. Equation
// URL: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E

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
const double eps = 1e-9;

bool isPossible(double x, double &c)
{
    double a=x*x+sqrt(x);
    double diff=c-a;
    return diff>eps;
}

void solve()
{
    double c; cin>>c;
    // BS on Ans
    // TTTFFF
    double lo=0,hi=1e6;
    while (hi-lo>eps)
    {
        double mid=(hi+lo)/2;
        if (isPossible(mid,c))
            lo=mid;
        else
            hi=mid-eps;
    }
    cout<<fixed<<setprecision(6)<<lo;
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