//메모리 누수 확인 코드

//다음 코드는 new 가 있는 코드에 삽입하면, new 연산자를 추적 -> 메모리 누수가 발생할 시 알려줌

#include <crtdbg.h>
#if _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//메모리 확인 - 현재 할당된 메모리를 확인, 
//다음 함수가 수행되는 영역 안에서 할당된 지역변수, 힙 할당 변수를 전부 확인한다.
//적당한 위치에서 실행할 것. 지역 변수 할당된 것도 전부 출력해버린다.
_CrtDumpMemoryLeaks();	//메모리 누수 확인
