/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1189                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1189                           #+#        #+#      #+#    */
/*   Solved: 2024/08/06 12:52:58 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int r, c, k;
char m[5][5];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool visited[5][5];
int cnt = 0;

void dfs(int x, int y, int l);

int main()
{
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }
    
    visited[r-1][0] = true;
    dfs(r - 1, 0, 1);

    cout << cnt;

    return 0;
}

void dfs(int x, int y, int l)
{
    if (x == 0 && y == c - 1) {
        if (l == k) {
            cnt++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        x += dx[i], y += dy[i];
        if (0 <= x && x < r && 0 <= y && y < c 
            && visited[x][y] == false && m[x][y] == '.') {
            visited[x][y] = true;
            dfs(x, y, l + 1);
            visited[x][y] = false;
        }
        x -= dx[i], y -= dy[i];
    }
}