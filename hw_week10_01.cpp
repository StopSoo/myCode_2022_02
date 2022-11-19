//#include <iostream>             // 기본 입출력 라이브러리
//using namespace std;            // 이름 공간으로 std를 선언
//
//class Number;                   // 클래스 Number를 전방 선언 --> 클래스 Check 내 멤버 함수가 클래스 Number의 참조 변수를 매개변수로 가지므로
//class Check {                   // 클래스 Check 선언 및 정의
//public:                         // 접근 지정자  public
//    void checkNum(Number&);     // 숫자가 7의 배수인지를 체크하는 멤버 함수 checkNum() 선언
//};
//
//class Number {                  // 클래스 Number를 정의
//    int startNum = 656, endNum = 789;       // 멤버 변수로 숫자 시작 지점과 끝 지점을 담는 정수형 변수 startNum, endNum을 선언
//public:                         // 접근 지정자 public
//    int arr[19] = {0};      // 숫자들을 담을 정수형 배열 arr을 선언하고 0으로 초기화
//    friend void Check::checkNum(Number& n); // 클래스 Check의 멤버 함수 checkNum()을 friend 함수를 사용하여 접근 가능하게 함
//    void printArray(int* p);    // 배열 arr의 원소들을 출력하는 멤버 함수 printArray()를 정의
//};
//
//void Check::checkNum(Number& n) {           // 숫자가 7의 배수인지를 체크하는 멤버 함수 checkNum()을 정의
//    int start = n.startNum;                 // 인수로 받은 객체 n 내 멤버 변수 startNum을 함수 내 지역 변수 start에 대입
//    int end = n.endNum;                     // 인수로 받은 객체 n 내 멤버 변수 endNum을 함수 내 지역 변수 end에 대입
//    int index=0;            // 배열의 인덱스 선언 및 초기화
//    for(int i=start; i<=end; i++) {         // start 값부터 end 값까지 for문을 수행
//        if(i%7 == 0)                        // 7의 배수라면
//            n.arr[index++] = i;             // 그 수를 객체 n의 배열 arr의 인덱스 index번째 자리에 넣고, index의 값을 1 증가시킴
//    }
//}
//
//void Number::printArray(int* p) {           // 배열 arr의 원소들을 출력하는 멤버 함수 printArray()를 선언
//    int size = 19;                          // 배열의 크기 19를 담는 정수형 변수 size 선언 및 초기화
//    int sum = 0;                            // 수의 합을 담을 정수형 변수 sum 선언 및 초기화
//    for(int i=0; i<size; i++) {             // size 값 만큼 for문을 수행하여 배열의 원소들을 출력하고, sum에 그 값들을 더해서 누적시킴
//        cout << "7로 나누어지는 숫자는 " << p[i] << endl;
//        sum += p[i];
//    }
//    cout << "7로 나눌 수 있는 모든 수의 합은 " << sum << endl;      // sum을 멘트와 함께 출력함
//}
//
//int main() {
//    Number num;         // 클래스 Number 객체 생성
//    Check ch;           // 클래스 Check 객체 생성
//
//    ch.checkNum(num);           // 객체 ch에 대해 인수를 num으로 하여 함수 checkNum()을 실행함
//    num.printArray(num.arr);    // 객체 num에 대해 인수를 num.arr로 하여 함수 printArray()를 실행함
//
//    return 0;           // 0을 반환하고 프로그램 종료
//}