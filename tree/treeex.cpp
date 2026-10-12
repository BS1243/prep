#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* child[26] = {};//알파벳 별 숫자 대응
    bool end = false;
};

void insert(Node* root, string word) {
    Node* cur = root;

    for (char let : word) {
        int idx = let - 'a';

        if (cur->child[idx] == nullptr)
            cur->child[idx] = new Node();

        cur = cur->child[idx];
    }
    cur->end = true;
}

bool search(Node* root, string word) {
    Node* cur = root;

    for (char c : word) {
        int idx = c - 'a';

        if (cur->child[idx] == nullptr)
            return false;

        cur = cur->child[idx];
    }

    return cur->end;
}

int main() {
    Node* root = new Node();

    vector<string> words = {
        "apple",
        "app",
        "banana",
        "cat"
    };

    for (string word : words) {
        insert(root, word);
    }

    cout << search(root, "apple") << endl;
    cout << search(root, "app") << endl;
    cout << search(root, "ap") << endl;
    cout << search(root, "banana") << endl;
    cout << search(root, "dog") << endl;

    return 0;
}