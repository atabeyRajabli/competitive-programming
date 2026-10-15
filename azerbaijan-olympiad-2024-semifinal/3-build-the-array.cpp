// Build the Array (Massiv Qurun) - Azerbaijan Republican Olympiad in Informatics 2024, semifinal
// Minimum number of range chmax(l, r, x) operations to build a from zeros, and the operations themselves.
// Equal values can share one operation if nothing smaller lies between them: coordinate compression +
// segment tree for range minimum, then greedily merge consecutive occurrences of each value. O(n log n).

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
const int sz =              1e5 + 5;
using namespace             std;

int n;
int a[sz], sg[sz << 2];
vector<int> v;
queue<int> ind[sz];
map<int, int> mp;
map<int, int> pm;

void build(int ind, int l, int r)
{
    if(l == r)
    {
        sg[ind] = mp[a[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(ind << 1, l, mid);
    build(ind << 1 | 1, mid + 1, r);
    sg[ind] = min(sg[ind << 1], sg[ind << 1 | 1]);
}

int get(int ind, int l, int r, int lx, int rx)
{
    if(l > rx || r < lx)return inff;
    if(lx <= l && r <= rx)return sg[ind];
    int mid = (l + r) >> 1;
    return min(get(ind << 1, l, mid, lx, rx), get(ind << 1 | 1, mid + 1, r, lx, rx));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]];
    }

    int cnt = 1;
    for(auto p : mp)
    {
        pm[cnt] = p.first;
        mp[p.first] = cnt++;
    }
    for(int i = 1; i <= n; i++)ind[mp[a[i]]].push(i);

    build(1, 1, n);

    vector<array<int, 3>> q;
    for(int i = 1; i < cnt; i++)
    {
        if(!pm[i])continue;
        while(!ind[i].empty())
        {
            int l = ind[i].front(), r = l;
            ind[i].pop();
            while(!ind[i].empty())
            {
                int mn = get(1, 1, n, l, ind[i].front());
                if(mn >= i)r = ind[i].front(), ind[i].pop();
                else break;
            }
            q.pb({l, r, pm[i]});
        }
    }

    cout << q.size() << endl;
    for(auto i : q)cout << i[0] << " " << i[1] << " " << i[2] << endl;
}
