#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int count = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first < pq.top()) {
            q.push(cur);
        } else {
            pq.pop();
            count++;

            if (cur.second == location)
                return count;
        }
    }

    return count;
}