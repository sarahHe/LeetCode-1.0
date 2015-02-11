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
    void merge(vector<Interval> &intervals, Interval newInterval, int i) {
        int cur = i;
        while (intervals[cur].start < newInterval.end && cur < intervals.size())
            cur++;
        if (cur == intervals.size())
            intervals[i-1].end = newInterval.end;
        else
            intervals[i-1].end = max(intervals[cur-1].end, newInterval.end);
        while (cur > i) {
            intervals.erase(intervals.begin()+cur-1);
            cur--;
        }
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
            
        int i = 0;
        while (intervals[i].start <= newInterval.start && i < intervals.size())
            i++;
        if (i == intervals.size()) {
            if (newInterval.start == intervals.back().end)
                intervals.back().end = newInterval.end;
            else
                intervals.push_back(newInterval);
        }
        else if (i == 0) {
            if (newInterval.end < intervals[0].start)
                intervals.push_back(newInterval);
            else
                intervals[0].start = newInterval.start;
        }
        else {
            //left = i-1, right = i;
            if (newInterval.start <= intervals[i-1].end) {
                if (newInterval.end < intervals[i].start)
                    intervals[i-1].end = max(intervals[i-1].end, newInterval.end);
                else 
                    merge(intervals, newInterval, i);
                
            }
            else if (newInterval.start > intervals[i-1].end && newInterval.start < intervals[i].start) {
                if (newInterval.end < intervals[i].start)
                    intervals.push_back(newInterval);
                else 
                    merge(intervals, newInterval, i);
            }
            else //newInterval.start < intervals[i].start
                merge(intervals, newInterval, i);
        }
        return intervals;
    }
};

// another solution
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<Interval> ans;
    int st_pos = 1, end_pos = 0, cur = 0;
    while (cur < intervals.size() && intervals[cur].end < newInterval.start) {
        ans.push_back(intervals[cur++]);
    }
    if (intervals.size() == cur) {
        ans.push_back(newInterval);
        return ans;
    }
    if (newInterval.end < intervals[cur].start) {
        st_pos = newInterval.start;
        end_pos = newInterval.end;
    } else {
        st_pos = min(newInterval.start, intervals[cur].start);
        end_pos = max(newInterval.end, intervals[cur++].end);
    }
    while (cur < intervals.size() && intervals[cur].start <= end_pos) {
        end_pos = max(end_pos, intervals[cur++].end);
    }
    ans.push_back(Interval(st_pos, end_pos));
    while (cur < intervals.size()) {
        ans.push_back(intervals[cur++]);
    }
    return ans;
}
