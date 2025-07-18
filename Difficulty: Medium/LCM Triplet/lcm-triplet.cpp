class Solution {
  public:
    
long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

long long lcm(long long a, long long b, long long c) {
    return lcm(a, lcm(b, c));
}
    int lcmTriplets(int n) {
        // code here
        long long res = 0;

    if (n <= 2) {
        res = n;
    } else if (n % 2 == 1) {
        // If n is odd, use n*(n-1)*(n-2)
        res = n * (n - 1) * (n - 2);
    } else {
        // If n is even, try both options
        res = max({lcm(n, n - 1, n - 3), lcm(n - 1, n - 2, n - 3)});
        // Special case: if n is divisible by 3
        if (n % 3 != 0)
            res = max(res, lcm(n, n - 1, n - 2));
    }
    return res;
    }
};