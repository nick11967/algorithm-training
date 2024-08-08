/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18353                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18353                          #+#        #+#      #+#    */
/*   Solved: 2024/08/08 11:44:23 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int lis[2000];

void bs(int x, int y, int target);

int main()
{
    int n, a, l=0, p;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < lis[l]) {
            lis[++l] = a; 
        }
        else if (a == lis[l]) {
            continue;
        }
        else {
            bs(0, l, a);
        }
    }

    cout << n - l - 1;

    return 0;
}

void bs(int x, int y, int target)
{
    if (x >= y) {
        lis[y] = target;
        return; 
    } 

    int mid = (x + y) / 2;

    if (lis[mid] >= target) {
        x = mid + 1;
        bs(x, y, target);
    }
    else {
        y = mid;
        bs(x, y, target);
    }
}