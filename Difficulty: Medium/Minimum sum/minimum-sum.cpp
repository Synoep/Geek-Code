class Solution {
public:
    string addStrings(string a, string b) {
        string res = "";
        int carry = 0, i = a.size()-1, j = b.size()-1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(res.begin(), res.end());
        // remove leading zeros
        int pos = res.find_first_not_of('0');
        return (pos == string::npos) ? "0" : res.substr(pos);
    }

    string minSum(vector<int> &nums) {
        int n = nums.size();

        // Defensive guard for invalid input
        if (n == 0) return "0";
        if (n == 1) return to_string(nums[0]);

        // Count sort for O(n)
        int count[10] = {0};
        for (int d : nums) count[d]++;

        // Distribute digits alternately to minimize sum
        string a = "", b = "";
        bool turn = true;
        for (int d = 0; d <= 9; ++d) {
            while (count[d]--) {
                if (turn) a += (d + '0');
                else b += (d + '0');
                turn = !turn;
            }
        }

        return addStrings(a, b);
    }
};
