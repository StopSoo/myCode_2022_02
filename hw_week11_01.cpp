//#include <iostream>         // 기본 입출력 라이브러리
//using namespace std;        // 이름 공간 std 선언
//
//class Box {                 // 클래스 Box
//    int width;              // 박스의 가로 길이를 담을 정수형 변수 width
//    int length;             // 박스의 세로 길이를 담을 정수형 변수 length
//    int height;             // 박스의 높이 길이를 담을 정수형 변수 height
//public:                     // 접근 지정자
//    Box() { width = 0; length = 0; height = 0; };   // 생성자를 선언하고 멤버 변수 값들을 0으로 초기화
//    void setValue(int w, int l, int h);     // 객체의 멤버 변수들 값을 설정하는 함수 setValue() 선언
//    Box& operator++ ();     // 전위 ++ 연산자 함수 operator++ () 선언
//    int calVolume();        // 박스의 부피를 구하는 함수 calVolume() 선언
//};
//
//void printInfo(Box, Box, Box);  // 객체들의 부피 값을 출력하는 함수 printInfo()의 원형 선언
//
//int main() {
//    Box box1, box2, box3;   // 객체 선언
//    box1.setValue(5, 5, 10);        // 객체 box1의 멤버 변수 값을 설정
//    box2.setValue(10, 15, 20);      // 객체 box2의 멤버 변수 값을 설정
//    box3.setValue(50, 30, 40);      // 객체 box3의 멤버 변수 값을 설정
//    ++box1;         // 객체 box1에 대해 전위 ++ 연산자 함수를 실행
//    ++box2;         // 객체 box2에 대해 전위 ++ 연산자 함수를 실행
//    ++box3;         // 객체 box3에 대해 전위 ++ 연산자 함수를 실행
//    printInfo(box1, box2, box3); // 객체 box1, box2, box3의 부피를 출력
//
//    return 0;       // 0을 반환하고 프로그램 종료
//}
//
//Box& Box::operator++() {        // 전위 ++ 연산자 함수 operator++ () 정의
//    width++;        // 멤버 변수 width의 값을 1 증가시킴
//    length++;       // 멤버 변수 length의 값을 1 증가시킴
//    height++;       // 멤버 변수 height의 값을 1 증가시킴
//    return *this;   // 변경된 객체의 참조를 반환함
//}
//
//void Box::setValue(int w, int l, int h) {   // 객체의 멤버 변수들 값을 설정하는 함수 setValue() 정의
//    width = w;      // 인수로 받은 w를 멤버 변수 width에 대입
//    length = l;     // 인수로 받은 l를 멤버 변수 length에 대입
//    height = h;     // 인수로 받은 h를 멤버 변수 height에 대입
//}
//
//int Box::calVolume() {      // 박스의 부피를 구하는 함수 calVolume() 정의
//    int result;     // 계산된 부피를 담을 정수형 변수 result 정의
//    result = width * length * height;       // 변수 result에 부피를 계산해서 대입함
//    return result;  // result를 반환함
//}
//
//void printInfo(Box b1, Box b2, Box b3) {    // 객체들의 부피 값을 출력하는 함수 printInfo() 정의
//    cout << "Box1 부피: " << b1.calVolume() << "cm3" << endl; // box1의 부피를 멘트와 함께 출력
//    cout << "Box2 부피: " << b2.calVolume() << "cm3" << endl; // box2의 부피를 멘트와 함께 출력
//    // box3의 부피는 box1, box2, box3의 부피를 다 더해서 멘트와 함께 출력
//    cout << "Box3 부피: " << b1.calVolume() + b2.calVolume() + b3.calVolume() << "cm3" << endl;
//}