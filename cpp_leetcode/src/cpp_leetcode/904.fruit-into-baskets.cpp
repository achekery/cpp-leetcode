/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
namespace my {
    template <typename T>
    string iterable_repr(const T& a) {
        stringstream ss; ss << "[";
        for (auto it_a = a.begin(); it_a != a.end(); ++it_a)
        {
            ss << *it_a;
            if (next(it_a) != a.end()) { ss << ", "; }
        }
        ss << "]"; return ss.str();
    }
    template <typename T>
    string iterable2_repr(const T& a) {
        stringstream ss; ss << "[";
        for (auto it_a = a.begin(); it_a != a.end(); ++it_a)
        {
            ss << iterable_repr(*it_a);
            if (next(it_a) != a.end()) { ss << ", "; }
        }
        ss << "]"; return ss.str();
    }
    template <typename T>
    string iterable3_repr(const T& a) {
        stringstream ss; ss << "[";
        for (auto it_a = a.begin(); it_a != a.end(); ++it_a)
        {
            ss << iterable2_repr(*it_a);
            if (next(it_a) != a.end()) { ss << ", "; }
        }
        ss << "]"; return ss.str();
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Find the max total number of fruit taken over A trees and K types.
        // Use modified Kadanes Algorithm to solve.
        const int ftree_n = fruits.size();
        int ftaken_max = 0, ftaken = 0;
        vector<int> fbask_a({ftree_n, -1}), fbask_b({ftree_n, -1});
        for (int ftree_i = ftree_n - 1; ftree_i >= 0; --ftree_i) {
            if (fbask_a[0] == ftree_n && fbask_a[1] == -1) {
                // Add to new basket a.
                fbask_a[0] = ftree_i; fbask_a[1] = ftree_i;
            } else if (fbask_b[0] == ftree_n && fbask_b[1] == -1
            && fruits[fbask_a[0]] != fruits[ftree_i]) {
                // Add to new basket b.
                fbask_b[0] = fbask_a[0]; fbask_b[1] = fbask_a[1];
                fbask_a[0] = ftree_i; fbask_a[1] = ftree_i;
            } else if (fruits[fbask_a[0]] == fruits[ftree_i]) {
                // Add to existing basket a.
                fbask_a[0] = ftree_i;
            } else if (fruits[fbask_b[0]] == fruits[ftree_i]) {
                // Add to existing basket b.
                int fbask_b1_prev = fbask_b[1];
                fbask_b[0] = fbask_a[0]; fbask_b[1] = fbask_a[1];
                fbask_a[0] = ftree_i; fbask_a[1] = fbask_b1_prev;
            } else {
                // Add to new basket that replaces basket b.
                int fbask_b1_next = min(fbask_a[1], fbask_b[0] - 1);
                fbask_b[0] = fbask_a[0]; fbask_b[1] = fbask_b1_next;
                fbask_a[0] = ftree_i; fbask_a[1] = ftree_i;
            }
            ftaken = max(fbask_a[1], fbask_b[1]) - ftree_i + 1;
            ftaken_max = max(ftaken_max, ftaken);
        }
        return ftaken_max;
    }
};
// @lc code=end
