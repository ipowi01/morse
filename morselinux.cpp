#include <iostream>
#include <vector>
#include <cctype>
#include <map>
#include <cstdlib>
using namespace std;


const map<char, string> tabla = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
        {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
        {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {' ', "/"}
};
void morsePitty(const vector<string>& morseEnkodolt) {
    for (const string& s : morseEnkodolt) {
        for (char x : s) {
            switch (x) {
                case '-':
                    system("play -n -q synth 0.3 sine 700");
                    system("sleep 0.05");
                    break;
                case '.':
                    system("play -n -q synth 0.1 sine 700");
                    system("sleep 0.05");
                    break;
                case '/':
                    system("sleep 0.3");
                    break;
            }
        }
    }
}
int main() {
    string bemenet;
    bool hang;
    vector<char> morseEnkodolando;
    vector<string> morseEnkodolt;
    cout << "Átfordítandó" << endl;
    getline(cin, bemenet);
    cout << "Hanggal? (0-1)" << endl;
    cin >> hang;
    for (char c: bemenet) {
        char iganyc = toupper(c);
        morseEnkodolando.push_back(iganyc);
    }

    for (int i = 0; i <= morseEnkodolando.size() - 1; i++) {
        char c = morseEnkodolando[i];
        if (tabla.count(c)) {
            morseEnkodolt.push_back(tabla.at(c));
        } else {
            morseEnkodolt.push_back("/");
        }
    }
    for (auto j: morseEnkodolt) cout << j << " ";
    if (hang == 1) {
        morsePitty(morseEnkodolt);
    }
    else {
        return 0;
    }
    return 0;
}


