#include <iostream>
#include <string>
#define MAX 100

void erase(char* str, const char ch) {
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


int test(const char * str, const char ch) {
	char * c = new char[MAX];
	
	sprintf_s(c, MAX, str);

	std::cout << c << " , len : " << strlen(c) << std::endl << " ==> ";
	erase(c, ch);
	std::cout << c << ", len : " << strlen(c) << std::endl;

	delete c;
	return 0;
}

int main(void) {
	test("hellohellohello", 'e');
	test("The quick brown dog jumps over the lazy fox", 'o');
	test("Copies the null-terminated byte string pointed to by src,", 'i');


	system("pause");
	return 0;
}
