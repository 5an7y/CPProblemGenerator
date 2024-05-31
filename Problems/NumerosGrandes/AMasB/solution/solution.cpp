#include <bits/stdc++.h>
using namespace std;

struct BigInteger {
    string str;
 
    BigInteger(string s) { str = s; }
 
    BigInteger operator+(const BigInteger& b)
    {
        string a = str;
        string c = b.str;
        int alen = a.length(), clen = c.length();
        int n = max(alen, clen);
        if (alen > clen)
            c.insert(0, alen - clen, '0');
        else if (alen < clen)
            a.insert(0, clen - alen, '0');
        string res(n + 1, '0');
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int digit = (a[i] - '0') + (c[i] - '0') + carry;
            carry = digit / 10;
            res[i + 1] = digit % 10 + '0';
        }
        if (carry == 1) {
            res[0] = '1';
            return BigInteger(res);
        }
        else {
            return BigInteger(res.substr(1));
        }
    }
    
    friend ostream& operator<<(ostream& out,
                               const BigInteger& b)
    {
        out << b.str;
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b; cin >> a >> b;
    BigInteger a0(a);
    BigInteger b0(b);
    BigInteger sum = a0 + b0;
    cout << sum << '\n';
    return 0;
}