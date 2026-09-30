#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0;
    int maxH = 0;

    for (auto card : sizes) {
        int w = max(card[0], card[1]);
        int h = min(card[0], card[1]);

        maxW = max(maxW, w);
        maxH = max(maxH, h);
    }

    return maxW * maxH;
}