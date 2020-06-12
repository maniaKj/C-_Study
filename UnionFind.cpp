/*

1. 클래스 정적 함수 활용
예시 : https://github.com/wlsvy/TIL/blob/master/Coding_Problem_Solving/Friend%20Circle%20Queries.cpp

2. 벡터 활용

3. 배열 활용

*/

#include <vector>
class UnionFind {
public:
	static void Init(std::size_t n) {
		Get().m_Elements = std::vector<int>(n, -1);
		atexit([]() {
			delete &Get();
		});
	}
	static void Union(int x, int y) {
		auto& elements = Get().m_Elements;
		x = Find(x);
		y = Find(y);

		if (x != y) {
			if (elements[x] < elements[y]) {
				elements[x] += elements[y];
				elements[y] = x;
			}
			else {
				elements[y] += elements[x];
				elements[x] = y;
			}
		}
	}
	static int Find(int target) {
		auto& elements = Get().m_Elements;
		int root = target;

		while (elements[root] >= 0) {
			root = elements[root];
		}
			
		while (elements[target] >= 0) {
			int tmp = elements[target];
			elements[target] = root;
			target = tmp;
		}

		return root;
	}

private:
	static UnionFind& Get() {
		static UnionFind* s_Instance = new UnionFind();
		return *s_Instance;
	}
	std::vector<int> m_Elements;
};


/*
=========================================================================================
*/

#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1000010;
int n;

int uf[N];

void init( void ) {
    for(int i = 0; i < N; i++)
        uf[i] = -1;
}

/* Find root of set containing x */
int root( int x ) {
    int r = x;

    /* Find root */
    while(uf[r] >= 0)
        r = uf[r];

    /* Compress path to root */
    while(uf[x] >= 0) {
        int tmp = uf[x];
        uf[x] = r;
        x = tmp;
    }

    return r;
}

/* Union of sets containing x and y */
void join( int x, int y ) {
    x = root(x);
    y = root(y);

    if(x != y) {
        if(uf[x] < uf[y]) {
            uf[x] += uf[y];
            uf[y] = x;
        }
        else {
            uf[y] += uf[x];
            uf[x] = y;
        }
    }
}

int main( void ) {

    init();

    assert(root(1) != root(2));
    join(1, 2);
    assert(root(1) == root(2));

    join(3, 4);
    join(2, 3);
    assert(root(1) == root(4));

    return 0;
}

----------------------------------------------------------
//활용 예시 - 해커랭크 문제 : https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
//vector 
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

/* Find root of set containing x */
int root(int x, vector<int> & uf) {
	int r = x;

	/* Find root */
	while (uf[r] >= 0)
		r = uf[r];

	/* Compress path to root */
	while (uf[x] >= 0) {
		int tmp = uf[x];
		uf[x] = r;
		x = tmp;
	}

	return r;
}

/* Union of sets containing x and y */
void join(int x, int y, vector<int> & uf) {
	x = root(x, uf);
	y = root(y, uf);

	if (x != y) {
		if (uf[x] < uf[y]) {
			uf[x] += uf[y];
			uf[y] = x;
		}
		else {
			uf[y] += uf[x];
			uf[x] = y;
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> uf(n, -1);
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (computers[i][j] == 0) continue;
			join(i, j, uf);
		}
	}

    set<int> s;
	for (int i = 0; i < n; i++) s.insert(root(i, uf));

	return s.size();
}
