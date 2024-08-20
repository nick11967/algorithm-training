/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15722                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15722                          #+#        #+#      #+#    */
/*   Solved: 2024/08/19 22:50:07 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 0, y = 0, dx = -1, dy = 0, c = 0;
    if (n == 0) {
        cout << "0 0";
        return 0;
    }
    for (int i = 1; ; i++) {
        if (i % 2 == 1) {
            dy = 1; dx = 0;
        }
        else {
            dy = -1; dx = 0;
        }

        for (int j = 0; j < i; j++) {
            x += dx; y += dy;
            c++;
            if (c == n) {
                cout << x << " " << y;
                return 0;
            }
        }

        if (i % 2 == 1) {
            dx = 1; dy = 0;
        }
        else {
            dx = -1; dy = 0;
        }

        for (int j = 0; j < i; j++) {
            x += dx; y += dy;
            c++;
            if (c == n) {
                cout << x<< " " << y;
                return 0;
            }
        }
    }
    return 0;
}