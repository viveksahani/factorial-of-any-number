#include <iostream>
#include <cstring>
using namespace std;
string reverse_string(string s)
{
    int l = s.length();
    char ch;
    for (int i = 0; i < l; i++, l--)
    {
        ch = s[i];
        s[i] = s[l - 1];
        s[l - 1] = ch;
    }
    return s;
}
int main()
{
    int n;
    cout << "enter number to find it's factorial = ";
    cin >> n;
    if (n < 2)
    {
        if (n == 1)
        {
            cout << "1";
            return 0;
        }
        cout << "please enter number greater than 0";
        return 0;
    }
    string str;
    str = to_string(n * (n - 1));
    str = reverse_string(str);
    for (int i = n - 2; i > 0; i--)
    {
        int length = str.length();
        int carry = 0;
        string copy_str;
        for (int j = 0; j < length; j++)
        {
            int num;
            char ch = str[j];
            num = ch - 48;
            num = num * i + carry;
            carry = num / 10;
            string local;
            local = to_string(num % 10);
            copy_str = copy_str + local;
            string carry_string = to_string(carry);
            if (j == (length - 1) && carry != 0)
            {
                carry_string = reverse_string(carry_string);
                copy_str = copy_str + carry_string;
            }
        }
        str = copy_str;
    }
    str = reverse_string(str);
    cout << str;
    return 0;
}