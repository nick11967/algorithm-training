/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25631                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25631                          #+#        #+#      #+#    */
/*   Solved: 2024/08/07 17:12:04 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    vector<int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        m.push_back(a);
    }

    sort(m.begin(), m.end());
    
    int cnt = 1, max = 1;
    for (int i = 1; i < n; i++) {
        if (m[i] == m[i-1]) {
            cnt++;
        }
        else {
            cnt = 1;
        }

        if (max < cnt) {
            max = cnt;
        }
    }

    cout << max;
    return 0;
}