/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1980                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1980                           #+#        #+#      #+#    */
/*   Solved: 2024/08/30 17:18:13 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, t;
    int m_b = 0, m_c = 10000;
    int t_b, t_c;

    cin >> n >> m >> t;
    for (int i = 0; ; i++) {
        if (n * i > t) break;
        t_b = i + (t - n * i) / m;
        t_c = t - (n * i);
        t_c = t_c - t_c / m * m;
        if (t_c < m_c) {
            m_b = t_b;
            m_c = t_c;
        }
        else if (t_c == m_c) {
            if (t_b > m_b) {
                m_b = t_b;
            }
        }
    }

    cout << m_b << " " << m_c;
    return 0;
}