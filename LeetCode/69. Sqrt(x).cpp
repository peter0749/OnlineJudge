class Solution {
public:
    int mySqrt(int x) {
        /*
          "Not binary search"
          By Newton's method:
          x = sqrt(y) = y^1/2
          x^2 = y, x>=0
          x^2 - y = 0
          => f(x) = y - x^2 = 0
          f'(x) = -2x
          xt+1 = xt - f(xt) / f'(xt)
               = xt - (y - xt*xt) / (-2xt)
               = xt + 0.5 * (y/xt - xt)
        */
        if (x==0) return 0;
        double y = x;
        double x0 = y*0.5;
        for (int i=0; i<20; ++i)
            x0 = x0 + 0.5 * (y/x0 - x0);
        return x0;
    }
};
