#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k)
{
    bool sieve[n + 1];
    memset(sieve, true, sizeof(sieve));

    // tạo sàng số nguyên tố
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    // tạo mảng snt
    int count = 0;
    for (int i = 2; i < n + 1; i++)
    {
        if (sieve[i])
        {
            count++;
        }
    }
    int snt[count];
    int c = 0;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i])
        {
            snt[c++] = i;
        }
    }
    // for (int i = 0; i < count; i++)
    // {
    //     cout << snt[i] << " ";
    // }
    // cout << endl;

    // kiem tra tung so tu 7 đến n
    int index = 0;
    int res = 0;
    for (int i = 7; i <= n; i++)
    {
        if (sieve[i])
        {
            while (snt[index] + snt[index + 1] + 1 < i)
            {
                index++;
            }
            if (snt[index] + snt[index + 1] + 1 == i)
            {
                cout << snt[index] << " + " << snt[index + 1] << " + 1 = " << i << endl;
                res++;
            }
        }
    }
    cout << (res >= k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    solve(n, k);
    // solve(23, 2);
}