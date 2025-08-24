/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start

/* Summary: 
    - Find sorted squares (ynums) from sorted inputs (xnums).
 * Intuition:
    - Could use brute force with sorted container. Runtime O(N Log N).
        This adds squares from sorted inputs in any order.
    - Could use two pointers with FIFO container (queue). Runtime O(N).
        This adds squares from sorted inputs in order from absmin to absmax.
        Extra step required to find absmin with binary search.
    - Could use two pointers with LIFO container (stack). Runtime O(N).
        This adds squares from sorted inputs in order from absmax to absmin.
        No extra step required to find absmax.
 * Approach: 
    - Use two pointers with LIFO container (stack).
 * Complexity:
    - Runtime O(N). Memory O(N).
 */

class Solution_1 {  /* ACS. Runtime 3 ms (*56.48%). Memory 31.33 MB (*5.27%). */
public:
    vector<int> sortedSquares(vector<int>& xnums) {
        // Use two pointers with LIFO container (stack).
        // Prefer STL containers for code simplicity.
        deque<int> ynums_stack;
        auto it_i = xnums.begin(); auto rit_j = xnums.rbegin();
        while (it_i != xnums.end() && rit_j != xnums.rend()) {
            if (abs(*it_i) > abs(*rit_j)) {
                ynums_stack.push_front((*it_i) * (*it_i));
                it_i = next(it_i);
            } else {
                ynums_stack.push_front((*rit_j) * (*rit_j));
                rit_j = next(rit_j);
            }
            if (it_i == rit_j.base()) { break; }
        }
        return vector<int>(ynums_stack.begin(), ynums_stack.end());
    }
};

class Solution_2 {  /* ACS. Runtime 0 ms (*100%). Memory 30.26 MB (*63.49%). */
public:
    vector<int> sortedSquares(vector<int>& xnums) {
        // Use two pointers with LIFO container (stack).
        // Prefer basic containers for code performance.
        const int n = xnums.size();
        vector<int> ynums(n); int ynums_idx = n - 1;
        auto it_i = xnums.begin(); auto rit_j = xnums.rbegin();
        while (it_i != xnums.end() && rit_j != xnums.rend()) {
            if (abs(*it_i) > abs(*rit_j)) {
                ynums[ynums_idx--] = (*it_i) * (*it_i);
                it_i = next(it_i);
            } else {
                ynums[ynums_idx--] = (*rit_j) * (*rit_j);
                rit_j = next(rit_j);
            }
            if (it_i == rit_j.base()) { break; }
        }
        return ynums;
    }
};

class Solution: public Solution_2 {};

// @lc code=end
