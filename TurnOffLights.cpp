#include <iostream>
#include <string>
using namespace std;
int countOperations(const string& bulbs, int n, int l) {
    int operations = 0; 
    int i = 0;           
    while (i < n) {
        if (bulbs[i] == '1') {       
            operations++;           
            i = i + l;           
        } else {
            i = i + 1;           
        }
    }
    return operations;  
}
int main() {
    int n, k;
    cin >> n >> k;       
    string bulbs;
    cin >> bulbs;       
    int lo = 1;          
    int hi = n;          
    int answer = n;   
    while (lo <= hi) {
        int mid = (lo + hi) / 2;   
        if (countOperations(bulbs, n, mid) <= k) {
            answer = mid;           
            hi = mid - 1;       
        } else {
            lo = mid + 1;         
        }
    }
    cout << answer << endl;
    return 0;
}
