#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 3000;            // chọn số đủ lớn để vượt qua test khi n = 1000 (MAX).
    int countPrimeFactor[n]; // array to store the number of prime factors
    memset(countPrimeFactor, 0, sizeof(countPrimeFactor));

    // caculate number of prime factors for each number from 2 to n
    for (int j = 2; j <= n; j++)
    {
        if (countPrimeFactor[j] == 0)
        { // check if j is prime
            for (int i = j; i <= n; i += j)
            {
                countPrimeFactor[i]++;
            }
        }
    }
    int res[1001];
    memset(res, 0, sizeof(res));
    int j = 1;
    for (int i = 2; i <= n && j < 1001; i++)
    {
        if (countPrimeFactor[i] >= 3)
        {
            res[j++] = i;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}