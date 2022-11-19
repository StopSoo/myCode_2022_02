//#include <iostream>         // 기본 입출력 라이브러리
//using namespace std;        // 이름 공간 std 선언
//
//class Distance {            // 클래스 Distance
//    int feet;               // feet 길이를 담을 정수형 변수 feet
//    int inch;               // inch 길이를 담을 정수형 변수 inch
//public:
//    Distance(int feet = 0, int inch = 0) {      // 생성자 Distance 생성 및 정의, 매개 변수를 모두 0으로 초기화
//        this->feet = feet;  // 이 객체의 feet에 인수로 받은 feet를 대입
//        this->inch = inch;  // 이 객체의 inch에 인수로 받은 inch를 대입
//    };
//    friend void printDistanceD1D2(Distance, Distance);      // 객체 d1과 d2 사이의 거리를 출력하는 외부 함수 printDistanceD1D2()를 friend로 선언
//    friend void printDistanceD3D4(Distance, Distance);      // 객체 d3와 d4 사이의 거리를 출력하는 외부 함수 printDistanceD3D4()를 friend로 선언
//    friend Distance operator+ (Distance, Distance);         // + 연산자 함수 선언
//};
//
//void printDistanceD1D2(Distance d1, Distance d2) { // 객체 d1과 d2 사이의 거리를 출력하는 함수 printDistanceD1D2()
//    cout << "d1.feet: " << d1.feet << ", d1.inch: " << d1.inch << endl;     // 객체 d1의 feet와 inch를 멘트와 함께 출력
//    cout << "d2.feet: " << d2.feet << ", d2.inch: " << d2.inch << endl;     // 객체 d2의 feet와 inch를 멘트와 함께 출력
//    // 두 객체의 거리의 합을 + 연산자 함수를 사용하여 출력
//    cout << "두 개(d1, d2)의 거리의 합: " << d1.feet + d2.feet << " feet, " << d1.inch + d2.inch << " inch" << endl;
//}
//
//void printDistanceD3D4(Distance d3, Distance d4) { // 객체 d3와 d4 사이의 거리를 출력하는 함수 printDistanceD3D4()
//    cout << "d3.feet: " << d3.feet << ", d3.inch: " << d3.inch << endl;     // 객체 d3의 feet와 inch를 멘트와 함께 출력
//    cout << "d4.feet: " << d4.feet << ", d4.inch: " << d4.inch << endl;     // 객체 d4의 feet와 inch를 멘트와 함께 출력
//    // 두 객체의 거리의 합을 + 연산자 함수를 사용하여 출력
//    cout << "두 개(d3, d4)의 거리의 합: " << d3.feet + d4.feet << " feet, " << d3.inch + d4.inch << " inch" << endl;
//}
//
//Distance operator+ (Distance td1, Distance td2) {  // + 연산자 함수 정의
//    Distance temp;      // Distance형 임시 변수 temp 선언
//    temp.feet = td1.feet + td2.feet;    // temp의 feet은 객체 td1의 feet와 td2의 feet 값을 더해서 대입
//    temp.inch = td1.inch + td2.inch;    // temp의 inch는 객체 td1의 feet와 td2의 feet 값을 더해서 대입
//    return temp;        // temp를 반환
//}
//
//int main() {
//    // 각 객체 d1, d2, d3, d4를 생성 후 인수 값으로 멤버 변수를 초기화
//    Distance d1(20,40), d2(46,51), d3(254,450), d4(126,244);
//    printDistanceD1D2(d1, d2);  // 함수를 실행해서 객체 d1, d2 사이의 거리를 출력
//    cout << endl;       // 한 줄 개행
//    printDistanceD3D4(d3, d4);  // 함수를 실행해서 객체 d3, d4 사이의 거리를 출력
//
//    return 0;
//}