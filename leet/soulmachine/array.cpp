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
    std::cout << t;
}

template <class T, class... Args>
void print(T t, Args... args)
{
    std::cout << t;
    print(args...);
    std::cout << std::endl;
}

vector<int> leet1twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> ret;
    for (int i=0; i<nums.size(); i++) {
        m[nums[i]] = i;
    }
    for (int i = 0; i<nums.size(); i++) {
        int gap = target - nums[i];
        if (m.find(gap)!=m.end() && m[gap]> i) {
            ret.push_back(i+1);
            ret.push_back(m[gap]+1);
            break;
        }
    }
    return ret;
}

vector<vector<int>> leet15threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3) return ret;

    sort(nums.begin(), nums.end());

    int target = 0;

    auto last = nums.end(); 

    for (auto i = nums.begin(); i<last - 2; ++i) {
        auto j = i+1;
        if (i>nums.begin() && *i == *(i-1)) continue; 

        auto k = last -1;

        while (j < k) {
            if (*i + *j + *k < target) {
                ++j;
                while (*j==*(j-1) && j<k) ++j; 
            } else if (*i + *j + *k > target) {
                --k; 
                while (*k==*(k+1) && j<k) --k;
            } else {
                ret.push_back({*i, *j, *k});
                ++j;
                --k;
                while (*j==*(j-1) && j<k) ++j;
                while (*k==*(k+1) && j<k) --k;
            }
        }
    }
    return ret;
}


int leet16threeSumClosest(vector<int>& nums, int target) {
    int ret = 0;
    int min_gap = INT_MAX;

    sort(nums.begin(), nums.end());

    for (auto a = nums.begin(); a!=prev(nums.end(), 2); ++a) {
        auto b = next(a); 
        auto c = prev(nums.end());

        while (b<c) {
            int sum = *a + *b + *c;
            int gap = abs(sum - target);

            if (gap < min_gap) {
                ret = sum; 
                min_gap = gap;
            }

            if (sum<target) ++b;
            else --c;
        }
    }
    return ret;
}

int main()
{
    auto start = chrono::steady_clock::now();

    //http://www.randomnumberapi.com/api/v1.0/random?min=1&max=1000&count=50
    
    vector<int> m1 = {2,7,11,15};
    vector<int> m2 = {-1, 0, 1, 2, -1, 4};
    vector<int> m3 = {-1, 2, 1, -4};
    vector<int> m4 = {-100, 89, 25, -7, -90, -19, -83, 87, 100, 61};
    vector<int> m5 = {-429, 136, 754, 720, -909, 378, -999, 593, 824, -296, 352, -972, -836, -977, -938, -873, -477, -579, 558, 434, 641, 598, 802, 145, 99, -27, -598, 784, 642, 252, 219, -475, 846, 811, -567, 401, 459, -666, -439, 615, 888, 336, 605, -597, -666, 781, 757, -644, -52, -82};

    // vector<int> ans = leet1twoSum(m2, 9);

    // vector<vector<int>> ans = leet15threeSum(m2);

    // walk2dVector(ans);

    int ans = leet16threeSumClosest(m3);

    watch(ans);
    

    auto end = chrono::steady_clock::now();
    // Store the time difference between start and end
    auto diff = end - start;

    std::cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}