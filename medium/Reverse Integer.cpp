class Solution {
public:
    int reverse(int x) {
        int y = 0;
        int max_int = 2 * (pow(2, 30) - 1) + 1;
        int min_int = -1 * pow(2, 31);

        while (x) {
            int last = x % 10;
            if (y > max_int / 10) return 0;
            if (y == max_int / 10 && last > 7) return 0;
            if (y < min_int / 10) return 0;
            if (y == min_int && last < -8) return 0;
            y = 10 * y + last;
            x /= 10;
        }
        
        return y;
    }
};
