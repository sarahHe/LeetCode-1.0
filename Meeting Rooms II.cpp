//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
//find the minimum number of conference rooms required.

//The idea is to group those non-overlapping meetings in the same room and then count how many rooms we need. 

int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    vector<Intervals> rooms;
    for (int i = 0; i < intervals.size(); i++) {
        int idx = findRoom(rooms, intervals[i]);
        if (idx == -1 || rooms.empty())
            rooms.push_back(intervals[i]);
        else
            rooms[idx] = intervals[i];
    }
}

int findRoomd(vector<Invertal> &room, Invertal interval) {
    for (int i = 0; i < rooms.size(); i++) {
        if (interval.start >= rooms[i].end)
            return i;
    }
    return -1;
}
