/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10320                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10320                          #+#        #+#      #+#    */
/*   Solved: 2024/08/24 13:14:15 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

vector<int> b;

void bb (int n, int t)
{
    int time[3601];
    fill_n(time, 3601, -1);
    queue<int> q;
    time[0] = 0;
    q.push(0);

    int cur, next;
    while (!q.empty()) {
        cur = q.front();
        if (cur == t) break;
        for (int i = 0; i < n; i++) {
            next = cur + b[i];
            if (next < 0) next = 0;
            else if (next > 3600) next = 3600;

            if (time[next] == -1) {
                time[next] = time[cur] + 1;
                q.push(next);
            }
        }
        q.pop();
    }

    if (time[t] != -1) cout << time[t] << " " << 0 << "\n";
    else {
        for (int i = t; i <= 3600; i++) {
            if (time[i] != -1) {
                cout << time[i] << " " << i - t << "\n";
                break;
            }
        }
    }
}

int main()
{
    int tc;
    int n, t, temp;

    cin >> tc;
    
    for (int i = 0; i < tc; i++) {
        cin >> n >> t;
        b.clear();
        for (int j = 0; j < n; j++) {
            cin >> temp;
            b.push_back(temp);
        }
        bb(n, t);
    }

    return 0;
}