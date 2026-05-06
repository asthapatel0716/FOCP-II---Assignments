#include <iostream>
#include<vector>
using namespace std;
const int MAXN = 10000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> distinctPrimeCount(MAXN + 1, 0);
    for (int i = 2; i <= MAXN; i++) {
        if (distinctPrimeCount[i] == 0) { 
            for (int j = i; j <= MAXN; j += i) {
                distinctPrimeCount[j]++;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int k = distinctPrimeCount[n];
        int ans = 1 << k; 
        cout << ans << '\n';
    }
    return 0;
}
