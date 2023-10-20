#include <bits/stdc++.h>

using namespace std;

// recursive
// int gcd(int a, int b)
// {
//     // __gcd(a,b);
//     // check base case
//     if (a < 0)
//         a = -a;
//     if (b < 0)
//         b = -b;
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;

//     return gcd(b, a % b);
// }

// iterative
int gcd(int a, int b)
{
    // check base case
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b;
    while (true)
    {
        cin >> a >> b;
        cout << gcd(a, b);
    }
}