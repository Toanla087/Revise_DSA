#include <bits/stdc++.h>
using namespace std;

long long n,m,q;
long long arr[1005][1005], diff[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (long long i=0;i<=n+1;i++) {
        for (long long j=0;j<=m+1;j++) {
            arr[i][j]=0;
            diff[i][j]=0;
        }
    }

    while(q--) {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        diff[a][b]++;
        diff[a][d+1]--;
        diff[c+1][b]--;
        diff[c+1][d+1]++;
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + diff[i][j];
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
