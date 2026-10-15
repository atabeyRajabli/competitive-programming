// iwin ioi - Azerbaijan IOI training camp selection exam #1, 2023
// S1 = iwin, S2 = ioi, S_n = (S_{n-2} + S_{n-1}) with the first character removed; print S_n[l..r] for n <= 80.
// Lengths follow L_n = L_{n-1} + L_{n-2} - 1, so each character is found by walking down the recursion. O(n) per character.

#include <bits/stdc++.h>
 
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
 
typedef long long ll;
typedef unsigned long long ull;
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
 
int n, m, k, a[sz];

string fr = "iwin";
string sc = "ioi";

char f(int n, int ind)
{
    if(n == 1)return fr[ind-1];
    if(n == 2)return sc[ind-1];

    //(i)winioi
    if(ind + 1 <= a[n-2])return f(n-2, ind+1);
    else return f(n-1, ind+1-a[n-2]);
}
 
void solve()
{
    int l, r;
    cin >> n >> l >> r;

    a[1] = 4;
    a[2] = 3;
    for(int i = 3; i<=n; i++)a[i] = a[i-1] + a[i-2] - 1;
        
    for(int i = l; i<=r; i++)
    {
        cout << f(n, i);
    }
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