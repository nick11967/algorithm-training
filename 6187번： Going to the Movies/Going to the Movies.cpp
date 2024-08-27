/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6187                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6187                           #+#        #+#      #+#    */
/*   Solved: 2024/08/24 12:36:43 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

vector<int> w;
int ans = 0;
int c, n;

void bf(int x, int sum)
{
    if (x == n){
        if (ans < sum) ans = sum;
        return;
    }
    else {
        bf(x+1, sum);
        if (sum + w[x] <= c) bf(x+1, sum+w[x]);
    }
}

int main()
{
    cin >> c >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        w.push_back(temp);
    }
    bf(0, 0);
    cout << ans;
    return 0;
}