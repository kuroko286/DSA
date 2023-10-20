#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b)
{

    bool sieve[b + 1];
    memset(sieve, true, sizeof(sieve));

    // tạo sàng số nguyên tố
    for (int i = 2; i <= b; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= b; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    // in ra các số nguyên tố từ a đến b
    for (int i = a; i < b + 1; i++)
    {
        if (sieve[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    int a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}