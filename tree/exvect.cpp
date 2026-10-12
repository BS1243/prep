#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

void dfs(int cur) {
    cout << cur << " ";

    for (int next : tree[cur]) {
        dfs(next);
    }
}

int main() {
    int n = 7;

    tree.resize(n + 1);

    // 1의 자식: 2, 3
    tree[1].push_back(2);
    tree[1].push_back(3);

    // 2의 자식: 4, 5
    tree[2].push_back(4);
    tree[2].push_back(5);

    // 3의 자식: 6, 7
    tree[3].push_back(6);
    tree[3].push_back(7);

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    dfs(1);

    return 0;
}