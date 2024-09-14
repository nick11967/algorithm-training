#include<bits/stdc++.h>
using namespace std;

int ans[3000000];

int div(int k)
{
    if (ans[k]!=0) return ans[k];
    else {
        if (k % 2 == 1) {
            int t = (k - 3) / 2;        
            return ans[k] = 1 + div(t) * 2;
        }
        else {
            int t = (k - 3) / 2;
            return ans[k] = 1 + div(t) + div(t+1);
        }
    }
}

int main()
{
    ans[1] = ans[2] = ans[3] = 1;
    ans[4] = 2;
    int n;
    int m = 0, cnt;
    cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        cnt = 1;
        if (i >= 3) cnt++;
        if (i >= 5) cnt += div(i - 4);
        if (n - i + 1 >= 3) cnt++;
        if (n - i + 1 >= 5) cnt += div(n - i + 1 - 4);
        if (m < cnt) m = cnt;
    }

    cout << m;
    return 0;
}