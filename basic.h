#pragma once

#include <iostream>
#include <vector>

using namespace std;

inline void pr1(const vector<int>& v)
{
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

inline void pr2(const vector<vector<int>>& v)
{
    for (const auto& row : v)
    {
        for (int x : row)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

inline void pr3(const vector<vector<vector<int>>>& v)
{
    for (const auto& layer : v)
    {
        for (const auto& row : layer)
        {
            for (int x : row)
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}