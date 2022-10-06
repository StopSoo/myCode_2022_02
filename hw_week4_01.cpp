//#include <iostream>             // 기본 입출력 라이브러리
//using namespace std;            // 이름 공간 std 선언
//
//class Time {                    // 클래스 Time 선언
//    int clock;                  // 시간을 나타내는 정수형 변수 선언
//public:
//    Time() {                    // 기본 생성자
//        clock = 0;              // 멤버 변수 clock을 0으로 초기화
//    }
//    int getClock(int a);        // 입력 받은 시간을 인수로 받아 다시 반환하는 멤버 함수 원형 정의
//    int result(int x, int y, int z);    // 시간, 분, 초를 인수로 받아 시간을 초로 변환하는 멤버 함수 원형 정의
//};
//
//int Time::getClock(int a) {     // 입력 받은 시간을 인수로 받아 다시 반환하는 멤버 함수
//    clock = a;                  // 입력 받은 시간을 멤버 변수 clock에 대입
//    return clock;               // clock 반환
//}
//
//int Time::result(int x, int y, int z) {  // 시간, 분, 초를 인수로 받아 시간을 초로 변환하는 멤버 함수
//    int chResult;               // 변환한 시간을 담을 정수형 변수 chResult 선언
//    chResult = x * 3600 + y * 60 + z;    // 시간을 초로 변환해서 정수형 변수 chResult에 대입
//    return chResult;            // chResult 반환
//}
//
//int main() {
//    Time time;                                  // Time 클래스형의 객체 생성
//    int a, b, c;                        // 시간, 분, 초를 입력 받을 정수형 지역 변수 선언
//    cout << "시간을 입력해주세요 : " << endl;        // 기본 멘트 출력
//    cout << "몇 시 ? ";                          // 시간 입력을 받는 기본 멘트 출력
//    cin >> a ;                                  // 시간을 입력 받음
//    cout << "몇 분 ? ";                          // 분 입력을 받는 기본 멘트 출력
//    cin >> b;                                   // 분을 입력 받음
//    cout << "몇 초 ? ";                          // 초 입력을 받는 기본 멘트 출력
//    cin >> c;                                   // 초를 입력 받음
//
//    cout << "입력한 시간 = ";                      // 입력한 시간을 나타낸다는 기본 멘트 출력
//    cout.width(2);     // 출력 너비를 설정
//    cout.fill('0');     // 채움 문자를 '0'으로 설정
//    cout << time.getClock(a) << ":";            // 입력 받은 시간을 반환하는 멤버 함수를 사용하여 시간 출력
//    cout.width(2);     // 출력 너비를 설정
//    cout.fill('0');     // 채움 문자를 '0'으로 설정
//    cout << time.getClock(b) << ":";         // 입력 받은 시간을 반환하는 멤버 함수를 사용하여 분 출력
//    cout.width(2);     // 출력 너비를 설정
//    cout.fill('0');     // 채움 문자를 '0'으로 설정
//    cout << time.getClock(c) << endl;        // 입력 받은 시간를 반환하는 멤버 함수를 사용하여 초 출력
//
//    cout << "시간을 초로 변환 = " << time.result(a,b,c);   // time 객체에 대해 멤버 함수 result를 실행한 결과를 형식에 맞게 출력
//}