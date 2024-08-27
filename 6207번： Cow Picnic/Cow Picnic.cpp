/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6207                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6207                           #+#        #+#      #+#    */
/*   Solved: 2024/08/24 13:40:12 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int k, n, m;
vector<int> c, p[1001];
vector<int>::iterator iter;
int cnt[1001];
bool visited[1001];

void bfs(int x)
{
    fill_n(visited, 1001, false);
    queue<int> q;
    q.push(x);
    visited[x] = true;

    int cur;
    while (!q.empty()) {
        cur = q.front();
        cnt[cur]++;
        for (iter = p[cur].begin(); iter != p[cur].end(); iter++) {
            if (!visited[*iter]) {
                q.push(*iter);
                visited[*iter] = true;
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> k >> n >> m;
    int temp;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        c.push_back(temp);
    }
    int s, e;
    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        p[s].push_back(e);
    }
    
    for (int i = 0; i < k; i++) {
        bfs(c[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == k) ans++;
    }
    cout << ans;
    return 0;
}