#include <iostream>             // 기본 입출력 라이브러리
#include <string>               // 문자열 함수를 사용하기 위한 라이브러리
using namespace std;            // 이름 공간 std 사용

class books {                   // 클래스 books 선언
public:                         // 접근 지정자
    int price;                  // 책 가격을 담을 정수형 변수 price
    string bookName;            // 책의 이름을 담을 문자열 변수 string
    void printBooks(books *p, int count) {                  // 책의 정보를 출력하는 함수 printBooks()
        for(int j=0; j<count; j++) {                        // 사용자가 입력한 수 만큼 반복문을 수행
            cout << "책 " << (j+1) << endl;                 // 몇 번째 책인지 알려줌
            cout << "제목 : " << p[j].bookName << endl;      // 기본 형식과 함께 책의 제목 출력
            cout << "가격 : " << p[j].price << endl;         // 기본 형식과 함께 책의 가격 출력
        }
    }
};

int main() {
    int cnt;            // 책의 수를 담을 정수형 변수 cnt
    cout << "입력할 책의 수를 입력하시오. : ";      // 사용자에게 입력을 받기 위한 기본 멘트 출력
    cin >> cnt;         // 사용자로부터 입력을 받음

    books *ptr = new books[cnt];             // books형 포인터에 cnt 값의 크기를 갖는 books형 배열을 동적으로 할당시킴

    for(int i=0; i < cnt; i++) {             // cnt 값 만큼 반복문을 수행
        cout << "책 " << (i+1) << "번 제목 및 가격 입력" << endl;        // 기본 멘트 출력
        cout << "제목 : ";    // 기본 멘트 출력
        cin.ignore();        // 버퍼에 입력되어 있던 데이터가 getline에 들어가므로 제거한다.
        getline(cin, ptr[i].bookName);// 사용자로부터 책의 이름을 입력 받아 ptr이 가리키는 (i+1)번째 객체의 멤버 변수 bookName에 대입
        cout << "가격 : ";    // 기본 멘트 출력
        cin >> ptr[i].price; // 사용자로부터 책의 가격을 입력 받아 ptr이 가리키는 (i+1)번째 객체의 멤버 변수 price에 대입
    }
    cout << endl;            // 한 줄 개행
    ptr->printBooks(ptr, cnt);     // 포인터 ptr이 가리키는 객체의 멤버 함수 printBooks()를 실행하여 저장되어 있던 책의 정보 출력

    delete [] ptr;           // 할당받은 메모리 반환
    return 0;                // 0을 반환하고 프로그램 종료
}