// Candies (Konfetlər) - Azerbaijan Republican Olympiad in Informatics 2024, semifinal
// Pick the affordable cake that leaves the most change in qəpik (cents). O(n).

#include <bits/stdc++.h>
using namespace std;

// author : a1abay

#define int         long long
#define pb          push_back
#define ins         insert
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)   (a * b / __gcd(a, b))

const int inf  = 1e9 + 7;
const int inff = 1e18 + 3;
const int mod = 1e9 + 7;
const int sz = 2e6 + 5;

int n, s;
int a[sz];

signed main()
{
    cin >> n >> s;
    s *= 100;
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x * 100 + y <= s)v.pb(x * 100 + y);
    }
    int mx = -1;
    for(int i : v)
    {
        mx = max(mx, (100 - (i % 100)) % 100);
    }
    if(v.empty())cout << -1;
    else cout << mx;
}
