#include <bits/stdc++.h>
using namespace std;

int get_ans(int n, vector<int> a) {   
    // 1. Find the MEX of the full array
    vector<char> seen(n + 1, 0);
    for (int x : a)
        if (x <= n) seen[x] = 1;

    int mex = 0;
    while (mex <= n && seen[mex]) ++mex;

    // Edge case: if MEX = 0, empty prefix already works
    if (mex == 0) return 0;

    // 2. Sliding window on circular array (array doubled)
    vector<int> freq(mex, 0);
    int have = 0, need = mex;
    int best = n;

    int left = 0;
    for (int right = 0; right < 2 * n; ++right) {
        int val = a[right % n];
        if (val < mex && ++freq[val] == 1) ++have;

        // shrink from left while window still has all 0..mex-1
        while (have == need && left <= right) {
            int len = right - left + 1;
            if (len <= n) best = min(best, len);

            int v = a[left % n];
            if (v < mex && --freq[v] == 0) --have;
            ++left;
        }
    }
    return best;
}

int main() {
    // ---------- Sample test cases ----------
    cout << get_ans(3, {1, 2, 3}) << "\n";      // Expected 0
    cout << get_ans(3, {1, 1, 0}) << "\n";      // Expected 2
    cout << get_ans(3, {0, 1, 2}) << "\n";      // Expected 3

    // ---------- Tough test case ----------
    cout << get_ans(7, {2, 0, 5, 1, 4, 0, 3}) << "\n"; // Expected 6

    return 0;
}
