#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    long long t;
    int a[101];
    int cnt[101];
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i] = 0;
    }

    int x = 1;
    cnt[1] = 1;
    int c;
    int left = 0;
    for (long long i = 1; i <= t; i++) {
        c = cnt[x];
        x = a[x];
        if (cnt[x] != 0) {
            if (c - cnt[x] + 1 != 0) left = (t - i) % (c - cnt[x] + 1);
            else left = 0;
            break;
        }
        else {
            cnt[x] = c + 1;
        }
    }
    for (int i = 0; i < left; i++) {
        x = a[x];
    }
    cout << x;
    return 0;
}