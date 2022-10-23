class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_digits[10] = {0};
        int guess_digits[10] = {0};
        int N = secret.size();
        int A = 0, C = 0; // C = A + B
        for (int i=0; i<N; ++i) {
            ++secret_digits[secret[i]-'0'];
            ++guess_digits[guess[i]-'0'];
            A += secret[i]==guess[i]? 1 : 0;
        }
        for (int i=0; i<10; ++i) {
            if (secret_digits[i] > 0 && guess_digits[i] > 0) {
                C += min(secret_digits[i], guess_digits[i]);
            }
        }
        int B = C - A;
        string out;
        stringstream ss;
        ss << A << "A" << B << "B";
        ss >> out;
        return out;
    }
};
