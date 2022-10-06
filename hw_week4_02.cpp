//#include <iostream>                     // 기본 입출력 라이브러리
//using namespace std;                    // 이름 공간 std 선언
//
//class BankClient {                      // 클래스 BankClient 선언
//public:                                 // 접근 지정자
//    int account, remain, money;         // 계좌를 담을 account, 잔액을 담을 remain, 예금/출금 금액을 담을 money를 정수형 변수로 선언
//    string name;                        // 예금주를 담을 name을 문자열 변수로 선언
//    BankClient(){ account = 2022123456; remain = 100000; money = 0; name = "Alice";};   // 매개변수가 없는 생성자 선언 & 멤버 변수를 기본값으로 초기화
//    int inOutMoney(){                   // 예금/출금 함수 선언
//        int choice;                     // 사용자의 선택을 담을 정수형 변수 선언
//        cout << "예금은 1번, 출금은 2번을 선택해주세요. : ";           // 사용자에게 선택을 받기 위한 기본 멘트 출력
//        cin >> choice;                  // 정수형 변수 choice에 사용자의 선택값을 대입
//        if(choice == 1) {               // 사용자가 '예금'을 선택했을 경우
//            cout << "얼마를 예금하시겠습니까 ? : ";                  // 사용자에게 예금액을 받기 위한 기본 멘트 출력
//            cin >> money;               // 사용자에게 입력 받은 금액을 money에 대입
//            remain += money;            // 입력 받은 money에 담겨 있는 값을 remain에 더해서 저장
//        } else if (choice == 2) {       // 사용자가 '출금'을 선택했을 경우
//            cout << "얼마를 출금하시겠습니까 ? : ";                  // 사용자에게 출금액을 받기 위한 기본 멘트 출력
//            cin >> money;               // 사용자에게 입력 받은 금액을 money에 대입
//            remain -= money;            // 입력 받은 money에 담겨 있는 값을 remain에서 빼서 저장
//        } else {                        // 사용자가 1,2 이외의 값을 선택했을 경우
//            cout << "잘못 선택하셨습니다. 프로그램을 종료합니다.";        // 사용자가 잘못 선택했음을 알리는 기본 멘트 출력
//            return 0;                   // 0을 반환하고 프로그램 종료
//        }
//    };
//    ~BankClient() { cout << "# 객체가 소멸되었습니다. " << endl; }   // 소멸자 생성 및 안내 멘트 출력
//};
//
//int main() {
//    BankClient person;          // 객체 생성
//    cout << "예금주 : " << person.name << endl;                    // 예금주와 객체 person의 멤버 변수 name을 함께  출력
//    cout << "계좌 번호 : " << person.account << endl;               // 계좌 번호와 객체 person의 멤버 변수 account를 함께  출력
//    cout << "잔액 : " << person.remain << endl << endl;   // 잔액과 객체 person의 멤버 변수 remain을 함께  출력
//
//    person.inOutMoney();        // 예금/출금 함수 실행
//
//    cout << "예금주 : " << person.name << endl;                    // 예금주와 객체 person의 멤버 변수 name을 함께  출력
//    cout << "계좌 번호 : " << person.account << endl;               // 계좌 번호와 객체 person의 멤버 변수 account를 함께  출력
//    cout << "잔액 : " << person.remain << endl << endl;   // 잔액과 객체 person의 멤버 변수 remain을 함께  출력
//
//    person.inOutMoney();
//
//    cout << "예금주 : " << person.name << endl;                    // 예금주와 객체 person의 멤버 변수 name을 함께  출력
//    cout << "계좌 번호 : " << person.account << endl;               // 계좌 번호와 객체 person의 멤버 변수 account를 함께  출력
//    cout << "잔액 : " << person.remain << endl << endl;   // 잔액과 객체 person의 멤버 변수 remain을 함께  출력
//}