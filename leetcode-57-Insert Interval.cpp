/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int n = intervals.size();
        if (n == 0) {
            result.push_back(newInterval);
            return result;
        }
        
        vector<Interval> temp;
        for (int i = 0; i < n; i ++) {
            if (temp.empty() || temp.back().end < intervals[i].start)
                temp.push_back(intervals[i]);
            else 
                temp.back().end = max(temp.back().end, intervals[i].end);
        }
        
        int j = 0;
        while (j < n && temp[j].end < newInterval.start) 
            result.push_back(temp[j ++]);
        
        if (j == n) {
            result.push_back(newInterval);
            return result;
        }
        
        if (temp[j].start > newInterval.end)
            result.push_back(newInterval);
        else {
            temp[j].start = min(temp[j].start, newInterval.start);
            temp[j].end = max(temp[j].end, newInterval.end);
            result.push_back(temp[j ++]);
        }
        
        for (; j < n; j ++) {
            if (result.back().end < temp[j].start)
                result.push_back(temp[j]);
            else 
                result.back().end = max(result.back().end, temp[j].end);
        }
        
        return result;
    }
};