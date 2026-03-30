class Solution {
public:
    bool isPowerOfThree(int n) {
        //如果一个数是3的n次幂。那么这个数一定含有3的质数因子
        //1162261467是整形范围内，最大的3次幂，它是3的19次方
        return n>0 && 1162261467 % n==0;
    }
};
