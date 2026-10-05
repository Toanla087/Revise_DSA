#include <bits/stdc++.h>
using namespace std;

long double u,v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> u >> v;


    long double rs = (u*u+v*v)/4.0;

    cout << fixed << setprecision(2) << rs;

    return 0;
}
