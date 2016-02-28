//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
//determine if a person could attend all meetings.

bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].end < intervals[i-1].start)
            return false;
    }
    return true;
}

class compare {
  public:
    bool operator()(const Interval &i1, const Interval &i2){
      return i1.start < i2.start;
    }
};
