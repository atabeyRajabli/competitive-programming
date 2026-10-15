// Starfall (Ulduz sürüşməsi) - Azerbaijan IOI training camp selection exam #1, 2023
// Each star moves linearly; |P + tD| <= r is a quadratic in t, giving an interval of whole seconds when it is visible.
// Sweep over interval endpoints for the busiest second. __int128 keeps the discriminant exact. O(n log n).

#include <bits/stdc++.h>
#include <cmath>
 
// author : AtabeyR
 
#define pb          push_back
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define all(v)      v.begin(), v.end()
#define OPT         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sec         second
#define fi          first
#define int         ll
#define print(k)    cerr << "Ans : "; cout << k << endl;
#define ins         insert
#define bpc         __builtin_popcountll
#define skip        continue
#define endll        '\n'
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)   a*b / (__gcd(a, b))
#define mpr         make_pair
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int oo = 0x3F3F3F3F;
const int ooo = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 998244353;
const int sz = 2e5+5;
using namespace std;
 
void open(string s, string f)
{
    freopen((s + ".txt").c_str(), "r", stdin);
    freopen((f + ".txt").c_str(), "w", stdout);
}
 
int n, r, x, dx, y, dy;
 
void solve()
{
    cin >> n >> r;

    map<int, int> v;

    for(int i = 1; i<=n; i++)
    {
        cin >> x >> y >> dx >> dy;

        __int128 a = (dx - x) * (dx - x) + (dy - y) * (dy - y);
        __int128 b = 2 * x * (dx - x) + 2 * y * (dy - y);
        __int128 c = x * x + y * y - r * r;
        ld d = b * b - 4 * a * c;

        if(d < 0) skip;

        ld t1 = (- b - sqrt(d)) / (2 * a);
        ld t2 = (- b + sqrt(d)) / (2 * a);
        

        if(t1 > t2 || t2 < 0) skip;
        
        
        //cout << fixed << setprecision(10) << " " << t2 << endll;
        
        t1 = max(ceill(t1), ld(0));
        t2 = floorl(t2);
        //cout << t2 << endll;
        v[t1]++;
        v[t2+1]--;
    }
    
    int ans = 0, cnt = 0;
    for(auto i : v)
    {
        cnt += i.sec;
        ans = max(ans, cnt);
    }
    cout << ans << endll;
}
 
int32_t main()
{
    // open("in", "out");
    
    OPT
    int t = 1;
    //cin >> t;

    for(int i = 1; i<=t; i++)
    {
        solve();
    }
}