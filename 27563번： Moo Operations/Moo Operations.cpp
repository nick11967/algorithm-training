/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27563                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27563                          #+#        #+#      #+#    */
/*   Solved: 2024/08/09 18:24:03 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
    int q;
    string s;
    cin >> q;
    while (q > 0) {
        cin >> s;
        int l = s.length();
        int temp, min = 3;
        for (int i = 1; i < l - 1; i++) {
            if (s[i] == 'O') {
                temp = 0;
                if (s[i-1] == 'O') temp++;
                if (s[i+1] == 'M') temp++;
                if (min > temp) min = temp;
            }
        }

        if (min == 3) {
            cout << -1 << "\n";
        }
        else {
            cout << l - 3 + min << "\n";
        }
        q--;
    }
    return 0;
}