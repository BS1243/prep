#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> board;
vector<int> length;
int nm = 0;

void rcur(int loc, int dep, int n)
{
    for (int i = loc + 1; i < n + 1; i++)
    {
        if (board[loc][i] && (dep < length[i]))
        {
            rcur(i, dep + 1, n);
            length[i] = dep + 1;
            if (dep > nm - 1)
                nm = dep;
        }
    }
    return;
}

void solution(int n, vector<vector<int>> edge)
{
    board.resize(n + 1, vector<int>(n + 1, 0));
    length.resize(n + 1, 99999);
    length[1] = 0;
    for (auto row : edge)
    {
        board[row[0]][row[1]] = 1;
        board[row[1]][row[0]] = 1;
    }
    rcur(1, 0, n);
    int anwser = 0;
    for (int x : length)
    {
        cout<<x<<" ";
        if (x == nm)
            anwser++;
    }
    cout << anwser;
    return;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {
        {1, 3},
        {1, 6},
        {3, 4},
        {3, 5},
        {3, 6},
        {5, 2},
        {6, 2}};

    solution(n, edge);
    return 1;
}
