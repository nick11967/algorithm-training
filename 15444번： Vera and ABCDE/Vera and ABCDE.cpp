/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15444                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15444                          #+#        #+#      #+#    */
/*   Solved: 2024/08/06 11:28:24 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
    int n;
    string s, str[5];
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        char c = s[i];
        str[0].append("***");
        if (c == 'A') {
            str[1].append("*.*");
            str[2].append("***");
            str[3].append("*.*");
            str[4].append("*.*");
        }
        else if (c == 'B') {
            str[1].append("*.*");
            str[2].append("***");
            str[3].append("*.*");
            str[4].append("***");
        }
        else if (c == 'C') {
            str[1].append("*..");
            str[2].append("*..");
            str[3].append("*..");
            str[4].append("***");
        }
        else if (c == 'D') {
            str[1].append("*.*");
            str[2].append("*.*");
            str[3].append("*.*");
            str[4].append("***");
        }
        else if (c == 'E') {
            str[1].append("*..");
            str[2].append("***");
            str[3].append("*..");
            str[4].append("***");
        }
    }

    cout << str[0] << "\n" << str[1] << "\n" << str[2] << "\n" << str[3] << "\n" << str[4];
}
