#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

class TrieNode {
public:
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
    size_t count = 0; // количество вхождений слова

    TrieNode() = default;
};

class Trie {
private:
    std::shared_ptr<TrieNode> root;

public:
    Trie() : root(std::make_shared<TrieNode>()) {}

    void insert(const std::string& word) {
        auto node = root;
        for (const char& ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = std::make_shared<TrieNode>();
            }
            node = node->children[ch];
        }
        node->count++;
    }

    size_t find(const std::string& word) {
        auto node = root;
        for (const char& ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return 0; // слово не найдено
            }
            node = node->children[ch];
        }
        return node->count; // возвращаем количество вхождений
    }

    size_t size() {
        return countUniqueWords(root);
    }

private:
    size_t countUniqueWords(std::shared_ptr<TrieNode> node) {
        size_t count = 0;
        if (node->count > 0) {
            count++; // учитываем текущее слово
        }
        for (const auto& pair : node->children) {
            count += countUniqueWords(pair.second); // считаем уникальные слова в дочерних узлах
        }
        return count;
    }
};

#endif // TRIE_H
