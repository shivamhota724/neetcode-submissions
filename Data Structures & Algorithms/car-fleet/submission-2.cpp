class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,double>> cars;
        for(int i=0;i<speed.size();i++){
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(),cars.end());
        double prevTime = 0;
        int fleet = 0;
        for(int i=speed.size()-1;i>=0;i--){
            double currTime = cars[i].second;
            if(currTime > prevTime){
            fleet++;
            prevTime = currTime;
            }
        }
        return fleet;
    }
};
