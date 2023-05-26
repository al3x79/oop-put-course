#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

class MorseTranslator {
public:
    map<string, string> morseCodeMap;
    map<string, string> reverseMorseCodeMap;

    MorseTranslator() {
        morseCodeMap["A"] = ".-";
        morseCodeMap["B"] = "-...";
        morseCodeMap["C"] = "-.-.";
        morseCodeMap["D"] = "-..";
        morseCodeMap["E"] = ".";
        morseCodeMap["F"] = "..-.";
        morseCodeMap["G"] = "--.";
        morseCodeMap["H"] = "....";
        morseCodeMap["I"] = "..";
        morseCodeMap["J"] = ".---";
        morseCodeMap["K"] = "-.-";
        morseCodeMap["L"] = ".-..";
        morseCodeMap["M"] = "--";
        morseCodeMap["N"] = "-.";
        morseCodeMap["O"] = "---";
        morseCodeMap["P"] = ".--.";
        morseCodeMap["Q"] = "--.-";
        morseCodeMap["R"] = ".-.";
        morseCodeMap["S"] = "...";
        morseCodeMap["T"] = "-";
        morseCodeMap["U"] = "..-";
        morseCodeMap["V"] = "...-";
        morseCodeMap["W"] = ".--";
        morseCodeMap["X"] = "-..-";
        morseCodeMap["Y"] = "-.--";
        morseCodeMap["Z"] = "--..";
        morseCodeMap["0"] = "-----";
        morseCodeMap["1"] = ".----";
        morseCodeMap["2"] = "..---";
        morseCodeMap["3"] = "...--";
        morseCodeMap["4"] = "....-";
        morseCodeMap["5"] = ".....";
        morseCodeMap["6"] = "-....";
        morseCodeMap["7"] = "--...";
        morseCodeMap["8"] = "---..";
        morseCodeMap["9"] = "----.";
        morseCodeMap["."] = ".-.-.-";
        morseCodeMap[","] = "--..--";
        morseCodeMap["_"] = "..--.-";
        morseCodeMap[":"] = "---...";
        morseCodeMap[";"] = "-.-.-.";
        morseCodeMap["?"] = "..--..";
        morseCodeMap["!"] = "-.-.--";
        morseCodeMap["-"] = "-....-";
        morseCodeMap["+"] = ".-.-.";
        morseCodeMap["/"] = "-..-.";
        morseCodeMap["("] = "-.--.";
        morseCodeMap[")"] = "-.--.-";
        morseCodeMap["="] = "-...-";
        morseCodeMap["@"] = ".--.-.";
        morseCodeMap["a"] = ".-";
        morseCodeMap["b"] = "-...";
        morseCodeMap["c"] = "-.-.";
        morseCodeMap["d"] = "-..";
        morseCodeMap["e"] = ".";
        morseCodeMap["f"] = "..-.";
        morseCodeMap["g"] = "--.";
        morseCodeMap["h"] = "....";
        morseCodeMap["i"] = "..";
        morseCodeMap["j"] = ".---";
        morseCodeMap["k"] = "-.-";
        morseCodeMap["l"] = ".-..";
        morseCodeMap["m"] = "--";
        morseCodeMap["n"] = "-.";
        morseCodeMap["o"] = "---";
        morseCodeMap["p"] = ".--.";
        morseCodeMap["q"] = "--.-";
        morseCodeMap["r"] = ".-.";
        morseCodeMap["s"] = "...";
        morseCodeMap["t"] = "-";
        morseCodeMap["u"] = "..-";
        morseCodeMap["v"] = "...-";
        morseCodeMap["w"] = ".--";
        morseCodeMap["x"] = "-..-";
        morseCodeMap["y"] = "-.--";
        morseCodeMap["z"] = "--..";

        for (const auto& pair : morseCodeMap)
            {
                reverseMorseCodeMap[pair.second] = pair.first;
            }
    }
};

class NormalToMorseConverter : public MorseTranslator {
public:
    string convertToMorse(const string& text) {
        string result;
        for (char c : text) {
            string key;
            key += c;
            auto it = morseCodeMap.find(key);
            if (it != morseCodeMap.end()) {
                result += it->second;
                result += " ";
            } else if (c == ' ') {
                result += "/ ";
            }
        }
        return result;
    }
};


class MorseToNormalConverter : public MorseTranslator {
public:
    string convertToNormal(const string& text) {
        string result1, current;
        for (char c : text) {
            if (c == ' ' || c == '/') {
                if (!current.empty()) {
                    auto it = reverseMorseCodeMap.find(current);
                    if (it != reverseMorseCodeMap.end()) {
                        result1 += it->second;
                    }
                    current.clear();
                }
                if (c == ' ') {
                    result1 += " ";
                }
            } else {
                current += c;
            }
        }
        return result1;
    }
};
int main() {
    string text;
    int choice;
    cout << "NORMAL/MORSE TRANSLATOR"<<endl<<endl;
    cout << "Choose the translation direction:" << endl;
    cout << "1. Normal text to Morse code" << endl;
    cout << "2. Morse code to Normal text" << endl;
    cout << "Enter 1 or 2: ";
    cin >> choice;
    cin.ignore();
    system("cls");

    try {
        if (choice == 1) {
            NormalToMorseConverter converter1;
            cout << "Enter the text to convert to Morse code: "<<endl;
            getline(cin, text);
            system("cls");
            cout << "Converted Morse code: " << endl << converter1.convertToMorse(text) << endl;
        } else if (choice == 2) {
            MorseToNormalConverter converter2;
            cout << "Enter the Morse code to convert to normal text: "<<endl;
            getline(cin, text);
            system("cls");
            cout << "Converted normal text: " << endl << converter2.convertToNormal(text) << endl;
        } else {
            throw runtime_error("Invalid choice. Please relaunch the program and enter 1 or 2.");
        }
    } catch (const exception& e) {
        cout << "XX ERROR XX " << e.what() << endl;
    }

    return 0;
}
