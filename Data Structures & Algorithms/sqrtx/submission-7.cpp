class Solution {
public:
    int mySqrt(int x) {
      if(x<2){
        return x;
      }
      long count=x;
    while(count*count>x){
      count=(count+x/count)/2;
    }
       return count;
    }
};