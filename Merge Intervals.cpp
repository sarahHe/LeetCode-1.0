// Given a collection of intervals, merge all overlapping intervals.
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

//interval: think about start and end. 
//use while to merge, build a new Interval pushed to res
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp (const Interval &a, const Interval &b) {
     if (a.start == b.start)
        return a.end < b.end;
        
     return a.start < b.start;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> res;
        int i = 0;
        for(; i<intervals.size()-1; i++) {
            int start = intervals[i].start,
            end = intervals[i].end,
            cur = i;
            while (i<intervals.size()-1 && end >= intervals[i+1].start) {
                end = max(end, intervals[i+1].end);
                i++;
            }
            Interval newInterval(start, end);
            res.push_back(newInterval);
        }
        if (i == intervals.size()-1)
            res.push_back(intervals[i]);
        return res;
    }
};
