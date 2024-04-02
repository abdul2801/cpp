#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, pos, ws;
    cout << "Enter no of frames: ";
    cin >> n;
    cout << "Enter frame lost: ";
    cin >> pos;
    cout << "Enter window size: ";
    cin >> ws;
    int count = n;
    int frameSent = 0;
    vector<int> frames;
    for (int i = 1; i <= n; i++)
    {
        if ((frameSent + 1) % pos == 0)
        {
            count += 1;
            frameSent = 0;
            frames.push_back(i);
            cout << "Frame lost: " << i << endl;
            for (int j = i + 1; j <= min(n, i + ws - 1); j++)
            {
                frames.push_back(j);
            }
            frames.push_back(i);
            i -= 1;
        }
        else
        {
            bool flag = true;
            for (auto &it : frames)
                if (it == i)
                    flag = false;
            if (flag)
                frames.push_back(i);
            frameSent += 1;
        }
    }
    cout << endl;
    cout << "No of frames transmitted: " << count << endl;
    cout << "No of frames retransmitted: " << count - n << endl;
    cout << "Sequence of Frames: ";
    for (auto &it : frames)
    {
        cout << it << " ";
    }
    return 0;
}