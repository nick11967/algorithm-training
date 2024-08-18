/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2623                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2623                           #+#        #+#      #+#    */
/*   Solved: 2024/08/17 17:26:09 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    vector<int> mat[1001];
    int cnt[1001] = {0, };
    
    cin >> n >> m;

    int p, prev, next;

    for (int i = 0; i < m; i++) {
        cin >> p >> prev;
        for (int j = 0; j < p - 1; j++) {
            cin >> next;
            mat[prev].push_back(next);
            cnt[next]++;
            prev = next;
        }
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }

    int c;
    while (!q.empty()) {
        c = q.front();
        ans.push_back(c);
        for (int i = 0; i < mat[c].size(); i++) {
            cnt[mat[c][i]]--;
            if (cnt[mat[c][i]] == 0) {
                q.push(mat[c][i]);
            }
        }
        q.pop();
    }

    if (ans.size() != n) {
        cout << "0";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << ans[i];
            if (i != n - 1) {
                cout << "\n";
            }
        }
    }

    return 0;
}