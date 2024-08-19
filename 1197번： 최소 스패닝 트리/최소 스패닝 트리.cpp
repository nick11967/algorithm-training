/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1197                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1197                           #+#        #+#      #+#    */
/*   Solved: 2024/08/19 19:52:42 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
// https://4legs-study.tistory.com/111 에서 코드를 참고함.

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int>> p;

int v, e;
vector<p> edges;
int parent[10001];

int find_root(int x);
void union_root(int x, int y);
int kruskal();

int main()
{
    int a, b, c;
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    cout << kruskal();

    return 0;
}

int find_root(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);

    if (x != y) parent[y] = x;
}

int kruskal()
{
    int mst = 0, cnt = 0;

    for (int i = 0; i < e; i++) {
        p edge = edges[i];

        int f = edge.second.first;
        int s = edge.second.second;

        if (find_root(f) == find_root(s)) continue;

        mst += edge.first;
        union_root(f, s);
        cnt++;

        if (cnt == v - 1) return mst;
    }
}
