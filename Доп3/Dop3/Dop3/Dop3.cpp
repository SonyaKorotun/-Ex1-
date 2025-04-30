#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <string>
#include <chrono>
#include <cctype>

class TrieNode {
public:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    size_t count = 0; // count of occurrences of words ending at this node
};

class Trie {
public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word) {
        auto node = root.get();
        for (char ch : word) {
            node = node->children.emplace(ch, std::make_unique<TrieNode>()).first->second.get();
        }
        node->count++;
    }

    size_t find(const std::string& word) const {
        const TrieNode* node = root.get();
        for (char ch : word) {
            auto it = node->children.find(ch);
            if (it == node->children.end())
                return 0; // word not found
            node = it->second.get();
        }
        return node->count;
    }

    size_t size() const {
        return uniqueWordsCount;
    }

    void countUniqueWords() {
        countUniqueWords(root.get());
    }

private:
    std::unique_ptr<TrieNode> root;
    size_t uniqueWordsCount = 0;

    void countUniqueWords(const TrieNode* node) {
        if (node->count > 0)
            uniqueWordsCount++;
        for (const auto& pair : node->children) {
            countUniqueWords(pair.second.get());
        }
    }
};

void trieDict(const std::string& text, const std::string& word) {
    Trie trie;
    std::string str;

    for (const auto& ch : text) {
        if (isalnum(ch) || ch == '\'') {
            str += std::tolower(ch);
        }
        else if (!str.empty()) {
            trie.insert(str);
            str.clear();
        }
    }
    // Insert the last word, if any
    if (!str.empty()) {
        trie.insert(str);
    }

    trie.countUniqueWords(); // count unique words
    std::cout << "\ndict size: " << trie.size() << std::endl;
    std::cout << word << ": " << trie.find(word) << std::endl;
}

int main() {
    std::ifstream fin("engwiki_ascii.txt", std::ios::binary);
    if (!fin.is_open()) {
        std::cout << "not open!" << std::endl;
        return 0;
    }

    std::string text;
    text.append((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());

    std::string word = "wiki"; // слово, которое ищем
    auto time_one = std::chrono::high_resolution_clock::now();
    trieDict(text, word);
    auto time_two = std::chrono::high_resolution_clock::now();
    std::cout << "trieDict\t" << std::chrono::duration<double>(time_two - time_one).count() << " seconds" << std::endl;

    return 0;
}