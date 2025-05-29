#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <sstream>
#include <cctype>

class TrieNode {
public:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    int count = 0; // количество вхождений слова
};

class Trie {
public:
    Trie() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word) {
        auto* node = root.get();
        for (char c : word) {
            if (!isalpha(c) && c != '\'') continue; // пропускаем недопустимые символы
            c = tolower(c);  // приведение к нижнему регистру
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = std::make_unique<TrieNode>();
            }
            node = node->children[c].get();
        }
        node->count++;
    }

    int find(const std::string& word) const {
        const TrieNode* node = root.get();
        for (char c : word) {
            if (!isalpha(c) && c != '\'') continue;
            c = tolower(c);
            auto child_iter = node->children.find(c);
            if (child_iter == node->children.end()) {
                return 0;
            }
            node = child_iter->second.get();
        }
        return node->count;
    }


    int size() const {
        return countUniqueWords(root.get());
    }

private:
    std::unique_ptr<TrieNode> root;

    int countUniqueWords(const TrieNode* node) const {
        int count = 0;
        if (node->count > 0) count++; // если это конец слова, считаем его
        for (const auto& child : node->children) {
            count += countUniqueWords(child.second.get());
        }
        return count;
    }
};

void triedict(const std::string& text) {
    // Создаем префиксное дерево
    Trie trie;
    std::unordered_map<std::string, int> hashTable;

    // Подсчет слов в тексте и добавление в trie и хеш-таблицу
    std::istringstream stream(text);
    std::string currentWord;

    auto startTrie = std::chrono::high_resolution_clock::now();
    while (stream >> currentWord) {
        // Очистка и форматирование слова
        std::string cleanedWord;
        for (char c : currentWord) {
            if (isalpha(c) || c == '\'') {
                cleanedWord += tolower(c);
            }
        }
        if (!cleanedWord.empty()) {
            trie.insert(cleanedWord);
            hashTable[cleanedWord]++;
        }
    }
    auto endTrie = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> trieDuration = endTrie - startTrie;

    // Подсчет уникальных слов
    int trieUniqueWords = trie.size();
    std::cout << "Дерево: Уникальные слова: " << trieUniqueWords << ", Время: " << trieDuration.count() << " сек\n";

    // Проверка совпадений
    std::cout << "Сравнение слов в таблице:\n";
    for (const auto& pair : hashTable) {
        int hashCount = pair.second;
        int trieCount = trie.find(pair.first);
        std::cout << "Слово: " << pair.first << ", Хеш-таблица: " << hashCount
            << ", Trie: " << trieCount << "\n";
    }
}

int main() {
    // Пример использования
    std::string text = "Hello world! This is a test. Hello again, world!";
    triedict(text);
    return 0;
}