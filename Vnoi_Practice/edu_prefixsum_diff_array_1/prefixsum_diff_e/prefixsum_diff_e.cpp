#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[1000005];
long long L[1000005];
long long R[1000005];
long long MAX_L = -99999999999;
long long MAX_R = -99999999999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (long long i=0;i<n;i++) {
        cin >> a[i];
    }

    long long sum_L = 0;
    for (long long i=0;i<n;i++) {
        sum_L = max(a[i],sum_L+a[i]);
        MAX_L = max(MAX_L,sum_L);
        L[i]=MAX_L;
    }

    long long sum_R = 0;
    for (long long i=n-1;i>=0;i--) {
        sum_R = max(a[i],sum_R+a[i]);
        MAX_R = max(MAX_R,sum_R);
        R[i]=MAX_R;
    }

    long long MAX = -99999999999;
    for (long long i=0;i<n-1;i++) {
        MAX = max(MAX, L[i]+R[i+1]);
    }

    cout << MAX << "\n";

    return 0;
}
