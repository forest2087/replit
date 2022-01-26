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
void print(T t, int dl=1)
{
    std::cout << t << " ";
    if (dl) cout << endl;
}

template <class T, class... Args>
void print(T t, Args... args)
{
    print(t, 0);
    print(args...);
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

// in an array of 1, 1, 0, 0, 0, find first zero position
int binarySearchFirstZero(vector<int> arr) {
    int left = 0, right = arr.size()-1, mid;
    while (left<right) {
        mid = (left+right) / 2;
        if (arr[mid]==0) {
            right = mid;
        } else {
            left = mid+1;
        }
    }   
    return left;
}

vector<int> solv1337_2(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;
    int curr = 0;

    // use max heap so we can keep the heap size at k
    // use min heap to keep it easy, but more space 
    priority_queue<pi> pq; 

    for (int i = 0; i<n; i++) {
        curr = binarySearchFirstZero(mat[i]);
        pq.emplace(curr, i);
        if (pq.size()>k) pq.pop();
    }

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;

}


int solv1137(int n) {

    if (n==0) return 0;
    if (n==1 || n==2) return 1;
        
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3;  i<=n; i++) {
        dp[i] = dp[i-3]+dp[i-2]+dp[i-1];
    }

    return dp[n];
}

int solv70(int n) {
    if (n==0) return 0;
    if (n==1) return 1;

    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i<=n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }

    return dp[n];
    
}

int solv746(vector<int> cost) {
    int n = cost.size();

    vector<int> dp(n+1);
    for (int i = 2; i<=n; i++) {
        dp[i] = min(dp[i-2] + cost[i-2], dp[i-1]+cost[i-1]);
    }

// walkVector(dp);
    return dp[n];
}

int solv198(vector<int> nums) {
    int n = nums.size();

    if (n==1) return nums[0];
    if (n==2) return max(nums[0], nums[1]);

    vector<int> dp(n); 
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i<n; i++) {
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }

    return dp[n-1];

}

int solv213_helper(vector<int> nums, int l, int r) {
    // size always > 2
    vector<int> dp(r-l);
    dp[0] = nums[l];
    dp[1] = max(nums[l], nums[l+1]);
    for (int i = 2; i<r; i++) {
        dp[i] = max(dp[i-2]+nums[l+i], dp[i-1]);
    }

    return dp[r-1];
}

int solv213(vector<int> nums) {
    // two scenario
    // 0...n-1
    // 1...n

    int n = nums.size();
    if (n==1) return nums[0];
    if (n==2) return max(nums[0], nums[1]);
    return max(solv213_helper(nums, 0, n-1), solv213_helper(nums, 1, n));
}

int solv740_helper(vector<int> nums) { 
    // this is same as the robber helper

    int n = nums.size();
    return solv213_helper(nums, 0, n);
    
}

int solv740(vector<int> nums) {

    // https://leetcode-cn.com/problems/delete-and-earn/solution/ru-guo-ni-li-jie-liao-da-jia-jie-she-zhe-ti-ni-ken/

    // if we select n, then n-1 and n+1 cannot be selected, this is the same as the robber cannot steal consecutive houses question
    // int n = nums.size();

    // since the constraint is
    // 1 <= nums[i] <= 10^4
    // vector<int> new_nums(10001, 0);

    // optimized to be 
    int n = *max_element(nums.begin(), nums.end()) + 1;
    vector<int> new_nums(n, 0);

    for (auto i: nums) {
        new_nums[i]+=i;
    }

    // walkVector(new_nums);
    int ans = solv740_helper(new_nums);

    return ans;
    // return 0;
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
    vector<vector<int>> m1337 {
        {1, 1, 0,0,0,},
        {1, 1, 1, 1, 1, 0},
        {1, 0,0,0,0}, 
        {1, 1, 0,0,0},
        {1, 1, 1, 1, 1},
    };


    //740
    // vector<int> v740={3,4,2};
    vector<int> v740={2,2,3,3,3,4};
    print(solv740(v740));


    //213
    // vector<int> v213={2, 3, 2};
    // vector<int> v213={1, 2, 3, 1};
    // print(solv213(v213));

    // int ans = solv(12, m1);
    // int ans = solv(11, m1);

    // watch(ans);

    //509
    // print(solv509(10));

    //1337
    // vector<int> ans1337=solv1337(m1337, 3);
    // walkVector(ans1337);

    //1337 maxheap + binary
    // vector<int> ans1337_2=solv1337_2(m1337, 3);
    // walkVector(ans1337_2);
    // print(binarySearchFirstZero(m1137[4]));

    //1137
    // print(solv1137(0));
    // print(solv1137(4));
    // print(solv1137(25));

    //70
    // print(solv70(0));
    // print(solv70(3));
    // print(solv70(20));

    //746
    // vector<int> v746 = {10, 15, 20};
    // vector<int> v746 = {1,100,1,1,1,100,1,1,100,1};
    // print(solv746(v746));

    //198
    // vector<int> v198={1, 2, 3, 1};
    // vector<int> v198={2,7,9,3,1};
    // print(solv198(v198));



    auto end = chrono::steady_clock::now();
    // Store the time difference between start and end
    auto diff = end - start;

    std::cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}