#include <bits/stdc++.h>

using namespace std;

typedef pair<int,pair<int,int>> P;

int main()
{
    int n, m;
    int c, x, h;
    vector<P> l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> x >> h;
        l.push_back({x,{c,h}});
    }
    sort(l.begin(), l.end());

    int cx = 0, cy = 0;
    for (int i = 0; i < l.size(); i++) {
        P p = l[i];
        c = p.second.first; x = p.first; h = p.second.second;
        if (c == 1) {
            if (cy - (x - cx) < h) {
                cy -= (x - cx);
                cx = x;
            }
            else {
                cout << "adios";
                return 0;
            }
        }
        else {
            if (cy - (x - cx) > h + 1) {
                cy -= (x - cx);
            }
            else cy = h + 1;
            cx = x;
        }
    }
    
    if (cy > (n - cx)) {
        cout << "adios";
    }
    else cout << "stay";
    return 0;
}