#include <stdio.h> 
#include <limits.h> 
   
// Number of vertices in the graph 
#define V 9 
   
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   
// A utility function to print the constructed distance array 
int printSolution(int dist[], int n) 
{ 
   printf("Vertex   Distance from Source\n"); 
   for (int i = 0; i < V; i++) 
      printf("%d tt %d\n", i, dist[i]); 
} 
   
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
     int dist[V];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
   
     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for (int v = 0; v < V; v++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
   
     // print the constructed distance array 
     printSolution(dist, V); 
} 
   
// driver program to test above function 
int main() 
{ 
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    dijkstra(graph, 0); 
   
    return 0; 
} 
/=======================================================/
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
