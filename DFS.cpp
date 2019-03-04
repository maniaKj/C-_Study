//출처 : https://programmers.co.kr/learn/courses/30/lessons/43164
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

vector<vector<string>> allanswer;
void dfs2(string start, map<string, vector<pair<string, bool>>> ticket, vector<string> result, int max) {
	result.push_back(start);
	if (result.size() == max) {
		allanswer.push_back(result);
		return;
	}

	vector<pair<string, bool>> tmp = ticket[start];
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].second) {
			map<string, vector<pair<string, bool>>> replica = ticket;
			replica[start][i].second = false;
			dfs2(tmp[i].first, replica, result, max);
		}
	}
}

bool comp(vector<string> v1, vector<string> v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == v2[i]) continue;
		else if (v1[i] < v2[i]) return true;
		else if (v1[i] > v2[i]) return false;
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	map<string, vector<pair<string, bool>>> tick;

	for (int i = 0; i < tickets.size(); i++) {
		tick[tickets[i][0]].push_back(make_pair(tickets[i][1], true));
	}

	vector<string> re;
	dfs2("ICN", tick, re, tickets.size() + 1);

	vector<string> alphamin = allanswer[0];
	for (int i = 0; i < allanswer.size(); i++) {
		if (comp(allanswer[i], alphamin)) alphamin = allanswer[i];
	}
	answer = alphamin;
	return answer;
}

