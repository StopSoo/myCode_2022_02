//#pragma once                // 헤더의 중복 선언 방지
//#include <iostream>         // 기본 입출력 라이브러리
//using namespace std;        // 이름 공간으로 std 선언
//
//class Student {             // Student라는 클래스를 선언
//public:                     // 접근 지정자
//    int num, score;         // 학번을 받기 위한 정수형 변수 num과 전체 점수를 받기 위한 정수형 변수 score 선언
//    double per;             // 환산된 점수를 저장하기 위한 실수형 변수 per 선언
//    string name;            // 이름을 받기 위한 문자열 변수 name 선언
//    Student() { num=0; name=""; }       // 매개변수가 없는 생성자 Student, 멤버 변수 초기화
//    void print(Student *pointer, int count);     // Student형의 포인터와 정수형 변수를 매개변수로 받는 멤버 함수 print() 선언
//};
//
//void Student::print(Student *pointer, int count) {
//    for(int i=0; i<count; i++) {                                // count만큼 반복문 수행
//        cout << (i+1) << "번째 학생 정보를 출력합니다." << endl;       // 기본 멘트 출력
//        cout << "이름 : " << pointer[i].name << endl;                // 정해진 멘트와 함께 배열의 i번째 요소의 이름 출력
//        cout << "학번 : " << pointer[i].num << endl;                 // 정해진 멘트와 함께 배열의 i번째 요소의 학번 출력
//        cout << "전체 : " << pointer[i].score << endl;               // 정해진 멘트와 함께 배열의 i번째 요소의 전체 점수 출력
//        pointer[i].per = (double)pointer[i].score / 200.0 * 100.0;      // 환산된 점수를 계산
//        cout << "점수 환산(%) : " << pointer[i].per << endl;          // 정해진 멘트와 함께 배열의 i번째 요소의 환산된 점수 출력
//    }
//};
