#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* child[26] = {};
    int count = 0;
};

void insert(Node* root, string word) {
    Node* cur = root;

    for (char c : word) {
        int idx = c - 'a';

        if (cur->child[idx] == nullptr) {
            cur->child[idx] = new Node();
        }

        cur = cur->child[idx];
        cur->count++;
    }
}

int search(Node* root, string word) {
    Node* cur = root;

    for (int i = 0; i < word.size(); i++) {
        int idx = word[i] - 'a';

        cur = cur->child[idx];

        if (cur->count == 1) {
            return i + 1;
        }
    }

    return word.size();
}

int solution(vector<string> words) {
    int answer = 0;

    Node* root = new Node();

    for (string word : words) {
        insert(root, word);
    }

    for (string word : words) {
        answer += search(root, word);
    }

    return answer;
}