#include <iostream>
#include <vector>
#include <string>

class Widget {
public:
	Widget& operator= (const Widget& rhs) {	//반환 타입은 현재의 클래스에 대한 참조자
		//....
		return *this;	//좌변 객체(의 참조자)를 반환
	}
	Widget& operator+=(const Widget& rhs) {	//다른 연산자에도 동일한 규약 적용
		//....
		return *this;
	}
	Widget& operator=(int rhs) {	//매개변수 타입이 다르더라도 동일한 규약 적용
		//....
		return *this;
	}
};
