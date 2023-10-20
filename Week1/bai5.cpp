#include <bits/stdc++.h>
using namespace std;

// tính m1^m2 theo module MOD
long long solve(long long m1, long long m2)
{
    long long MOD = 1000000007;
    if (m2 == 0)
    {
        return 1;
    }
    if (m2 == 1)
    {
        return m1 % MOD;
    }

    if (m2 % 2 == 0)
    {
        long long temp = solve(m1, m2 / 2);
        return (temp * temp) % MOD;
    }
    else
    {
        long long temp = solve(m1, (m2 - 1) / 2);
        return (m1 * ((temp * temp) % MOD)) % MOD;
    }

    return m1;
}

int main()
{
    long long M = 1000000007; // lưu ý M là số nguyên tố
    long long N = 1000000006; // lấy mũ theo module M - 1 (định lý fermat)

    // lấy input số nguyên lớn bằng string
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();

    // biểu diễn số nguyên lớn bằng mảng
    int n1[len1];
    int n2[len2];
    for (int i = 0; i < len1; i++)
    {
        n1[i] = s1[i] - '0';
    }
    for (int i = 0; i < len2; i++)
    {
        n2[i] = s2[i] - '0';
    }

    // lấy module (rút gọn số)
    long long m1 = n1[0] % M;
    for (int i = 1; i < len1; i++)
    {
        m1 = (m1 * 10 + n1[i]) % M;
    }
    long long m2 = n2[0] % N;
    for (int i = 1; i < len2; i++)
    {
        m2 = (m2 * 10 + n2[i]) % N;
    }
    cout << solve(m1, m2);
    return 0;
}