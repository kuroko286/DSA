#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;

    cin >> n;
    int temp = n;
    int i = 2;
    while (i <= temp)
    {

        while (n % i == 0)
        {
            if (n == i)
            {
                cout << i;
            }
            else
            {
                cout << i << " "
                     << "x"
                     << " ";
            }

            n /= i;
        }
        i++;
    }

    return 0;
}