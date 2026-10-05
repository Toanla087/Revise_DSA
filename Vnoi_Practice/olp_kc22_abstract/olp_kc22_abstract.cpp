#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long arr[1005][1005];
bool vis[1005][1005];

long long cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (long long i=0;i<n;i++) {
        for (long long j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }

    cnt=0;

    for (long long i=0;i<n;i++) {
        long long max_left=-1;
        for (long long j=0;j<m;j++) {
            if(arr[i][j]>max_left) {
                if(!vis[i][j] && arr[i][j]>0) {
                    vis[i][j]=true;
                    cnt++;
                }
                max_left=arr[i][j];
            }
        }

        long long max_right=-1;
        for (long long j=m-1;j>=0;j--) {
            if(arr[i][j]>max_right) {
                if(!vis[i][j] && arr[i][j]>0) {
                    vis[i][j]=true;
                    cnt++;
                }
                max_right=arr[i][j];
            }
        }
    }

    for (long long j=0;j<m;j++) {
        long long max_top=-1;
        for (long long i=0;i<n;i++) {
            if(arr[i][j]>max_top) {
                if(!vis[i][j] && arr[i][j]>0) {
                    vis[i][j]=true;
                    cnt++;
                }
                max_top=arr[i][j];
            }
        }

        long long max_bottom=-1;
        for (long long i=n-1;i>=0;i--) {
            if(arr[i][j]>max_bottom) {
                if(!vis[i][j] && arr[i][j]>0) {
                    vis[i][j]=true;
                    cnt++;
                }
                max_bottom=arr[i][j];
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
