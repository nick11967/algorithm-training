#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<pair<int,int>> line[n];
    long long ml[n];

    int u, v, c;
    for (int i = 1; i <= n; i++) ml[i] = -1;
    ml[e] =  9223372036854775807;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        line[u].push_back({v, c});
        line[v].push_back({u, c});
    }

    queue<pair<int,pair<long long,long long>>> q;
    q.push({s,{0,0}});
    ml[s] = 0;
    while(!q.empty()) {
        pair<int,pair<long long,long long>> p = q.front();
        int idx = p.first;
        long long len = p.second.first, c = p.second.second;
        if (len > ml[idx]){
            q.pop();
            continue;
        }
        if (idx == e) {
            q.pop();
            continue;
        }
        for (int i = 0; i < line[idx].size(); i++) {
            int n_idx = line[idx][i].first;
            long long n_len = len + line[idx][i].second + c;
            if (n_len > ml[e]) {
                continue;
            }
            long long n_c = line[idx][i].second + c + c;

            if (ml[n_idx] == -1 || ml[n_idx] > n_len) {
                ml[n_idx] = n_len;
                q.push({n_idx,{n_len,n_c}});
            }
        }
        q.pop();
    }

    long long ans = ml[e];
    vector<int> ans_s;
    if (ans == 0) cout << 0;
    else {
        while (ans > 0){
            ans_s.push_back(ans%2);
            ans /= 2;
        }
        for (int i = ans_s.size() - 1; i >= 0; i--) {
            cout << ans_s[i];
        }
    }
    return 0;
}