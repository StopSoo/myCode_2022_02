#include <iostream>                 // 기본 입출력 라이브러리
using namespace std;                // 이름 공간 std 선언

void changeSpeed(double *ptr);      // 선박의 초당 노트 속도를 바꾸는 함수 changeSpeed()의 원형을 정의

int main() {
    double speed;                   // 속도를 담는 double형 변수 speed 선언
    double *p = &speed;             // 변수 speed를 가리키는 double형 포인터 p 선언
    speed = (double)17000 / 3000;   // 항구에 진입하기 전 선박의 속도를 계산하여 변수 speed에 대입
    cout << "선박 속도(항구 진입 전): " << speed << "킬로미터(초)" << endl;           // 항구에 진입하기 전 속도를 멘트와 함께 출력
    changeSpeed(p);             // 함수 changeSpeed()를 이용하여 선박의 초당 노트 속도를 변경
    cout << "선박 속도(항구 진입 후): " << speed << "킬로미터(초)" << endl;           // 항구에 진입한 후 속도를 멘트와 함께 출력

    return 0;       // 0을 반환하고 프로그램 종료
}

void changeSpeed(double *ptr) {     // double형 포인터를 이용하여 선박의 초당 노트 속도를 바꾸는 함수 changeSpeed() 정의
    *ptr = double(17000-10000) / 3000;      // double형 포인터 ptr이 가리키는 변수에 속도를 바꿔서 계산 후 대입
}