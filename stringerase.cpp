#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void erase(char* str, char ch) {
	int i = 0, j = 0;

	while (str[i] != '\0') {
		if (str[i] == ch) {
			if (i > j) j = i + 1;
			while (true) {
				if (str[j] == '\0') {
					while (str[i] != '\0') str[i++] = '\0';
					return;
				}
				else if (str[j] != ch) {
					str[i] = str[j];
					str[j] = ch;
					break;
				}
				j++;
			}
		}
		i++;
	}
}


int main(void) {
	string s = "asdfasdf";

	s = "hellohellohello";
	cout << s << " , len : " << s.length() << ", after : ";
	erase(&s[0], 'e');
	cout << s << ", len : " << s.length() << endl;

	s = "aaaaaaaaaaaaaa";
	cout << s << " , len : " << s.length() << ", after : ";
	erase(&s[0], 'b');
	cout << s << ", len : " << s.length() << endl;


	system("pause");

	return 0;
}
