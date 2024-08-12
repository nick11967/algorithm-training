/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2239                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2239                           #+#        #+#      #+#    */
/*   Solved: 2024/08/12 19:09:27 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int m[9][9];

int back(int x, int y) {
    int bx, by;
    bx = x / 3;
    by = y / 3;
    bool f = false;
    for (int n = 1; n <= 9; n++) {
        f = false;
        for (int i = bx * 3; i < bx * 3 + 3; i++) {
            for (int j = by * 3; j < by * 3 + 3; j++) {
                if (m[i][j] == n) {
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (f) continue;

        for (int i = 0; i < 9; i++) {
            if (m[i][y] == n) {
                f = true;
                break;
            }
        }
        if (f) continue;

        for (int j = 0; j < 9; j++) {
            if (m[x][j] == n) {
                f = true;
                break;
            }
        }
        if (f) continue;

        m[x][y] = n;
        int nx, ny;
        nx = ny = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (m[i][j] == 0) {
                    nx = i;
                    ny = j;
                    break;
                }
            }
            if (nx != -1) break;
        }

        if(nx == -1) {
            return 1;
        }
        else {
            m[x][y] = n;
            int b = back(nx, ny);
            if (b == -1) {
                m[x][y] = 0;
                continue;
            }
            else {
                return 1;
            }
        }
    }
    return -1;
}

int main()
{
    string n;

    for (int i = 0; i < 9; i++) {
        cin >> n;
        for (int j = 0; j < 9; j++) {
            m[i][j] = n[j] - '0';
        }
    }

    int x, y;
    x = y = -1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (m[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) break;
    }

    int b;

    if (x != -1) {
        b = back(x, y);
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << m[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}