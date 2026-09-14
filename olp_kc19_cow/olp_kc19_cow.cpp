#include <bits/stdc++.h>
using namespace std;

long long n, a, b;
long long x, y, r;
long long rs;
double Min = DBL_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    for (int i=0;i<n;i++) {
        cin >> x >> y >> r;
        Min = min(Min, sqrt((x-a)*(x-a)+(y-b)*(y-b))-r);
    }

    rs = Min;

    if (Min == rs) {
        rs--;
    }

    cout << rs;

    return 0;
}
