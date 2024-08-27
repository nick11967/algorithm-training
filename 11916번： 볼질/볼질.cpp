/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11916                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11916                          #+#        #+#      #+#    */
/*   Solved: 2024/08/24 12:26:24 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
    int n, x, ans = 0;
    bool one, two, thr;
    one = two = thr = false;
    int ball = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            ball++;
        }
        else if (x == 3) {
            ball++;
            if (thr) {
                ans++;
                thr = false;
            }
            if (two) {
                thr = true;
                two = false;
            }
            if (one) {
                two = true;
                one = false;
            }
        }

        if (x == 2 || ball == 4) {
            ball = 0;
            if (one) {
                if (two) {
                    if (thr) ans++;
                    else thr = true;
                }
                else two = true;
            }
            else one = true;
        }
    }

    cout << ans;
    return 0;
}