#include <iostream>                         // 기본 입출력 라이브러리
using namespace std;                        // 네임 공간 std 사용

int main() {
    int cnt;                                // 입력 받을 정수의 개수를 담을 정수형 변수 cnt 선언
    cout << "정수를 얼마나 입력 받을까요 ? ";      // 사용자에게 입력을 받기 위한 기본 멘트 출력
    cin >> cnt;                             // 사용자에게 입력 받을 정수의 개수를 입력 받음
    if(cnt <= 0) {                          // cnt가 0 이하일 경우
        cout << "1 이상의 값을 입력하세요." << endl;      // 1 이상의 값을 입력해달라는 멘트 출력
        return 0;                           // 0을 반환하고 프로그램 종료
    }

    int *p;                                 // 정수형 포인터 선언
    p = new int[cnt];                       // 사용자에게 입력 받은 값의 크기를 가지는 정수형 배열에 대한 메모리를 동적으로 할당한 후, 배열의 주소를 포인터에 대입함
    if (!p) {                               // p가 NULL일 경우
        cout << "메모리를 할당할 수 없습니다. ";   // 멘트 출력
        return 0;                           // 0을 반환하고 프로그램 종료
    }

    for(int i=0; i<cnt; i++) {              // cnt 값 만큼 반복문을 수행
        cout << "정수 입력 : ";               // 사용자에게 입력을 받기 위한 기본 멘트 출력
        cin >> p[i];                        // 사용자에게 정수를 입력 받음
    }

    cout << "정수 출력 : ";                   // 출력을 하기 위한 기본 멘트 출력
    for(int j=0; j<cnt; j++) {              // 사용자가 입력한 값을 출력하기 위해 반복문을 수행
        cout << p[j];                       // 배열의 인덱스가 1씩 증가하며 배열에 저장된 값들이 출력됨
        if(j<cnt-1)                         // 배열의 마지막 원소가 아닐 경우
            cout << ", ";                   // 원소 다음에 ", "를 출력
    }
    cout << endl;               // 한 줄 개행

    delete [] p;                // 메모리 반환
    return 0;                   // 0을 반환하고 프로그램 종료
}