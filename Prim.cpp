#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<bool> used(n);
    unordered_map<int, vector<pair<int, int>>> island; //섬 번호, (연결된 섬, 비용)

    for(auto i : costs){
        island[i[0]].push_back(make_pair(i[2], i[1]));
        island[i[1]].push_back(make_pair(i[2], i[0]));
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(auto i : island[0]) pq.push(i);
    used[0] = true;
    
    while(!pq.empty()){
        auto bridge = pq.top(); pq.pop();
        if(used[bridge.second]!=true){
            used[bridge.second]=true;
            answer += bridge.first;
            for(auto i : island[bridge.second]) pq.push(i);
            
        }
    }
    return answer;
}
