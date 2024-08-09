/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17290                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17290                          #+#        #+#      #+#    */
/*   Solved: 2024/08/09 18:35:50 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

bool m[10][10];

int main()
{
    int r, c;
    char x;
    int min = 20;

    cin >> r >> c;
    r--; c--;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> x;
            if (x == 'o') {
                for (int k = 0; k < 10; k++) {
                    m[i][k] = true;
                    m[k][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <10; j++) {
            if (m[i][j] == false) {
                int l = abs(i-r) + abs(j-c);
                if (min > l) min = l;
            }
        }
    }

    cout << min;

    return 0;
}