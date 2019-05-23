//해커랭크 : https://www.hackerrank.com/challenges/and-xor-or/problem
//배열 크기 N, 1<= L < R <=N 에 대하여, 배열의 [L, R] 범위에 있는 최소 값 찾기 => 스택 사용하여 시간복잡도 O(n)

int func(int a, int b) { return (((a & b) ^ (a | b)) & (a ^ b)); }

int andXorOr(vector<int> a) {
  stack<int> st;
  int answer = 0;

  for (auto val : a) {
    while (!st.empty()) {
      int tmp = func(st.top(), val);
      if (tmp > answer)
        answer = tmp;
      if (st.top() > val)
        st.pop();
      else
        break;
    }
    st.push(val);
  }

  return answer;
}
//의사코드
/*For each int i in the array A
    while stack is nonempty
        yield (i, top of stack)
        if i is less than the top of the stack, pop the stack
        otherwise break the while loop
    push i onto stack
*/


//해커랭크 : https://www.hackerrank.com/challenges/poisonous-plants/problem
//배열 값을 확인하면서 특정 원소의 왼쪽 원소에 대하여 값이 크면 지워버리는 문제
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
  int answer = 0;

  stack<int> st;
  stack<pair<int ,int>> pst;
  int cnt = 0;
  int prev;

  st.push(p[0]);
  cnt = 0;
  prev = p[0];

  for (int i = 1; i < p.size(); i++) {
    if (p[i] > prev) {
      pst.push(make_pair(prev, cnt));
      prev = p[i];
      if (answer < cnt)
        answer = cnt;
      cnt = 1;
      continue;
    }

    if (p[i] > st.top()) {
        pair<int, int> pppp = make_pair(-1, -1);
        while(!pst.empty() && p[i] <= pst.top().first){ //while 문으로 값 찾기
          pppp = make_pair(pst.top().first, max(pppp.second, pst.top().second));
          pst.pop();
        }
        if (p[i] <= pppp.first) {

          prev = p[i];
          cnt = max(pppp.second, cnt) + 1;
          continue;
      }
      prev = p[i];
      cnt++;
      continue;
    }

    st.push(p[i]);
    prev = p[i];
    
    if (answer < cnt)
      answer = cnt;
    cnt = 0;
  }

  if (answer < cnt)
    answer = cnt;

  return answer;
}

