// Lost Pen (İtmiş Qələm) - Azerbaijan Republican Olympiad in Informatics 2024, semifinal
// n <= 2*10^6 under a 5 MB memory limit: one bit per color, the color never seen is the lost one. O(n) time, n bits.

#include <bits/stdc++.h>

// author : a1abay

#define pb          push_back
#define all(v)      v.begin(), v.end()
#define int         ll
#define gcd(a, b)   __gcd(a, b)
#define lcm(a, b)   (a*b / (__gcd(a, b)))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long           ll;
const int inf =             1e9 + 7;
const int inff =            1e18 + 7;
const int sz =              2e5 + 5;
using namespace             std;

int n, x;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<bool> v(n + 1, false);
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        v[x] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        if(v[i] == false)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1;
}
