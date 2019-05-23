//콜백 함수 활용법
template< class T = void >
struct CompUsingTemplate{
  constexpr bool operator()(const T &lhs, const T &rhs) const {
    return lhs > rhs;
  }
};
priority_queue<int, vector<int>, CompUsingTemplate<int>> pq;

struct CompWithoutTemplate {
  constexpr bool operator()(const int &lhs, const int &rhs) const {
    return lhs > rhs;
  }
};
priority_queue<int, vector<int>, CompWithoutTemplate> pq1;
