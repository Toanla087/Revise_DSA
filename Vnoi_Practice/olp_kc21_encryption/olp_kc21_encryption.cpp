#include <bits/stdc++.h>
using namespace std;

long long L, R, A, K, rs;

long long gcd_2num(long long a, long long b) {
    while (b != 0) {
        long long tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> R >> A >> K;

    long long g = gcd_2num(A, K);
    long long K_prime = K/g;
    long long count_R = R/K_prime;
    long long count_L = (L-1)/K_prime;
    rs = count_R-count_L;

    cout << rs;

    return 0;
}
