/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1157                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1157                           #+#        #+#      #+#    */
/*   Solved: 2024/08/06 11:10:18 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int cnt[26];

int main()
{
    string str;
    cin >> str;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if ('a' <= c && c <= 'z') {
            cnt[c-'a']++;
        }
        else {
            cnt[c-'A']++;
        }
    }

    int max = -1, index = 0;
    for (int i = 0; i < 26; i++) {
        if (max < cnt[i]) {
            max = cnt[i];
            index = i;
        }
        else if (cnt[i] == max) {
            index = -1;
        }
    }

    if (index == -1) {
        cout << "?";
    }
    else {
        cout << (char)(index + 'A');
    }

    return 0;
}