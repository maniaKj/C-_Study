//특정 숫자가 소수인지 확인하는 방법 -> 시간 복잡도 logn
//해커랭크 : https://www.hackerrank.com/challenges/ctci-big-o/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
string primality(int n) {
    if(n == 1) return "Not prime";
    long long val = 2;
    while (val * val <= n) {
        if (n % val == 0) return "Not prime";
        val++;
    }
    
    return "Prime";
}

//1 부터 n 까지의 숫자 중에서 소수 확인
//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/14406
#include <vector>
#include <iostream>
using namespace std;

long long solution(int N) {
    int *Allp = (int*)calloc(N + 1, sizeof(int));
	bool check = false;

	for (int i = 2; i <= N; i++) Allp[i] = i;

	for (int i = 2; i <= N; i++) {
		if (Allp[i] == 0) continue;
		for (int j = i * 2; j <= N; j += i) {
			Allp[j] = 0;
			//cout << j << endl;
		}
	}

	long long answer = 0;
	for (long long j = 0; j <= N; j++)
		answer += Allp[j];
	return answer;
}
