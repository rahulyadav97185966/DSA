class Solution {
public:
    bool solve(int n, long long int powval, int index){
        if(n == powval){
            return true;
        }
        if(powval > n){
            return false;
        }
        long long int val2 = pow(4,index);
        return solve(n,val2, index+1);
    }
    bool isPowerOfFour(int n) {
        if(n == 1){
            return true;
        }
        return solve(n,1,0);
    }
};