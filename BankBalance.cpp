#include <iostream>
#include <map>
using namespace std;
class Bank {
    map<int, long long> accounts; 
public:
    bool create(int userID, long long amount) {
        if (accounts.count(userID)) {
            accounts[userID] += amount;
            return false;
        }
        accounts[userID] = amount;
        return true;
    }
    bool debit(int userID, long long amount) {
        if (!accounts.count(userID) || accounts[userID] < amount)
            return false;
        accounts[userID] -= amount;
        return true;
    }
    bool credit(int userID, long long amount) {
        if (!accounts.count(userID))
            return false;
        accounts[userID] += amount;
        return true;
    }
    long long balance(int userID) {
        if (!accounts.count(userID))
            return -1;
        return accounts[userID];
    }
};
int main() {
    Bank bank;
    int q;
    cin >> q;
    while (q--) {
        string query;
        cin >> query;
        if (query == "CREATE") {
            int x; long long y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << "\n";
        } else if (query == "DEBIT") {
            int x; long long y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << "\n";
        } else if (query == "CREDIT") {
            int x; long long y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << "\n";
        } else if (query == "BALANCE") {
            int x;
            cin >> x;
            cout << bank.balance(x) << "\n";
        }
    }
    return 0;
}
