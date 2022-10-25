#include <iostream>             // 기본 입출력 라이브러리
using namespace std;            // 이름 공간 std 선언

class Factory {                 // 클래스 Factory 정의
private:                        // 접근 지정자 private
    int cnt;                    // 모니터의 수를 담는 정수형 변수 cnt
    char* name;                 // 모니터의 이름을 담는 문자형 포인터 name
public:
    Factory(int cnt, char* name) {           // 기본 생성자 선언
        cout << "메모리 할당" << endl;          // 메모리가 할당되었음을 나타내는 멘트 출력
        this->cnt = cnt;                     // 인수로 받은 cnt를 이 객체 내 멤버 변수 cnt에 대입
        this->name = name;                   // 인수로 받은 name을 이 객체 내 멤버 변수 name에 대입
    }
    Factory(const Factory& f) {              // 복사 생성자 선언
        this->name = f.name;                 // 참조형 변수로 선언한 객체 f의 멤버 변수 name 값을 이 객체 내 멤버 변수 name에 대입
        this->cnt = f.cnt;                   // 참조형 변수로 선언한 객체 f의 멤버 변수 cnt 값을 이 객체 내 멤버 변수 cnt에 대입
    };
    ~Factory() {                             // 소멸자 선언
        cout << "소멸자 실행" << endl;          // 소멸자가 실행됨을 알리는 멘트 출력
    };
    char* giveName() {                       // 객체의 멤버 변수 name을 반환하는 함수 giveName() 정의
        return this->name;
    }
    int giveCnt() {                          // 객체의 멤버 변수 cnt를 반환하는 함수 giveCnt() 정의
        return this->cnt;
    }
};

int main() {
    Factory item1(1, "SAMSUNG");  // item1 객체 생성
    Factory item2(item1);                    // item2 객체 복사 생성. 복사 생성자
    int size = strlen(item2.giveName());  // 객체 내 멤버 변수 name의 길이를 추출해서 정수형 변수 size에 대입
    char* n = new char[size];                // size 만큼의 문자 배열을 동적으로 생성
    strcpy(n, item2.giveName());    // item2의 name에 저장된 문자열을 동적으로 할당된 문자 배열 n에 복사
    cout << n << " " << item2.giveCnt() << "대 생산 !!" << endl;        // 생성된 객체에 대한 정보 출력

    delete [] n;        // 동적으로 할당 받은 배열 n에 대한 메모리를 반환
    return 0;           // 0을 반환하고 프로그램 종료
}