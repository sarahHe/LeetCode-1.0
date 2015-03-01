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
bool cmp(Interval i1, Interval i2) {
    if (i1.start == i2.start)
        return i1.end < i2.end;
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval>    res;
        if (intervals.size() < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int i =  0;
        while (i < intervals.size()) {
            int start = intervals[i].start,
                end = intervals[i].end;
            while (i < intervals.size() && end >= intervals[i].start) {
                end = max(end, intervals[i].end); // must inside the while loop
                i++;
            }
            
            Interval newInterval(start, end);
            res.push_back(newInterval);
        }
        return res;
    }
};
