// Hopping (Hoppana-hoppana) - Azerbaijan IOI training camp selection exam #1, 2023
// Box i can stay unchanged only if h_i <= i*m. With a_i = h_i - i*m, a set of boxes can all stay unchanged iff
// a is non-increasing along them, so the answer is n minus the longest such subsequence (multiset patience sort). O(n log n).

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
const int sz = 2e5+5;
const int oo = 0x3F3F3F3F;
const int ooo = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 998244353;

using namespace std;
 
void open(string s, string f)
{
    freopen((s + ".txt").c_str(), "r", stdin);
    freopen((f + ".txt").c_str(), "w", stdout);
}

int n, m, k, a[sz] ,b[sz];

void solve()
{
    cin >> n >> m;

    for(int i = 1; i<=n; i++)cin >> a[i], a[i] -= i * m;

    multiset<int> ms;
    for(int i = 1; i<=n; i++)
    {
        if(a[i] > 0)skip;

        if(ms.empty())ms.ins(-a[i]);
        else
        {
            auto it = ms.upper_bound(-a[i]);
            if(it == ms.end())ms.ins(-a[i]);
            else 
            {
                ms.erase(it);
                ms.ins(-a[i]);
            }
        }
    }

    cout << n - ms.size();
}
 
signed main()
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
// "
// 10 2 
// 2 4 7 | 3 9 | 1 6 | 5 8 | 0
// 2 4 6 | 3 5 | 1 3 | 5 7 | 0
// 0 0 1 | 0 4 | 0 3 | 0 1 | 0
//     0     0     0     0


// "