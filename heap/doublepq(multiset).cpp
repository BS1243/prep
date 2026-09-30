#include <set>
#include <string>
#include <vector>

using namespace std;
//ms.end() , ms.begin() 모두 location 반환
//ms.end() prev꺼가 end 객체 
//multiset<int, greater<int>> ms; 내림차순
vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (string op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));//2~ stoi insert
            ms.insert(num);
        }
        else if (!ms.empty()) {
            if (op == "D 1") {
                auto it = prev(ms.end());
                ms.erase(it);
            }
            else {
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty())
        return {0, 0};

    return {
        *prev(ms.end()),
        *ms.begin()      
    };
}