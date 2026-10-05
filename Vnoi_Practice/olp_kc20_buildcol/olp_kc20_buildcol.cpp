#include <bits/stdc++.h>
using namespace std;

int n;
long long M;
long long a[100005];

bool check(long long X) {
    long long b[n];
    for (int i = 0; i < n; i++) {
        b[i] = max(a[i], X);
    }

    long long L[n], R[n];

    L[0] = b[0];
    for (int i = 1; i < n; i++) {
        L[i] = max(L[i - 1], b[i]);
    }

    R[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        R[i] = max(R[i + 1], b[i]);
    }

    long long total_water = 0;
    for (int i = 0; i < n; i++) {
        total_water += min(L[i], R[i]) - b[i];
    }

    return total_water >= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> M;

    long long max_h = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_h = max(max_h, a[i]);
    }

    long long low = 0, high = max_h;
    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
