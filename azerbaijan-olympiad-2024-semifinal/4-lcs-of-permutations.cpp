// Longest Common Subsequence of k Permutations (İbrahimin Dissertasiya İşi) - Azerbaijan Republican Olympiad in Informatics 2024, semifinal
// Edge i -> j when i comes before j in all k permutations; the answer is the longest path in that DAG. O(n^2 k).

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
const int sz =              1e3 + 5;
using namespace             std;

int n, k;
int a[6][sz], ind[6][sz], in[sz], used[sz], pre[sz][sz], d[sz];
vector<int> g[sz];

void dfs(int v)
{
    used[v] = 1;
    for(int i : g[v])
    {
        if(used[i])continue;
        d[i] = d[v] + 1;
        dfs(i);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            ind[i][a[i][j]] = j;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int ok = 1;
            for(int x = 1; x <= k; x++)
            {
                ok &= (ind[x][i] < ind[x][j]);
            }
            if(ok)
            {
                g[i].pb(j);
                in[j]++;
            }
        }
    }

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    for(int i = 1; i <= n; i++)
    {
        if(!in[i])q.push({0, i});
    }

    while(!q.empty())
    {
        int v = q.top()[1];
        q.pop();
        for(int i : g[v])
        {
            if(d[v] - 1 < d[i])
            {
                d[i] = d[v] - 1;
                q.push({d[i], i});
            }
        }
    }

    int mx = *min_element(d + 1, d + 1 + n);
    cout << -mx + 1 << endl;
}
