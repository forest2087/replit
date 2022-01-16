/*
link
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <functional> // std::greater
#include <algorithm>  // std::sort
#include <set>
#include <stack>
#include <ostream>
#include <string>
#include <cmath>
#include <deque>
#include <chrono>
#include <queue>

#define c(x) cout << (#x) << endl;
#define sep() cout << "------------------" << endl;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define walkMap(x)                                                 \
    cout << "walk map: " << (#x) << endl;                          \
    for (auto const &pair : x)                                     \
    {                                                              \
        cout << "{" << pair.first << ": " << pair.second << "}\n"; \
    };
#define walkVector(x)                           \
    cout << "walk vector: " << (#x) << endl;    \
    for (auto i = x.begin(); i != x.end(); ++i) \
        cout << *i << ' ';                      \
    cout << endl;
#define walk2dVector(x)                                \
    cout << "walk vector: " << (#x) << endl;           \
    for (auto j : x)                                   \
    {                                                  \
        for (auto it = j.begin(); it != j.end(); ++it) \
            cout << *it << ' ';                        \
        cout << endl;                                  \
    }                                                  \
    cout << endl;

#define walk1dArray(x, n)       \
    for (int j = 0; j < n; j++) \
    {                           \
        cout << x[j] << " ";    \
    }                           \
    cout << endl;

#define walk2dArray(x, n)           \
    for (int i = 0; i < n; i++)     \
    {                               \
        for (int j = 0; j < n; j++) \
        {                           \
            cout << x[i][j] << " "; \
        }                           \
        cout << endl;               \
    }

using namespace std;

template <class T>
void print(T t)
{
    std::cout << t ;
}

template <class T, class... Args>
void print(T t, Args... args)
{
    std::cout << t;
    print(args...);
    std::cout << std::endl;
}

int solv509(int n)
{
    if (n==0) return 0;
    if (n<3) return 1;

    int ans, curr=1, prev=1;
    for (int i = 3; i<=n; i++) {
        ans = curr+prev;
        prev = curr;
        curr = ans;
    }
    return ans;
}

typedef pair<int, int> pi;
vector<int> solv1337(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    int curr = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq; 

    for (int i = 0; i<n; i++) {
        curr = 0;
        for (int j = 0; j<m; j++) {
            curr+=mat[i][j];
        }
        pq.emplace(curr, i);
    }

    // while(!pq.empty()) {
    //     print(pq.top().second, "");
    //     pq.pop();
    // }

    while (k>0) {
        --k;
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main()
{
    auto start = chrono::steady_clock::now();

    //http://www.randomnumberapi.com/api/v1.0/random?min=1&max=1000&count=50
    vector<int> m1 = {3, 7, 9};
    vector<int> m2 = {452, 613, 599, 127, 626};
    vector<int> m3 = {3, 1, 1, 9, 5, 9, 4, 8, 1, 8, 6, 10, 9, 5, 6, 5, 3, 3, 5, 1, 10, 5, 8, 5, 2, 6, 7, 6, 2, 3, 1, 8, 8, 6, 6, 8, 6, 8, 3, 4, 5, 5, 4, 4, 7, 10, 3, 9, 10, 3};
    vector<int> m4 = {-100, 89, 25, -7, -90, -19, -83, 87, 100, 61};
    vector<int> m5 = {-429, 136, 754, 720, -909, 378, -999, 593, 824, -296, 352, -972, -836, -977, -938, -873, -477, -579, 558, 434, 641, 598, 802, 145, 99, -27, -598, 784, 642, 252, 219, -475, 846, 811, -567, 401, 459, -666, -439, 615, 888, 336, 605, -597, -666, 781, 757, -644, -52, -82};
    vector<vector<int>> m1137 {
        {1, 1, 0,0,0,},
        {1, 1, 1, 1, 1, 0},
        {1, 0,0,0,0}, 
        {1, 1, 0,0,0},
        {1, 1, 1, 1, 1},
    };

    // int ans = solv(12, m1);
    // int ans = solv(11, m1);

    // watch(ans);

    //509
    // print(solv509(10));

    //1137
    vector<int> ans1137=solv1337(m1137, 3);
    walkVector(ans1137);


    auto end = chrono::steady_clock::now();
    // Store the time difference between start and end
    auto diff = end - start;

    std::cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}