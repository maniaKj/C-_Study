#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<bool> used(n);	//이미 해당 섬을 방문했는지 확인
    unordered_map<int, vector<pair<int, int>>> island; //섬 번호, (연결된 섬, 비용)

    for(auto i : costs){
        island[i[0]].push_back(make_pair(i[2], i[1]));	//연결 경로 값을 맵에 삽입한다.
        island[i[1]].push_back(make_pair(i[2], i[0]));
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;	//우선순위 큐 선언
    
    for(auto i : island[0]) pq.push(i);	//초기화. 첫번째 섬 삽입
    used[0] = true;	//첫번째 섬 방문.
    
    while(!pq.empty()){
        auto bridge = pq.top(); pq.pop();	//우선순위 큐의 top을 가져온다.
        if(used[bridge.second]!=true){		//방문하지 않았다면
            used[bridge.second]=true;
            answer += bridge.first;		//연결 비용 추가
            for(auto i : island[bridge.second]) //해당 섬의 이웃한 섬에 대하여
		 if(!used[i.second]) pq.push(i); //방문하지 않았다면 우선순위 큐에 삽입
            
        }
    }
    return answer;	//최종 비용 반환
}
