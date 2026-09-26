#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];

        vector<int> temp(
            array.begin() + i - 1,
            array.begin() + j
        );

        sort(temp.begin(), temp.end());

        answer.push_back(temp[k - 1]);
    }

    return answer;
}