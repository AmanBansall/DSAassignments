#include <iostream>
using namespace std;

int main() {
    char str[100];
    int freq[256] = {0};  // to count characters
    
    cout << "Enter a string: ";
    cin.getline(str, 100);

    // count how many times each character comes
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    // check first character that comes only once
    char ans = '\0';
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(int)str[i]] == 1) {
            ans = str[i];
            break;
        }
    }

    if (ans != '\0')
        cout << "First non-repeating character: " << ans;
    else
        cout << "No non-repeating character";

    return 0;
}
