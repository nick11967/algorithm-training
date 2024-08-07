/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25632                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25632                          #+#        #+#      #+#    */
/*   Solved: 2024/08/07 17:31:22 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int cnt_prime(int s, int e);

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cnt_yt = cnt_prime(a, b);
    int cnt_yj = cnt_prime(c, d);

    if (a <= c) {
        if (c <= b && b <= d) {
            int cnt = cnt_prime(c, b);
            if (cnt % 2 == 1) cnt_yt++;
        }
    }
    else {
        if (a <= d && d <= b) {
            int cnt = cnt_prime(a, d);
            if (cnt % 2 == 1) cnt_yt++;
        }
    }

    if (cnt_yt > cnt_yj) cout << "yt";
    else cout << "yj";

    return 0;
}

int cnt_prime(int s, int e)
{
    int cnt = 0;
    for (int i = s; i <= e; i++) {
        if (i == 2 || i == 3) {
            cnt++;
            continue;
        }
        else if (i % 2 == 0) {
            continue;
        }
        else {
            bool p = true;
            for (int j = 3; j < i; j++) {
                if (i % j == 0) {
                    p = false;
                    break;
                }
            }
            if (p) {
                cnt++;
            }
        }
    }
    return cnt;
}