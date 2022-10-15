#include <iostream>         // 기본 입출력 라이브러리
#include <string>           // string 클래스
using namespace std;        // 이름 공간 std 선언

int main() {
    string str1, str2 = ""; // 원본 문자열과 대소문자를 변경한 문자열을 담을 string형 변수 str1, str2 선언 후 str2는 기본 값으로 초기화
    while(1) {              // -1이 입력되기 전까지는 무한 반복
        cout << "원본 문자열을 입력하세요 (-1을 입력할 경우 프로그램 종료) : ";     // 사용자에게 원본 문자열을 입력 받기 위한 기본 멘트 출력
        cin >> str1;        // str1에 사용자가 입력한 문자열을 대입
        if(str1 == "-1") {  // 사용자가 -1을 입력했을 경우
            cout << "프로그램이 종료되었습니다.";  // 프로그램이 종료되었음을 알리는 멘트 출력
            break;          // 반복문을 빠져 나옴
        }

        int len = str1.length();        // string 클래스의 length() 함수를 이용해 원본 문자열의 길이를 계산 후 정수형 변수 len에 저장
        for(int i=0; i<len; i++) {      // 원본 문자열의 길이 만큼 반복문을 수행
            if(str1[i] >= 'a' && str1[i] <= 'z')    // 소문자인 경우
                str2 += toupper(str1[i]);        // 대문자로 변경
            else                                    // 대문자인 경우
                str2 += tolower(str1[i]);        // 소문자로 변경
        }

        cout << "대소문자가 변경된 문자열 --> " << str2 << endl;   // 대소문자가 변경된 문자열을 멘트와 함께 출력
        str2.clear();       // 다음 반복 때는 다른 문자열을 출력해야 하므로 str2에 저장된 문자열을 지움
    }

    return 0;               // 0을 반환하고 프로그램 종료
}