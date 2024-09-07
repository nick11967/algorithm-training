/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2162                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: nick11967 <boj.kr/u/nick11967>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2162                           #+#        #+#      #+#    */
/*   Solved: 2024/09/07 13:50:47 by nick11967     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

typedef long double C;
typedef complex<C> P;
typedef pair<P,P> L;

#define X real()
#define Y imag()

vector<int> parent;
vector<int> ran;
vector<L> line;
vector<int> cnt;

int n;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (ran[u] > ran[v]) swap (u, v);
    parent[u] = v;

    if (ran[u] == ran[v]) ran[v]++;
}

int lr(P p, L l)
{
    P s1, s2;
    s1 = l.first;
    s2 = l.second;
    C cp = (conj(p-s1)*(p-s2)).Y;
    if (cp > 0) return 1;
    else if (cp < 0) return -1;
    else return 0;
}

bool check(L l1, L l2)
{
    // 각 점과 상대 선분의 외적 값
    int n1, n2, n3, n4; 
    n1 = lr(l1.first, l2);
    n2 = lr(l1.second, l2);
    n3 = lr(l2.first, l1);
    n4 = lr(l2.second, l1);

    // 좌표 변수
    int x11, x12, x21, x22, y11, y12, y21, y22;
    x11 = l1.first.X; y11 = l1.first.Y;
    x12 = l1.second.X; y12 = l1.second.Y;
    x21 = l2.first.X; y21 = l2.first.Y;
    x22 = l2.second.X; y22 = l2.second.Y;

    // 1. 겹치는 경우
    if (n1 == 0 && n2 == 0) {
        if ((x11 != x21)
            && ((x11 <= x21 && x21 <= x12)
            || (x21 <= x11 && x11 <= x22))) {
            cout << "1. true\n";
            return true;
        } 
        else if ((x11 == x21)) {
            if (y11 > y12) swap(y11, y12);
            if (y21 > y22) swap(y21, y22);
            if((y11 <= y21 && y21 <= y12)
                || (y21 <= y11 && y11 <= y22)){
                cout << "1. true\n";
                return true;
            }
        }
    }
    // 2. 한 꼭짓점에서 만나는 경우
    else if ((l1.first == l2.first) || (l1.first == l2.second)
        || (l1.second == l2.first) || (l1.second == l2.second)) {
        cout << "2. true\n";
        return true;
    }
    // 3. 교차점 하나
    else if (n1 * n2 < 0 && n3 * n4 < 0) {
        cout << "3. true\n";
        return true;
    }
    // 4. T자 형태
    else {
        if (n1 == 0 
            && (x21 <= x11 && x11 <= x22) 
            && ((y11 - y21) * (y11 - y22) <= 0)) {
            cout << "4. true\n";
            return true;
        }
        else if (n2 == 0
            && (x21 <= x12 && x12 <= x22)
            && ((y12 - y21) * (y12 - y22) <= 0)) {
            cout << "4. true\n";
            return true;
        }
        else if (n3 == 0
            && (x11 <= x21 && x21 <= x12)
            && ((y21 - y11) * (y21 - y12) <= 0)) {
            cout << "4. true\n";
            return true;
        }
        else if (n4 == 0
            && (x11 <= x22 && x22 <= x12)
            && ((y22 - y11) * (y22 - y12) <= 0)) {
            cout << "4. true\n";
            return true;
        }
    }

    return false;
}

int main()
{
    int x1, y1, x2, y2;
    int n1, n2, n3, n4;
    cin >> n;
    for (int i = 0; i < n; i++) {
        parent.push_back(i);
        ran.push_back(1);
        cnt.push_back(0);
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        else if (x1 == x2 && y1 > y2) {
            swap(y1, y2);
        }
        line.push_back({{x1, y1}, {x2, y2}});
    }

    int x11, x12, x21, x22, y11, y12, y21, y22;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (find(i) == find(j)) continue;
            if (check(line[i], line[j])) {
                cout << i << " " << j << " merge\n";
                merge(i, j);
            }
        }
    }

    int g_cnt = 0, max = 0;
    for (int i = 0; i < n; i++) {
        cnt[find(i)]++;
    }
    for (int i = 0; i< n; i++) {
        if (cnt[i] != 0) {
            g_cnt++;
            if (max < cnt[i]) max = cnt[i];
        }
    }

    cout << g_cnt << "\n" << max;

    return 0;
}   