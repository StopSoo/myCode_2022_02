//#include <iostream>         // 기본 입출력 라이브러리
//using namespace std;        // 이름 공간 std 선언
//
//class Pyramid {             // 클래스 Pyramid 선언
//    char ch;                // 출력할 문자를 담을 char형 변수 ch 선언
//    int outCount;           // 이중 반복문에서 바깥 루프의 반복 횟수를 담기 위한 정수형 변수 outCount 선언
//public:
//    static int lineCount;   // 탭을 출력할 때 사용할 lineCount를 정적 변수로 선언
//    // 입력된 글자 수를 출력하는 전역 함수 printOutCount()를 friend 함수를 사용하여 선언
//    friend void printOutCount(Pyramid&);
//    Pyramid() {             // 기본 생성자 Pyramid
//        ch = 65;            // 출력할 문자 ch를 65로 초기화 --> 문자 'A'
//        int inCount=1;      // 이중 반복문에서 안쪽 루프의 반복 횟수를 담기 위한 정수형 변수 inCount 선언
//        cout << "글자 수를 입력하세요 (26 이하의 숫자) : ";       // 사용자에게 입력을 받기 위한 안내 멘트 출력
//        cin >> outCount;    // 사용자로부터 입력 받은 값을 변수 outCount에 저장
//        if(outCount > 26) { // 만약 사용자가 26 초과의 숫자를 입력했을 경우
//            cout << "26 이하의 숫자를 입력하세요. 프로그램을 종료합니다." << endl;       // 안내 멘트를 출력
//            return;         // 프로그램 종료
//        }
//        lineCount = outCount;       // 변수 lineCount에 outCount 값을 저장
//
//        for(int i=0; i<outCount; i++) {         // 사용자에게 입력 받은 값 만큼 루프를 수행함
//            for (int i = 0; i < lineCount; i++) {    // lineCount 값 만큼 탭을 출력함
//                cout << " \t";
//            }
//            for (int i = 0; i < inCount; i++) {      // inCount 값 만큼 반복문을 수행
//                cout << ch << "\t";             // 문자와 탭을 함께 출력
//                if (i < inCount - 1)               // 마지막에서 두 번째 문자까지만
//                    ch++;                       // ch의 값을 1 증가시킴
//            }
//            for (int i = 0; i < inCount - 1; i++) {    // (inCount-1) 값 만큼 반복문을 수행
//                cout << --ch << "\t";           // ch의 값을 1씩 증가시키면서 탭과 함께 출력
//            }
//
//            inCount++;          // 아랫줄로 갈수록 출력되는 문자의 개수는 증가해야 하므로 변수 inCount의 값을 1 증가시킴
//            lineCount--;        // 아랫줄로 갈수록 출력되는 탭의 개수는 감소해야 하므로 변수 lineCount의 값을 1 감소시킴
//            cout << endl;       // 한 줄 개행
//        }
//    }
//};
//
//int Pyramid::lineCount = 0;                 // 정적 멤버 변수 lineCount를 0으로 초기화
//
//void printOutCount(Pyramid& p) {            // 전역 함수 printOutCount()를 정의
//    cout << "입력한 글자 수 : " << p.outCount << endl;        // 인수로 받은 Pyramid 객체 내 멤버 변수 outCount를 멘트와 함께 출력
//}
//
//int main() {
//    Pyramid py;                // Pyramid 객체 py를 생성
//    printOutCount(py);      // py에 대해 전역 함수 printOutCount()를 실행
//    return 0;                  // 0을 반환하고 프로그램 종료
//}