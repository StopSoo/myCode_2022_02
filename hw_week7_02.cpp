#include <iostream>         // 기본 입출력 라이브러리
#include <string>           // string 함수를 사용하기 위한 헤더 파일 포함
#include <ctime>            // 랜덤 함수의 seed값을 time으로 설정하기 위한 헤더 파일 포함
using namespace std;        // 이름 공간 std 선언

void changeNum(string& n1, string& n2) {    // 민수와 철수의 숫자를 바꾸는 함수 changeNum() 정의
    string temp;        // 임시 변수 temp 선언
    temp = n1;          // n1의 값을 temp에 대입
    n1 = n2;            // n2의 값을 n1에 대입
    n2 = temp;          // 원래의 n1 값을 가진 temp의 값을 n2에 대입
}

void reverseNum(string who, string s) {     // 민수와 철수의 숫자를 역순으로 출력하는 함수 reverseNum()
    string result = "";        // 주어진 문자열을 역순으로 바꿔서 넣을 string 변수 result를 선언

    for (int i = s.length() - 1; i > -1;  i--) {    // 주어진 문자열을 for문을 사용하여 역순으로 하나씩 변수 result에 대입함
        result += s[i];
    }

    int idx = 0;        // 인덱스를 나타내는 정수형 변수 idx를 선언하고 0으로 초기화
    for (int i = 0; i < s.length(); i++) {          // 문자열의 길이 만큼 for문을 수행
        if (result[i] == '0') {     // 만약 문자열의 인덱스 i번째 문자가 '0'이라면
            idx++;      // idx의 값을 1 증가시킴
        }
        else {          // 문자열의 인덱스 i번째 문자가 '0'이 아니라면
            break;      // for문을 중단함
        }
    }

    if (idx == 0) {     // 만약 idx가 0일 경우(역순으로 바꾼 문자열이 '0'으로 시작하지 않을 경우)
        cout << who << "의 숫자 = " << result << endl;     // 멘트와 함께 result를 그대로 출력
    }
    else {              // idx가 0이 아닐 경우
        // idx 번째 인덱스 문자부터 (result.length() - idx) 만큼의 길이로 자른 결과물을 멘트와 함께 출력
        cout << who << "의 숫자 = " << result.substr(idx, result.length() - idx) << endl;
    }
}

int main() {
    srand((unsigned int)time(NULL));        // 랜덤 함수의 seed 값을 time으로 설정
    int numM = rand() % 10000000;           // 민수의 숫자를 담을 정수형 변수 numM을 선언하고 랜덤 값을 대입함
    int numC = rand() % 10000000;           // 철수의 숫자를 담을 정수형 변수 numC를 선언하고 랜덤 값을 대입함

    string temp1 = to_string(numM);             // 문자열 변수 temp1을 선언하고 numM을 to_string() 함수를 이용하여 string형으로 변경함
    string temp2 = to_string(numC);             // 문자열 변수 temp2를 선언하고 numC를 to_string() 함수를 이용하여 string형으로 변경함
    cout << "민수의 숫자 = " << temp1 << endl;         // 역순으로 변경하기 전 민수의 숫자를 멘트와 함께 출력함
    cout << "철수의 숫자 = " << temp2 << endl << endl; // 역순으로 변경하기 전 철수의 숫자를 멘트와 함께 출력함

    cout << "숫자를 서로 교환했습니다." << endl;          // 숫자가 교환되었음을 알리는 멘트를 출력
    changeNum(temp1, temp2);                 // 민수와 철수의 숫자를 교환함

    cout << "숫자를 거꾸로 변경했습니다." << endl << endl; // 숫자가 역순으로 변경되었음을 알리는 멘트를 출력
    reverseNum("민수", temp1);               // 이름과 숫자를 인수로 하여 민수의 숫자를 역순으로 변경 후 출력
    reverseNum("철수", temp2);               // 이름과 숫자를 인수로 하여 철수의 숫자를 역순으로 변경 후 출력

    return 0;       // 0을 반환하고 프로그램 종료
}