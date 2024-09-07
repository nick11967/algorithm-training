/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14003                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14003                          #+#        #+#      #+#    */
/*   Solved: 2024/09/07 23:37:16 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
// 참고 자료: https://yabmoons.tistory.com/561

#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> l, v;

int main()
{
    int n, k;
    int ml = -1, mi = 0;
    int j;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        if (v.size() == 0 || v[v.size() - 1].first < k) {
            if (v.size() == 0) l.push_back({k, -1});
            else l.push_back({k, v[v.size()-1].second});
            v.push_back({k, i});
            ml = v.size();
            mi = i;
        }
        else {
            int left = 0, right = v.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (v[mid].first >= k) right = mid;
                else left = mid + 1;
            }
            v[left] = {k, i};
            if (left == 0) l.push_back({k, -1});
            else l.push_back({k, v[left-1].second});
        }
    }

    cout << ml << "\n";
    vector<int> ans;
    int idx = mi;
    for (int i = 0; i < ml; i++) {
        ans.push_back(l[idx].first);
        idx = l[idx].second;
    }
    for (int i = ml - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}