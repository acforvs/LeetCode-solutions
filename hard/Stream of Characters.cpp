class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (auto &word : words) {
            TrieNode* node = trie;
            for (int i = word.length() - 1; i >= 0; i--) {
                char c = word[i];
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->is_word = true;
        }
    }

    bool query(char letter) {
        stream.push_front(letter);

        TrieNode* node = trie;
        for (char c : stream) {
            if (node->is_word) {
                return true;
            }
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->is_word;
    }
private:
    struct TrieNode {
        bool is_word;
        unordered_map<char, TrieNode*> children;
    };
    TrieNode* trie = new TrieNode();
    deque<char> stream;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
