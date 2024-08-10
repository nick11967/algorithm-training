/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28420                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28420                          #+#        #+#      #+#    */
/*   Solved: 2024/08/10 20:32:26 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
입력 크기가 작아 단순한 구현으로도 통과했지만
입력을 받으면서 누적 합을 구해뒀다면 시간을 줄일 수 있었을 것이다.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, c;
    int w[300][300];

    cin >> n >> m;
    cin >> a >> b >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> w[i][j];
        }
    }

    int min = 1800000, sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + a <= n && j + b + c <= m) { 
                sum = 0;
                for (int k = 0; k < a; k++) {
                    for (int l = 0; l < b + c; l++) {
                        sum += w[i+k][j+l];
                    }
                }
                if (min > sum) {
                    min = sum;
                }
            }

            if (i + a + b <= n && j + c + a <= m) {
                sum = 0;
                for (int k = 0; k < a; k++) {
                    for (int l = 0; l < c; l++) {
                        sum += w[i+k][j+l];
                    }
                }
                for (int k = 0; k < b; k++) {
                    for (int l = 0; l < a; l++) {
                        sum += w[i+a+k][j+c+l];
                    }
                }
                if (min > sum) {
                    min = sum;
                }
            }

            if (i + a + c <= n && j + b + a <= m) {
                sum = 0;
                for (int k = 0; k < a; k++) {
                    for (int l = 0; l < b; l++) {
                        sum += w[i+k][j+l];
                    }
                }
                for (int k = 0; k < c; k++) {
                    for (int l = 0; l < a; l++) {
                        sum += w[i+a+k][j+b+l];
                    }
                }
                if (min > sum) {
                    min = sum;
                }
            }
        }
    }

    cout << min;

    return 0;
}