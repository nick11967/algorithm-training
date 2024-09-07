/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12738                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12738                          #+#        #+#      #+#    */
/*   Solved: 2024/09/08 01:16:29 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, m = 0;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (v.size() == 0 || v[v.size() - 1] < k) {
            v.push_back(k);
            m = v.size();
        }
        else {
            int left = 0, right = v.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (v[mid] >= k) right = mid;
                else left = mid + 1;
            }
            v[left] = k;
        }
    }
    cout << m;
    return 0;
}