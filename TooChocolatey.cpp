#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        set<int> alexUsed, bobUsed;
        long long alex = 0, bob = 0;
        int turn = 0;
        for(int pile : arr) {
            if(turn == 0 && alexUsed.find(pile) == alexUsed.end()) {
                alexUsed.insert(pile);
                alex += pile;
                turn = 1;
            } else if(turn == 1 && bobUsed.find(pile) == bobUsed.end()) {
                bobUsed.insert(pile);
                bob += pile;
                turn = 0;
            }
        }
        cout << (alex > bob ? "Alex" : "Bob") << "\n";
    }
    return 0;
}
