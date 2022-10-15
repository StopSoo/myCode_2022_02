#include <iostream>     // 기본 입출력 라이브러리
#define PI 3.14         // 원주율 값을 PI로 선언
using namespace std;    // 이름 공간 std 선언

class Sphere {          // 클래스 Sphere
public:                 // 접근 지정자 public
    int index;          // 구의 순서를 담는 정수형 멤버 변수 index 선언
    int radius;         // 구의 반지름의 길이를 담는 정수형 멤버 변수 radius

    Sphere(int index) { // 매개변수가 있는 생성자 Sphere 선언
        this->index = index;    // 멤버 변수 index에 인수 index 값을 대입
        cout << "구 객체 생성 " << this->index << endl;      // 생성자가 실행되었음을 알리는 멘트를 출력
    }
    ~Sphere() {         // 소멸자 Sphere 선언
        cout << "구 객체 소멸 " << this->index << endl;            // 소멸자가 실행되었음을 알리는 멘트를 출력
    }
    double calVol() {   // 구의 부피를 계산해서 반환하는 멤버 함수 calVol() 정의
        // 구의 부피를 담을 double형 변수 vol 선언 및 계산식으로 초기화
        double vol = (4.0 / 3.0) * PI * radius * radius * radius;    // 구의 부피 계산
        return vol;     // 구의 부피 반환
    };
};

int main() {
    // 정해진 기준보다 큰 부피를 갖는 구의 개수, 작은 부피를 갖는 구의 개수를 담을 double형 변수 big, small 선언 및 초기화
    double big=0, small=0;
    // 5의 크기를 갖는 Sphere 클래스 객체 배열을 동적으로 생성 후, 생성자 Sphere(index)로 초기화
    Sphere *sp = new Sphere[5] {Sphere(1), Sphere(2), Sphere(3), Sphere(4), Sphere(5)};
    cout << endl;       // 한 줄 개행

    for(int i=0; i<5; i++) {        // for문을 5번 수행
        cout << "구 " << (i+1) << "의 반지름 >> ";   // 몇 번째 구의 반지름을 입력하는지를 알리는 멘트 출력
        cin >> sp[i].radius;        // 구의 반지름을 입력 받아 변수 radius에 대입
    }
    cout << endl;       // 한 줄 개행

    for(int j=0; j<5; j++) {        // for문을 5번 수행
        if(sp[j].calVol() > 765.0)  // 객체마다 함수 calVol()을 수행해서 나온 부피 값이 765보다 클 경우
            big++;      // 변수 big의 값을 1 증가시킴
        else    // 부피가 765보다 작을 경우
            small++;    // 변수 small의 값을 1 감소시킴
    }

    cout << "구의 부피가 765cm3 이상인 큰 구는 " << big << "개 입니다." << endl;           // 구의 부피가 기준 값보다 큰 경우의 멘트를 출력
    cout << "구의 부피가 765cm3 이하인 작은 구는 " << small << "개 입니다." << endl;       // 구의 부피가 기준 값보다 작은 경우의 멘트를 출력
    cout << endl;       // 한 줄 개행

    delete [] sp;       // 동적으로 할당받은 메모리를 반납
    return 0;           // 0을 반환하고 프로그램 종료
}