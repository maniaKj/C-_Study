//해커랭크 : https://www.hackerrank.com/challenges/coin-change/problem

long getWays(long n, vector<long> c) {
  int64_t A[c.size()][n + 1];
  for (int64_t i = 0; i < c.size(); i++) {
    A[i][0] = 1;
  }
  for (int64_t i = 0; i < c.size(); i++) {
    for (int64_t j = 1; j <= n; j++) {
      int64_t x, y;
      x = (i > 0) ? A[i - 1][j] : 0;
      y = (j - c[i] >= 0) ? A[i][j - c[i]] : 0;
      A[i][j] = x + y;
    }
  }

  return A[c.size() - 1][n];
}
