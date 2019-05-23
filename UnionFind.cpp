//array 말고 vector 활용 버전은 아래 있음

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
