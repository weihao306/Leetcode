/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (48.78%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 48.8K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */

// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        //左右数量相等,则取出右边的一个对象push进入左边的大顶堆
        if(leftQue.size() == rightQue.size())
        {
            rightQue.push(num);
            leftQue.push(rightQue.top());
            rightQue.pop();
        }
        //左边多一个,则取出左边的一个对象push进右边的小顶堆
        else if(leftQue.size() == rightQue.size()+1)
        {
            leftQue.push(num);
            rightQue.push(leftQue.top());
            leftQue.pop(); 
        }
    }
    
    double findMedian() {
        double res = 0.0;
        if(leftQue.size() == rightQue.size())
        {
            res = ((double)leftQue.top() + (double)rightQue.top())/2;
        }
        else res = leftQue.top();
        return res;
    }
private:
    priority_queue<int,vector<int>,less<int>> leftQue; //大顶堆
    priority_queue<int,vector<int>,greater<int>> rightQue; //小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

