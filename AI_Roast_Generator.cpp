//Correct code without bugs.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to replace {name} placeholder with actual user name
string replaceName(string roast, string name) {
    string placeholder = "{name}";
    int pos = roast.find(placeholder);
    
    // Keep replacing until no more {name} found
    while (pos != string::npos) {
        roast.replace(pos, placeholder.length(), name);
        pos = roast.find(placeholder);
    }
    return roast;
}

int main() {
    // Seed the random number generator with current time
    srand(time(0));
    
    // Bug 2 Fix: Skip first predictable random values
    rand();
    rand();
    
    // Store all roast templates in a vector
    // Bug 1 Fix: Replaced em dash (—) with simple double dash (--)
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name} doesn't debug code -- they negotiate with bugs.",
        "{name}'s WiFi password is probably 'password123'.",
        "Scientists studied {name}'s attention span and accidentally cured insomnia.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "{name} doesn't need an alarm clock -- disappointment wakes them up every morning.",
        "The only exercise {name} gets is jumping to conclusions.",
        "{name} tried to think outside the box but couldn't find the box."
    };
    
    // Ask user to enter their name
    string userName;
    cout << "Enter your name: ";
    
    // Bug 3 Fix: Using getline instead of cin to read full name with spaces
    getline(cin, userName);
    
    // Bug 4 Fix: Check if name is empty
    if(userName.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }
    
    // Randomly select a roast from the vector
    int randomIndex = rand() % roasts.size();
    
    // Replace {name} with actual user name
    string finalRoast = replaceName(roasts[randomIndex], userName);
    
    // Display the final roast
    cout << "\nYour Roast: " << finalRoast << endl;
    
    return 0;
}
