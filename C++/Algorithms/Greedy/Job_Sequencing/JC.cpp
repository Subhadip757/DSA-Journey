// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.
// Examples :

// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

#include <bits/stc++.h>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();

    vector<pair<int, int>> jobs;

    for (int i = 0; i < n; i++)
    {
        jobs.push_back({profit[i], deadline[i]});
    }

    // sort the array on basis of profit in descending order
    sort(jobs.rbegin(), jobs.rend());

    vector<bool> vis(n + 1, 0);

    int maxJobs = 0, totalProfit = 0;
    for (auto &job : jobs)
    {
        int p = job.first, d = job.second;
        for (int j = d; j > 0; j--)
        {
            if (vis[j] == 0)
            {
                vis[j] = p;
                maxJobs++;
                totalProfit += p;
                break;
            }
        }
    }
    return {maxJobs, totalProfit};
}