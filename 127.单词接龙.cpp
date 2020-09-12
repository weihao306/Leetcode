/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.55%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    59.7K
 * Total Submissions: 137.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> strset;
        for(auto &i : wordList) strset.insert(i);   //将所有节点加入集合，如果访问过就删除

        queue<pair<string, int>> q;
        q.push({beginWord, 1});   //beginWord进入队列

        string temp;    //到达的节点
        int step;       //到达节点花费的步数
        while(! q.empty())
        {
            if(q.front().first == endWord)
                return q.front().second;
            temp = q.front().first;
            step = q.front().second;

            q.pop();    //已访问的节点出队列

            //寻找下一个单词
            char ch;
            for(int i = 0; i < temp.length(); i++)
            {
                ch = temp[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    if(ch == c)
                        continue;
                    temp[i] = c;
                    if(strset.find(temp) != strset.end()) //如果从集合中找到了temp
                    {
                        q.push({temp, step+1}); //将新的单词加入队列
                        strset.erase(temp);     //从集合中删除temp
                    }
                    temp[i] = ch;   //还原
                }
            }
        }
        return 0;
    }
};
// @lc code=end

