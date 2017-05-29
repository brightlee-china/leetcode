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
private:
    struct cmp {
        bool operator() (const Interval &a, const Interval &b) const {
            return a.start < b.start;
        }
    };
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        
        sort(intervals.begin(), intervals.end(), cmp());
        for (int i = 0; i < intervals.size(); i ++) {
            if (result.empty() || result.back().end < intervals[i].start) {
                result.push_back(intervals[i]);
            }
            else if (result.back().end < intervals[i].end) {
                result.back().end = intervals[i].end;
            }
        }
        
        return result;
    }
};