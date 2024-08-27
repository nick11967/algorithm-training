/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6138                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6138                           #+#        #+#      #+#    */
/*   Solved: 2024/08/24 12:06:42 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ans = 0;
    vector<pair<int,int>> k;
    cin >> t >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp < 0) k.push_back({-temp, -1});
        else k.push_back({temp, 1});
    }
    sort(k.begin(), k.end());
    
    int time = 0, x = 0, b = 0;
    for (int i = 0; i < n; i++) {
        time += abs(x - (k[i].first * k[i].second));
        if (time > t) break;
        else {
            ans++;
            x = k[i].first * k[i].second;
        }
    }

    cout << ans;
    return 0;
}