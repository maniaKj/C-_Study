//출처 : https://www.hackerrank.com/challenges/common-child/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

int main()
{
string s1, s2;
cin >> s1 >> s2;
vector<vector<int>> vec;
for(int i = 0;i<= 5000;i++){
vector<int> tmp(5001, 0);
vec.push_back(tmp);
}
for (int i = 1; i <= s1.length();i++) {
for (int j = 1; j <= s2.length(); j++) {
if (s1[i-1] == s2[j-1]) {
vec[i][j] = vec[i - 1][j - 1] + 1;
}
else {
vec[i][j] = max(vec[i][j - 1], vec[i - 1][j]);
}
}
}
/*for (int i = 0; i <= s1.length(); i++) {
for (int j = 0; j <= s2.length(); j++) {
cout << vec[i][j] << " ";
}
cout << endl;
}*/
cout<<vec[s1.length()][s2.length()];
return 0;
}
