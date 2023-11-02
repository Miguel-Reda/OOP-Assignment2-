// File: ………cpp
// Purpose: convert male speech to neutral
// Author: Ammar Mohamed Mahmoud Hamed
// Section: S9 Wednesday 2nd slot
// ID: 20220216
// TA: Samar Sabry Shaker
// Date: …… Oct 2023
#include <iostream>
#include <string>
#include <regex>

using namespace std;

void inclusive_speech(string& sentence) {
    // Replace masculine pronouns with both-gender pronouns
    sentence = regex_replace(sentence, regex("\\b([hH]e)\\b"), "$1 or she");
    sentence = regex_replace(sentence, regex("\\b([hH]im)\\b"), "$1 or her");




}

int main() {
    string input_sentence;
    getline(cin,input_sentence);
    inclusive_speech(input_sentence);
    cout << input_sentence << endl;
}

