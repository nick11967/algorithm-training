/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16968                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16968                          #+#        #+#      #+#    */
/*   Solved: 2024/08/24 12:00:52 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
    string s;
    int ans = 1;
    cin >> s;
    if (s.length() != 0) {
        if (s[0] == 'c') ans *= 26;
        else if (s[0] == 'd') ans *= 10;
    }
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'c') {
            if (s[i] == s[i-1]) ans *= 25;
            else ans *= 26;
        }
        else if (s[i] == 'd') {
            if (s[i] == s[i-1]) ans *= 9;
            else ans *= 10;
        }
    }
    cout << ans;
    return 0;
}