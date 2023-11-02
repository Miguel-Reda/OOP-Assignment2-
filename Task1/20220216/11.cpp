// File: ………cpp
// Purpose: text file comparison
// Author: Ammar Mohamed Mahmoud Hamed
// Section: S9 Wednesday 2nd slot
// ID: 20220216
// TA: Samar Sabry Shaker
// Date: …… Oct 2023
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void compare_files() {
    // Prompt the user for the names of two files to compare
    string filename1, filename2;
    cout << "Enter the name of the first file: ";
    cin >> filename1;
    cout << "Enter the name of the second file: ";
    cin >> filename2;

    // Prompt the user for the comparison mode
    char mode;
    cout << "Enter 'c' for character-by-character comparison, or 'w' for word-by-word comparison: ";
    cin >> mode;

    // Read the contents of the files into strings
    ifstream file1(filename1);
    ifstream file2(filename2);
    string contents1((istreambuf_iterator<char>(file1)), istreambuf_iterator<char>());
    string contents2((istreambuf_iterator<char>(file2)), istreambuf_iterator<char>());

    // Compare the files character by character
    if (mode == 'c') {
        if (contents1 == contents2) {
            cout << "The files are identical." << endl;
        } else {
            int line_number = 1;
            for (int i = 0; i < min(contents1.size(), contents2.size()); i++) {
                if (contents1[i] != contents2[i]) {
                    cout << "The files differ at line " << line_number << ", column " << i+1 << ":" << endl;
                    cout << "File 1: " << contents1.substr(i, 20) << endl;
                    cout << "File 2: " << contents2.substr(i, 20) << endl;
                    break;
                }
                if (contents1[i] == '\n') {
                    line_number++;
                }
            }
        }
    }

        // Compare the files word by word
    else if (mode == 'w') {
        replace(contents1.begin(), contents1.end(), '\n', ' ');
        replace(contents2.begin(), contents2.end(), '\n', ' ');
        replace(contents1.begin(), contents1.end(), '\t', ' ');
        replace(contents2.begin(), contents2.end(), '\t', ' ');
        string word1, word2;
        int line_number = 1, column_number = 0;
        for (int i = 0; i < min(contents1.size(), contents2.size()); i++) {
            if (contents1[i] == ' ') {
                column_number++;
                word1.clear();
            } else {
                word1 += contents1[i];
            }
            if (contents2[i] == ' ') {
                column_number++;
                word2.clear();
            } else {
                word2 += contents2[i];
            }
            if (word1 != word2) {
                cout << "The files differ at line " << line_number << ", column " << column_number-word2.size() << ":" << endl;
                cout << "File 1: " << word1 << endl;
                cout << "File 2: " << word2 << endl;
                break;
            }
            if (contents1[i] == '\n') {
                line_number++;
                column_number = 0;
            }
        }
    }

        // Invalid comparison mode
    else {
        cout << "Invalid comparison mode." << endl;
    }
}

int main() {
    compare_files();
}

