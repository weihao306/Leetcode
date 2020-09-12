/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.44%)
 * Likes:    463
 * Dislikes: 0
 * Total Accepted:    105K
 * Total Submissions: 165.6K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size() < 2)
        {
            ans.push_back(strs);
            return ans;
        }

        //将小写字母和质数关联，质数的积是唯一的
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 
                            71, 73, 79, 83, 89, 97, 101};
        //将质数作为键值
        unordered_map<double, vector<string>> hash;
        double t = 1;
        for(string s : strs)
        {
            t = 1;
            for(char c : s)
                t *= prime[c - 'a'];
            if(hash.find(t) == hash.end())
                hash.insert({t, {}});
            hash[t].push_back(s);
        }
        for(auto p : hash)
            ans.push_back(p.second);

        return ans;
    }
};
// @lc code=end

