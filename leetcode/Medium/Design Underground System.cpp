#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkins;
    // sum, count
    unordered_map<string, unordered_map<string, pair<int, int>>> pairs;
    
    UndergroundSystem()
    {}
    
    void checkIn(int id, string stationName, int t)
    {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t)
    {
        string startStation = checkins[id].first;
        int tstart = checkins[id].second;
        
        pairs[startStation][stationName].first += t - tstart;
        pairs[startStation][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation)
    {
        return pairs[startStation][endStation].first*1.0 / pairs[startStation][endStation].second;
    }
};
