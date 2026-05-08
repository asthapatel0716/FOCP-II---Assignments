// correct code without bugs

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to replace {name} placeholder with actual user name
string replaceName(string excuse, string name) {
    string placeholder = "{name}";
    int pos = excuse.find(placeholder);
    
    // Keep replacing until no more {name} found
    while (pos != string::npos) {
        excuse.replace(pos, placeholder.length(), name);
        pos = excuse.find(placeholder);
    }
    return excuse;
}

int main() {
    // Seed the random number generator with current time
    srand(time(0));
    
    // Store all excuse templates in a vector
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name}'s dog ate the assignment file somehow.",
        "{name} was almost done but accidentally deleted everything.",
        "{name} couldn't focus because the electricity went out for hours.",
        "{name} tried submitting the assignment but the college portal crashed."
    };
    
    // Ask user to enter their name
    string userName;
    cout << "Enter your name: ";
    
    // Fix 1: Using getline instead of cin to read full name with spaces
    getline(cin, userName);
    
    // Fix 2: Check if name is empty
    if(userName.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }
    
    // Fix 3: Corrected random range to include all 10 excuses
    int randomIndex = rand() % excuses.size();
    
    // Replace {name} with actual user name
    string finalExcuse = replaceName(excuses[randomIndex], userName);
    
    // Display the final excuse
    cout << "\nYour Excuse: " << finalExcuse << endl;
    
    return 0;
}
