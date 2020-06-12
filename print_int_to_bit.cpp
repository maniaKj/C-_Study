#include <stdio.h>
#include <string>
#include <iostream>
//--------------------------간단한 방법----------------------------//
void printBit(int n) {
    if(n ==0) {
        cout << '0' << endl;
        return;
    }
  string str = "";
  while (n > 0) {
    str += '0' + n % 2;
    n = n >> 1;
  }
  for (auto iter = str.rbegin(); iter != str.rend(); iter++) {
    cout << *iter;
  }
  cout << endl;
}

template<typename T, typename = std::enable_if_t<is_integral_v<T>>>
bool GetBit(T x, unsigned int n) {
	return x & (1 << n);
}

//컴파일러가 enable_if 지원하지 않을 때
bool GetBit(int x, unsigned int n) {
	return x & (1 << n);
}

//--------------------------비트연산자 활용----------------------------//
int getAbit(unsigned short x, int n);
char *ushortToBinary(unsigned short i);

int main(void) {

  unsigned short num = 24761;
  printf("%s\n", ushortToBinary(num)); // 2진수로 출력
  // 출력 결과: 0110000010111001


  // 0번 비트 (맨 우측 비트) 읽기
  printf("%d\n", getAbit(num, 0));
  // 1


  // 1번 비트 (맨 우측에서 2번째 비트) 읽기
  printf("%d\n", getAbit(num, 1));
  // 0



  // num을 1비트씩 읽어, 2진수로 출력하기
  printf("\n[ ");
  for (int i = 15; i >= 0; i--) {
    printf("%d", getAbit(num, i));
  }
  printf(" ]\n");
  // [ 0110000010111001 ]


  return 0;
}




// 지정한 정수에서, 몇번째 비트만 읽어서 반환하는 함수
int getAbit(unsigned short x, int n) { // getbit()
  return (x & (1 << n)) >> n;
}


// 16비트 정수를 2진수 문자열로 변환 함수
char *ushortToBinary(unsigned short i) {
  static char s[16 + 1] = { '0', };
  int count = 16;

  do { s[--count] = '0' + (char) (i & 1);
       i = i >> 1;
  } while (count);

  return s;
}
