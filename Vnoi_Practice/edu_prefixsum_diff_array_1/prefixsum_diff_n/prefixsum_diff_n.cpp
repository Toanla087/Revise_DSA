#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1005][1005], b[1005];
long long sum;
long long MAX = LLONG_MIN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (long long i=0;i<n;i++) {
        for (long long j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }

    for (long long i=0;i<n;i++) {
        for (long long t=0;t<m;t++) {
            b[t]=0;
        }
        for (long long k=i;k<n;k++) {
            for (long long j=0;j<m;j++) {
               b[j]+=a[k][j];
            }
            sum = 0;
            for (long long j=0;j<m;j++) {
                sum = max(b[j],sum+b[j]);
                MAX = max(MAX,sum);
            }
        }
    }

    cout << MAX << "\n";
    return 0;
}
