#include <bits/stdc++.h>
using namespace std;

// so sanh 2 so lon
int compare(string s1, string s2)
{
    while (s1.length() < s2.length())
    {
        s1 = "0" + s1;
    }
    while (s2.length() < s1.length())
    {
        s2 = "0" + s2;
    }
    if (s1 == s2)
    {
        return 0;
    }
    if (s1 > s2)
    {
        return 1;
    }
    return -1;
}

// add
string add(string a, string b)
{
    int l1 = a.length();
    int l2 = b.length();
    int carry = 0;
    string res = "";
    if (l1 > l2)
    {
        for (int i = 0; i < l1 - l2; i++)
        {
            b = "0" + b;
        }
    }
    else if (l2 > l1)
    {
        for (int i = 0; i < l2 - l1; i++)
        {
            a = "0" + a;
        }
    }
    // length after change
    l1 = a.length();
    for (int i = l1 - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }
    if (carry)
    {
        res = to_string(carry) + res;
    }
    return res;
}

// subtract
string subtract(string a, string b)
{
    if (compare(a, b) == 0)
    {
        return "0";
    }
    if (compare(a, b) == 1)
    {
        int borrow = 0;
        string res = "";
        while (a.length() < b.length())
        {
            a = "0" + a;
        }
        while (b.length() < a.length())
        {
            b = "0" + b;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            int sum = a[i] - b[i] - borrow;
            if (sum < 0)
            {
                sum += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            res = to_string(sum) + res;
        }
        // remove leading zeros
        int index = 0;
        while (res[index] == '0')
        {
            index++;
        }
        res = res.substr(index);
        return res;
    }
    else
    {
        return ("-" + subtract(b, a));
    }
}

// multiply large with small number ( 0 -> 9)
string multiply1(string a, int b)
{
    int carry = 0;
    string res = "";
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') * b + carry;
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }
    if (carry)
    {
        res = to_string(carry) + res;
    }
    return res;
}
// multiply large with large
string multiply2(string a, string b)
{
    int level = -1;
    string temp;
    string res = "0";
    for (int i = b.length() - 1; i >= 0; i--)
    {
        level++;
        temp = multiply1(a, (b[i] - '0'));
        for (int i = 0; i < level; i++)
        {
            temp += '0';
        }
        // cout << temp << " ";
        res = add(res, temp);
    }
    return res;
}

// lay thuong khi chia 2 so lon
string divide(string a, string b)
{
    // kb lưu các tích k*b (k = 0 -> 9)
    string kb[11];
    kb[0] = "0";
    int k;
    for (int i = 1; i <= 10; i++)
    {
        kb[i] = add(kb[i - 1], b);
    }
    string res = "";
    string holder = "";
    for (int i = 0; i < a.length(); i++)
    {
        holder += to_string(a[i] - '0');
        k = 1;
        while (compare(holder, kb[k]) != -1)
        {
            k++;
        }
        res += to_string(k - 1);
        holder = subtract(holder, kb[k - 1]);
    }
    // remove leading zeros
    int index = 0;
    while (res[index] == '0')
    {
        index++;
    }
    res = res.substr(index);
    return res;
}

// lay du khi chia 2 so lon
string mod(string a, string b)
{
    // kb lưu các tích k*b (k = 0 -> 9)
    string kb[11];
    kb[0] = "0";
    int k;
    for (int i = 1; i <= 10; i++)
    {
        kb[i] = add(kb[i - 1], b);
    }
    string res = "";
    string holder = "";
    for (int i = 0; i < a.length(); i++)
    {
        holder += to_string(a[i] - '0');
        k = 1;
        while (compare(holder, kb[k]) != -1)
        {
            k++;
        }
        res += to_string(k - 1);
        holder = subtract(holder, kb[k - 1]);
    }
    return holder;
}

int main()
{
    string a;
    string b;
    while (true)
    {
        cin >> a >> b;
        cout << mod(a, b) << endl;
    }

    return 0;
}