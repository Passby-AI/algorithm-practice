
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right)
        {
            right-=((unsigned int) right&(-(unsigned int)right));
        }
        return right;
    }
};
