#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> p_time(n);
    vector<int> tasks(n * 4);

    for (int i = 0; i < n; i++)
    {
        cin >> p_time[i];
    }

    for (int i = 0; i < n * 4; i++)
    {
        cin >> tasks[i];
    }

    sort(p_time.begin(), p_time.end());
    sort(tasks.begin(), tasks.end(), greater<int>());

    int max_time = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        int curr_p_time = p_time[i];
        int max_task = INT_MIN;

        for (int j = 0; j < 4; j++)
        {
            max_task = max(max_task, tasks[i * 4 + j]);
        }

        max_time = max(max_time, curr_p_time + max_task);
    }

    cout <<  max_time << "\n";
}