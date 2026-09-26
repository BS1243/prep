#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int solve(vector<vector<int>> jobs)
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        >
        jobq, crntq;

    for (int i = 0; i < jobs.size(); i++)
    {
        jobq.push({jobs[i][0], jobs[i][1]});
    }

    int ms = 0, totaltime = 0, returntime = 0; // 현재 시간,총 시간,한 객체의 반환시간

    while (!jobq.empty() || !crntq.empty())
    {

        while (!jobq.empty() && jobq.top().first <= ms)
        { // 요청시간 지난거 push
            auto [a, b] = jobq.top();
            crntq.push({b, a});
            jobq.pop();
        }

        if (!crntq.empty())
        {
            auto [b, a] = crntq.top();
            returntime = b + ms - a;
            totaltime += returntime;
            ms += b;
            crntq.pop();
            continue;
        }
        ms+=1;
    }
    return totaltime / jobs.size();
}


int solution(vector<vector<int>> jobs) {
    int answer = solve(jobs);
    return answer;
}
