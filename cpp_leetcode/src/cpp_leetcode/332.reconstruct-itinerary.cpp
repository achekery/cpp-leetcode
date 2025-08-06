/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Find lex min itinerary over V vertices and E edges.
        // Runtime O(E Log E/V). Memory O(E).

        typedef priority_queue<string, vector<string>, greater<string>>
            minhp_t;
        unordered_map<string, minhp_t> adja;
        deque<string> trav, itin;

        for (auto& t: tickets) {
            if (adja.find(t[0]) == adja.end()) { adja[t[0]] = minhp_t(); }
            adja[t[0]].push(t[1]);
        }

        trav.push_back({"JFK"}); 
        while (!trav.empty()) {
            const auto& va = trav.back();
            if (!adja[va].empty()) {
                // Discover child node using depth-first search.
                const auto& vb = adja[va].top();
                trav.push_back(vb);
                adja[va].pop();
            } else {
                // Explore current node using backtracking.
                itin.push_front(va);
                trav.pop_back();
            }
        }

        return vector<string>(itin.begin(), itin.end());
    }
};



// @lc code=end
