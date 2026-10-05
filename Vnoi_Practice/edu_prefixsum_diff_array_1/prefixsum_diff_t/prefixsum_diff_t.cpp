#include <bits/stdc++.h>
using namespace std;

long long n,q;
long long a[1000005], b[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (long long i=1;i<=n;i++) {
        cin >> a[i];
    }

    for (long long i=2;i<=n+1;i++) {
        b[i]=0;
    }

    b[1] = a[1];
    for (long long i=2;i<=n;i++) {
        b[i] = a[i] - a[i - 1];
    }


    while(q--) {
        long long l, r, x;
        cin >> l >> r >> x;

        b[l]+=x;
        if (r+1<n+1) {
            b[r+1] -= x;
        }
    }

    a[1]=b[1];
    for (long long j=2;j<=n;j++) {
        a[j]=a[j-1]+b[j];
    }

    for (long long i=1;i<=n;i++) {
        cout << a[i] << " ";
    }

    cout << "\n";
    return 0;
}
