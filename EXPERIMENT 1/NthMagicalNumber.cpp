#include<iostream>
using namespace std;

class Solution {
public:
    
    static const int mod = 1e9 + 7;

    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int nthMagicalNumber(int n, int a, int b) {

        long long left = 1;
        long long right = 2e18;
        long long answer = 0;

        long long lcmValue = lcm(a, b);

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            long long count =
                (mid / a) +
                (mid / b) -
                (mid / lcmValue);

            if (count >= n) {
                answer = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }

        return answer % mod;
    }
};

int main() {

    int n, a, b;
    cin >> n >> a >> b;

    Solution obj;

    cout << obj.nthMagicalNumber(n, a, b);

    return 0;
}
