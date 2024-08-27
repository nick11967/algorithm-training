/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27884                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27884                          #+#        #+#      #+#    */
/*   Solved: 2024/08/24 14:11:10 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int n, m;
long long ans;
int s[21];

int long_loller() 
{
    int cnt = 1, max = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            cnt++;
        }
        else {
            cnt = 1;
        }

        if (max < cnt) max = cnt;
    }

    return max;
}

long long f(int x)
{
    long long ret;

    if (x == n) {
        if (long_loller() == m) {
            ret = 1;
            for (int i = 0; i < n; i++) {
                if (s[i] == 0) {
                    ret = ret * 5 % MOD;
                }
                else {
                    ret = ret * 11 % MOD;
                }
            }
            return ret;
        }
        else return 0;
    }
    else {
        s[x] = 0;
        ret = f(x+1);
        s[x] = 1;
        ret = (ret + f(x+1)) % MOD;
        return ret;
    }
    
}

int main()
{
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s;

    cout << f(0);

    return 0;
}