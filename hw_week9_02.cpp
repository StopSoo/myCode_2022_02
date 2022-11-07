#include <iostream>         // 기본 입출력 라이브러리
using namespace std;        // 이름 공간 std 선언

class Car {                 // Car 클래스 선언
private:                    // 접근 지정자
    int number;             // 차량 번호를 담는 정수형 변수 number
    string name;            // 차량 이름을 담는 string형 변수 name
    int check;              // 차량 표시를 담는 정수형 변수 check
public:                     // 접근 지정자
    Car() { number = 1; name = ""; check = 0;};         // 멤버 변수들을 기본 값으로 초기화하는 생성자
    static int count;       // 정적 멤버 변수의 선언
    int getNum();           // 차량 번호를 입력 받는 함수 getNum()
    void getName();         // 차량 이름을 입력 받는 함수 getName()
    void getCheck();        // 차량 표시를 입력 받는 함수 getCheck()
    void printInfo();       // 차량 정보를 출력하는 함수 printInfo()
};

int Car::count = 0;         // 정적 멤버 변수의 정의 및 초기화
int Car::getNum() {         // 차량 번호를 입력 받는 함수 getNum()
    cout << "차량 번호 입력 : ";
    cin >> number;
    count++;                // 생성된 객체의 수를 담는 정적 멤버 변수 count의 값을 1 증가시킴
}

void Car::getName() {       // 차량 이름을 입력 받는 함수 getName()
    cout << "차량 이름 입력 : ";
    cin >> name;
}

void Car::getCheck() {      // 차량 표시를 입력 받는 함수 getCheck()
    cout << "표시 (1 - 10) : ";
    cin >> check;
}

void Car::printInfo() {     // 차량 정보를 출력하는 함수 printInfo()
    cout << endl;
    cout << "차량 번호 : " << number << endl;
    cout << "차량 이름 : " << name << endl;
    cout << "표시 : " << check << endl << endl;
}

int main() {
    int size;       // 사용자가 차량 정보를 저장할 횟수를 담을 정수형 변수 size 선언
    cout << "몇 대의 차량 정보를 입력하시겠습니까 ? : ";        // 안내 멘트 출력
    cin >> size;    // 사용자에게 값을 입력 받고 size에 대입
    Car car1;       // Car형의 객체 car1을 생성
    for(int i=0; i < size; i++) {       // size 값 만큼 반복문을 수행
        car1.getNum();      // 객체 car1에 대해 함수 getNum()을 실행
        car1.getName();     // 객체 car1에 대해 함수 getName()을 실행
        car1.getCheck();    // 객체 car1에 대해 함수 getCheck()을 실행
        car1.printInfo();   // 객체 car1에 대해 함수 printInfo()을 실행
    }
    cout << "클래스에서 생성된 객체 수 : " << Car::count << endl;      // 총 몇 개의 객체가 생성되었는지를 멘트와 함께 출력
    return 0;   // 0을 반환하고 프로그램 종료
}