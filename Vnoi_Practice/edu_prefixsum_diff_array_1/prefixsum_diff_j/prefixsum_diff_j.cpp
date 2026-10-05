#include <bits/stdc++.h>
using namespace std;

long long n, D;
long long a[100005];

long long subarrayDivByK(long long arr[], int k) {
    map<long long, long long>mp;
    mp[0]=1;
    long long cnt=0;
    long long sum=0;
    for (long long i=0;i<n;i++) {
        sum+=arr[i];
        long long rem = sum%k;
        if (rem <0) {
            rem+=k;
        }
        if(mp.find(rem)!=mp.end()) {
            cnt+=mp[rem];
        }
        mp[rem]++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> D;

    for (long long i=0;i<n;i++) {
        cin >> a[i];
    }

    long long rs = subarrayDivByK(a,D);

    cout << rs << "\n";

    return 0;
}
