#include <bits/stdc++.h>
using namespace std;
bool isPowerof2(int i)
{
    int cnt = 0;
    while (i > 0)
    {
        if ((i & 1) == 1)
        {
            cnt++;
        }
        i = i >> 1;
    }
    if (cnt == 1)
    {
        return true;
    }
    return false;
}
int findP(string msg)
{
    int p = 0;
    int m = msg.length();
    while (pow(2, p) < p + m + 1)
    {
        p++;
    }
    return p;
}
string generateHamming(string msg)
{
    int p = findP(msg);
    reverse(msg.begin(), msg.end());
    int m = msg.length() + p;
    string ham(m, '0');
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        if (isPowerof2(i + 1))
        {
            ham[i] = '0';
        }
        else
        {
            ham[i] = msg[j++];
        }
    }
    for (int i = 0; i < ham.length(); i++)
    {
        if (!isPowerof2(i + 1))
            continue;
        int res = 0;
        int j = i;
        // size to skip/read is i+1
        while (j < ham.length())
        {
            int read = 0;
            while (j < ham.length() && read < i + 1)
            {
                res = res ^ (ham[j] - '0');
                read++;
                j++;
            }
            int skip = 0;
            while (j < ham.length() && skip < i + 1)
            {
                j++;
                skip++;
            }
        }
        ham[i] = res + '0';
    }
    reverse(ham.begin(), ham.end());
    return ham;
}
void detectError(string ham)
{
    reverse(ham.begin(), ham.end());
    int check = 0;
    int pos = 0;
    for (int i = 0; i < ham.length(); i++)
    {
        if (!isPowerof2(i + 1))
            continue;
        int res = 0;
        int j = i;
        // size to skip/read is i+1
        while (j < ham.length())
        {
            int read = 0;
            while (j < ham.length() && read < i + 1)
            {
                res = res ^ (ham[j] - '0');
                read++;
                j++;
            }
            int skip = 0;
            while (j < ham.length() && skip < i + 1)
            {
                j++;
                skip++;
            }
        }
        res <<= pos;
        pos++;
        check = check | res;
    }
    if (check == 0)
    {
        cout << "No error detected\n";
    }
    else
    {
        cout << "Error detected at position " << check << endl;
        ham[check - 1] = ham[check - 1] == '0' ? '1' : '0';
        reverse(ham.begin(), ham.end());
        cout << "Corrected message is: " << ham;
    }
}
int main()
{
    string data;
    cout << "Enter data word: ";
    cin >> data;
    string ham = generateHamming(data);
    cout << "Hamming code generated: " << ham << endl;
    cout << "Enter message received: ";
    string recv;
    cin >> recv;
    detectError(recv);
}
