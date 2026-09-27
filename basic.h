#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

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
inline void prq(queue<T> q)
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
inline void prqpair(queue<pair<T1, T2>> q)
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