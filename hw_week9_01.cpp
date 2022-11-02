#include <iostream>     // 기본 입출력 라이브러리
#define PI 3.14         // 원주율 값을 기호 상수로 선언
using namespace std;    // 이름 공간 std 선언

class measure {     // 클래스 measure 정의
private:            // 접근 지정자 private
    int choice;     // 사용자가 선택한 도형 번호를 담을 정수형 변수 choice
    int radius;     // 도형의 반지름을 담을 정수형 변수 radius 선언
    int height;     // 도형의 높이를 담을 정수형 변수 height 선언
    double result;  // 계산된 도형의 부피나 면적을 담을 double형 변수 result 선언
public:             // 접근 지정자 public
    measure();      // 매개 변수가 없는 생성자 선언
    measure(int choice, int radius, int height);    // 매개 변수를 3개 가지는 생성자 선언
    void choiceMenu();      // 도형을 선택하는 함수 원형 정의
    double calRes();        // 부피나 면적을 측정하는 함수 원형 정의
    void circleRes();       // 원의 면적을 계산하는 함수 원형 정의
    void rectRes();         // 직사각형의 면적을 계산하는 함수 원형 정의
    void triangleRes();     // 삼각형의 면적을 계산하는 함수 원형 정의
    void squareRes();       // 정사각형의 면적을 계산하는 함수 원형 정의
    void coneRes();         // 원뿔의 부피를 계산하는 함수 원형 정의
    void sphereRes();       // 구의 부피를 계산하는 함수 원형 정의
    void cylinderRes();     // 실린더의 부피를 계산하는 함수 원형 정의
};
// 매개 변수가 없는 생성자 정의
measure::measure() {        
    this->choice = 1;
    this->radius = 1;
    this->height = 1;
}
// 매개변수가 3개인 생성자 정의
measure::measure(int choice, int radius, int height) {
    this->choice = choice;
    this->radius = radius;
    this->height = height;
}

int main() {
    measure res1, res2(5, 5, 5);            // measure형의 객체를 두 개 생성하는데 하나는 기본 생성자로 초기화하고, 다른 하나는 매개 변수가 있는 생성자로 초기화한다.
    res1.choiceMenu();       // 면적 및 부피를 계산할 도형을 선택하는 함수를 호출
    res1.calRes();           // 도형의 면적을 계산하는 함수를 호출하는 함수를 호출
    res2.calRes();
    return 0;
}
// 면적 및 부피를 구할 도형을 선택하는 함수 정의
void measure::choiceMenu() {
    cout << "면적 및 부피 계산기" << endl << endl;
    cout << "1. 원의 면적" << endl;
    cout << "2. 직사각형의 면적" << endl;
    cout << "3. 삼각형의 면적" << endl;
    cout << "4. 정사각형의 면적" << endl;
    cout << "5. 원뿔의 부피" << endl;
    cout << "6. 구의 부피" << endl;
    cout << "7. 실린더의 부피" << endl << endl;

    cout << "입력 : ";
    cin >> choice;
}
// 사용자의 선택에 따라 도형의 면적을 계산하는 함수를 호출하는 함수 정의
double measure::calRes() {
    if(choice == 1)
        circleRes();
    else if(choice == 2)
        rectRes();
    else if(choice == 3)
        triangleRes();
    else if(choice == 4)
        squareRes();
    else if(choice == 5)
        coneRes();
    else if(choice == 6)
        sphereRes();
    else if(choice == 7)
        cylinderRes();
    else
        cout << "잘못 입력하셨습니다. 프로그램을 종료합니다." << endl;

    return 0;
}
/* 도형의 면적을 구하는 함수들을 정의하는 파트 */
void measure::circleRes() {      // 1. 원의 면적을 구하는 함수
    if(radius == 1) {
        cout << "원의 반지름의 길이를 입력 : ";
        cin >> radius;
        result = PI * radius * radius;
        cout << "원의 면적은 " << result << endl;
    } else {
        result = PI * radius * radius;
        cout << "원의 면적은 " << result << endl;
    }
}
void measure::rectRes() {        // 2. 직사각형의 면적을 구하는 함수
    if(radius == 1) {
        cout << "직사각형의 변의 길이 입력 (a,b) : ";
        cin >> radius >> height;
        result = radius * height;
        cout << "직사각형의 면적은 " << (int)result << endl;
    } else {
        result = radius * height;
        cout << "직사각형의 면적은 " << (int)result << endl;
    }
}
void measure::triangleRes() {   // 3. 삼각형의 면적을 구하는 함수
    if(radius == 1) {
        cout << "삼각형의 변의 길이와 높이의 길이를 입력 (a,b) : ";
        cin >> radius >> height;
        result = 1.0 / 2.0 * radius * height;
        cout << "삼각형의 면적은 " << (int)result << endl;
    } else {
        result = 1.0 / 2.0 * radius * height;
        cout << "삼각형의 면적은 " << (int)result << endl;
    }
}
void measure::squareRes() {     // 4. 정사각형의 면적을 구하는 함수
    if(radius == 1) {
        cout << "정사각형의 한 변의 길이를 입력 : ";
        cin >> height;
        result = height * height;
        cout << "정사각형의 면적은 " << (int)result << endl;
    } else {
        result = height * height;
        cout << "정사각형의 면적은 " << (int) result << endl;
    }
}
void measure::coneRes() {      // 5. 원뿔의 부피를 구하는 함수
    if(radius == 1) {
        cout << "원뿔의 밑면의 반지름을 입력 : ";
        cin >> radius;
        cout << "원뿔의 높이를 입력 : ";
        cin >> height;
        result = 1.0 / 3.0 * PI * radius * radius * height;
        cout << "원뿔의 부피는 " << result << endl;
    } else {
        result = 1.0 / 3.0 * PI * radius * radius * height;
        cout << "원뿔의 부피는 " << result << endl;
    }
}
void measure::sphereRes() {    // 6. 구의 부피를 구하는 함수
    if(radius == 1) {
        cout << "구의 반지름을 입력 : ";
        cin >> radius;
        result = 4.0 / 3.0 * PI * radius * radius * radius;
        cout << "구의 부피는 " << result << endl;
    } else {
        result = 4.0 / 3.0 * PI * radius * radius * radius;
        cout << "구의 부피는 " << result << endl;
    }
}
void measure::cylinderRes() {   // 7. 실린더의 부피를 구하는 함수
    if(radius == 1) {
        cout << "실린더의 반지름 입력 : ";
        cin >> radius;
        cout << "실린더의 높이 입력 : ";
        cin >> height;
        result = PI * radius * radius * height;
        cout << "실린더의 부피는 " << result << endl;
    } else {
        result = PI * radius * radius * height;
        cout << "실린더의 부피는 " << result << endl;
    }
}