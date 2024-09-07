// 참고 사이트: https://m.blog.naver.com/fbfbf1/222278788809

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> t_rank;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    // 낮은 트리를 높은 트리 아래로 합치기
    if (t_rank[u] > t_rank[v]) swap(u, v);
    parent[u] = v;

    if (t_rank[u] == t_rank[v]) t_rank[v]++;
}

int main() {
    for (int i = 0; i < 10; i++) {
        parent.push_back(i);
        t_rank.push_back(1);
    }
}