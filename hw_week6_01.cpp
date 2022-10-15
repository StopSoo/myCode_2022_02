#include <iostream>         // 기본 입출력 라이브러리
#include <string>           // string 클래스
using namespace std;        // 이름 공간 std 선언

int main() {
    // 문자열 str1 선언 후 주어진 문자열로 초기화
    string str1 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
    int len = str1.length();        // string 클래스의 length() 함수를 사용하여 문자열의 길이를 정수형 변수 len에 저장

    string str2;                    // 원본 문자열을 역순으로 저장하기 위한 문자열 str2 선언
    for(int i=len-1; i>=0; i--) {   // for문을 사용하여 인덱스 (len-1)부터 0까지 반복
        str2 += str1[i];            // 원본 문자열의 마지막 문자부터 역순으로 하나씩 문자열 str2에 더함
    }

    cout << "원본 문자열 : " << str1 << endl;    // 원본 문자열을 멘트와 함께 출력
    cout << "역순 문자열 : " << str2 << endl;    // 원본 문자열을 역순으로 바꾼 문자열을 멘트와 함께 출력

    return 0;               // 0을 반환하고 프로그램 종료
}