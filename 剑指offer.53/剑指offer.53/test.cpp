﻿//给定一个数组 A[0, 1, …, n - 1]，请构建一个数组 B[0, 1, …, n - 1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i] = A[0]×A[1]×…×A[i - 1]×A[i + 1]×…×A[n - 1]。不能使用除法。
//
//示例:
//
//输入: [1, 2, 3, 4, 5]
//输出 : [120, 60, 40, 30, 24]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> constructArr(vector<int>& a)
    {
        int length = a.size();
        if (length == 0)
            return {};
        vector<int> answer(length);
        answer[0] = 1;
        for (int i = 1; i < length; ++i)
        {
            answer[i] = a[i - 1] * answer[i - 1];
        }
        int j = 1;
        for (int i = length - 1; i >= 0; --i)
        {
            answer[i] = answer[i] * j;
            j *= a[i];
        }
        return answer;
    }
};