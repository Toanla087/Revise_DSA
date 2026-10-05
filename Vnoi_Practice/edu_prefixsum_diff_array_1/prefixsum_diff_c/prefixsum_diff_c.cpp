#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[100005];
long long MIN = -99999999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (long long i=0;i<n;i++) {
        cin >> a[i];
    }

    long long sum = 0;
    for (long long i=0;i<n;i++) {
        sum = max(a[i],sum+a[i]);
        MIN = max(MIN,sum);
    }

    cout << MIN << "\n";

    return 0;
}
