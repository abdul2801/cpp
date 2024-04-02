#include <bits/stdc++.h>
using namespace std;
int main()
{
    int frames, lost, ret = 0, count = 0;
    cout << "Enter no of frames: ";
    cin >> frames;
    cout << "Enter frame lost: ";
    cin >> lost;
    for (int i = 0; i < frames; i++)
    {
        if ((count + 1) % lost == 0)
        {
            ret++;
            count++;
            cout << "Frame retransmitted: " << i + 1 << endl;
        }
        count++;
    }
    cout << "Number of retransmitted frames: " << ret << endl;
    cout << "Number of frames transmitted: " << count;
}
