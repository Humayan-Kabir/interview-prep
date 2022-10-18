class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        auto comparator = [&](int x, int y) -> bool {
            return counter[x] > counter[y];
        }      
        priority_queue<int,vector<int>, decltype(comparator)> pq(comparator); 
        for(auto it : hashMap) {
            pq.push(it.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push(pq.top());
            pq.pop();
        }
        return ans;
    }
};