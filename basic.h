#pragma once

#include <iostream>
#include <vector>
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