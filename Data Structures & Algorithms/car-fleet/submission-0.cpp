class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car; // position, speed
        for(int i=0; i<position.size(); i++){
            car.push_back({position[i], speed[i]});
        }
        sort(car.rbegin(), car.rend());

        int fleet = 0;
        float maxTime = 0.00;

        for(int i=0; i<car.size(); i++){
            float time = (float)(target - car[i].first) / car[i].second;

            if(time > maxTime){
                fleet++;
                maxTime = time;
            } else {
                continue;
            }
        }

        return fleet;
    }
};
