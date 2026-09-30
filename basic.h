#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

template <typename T>
inline void pr1(const vector<T>& v)
{
    for (const auto& x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

template <typename T>
inline void pr2(const vector<vector<T>>& v)
{
    for (const auto& row : v)
    {
        for (const auto& x : row)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

template <typename T>
inline void pr3(const vector<vector<vector<T>>>& v)
{
    for (const auto& layer : v)
    {
        for (const auto& row : layer)
        {
            for (const auto& x : row)
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

// 일반 queue 출력
template <typename T>
inline void prq(queue<T> q) //Q
{
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

// pair queue 출력
template <typename T1, typename T2>
inline void prqpair(queue<pair<T1, T2>> q) //Q pair
{
    while (!q.empty())
    {
        cout << '('
             << q.front().first
             << ", "
             << q.front().second
             << ") ";

        q.pop();
    }
    cout << '\n';
}

template <typename T>
inline void prs(stack<T> s) //stack
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}

template <typename T1, typename T2>
inline void prsp(stack<pair<T1, T2>> s) //stack pair
{
    while (!s.empty())
    {
        cout << '('
             << s.top().first
             << ", "
             << s.top().second
             << ") ";

        s.pop();
    }

    cout << '\n';
}

// 일반 priority_queue 출력
template <typename T, typename Container, typename Compare>
inline void prpq(priority_queue<T, Container, Compare> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

// pair priority_queue 출력
template <typename T1, typename T2, typename Container, typename Compare>
inline void prpqpair(
    priority_queue<pair<T1, T2>, Container, Compare> pq)
{
    while (!pq.empty())
    {
        cout << '('
             << pq.top().first
             << ", "
             << pq.top().second
             << ") ";

        pq.pop();
    }
    cout << '\n';
}