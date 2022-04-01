class MyCalendar {
public:
    MyCalendar() {
           
    }
    map<int,int> events;
    bool book(int start, int end) {
        if (events.empty()) {
            events[start] = end;
            return true;
        }
        auto it = events.upper_bound(start);
        if (it != events.end() && it->start < end) {
            return false;
        }
        if (it != events.begin() && it->second > start) {
            return false;
        }
        events[start] = true;
        return true;
    }
};