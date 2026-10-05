#include <bits/stdc++.h>
using namespace std;

long long n, K;
long long a[100005];

long long subarrayWithAverageK(long long arr[]) {
    map<long long, long long>mp;
    mp[0]=1;
    long long cnt=0;
    long long sum=0;
    for (long long i=0;i<n;i++) {
        sum+=(arr[i]-K);
        if(mp.find(sum)!=mp.end()) {
            cnt+=mp[sum];
        }
        mp[sum]++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> K;

    for (long long i=0;i<n;i++) {
        cin >> a[i];
    }

    long long rs = subarrayWithAverageK(a);

    cout << rs << "\n";

    return 0;
}
