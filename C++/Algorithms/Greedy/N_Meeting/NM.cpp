// You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time.

// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Examples :

// Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

#include <bits/stc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        // sort it in basis of end time in ascending order
        vector<pair<int, int>> timer;
        for (int i = 0; i < end.size(); i++)
        {
            timer.push_back({start[i], end[i]});
        }

        sort(timer.begin(), timer.end(), comp);

        int total = 0;
        int ending = -1;

        for (int i = 0; i < end.size(); i++)
        {
            if (timer[i].first > ending)
            {
                total++;
                ending = timer[i].second;
            }
        }
        return total;
    }
};