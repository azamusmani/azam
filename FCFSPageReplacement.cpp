#include <bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int frames)
{
    unordered_set<int> s;
    queue<int> q;
    int pFaults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frames)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pFaults++;
                q.push(pages[i]);
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = q.front();
                q.pop();
                s.erase(val);
                s.insert(pages[i]);
                q.push(pages[i]);
                pFaults++;
            }
        }
    }
    return pFaults;
}
int main()
{
    int n, frames;
    cout << "Enter the number of pages:" << endl;
    cin >> n;
    int pages[n];
    cout << "Enter the page reference string:";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> frames;
    cout << "Total page faults: " << pageFaults(pages, n, frames) << endl;

    return 0;
}