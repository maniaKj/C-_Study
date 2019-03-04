#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    //다익스트라 알고리즘 사용. 노드 간의 경로 길이가 모두 1인 점을 고려했음
    //패러미터를 아래와 같이 주면 ok
    // n = 6(node 갯수), edge = [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]] (노드끼리 연결된 여부)
    int *dist = new int[n+1], *varr = new int[n+1]; dist[0] = -1; //varr 의 원소 0: 방문x 1: 방문함
    vector<pair<int,vector<int>>> node;
    vector<int> visited, prevVisit; //방문한 노드, 바로 방금 방문한 노드 모음
    int start = 1; //시작할 노드 번호 이 아래 부터는 초기화
    
    //**************초기화***************
    prevVisit.push_back(start);
    for(int i = 1;i <= n;i++){
        vector<int> tmp;
        for(int j = 0;j<edge.size();j++){
            if(edge[j][0] == i) tmp.push_back(edge[j][1]);
            else if(edge[j][1] == i)tmp.push_back(edge[j][0]);
        }
        node.push_back(make_pair(i,tmp));
    }
    for(int i = 1;i <= n;i++)
        {if(i!= start){dist[i] = 99; varr[i] = 0;}
        else {dist[i] = 0; visited.push_back(i); varr[i] = 1;}}
    /*for(auto i = node.begin();i!=node.end();i++) {
        cout << (*i).first << " : ";
        for(int j = 0;j<(*i).second.size();j++) cout << (*i).second[j] << ", "; cout<<endl;
    }*/
    
    
    //**************다익스트라***************
    int cnt = 1; // while 횟수 카운트
    while(visited.size() != n){
        vector<int> tmpv;
        for(auto i = prevVisit.begin();i != prevVisit.end();i++){
            for(auto j = node[*i-1].second.begin();j!= node[*i-1].second.end();j++){
                if(dist[*i] + 1 <dist[*j]) { //모든 노드 사이의 거리가 1이라서 dist + 1 했음
                    dist[*j] = dist[*i] + 1;
                    if(varr[*j] == 0) {varr[*j] = 1; tmpv.push_back(*j);}
                }
            }
        }
        prevVisit = tmpv;
        for(int i = 0;i<tmpv.size();i++) visited.push_back(tmpv[i]);
        
        //**************중간과정 검증파트***************
        //cout << "cnt : " << cnt++ << endl;
        //cout<<"   V : "; for(auto i = visited.begin();i!=visited.end();i++) cout << *i << ", "; cout<<endl;
        //cout<<"preV : "; for(auto i = prevVisit.begin();i!=prevVisit.end();i++) cout << *i << ", "; cout<<endl;
    }
    
    //**************최종 결과 확인***************
    //cout<<"dist : "; for(int i = 1;i<=n;i++) cout<<dist[i]<<", "; cout<<endl;
    
    //**************끝***************
    int max = 0, answer = 0;
    for(int i = 1;i<=n;i++) if(max < dist[i]) max = dist[i];
    for(int i = 1;i<=n;i++) if(dist[i] == max) answer++;
    return answer;
}
