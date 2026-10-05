#include <bits/stdc++.h>
using namespace std;

long long n,m,q;
long long a[1005][1005], b[1005][1005];
long long sum;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (long long i=0;i<n;i++) {
        for (long long j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }

    for (long long i=0;i<=n;i++) {
        for (long long j=0;j<=m;j++) {
            b[i][j]=0;
        }
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            b[i][j] = a[i-1][j-1] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }

    while(q--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sum = b[x2][y2] - b[x1-1][y2] - b[x2][y1-1] + b[x1-1][y1-1];
        cout << sum << "\n";
    }
    return 0;
}
