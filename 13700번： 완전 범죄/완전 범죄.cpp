/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13700                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13700                          #+#        #+#      #+#    */
/*   Solved: 2024/08/19 23:02:05 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int n, s, d, f, b, k;
bool visited[100001] = {false, };

int main()
{
    cin >> n >> s >> d >> f >> b >> k;
    if (k > 0) {
        int p;
        for (int i = 0; i < k; i++) {
            cin >> p;
            visited[p] = true;
        }
    }

    queue<pair<int, int>> q;

    q.push({s, 0});
    visited[s] = true;

    while (!q.empty()) {
        pair<int, int> house = q.front();

        if (house.first == d) {
            cout << house.second;
            return 0;
        }

        if (house.first + f <= n && !visited[house.first + f]) {
            visited[house.first + f] = true;
            q.push({house.first + f, house.second + 1});
        }
        if (house.first - b >= 1 && !visited[house.first - b]) {
            visited[house.first - b] = true;
            q.push({house.first - b, house.second + 1});
        }

        q.pop();
    }

    cout << "BUG FOUND";

    return 0;
}