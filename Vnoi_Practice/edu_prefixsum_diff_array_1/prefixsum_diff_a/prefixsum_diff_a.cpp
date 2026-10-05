#include <bits/stdc++.h>
using namespace std;

long long n,q;
long long a[100005], b[100005];
long long sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (long long i=1;i<=n;i++) {
        cin >> a[i];
    }

    b[1]=a[1];
    for (long long j=2;j<=n;j++) {
        b[j]=b[j-1]+a[j];
    }

    while(q--) {
        long long l, r;
        cin >> l >> r;
        sum = 0;
        if (l==1) {
            sum = b[r];
        } else if (l>1) {
            sum = b[r]-b[l-1];
        }
        cout << sum << "\n";
    }
    return 0;
}
