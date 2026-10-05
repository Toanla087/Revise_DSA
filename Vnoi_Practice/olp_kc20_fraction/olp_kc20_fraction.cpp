#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000005;
int spf[MAXV];
int count_prime[MAXV];
int n;
int a[MAXV], b[MAXV];
vector<int> modified_primes;

void sieve() {
    for (int i = 1; i < MAXV; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < MAXV; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXV; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    sieve();
    for (int tc=1;tc<=T;tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < n; j++) {
            cin >> b[j];
        }

        for (int i = 0; i < n; i++) {
            int x = a[i];
            while (x > 1) {
                int p = spf[x];
                if (p != 2 && p != 5) {
                    if (count_prime[p] == 0) {
                        modified_primes.push_back(p);
                    }
                    count_prime[p]--;
                }
                x /= p;
            }
        }

        for (int i = 0; i < n; i++) {
            int x = b[i];
            while (x > 1) {
                int p = spf[x];
                if (p != 2 && p != 5) {
                    if (count_prime[p] == 0) {
                        modified_primes.push_back(p);
                    }
                    count_prime[p]++;
                }
                x /= p;
            }
        }

        bool is_finite = true;
        for (int p : modified_primes) {
            if (count_prime[p] > 0) {
                is_finite = false;
            }
            count_prime[p] = 0;
        }

        if (is_finite) {
            cout << "finite\n";
        } else {
            cout << "repeating\n";
        }
    }
    return 0;
}
