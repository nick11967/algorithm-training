#include<bits/stdc++.h>

using namespace std; 

int main()
{
    int n, m;
    cin >> n >> m;

    char alice[n+1][m+1], bob[n+1][m+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> alice[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> bob[i][j];
    }

    int cnt_a[m], cnt_b[m];
    int cnt_alice = 0, cnt_bob = 0;
    char c;
    for (int j = 1; j <= m; j++) {
        cnt_a[j] = 0;
        c = 'A';
        for (int i = 1; i <= n; i++) {
            if (alice[i][j] == 'B') {
                if (c == 'B') cnt_a[j]++;
                else c = 'B';
            }
            else if (c == 'B') {
                c = 'A';
                cnt_a[j]++;
            }
        }
        cnt_alice += cnt_a[j];

        cnt_b[j] = 0;
        c = 'B';
        for (int i = 1; i <= n; i++) {
            if (bob[i][j] == 'A') {
                if (c == 'A') cnt_b[j]++;
                else c = 'A';
            }
            else if (c == 'A') {
                c = 'B';
                cnt_b[j]++;
            }
        }
        cnt_bob += cnt_b[j];
    }
    if (cnt_alice > cnt_bob + 1) cout << "Bob\n";
    else cout << "Alice\n";
    cout << cnt_alice << " " << cnt_bob <<"\n";

    int q;
    int r1, c1, r2, c2;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (alice[r1][c1] != bob[r2][c2]) {
            swap(alice[r1][c1], bob[r2][c2]);
            int temp = 0;
            c = 'A';
            for (int i = 1; i <= n; i++) {
                if (alice[i][c1] == 'B') {
                    if (c == 'B') temp++;
                    else c = 'B';
                }
                else if (c == 'B') {
                    c = 'A';
                    temp++;
                }
            }
            cnt_alice = cnt_alice - cnt_a[c1] + temp;
            cnt_a[c1] = temp;

            temp = 0; c = 'B';
            for (int i = 1; i <= n; i++) {
                if (bob[i][c2] == 'A') {
                    if (c == 'A') temp++;
                    else c = 'A';
                }
                else if (c == 'A') {
                    c = 'B';
                    temp++;
                }
            }
            cnt_bob = cnt_bob - cnt_b[c2] + temp;
            cnt_b[c2] = temp;
        }
        if (cnt_alice > cnt_bob + 1) cout << "Bob\n";
        else cout << "Alice\n";
        cout << cnt_alice << " " << cnt_bob <<"\n";
    }
    return 0;
}