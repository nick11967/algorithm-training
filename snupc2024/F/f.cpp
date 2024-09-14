#include <bits/stdc++.h>

using namespace std;

vector<int> line[100001];
vector<int> child[100001];
long long s[100001];
bool visi[100001];

void dfs(int x)
{
    for (int i = 0; i < line[x].size(); i++) {
        int next = line[x][i];
        if (!visi[next]) {
            visi[next] = true;
            child[x].push_back(next);
            dfs(next);
        }
    }
}

void grow(int u, long long x)
{
    if (s[u] >= x) {
        s[u] += x;
    }
    else {
        x = x - s[u];
        s[u] += s[u];
        if (child[u].size() == 0) return;

        long long left_eq = x / child[u].size();
        if (left_eq == 0) return;

        for (int i = 0; i < child[u].size(); i++) {
            grow(child[u][i], left_eq);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 
    int n, q;
    cin >> n >> q;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        line[u].push_back(v);
        line[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    visi[1] = true;
    dfs(1);

    int c;
    long long x;
    for (int t = 0; t < q; t++) {
        cin >> c;
        if (c == 1) {
            cin >> u >> x;
            grow(u, x);
        }
        else {
            cin >> u;
            cout << s[u] << "\n";
        }
    }

    return 0;
}