#include <iostream>
#include <fstream>
#include <chrono>
#include "Trieee.h"

void triedict(const std::string& text, const std::string& word) {
    Trie trie;
    std::string str = "";

    for (const char& ch : text) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '\'') {
            str += tolower(ch); // Приводим к нижнему регистру
        }
        else if (str.size() > 0) {
            trie.insert(str);
            str = "";
        }
    }

    // Добавляем последнее слово, если в строке есть
    if (str.size() > 0) {
        trie.insert(str);
    }

    std::cout << "\ndict size: " << trie.size() << std::endl;
    std::cout << word << ": " << trie.find(word) << std::endl;
}

int main() {
    using namespace std;
    string text;
    ifstream fin("C:\\Users\\koros\\Desktop\\2КУРС2СЕМЕСТР\\САОД\\prefix\\engwiki_ascii.txt", ios::binary);
    if (!fin.is_open()) {
        cout << "not open!" << endl;
        return 0;
    }
    text.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    string word = "wiki"; // слово, которое ищем
    auto time_one = chrono::high_resolution_clock::now();
    triedict(text, word);
    auto time_two = chrono::high_resolution_clock::now();
    cout << "trie\t" << chrono::duration<double>(time_two - time_one).count() << " seconds" << endl;

    return 0;
}