#define _CRT_SECURE_NO_WARNINGS 1

/*将矩阵按对角线排序*/
/* https://leetcode.cn/problems/sort-the-matrix-diagonally/ */
//class Solution {
//public:
//
//    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
//        int n = mat.size(), m = mat[0].size();
//
//        for (int j = 0; j < m; j++)//最上行
//        {
//            vector<int> vec;
//            int r = 0, c = j;
//            while (r < n && c < m)
//                vec.push_back(mat[r++][c++]);
//            sort(vec.begin(), vec.end());
//            r = 0, c = j;
//            int sz = 0;
//            while (sz < vec.size())
//                mat[r++][c++] = vec[sz++];
//        }
//        for (int i = 0; i < n; i++)//最左列
//        {
//            vector<int> vec;
//            int r = i, c = 0;
//            while (r < n && c < m)
//                vec.push_back(mat[r++][c++]);
//            sort(vec.begin(), vec.end());
//            r = i, c = 0;
//            int sz = 0;
//            while (sz < vec.size())
//                mat[r++][c++] = vec[sz++];
//        }
//
//        return mat;
//    }
//};

/*逃离迷宫*/
/* https://www.acwing.com/problem/content/description/3678/ */
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 107, M = 107;
//bool isPass = false;
//int st[N][M];
//char mp[N][M];
//int ddec[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
//
//int n, m, k, x1, x2, y1, y2, T;
//
//bool isLegal(int x, int y, int count)
//{
//    return (x > 0 && x <= n && y > 0 && y <= m) &&//坐标合法
//        mp[x][y] != '*' &&//非墙
//        count >= st[x][y];//最少转弯次数到此点
//}
//
//void dfs(int x, int y, int Dec, int count)
//{
//
//    if (!isLegal(x, y, count) || isPass)//是否合法 + 存在路径即退出
//        return;
//
//    if (x == x2 && y == y2)
//    {
//        isPass = true;
//        return;
//    }
//
//    st[x][y] = count;//更新最优转弯
//
//    for (int i = 0; i < 4; i++)
//        if (i != Dec) dfs(x + ddec[i][0], y + ddec[i][1], i, count - 1);
//        else dfs(x + ddec[Dec][0], y + ddec[Dec][1], Dec, count);
//
//
//}
//
//int main()
//{
//    scanf("%d", &T);
//    while (T--)
//    {
//        memset(st, 0, sizeof st);
//        isPass = false;
//
//        scanf("%d%d", &n, &m); //getchar();
//        for (int i = 1; i <= n; i++)
//        {
//            getchar();//烦人
//            for (int j = 1; j <= m; j++)
//                scanf("%c", &mp[i][j]);
//        }
//        getchar();
//        scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);
//
//        st[x1][y1] = k;
//        for (int i = 0; i < 4; i++)
//            dfs(x1 + ddec[i][0], y1 + ddec[i][1], i, k);
//
//        if (isPass) printf("yes\n");
//        else printf("no\n");
//    }
//}
// /*总结:
// * 需要剪枝, 但因为有转弯次数限制, 不能用bool来表示该点是否需要二次进入, 因为无法分辨两次进入哪一个为最优的
// * 比如第一次进入的时候, 剩余转弯次数为0, 无法进行转弯后到达, 而第二次却可以
// * 则需要记录到达某点的最少转弯次数
// * by:陌上青花_4
// */

/*将数字变成0的操作数*/
/* https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/ */
//class Solution {
//public:
//    int numberOfSteps(int num) {
//
//        int res = 0;
//
//        while (num)
//        {
//            if (num & 1) res += 2;
//            else res += 1;
//
//            num >>= 1;
//        }
//
//        if (res) res--;
//
//        return res;
//    }
//};

/*大小为 K 且平均值大于等于阈值的子数组数目*/
/* https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/ */
//class Solution {
//public:
//    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//
//        vector<int> sum(arr.size() + 1);
//        int res = 0, Sum = k * threshold;
//
//        for (int i = 1; i < sum.size(); i++)
//            sum[i] = sum[i - 1] + arr[i - 1];
//
//        for (int i = k; i < sum.size(); i++)
//            if (sum[i] - sum[i - k] >= Sum)
//                res++;
//
//        return res;
//    }
//};