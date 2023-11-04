// File: 10.cpp
// Purpose: Message Altering to Avoid Censorship.
// Author: Joseph Sameh Fouad
// Section: S9 Wednesday 2nd slot
// ID: 20220099
// TA: Samar Sabry Shaker
// Date: 11 Nov 2023

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
  ifstream input_file("in.txt");
  ifstream translation_file("in2.txt");
  ofstream output_file("out.txt");

  if (!input_file.is_open() || !translation_file.is_open() || !output_file.is_open())
  {
    cout << "Error opening files." << '\n';
    return 0;
  }
  map<string, vector<string>> translation_map;
  string arabicWord, translation;

  string line;
  while (getline(translation_file, line))
  {
    string word, tmp;
    bool f = true;
    for (auto i : line)
    {
      if (i != ' ' && i != ':')
        word += i;
      else if (f)
      {
        tmp = word;
        word = "";
        f = false;
      }
      else
      {
        translation_map[tmp].push_back(word);
        word = "";
      }
    }
  }

  while (getline(input_file, line))
  {
    string translatedLine;
    string word;
    for (auto i : line)
    {
      if (i != ' ' && i != '.')
        word += i;
      else
      {
        if (translation_map.find(word) != translation_map.end())
        {
          word = translation_map[word][0];
        }
        translatedLine += word + i;
        word = "";
      }
    }
    if (translation_map.find(word) != translation_map.end())
    {
      word = translation_map[word][0];
    }
    translatedLine += word;
    word = "";
    output_file << translatedLine << '\n';
  }

  cout << "Translation complete." << '\n';
  input_file.close();
  translation_file.close();
  output_file.close();
  return 0;
}
