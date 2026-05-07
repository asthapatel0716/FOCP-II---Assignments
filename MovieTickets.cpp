#include <iostream>
#include <map>
#include <set>
using namespace std;

class MovieTicket {
    map<int, set<int>> bookings; // movieID -> set of customerIDs
    const int MAX_SLOTS = 100;

public:
    bool book(int customerID, int movieID) {
        if (bookings[movieID].count(customerID) || (int)bookings[movieID].size() >= MAX_SLOTS) {
            return false;
        }
        bookings[movieID].insert(customerID);
        return true;
    }

    bool cancel(int customerID, int movieID) {
        if (!bookings[movieID].count(customerID)) {
            return false;
        }
        bookings[movieID].erase(customerID);
        return true;
    }

    bool isBooked(int customerID, int movieID) {
        return bookings[movieID].count(customerID) > 0;
    }

    int availableTickets(int movieID) {
        return MAX_SLOTS - (int)bookings[movieID].size();
    }
};

int main() {
    MovieTicket mt;
    int q;
    cin >> q;

    while (q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << "\n";

        } else if (query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << "\n";

        } else if (query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << "\n";

        } else if (query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << "\n";
        }
    }
    return 0;
}
