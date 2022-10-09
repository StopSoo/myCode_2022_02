#include <iostream>                 // 기본 입출력 라이브러리
using namespace std;                // 이름 공간으로 std 사용

class Lecture {                     // Lecture라는 이름의 클래스
public:                             // 접근 지정자
    string name, check;             // 이름과 출석 여부를 나타내는 문자열 변수 name과 check 선언
    int number;                     // 학번을 나타내는 정수형 변수 number 선언
    Lecture() { name = ""; check = ""; number = 0; }        // 생성자 선언 및 멤버 변수 초기화
    void printCheck(Lecture *pointer) {         // 출석을 체크하는 멤버 함수 printCheck()
        cout << "이름 : " << name << endl;       // 멘트와 객체의 이름 출력
        cout << "학번 : " << number << endl;     // 멘트와 객체의 학번 출력
        cout << "출결(출석, 지각, 결석) : ";        // 멘트를 출력하고 사용자로부터 출결 상태를 입력 받음
        cin >> check;               // 사용자로부터 입력 받은 문자열을 문자열 변수 check에 대입
    }
    ~Lecture() {                    // 소멸자 선언
        cout << name << " 출석 체크가 완료되었습니다." << endl;     // 출석 체크가 완료되었음을 나타내는 멘트 출력
    }
};

void printLine() {                  // 구분선을 출력하는 함수 printLine()
    cout << "------------------------------" << endl;
}

// Lecture()형 포인터를 매개변수로 받아 그 포인터가 가리키는 객체의 멤버 변수를 포함하여 멘트를 출력하는 함수 printStart()
void printStart(Lecture *pointer) {
    cout << pointer->name << " 출석 체크를 시작합니다." << endl;
}

int main() {
    Lecture *p, *q, *r;             // Lecture형 포인터 p, q, r 선언
    p = new Lecture;                // Lecture형 객체를 동적으로 할당한 후 포인터 p에 그 주소를 대입
    q = new Lecture;                // Lecture형 객체를 동적으로 할당한 후 포인터 q에 그 주소를 대입
    r = new Lecture;                // Lecture형 객체를 동적으로 할당한 후 포인터 r에 그 주소를 대입

    p->name = "김철수"; p->number = 2022654321;    // 포인터 p가 가리키는 멤버 변수 name과 number에 기본 초기화 값 입력
    q->name = "이유리"; q->number = 2022987956;    // 포인터 q가 가리키는 멤버 변수 name과 number에 기본 초기화 값 입력
    r->name = "이훈이"; r->number = 2022456789;    // 포인터 r이 가리키는 멤버 변수 name과 number에 기본 초기화 값 입력

    printStart(p);           // p를 인수로 하여 함수 printStart() 호출
    printStart(q);           // q를 인수로 하여 함수 printStart() 호출
    printStart(r);           // r을 인수로 하여 함수 printStart() 호출

    printLine();                    // printLine() 함수를 호출하여 구분선을 출력
    p->printCheck(p);        // 포인터 p가 가리키는 객체의 멤버 함수인 printCheck()를 p를 인수로 하여 호출
    cout << endl;                   // 한 줄 개행
    q->printCheck(q);        // 포인터 q가 가리키는 객체의 멤버 함수인 printCheck()를 q를 인수로 하여 호출
    cout << endl;                   // 한 줄 개행
    r->printCheck(r);        // 포인터 r이 가리키는 객체의 멤버 함수인 printCheck()를 r을 인수로 하여 호출
    printLine();                    // printLine() 함수를 호출하여 구분선을 출력

    delete p;                   // p의 메모리를 반환하면서 소멸자 실행
    delete q;                   // q의 메모리를 반환하면서 소멸자 실행
    delete r;                   // r의 메모리를 반환하면서 소멸자 실행

    return 0;                   // 0을 반환하고 프로그램 종료
}
