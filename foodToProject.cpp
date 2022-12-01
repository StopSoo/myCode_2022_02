#include <iostream>     // 기본 입출력 라이브러리
#include <cstdlib>      // 랜덤함수를 사용하기 위함
#include <ctime>        // 랜덤함수의 씨드 값을 time으로 설정하기 위함
#define MAX 100         // 멤버 배열 크기를 기호 상수로 정의
using namespace std;

typedef struct Info Member;     // 구조체 Info를 Member로 호출할 수 있게 함
typedef struct Menu Menu;       // 구조체 Menu를 Menu로 호출할 수 있게 함
struct Menu {       // 주문 메뉴를 담을 구조체 Menu
    string name;    // 음식의 이름
    int count;      // 음식 수
};
struct Info {
    string id = "";     // 고객의 아이디
    string pw = "";     // 고객의 패스워드
    string name = "";   // 고객의 이름
    int po = 0;         // 고객의 포인트
    Menu order[MAX];    // 고객이 주문한 음식을 담을 배열
};
typedef struct Node Node;   // 구조체 Node를 Node로 호출할 수 있게 함   --> 이중 연결 리스트
struct Node {
    Member member;      // 회원
    Node *l_list;       // 왼쪽 링크
    Node *r_list;       // 오른쪽 링크
} node[MAX];                // 구조체 Node를 선언함과 동시에 MAX 크기를 가진 배열 node를 선언함

int arr_index;                  // 배열의 인덱스
int cur_index;                  // 현재 로그인한 멤버의 인덱스
int indexO = 0;                 // 주문 목록 배열에서의 인덱스
int stIndex = 0;                // 추가 주문에서 사용하기 위한 인덱스
Node *head, *tail;              // 첫 노드, 마지막 노드인 head, tail
Node *myAlloc() {               // 노드에 노드 배열의 주소를 할당하는 myAlloc() 함수
    return &node[arr_index++];
}

/*--- 함수 원형 정의 부분 ---*/
void initial();         // 이중 연결 리스트와 변수들을 초기화
void intro_in();        // 로그인 전 마이 페이지
void intro_out();       // 로그인 후 마이 페이지
void joinMem();;        // 회원 가입
void deleteMem();       // 회원 탈퇴
void login();           // 로그인
void logout();          // 로그아웃
void point();           // 포인트 조회
void printOrderList();  // 장바구니 출력

void viewMyOrder();     // 나의 주문 확인하기
void chooseMoreOrNot(); // 음식 선택이 끝난 후 더 고를 것인지를 묻는 함수
void choiceFood();      // 음식을 선택하는 함수
void printBigMenu();    // 음식 대분류 출력
void choiceSnack();     // 분식
void choiceKoreanFood();// 한식
void choiceChineseFood();   // 중식
void choiceFastFood();  // 패스트푸드
void chooseMoreOrNot(); // 더 선택할지 말지를 입력 받는 함수
void setDeliveryInfo(); // 주문 정보를 확인하고 배달/포장 여부를 선택해 주문을 완료하는 함수


int main() {
    initial();
    intro_in();
}

/*--- 함수 정의 영역 ---*/
void initial() {                // 이중 연결 리스트를 초기화하는 함수 initial()
    arr_index = 0;              // 노드 배열의 인덱스를 0으로 초기화
    cur_index = 1;              // 현재 로그인한 멤버의 인덱스를 1로 초기화
    head = myAlloc();           // head를 노드 배열의 0번째 원소를 가리키게 함
    tail = myAlloc();           // tail을 노드 배열의 1번째 원소를 가리키게 함
    // head와 tail이 서로가 서로를 가리키게 함
    head->r_list = tail;
    tail->l_list = head;
}

void intro_in() {
    int number;
    cout << "~*~\t배달 음식이 필요할 땐, 딜나 (Delivery-Now)!\t~*~" << endl;
    cout << "\t\t<\tM   Y   P   A   G   E\t>" << endl;
    cout << "\t\t\t필요한 기능을 선택해주세요." << endl;
    cout << "1. 회원 가입  2. 회원 탈퇴  3. 로그인  4. 프로그램 종료\t\t" << endl;
    cout << ">>>  ";
    cin >> number;
    if (number == 1) {  // 1. 회원 가입
        joinMem();
    } else if (number == 2) {   // 2. 회원 탈퇴
        deleteMem();
    } else if (number == 3) {   // 3. 로그인
        login();
    } else {    // 4. 프로그램 종료
        return;
    }
}

void intro_out() {
    int number;
    cout << "~*~\t배달 음식이 필요할 땐, 딜나 (Delivery-Now)!\t~*~" << endl;
    cout << "\t\t<   M   Y   P   A   G   E   >" << endl;
    cout << "\t\t\t필요한 기능을 선택해주세요." << endl;
    cout << "1. 로그아웃  2. 포인트 충전  3. 나의 주문 기록 확인하기 4. 음식 주문하기 \t\t" << endl;
    cout << ">>>  ";
    cin >> number;
    if (number == 1) {  // 1. 로그아웃
        logout();
    } else if (number == 2) {   // 2. 포인트 충전
        point();
    } else if (number == 3) {   // 3. 나의 주문 기록 확인하기
        viewMyOrder();
    } else {    // 4. 음식 주문하기
        choiceFood();
    }
}

void login() {       // 로그인
    string t_id;
    string t_pw;
    cout << "로그인을 위한 화면입니다." << endl;
    cout << "아이디를 입력해주세요 : ";
    cin >> t_id;
    cout << "패스워드를 입력해주세요 : ";
    cin >> t_pw;

    int index = 1;
    for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {         // 등록된 회원 내에서 확인
        if(temp->member.id == t_id && temp->member.pw == t_pw) {                // 입력한 정보와 일치하는 회원이 있다면
            cout << temp->member.name << "님, 환영합니다 :-)" << endl << endl;     // 환영 멘트를 출력
            cur_index = index;  // 현재 인덱스를 그 회원의 인덱스로 저장
            cur_index++;
            break;          // for문 종료
        }
        index++;
    }
    if(cur_index == 0) {    // cur_index 값의 변화가 없다면 (= 회원을 찾지 못했다면)
        cout << "일치하는 회원이 없습니다 :-(" << endl;        // 멘트 출력 후
        intro_in();     // 초기화면으로 돌아감
    } else {    // 회원을 찾았다면
        intro_out();
    }
}

void logout() {     // 로그아웃
    string t_id;    // 임시 아이디 변수
    string t_pw;    // 임시 패스워드 변수
    cout << "로그아웃을 위한 화면입니다." << endl;
    cout << "아이디를 입력해주세요 : ";
    cin >> t_id;
    cout << "패스워드를 입력해주세요 : ";
    cin >> t_pw;

    for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {     // 등록된 회원 내에서 확인
        if(temp->member.id == t_id && temp->member.pw == t_pw) {    // 일치하는 회원이 있다면
            cout << temp->member.name << "님, 로그아웃되셨습니다 :-)" << endl << endl;
            break;              // for문 종료
        }
    }
    intro_in();     // 초기 화면 함수 실행
}

void joinMem() {    // 회원가입
    cout << "\t<   회   원   가   입   >" << endl;
    cout << "\t\t회원 가입을 선택하셨습니다." << endl;
    Node *temp = myAlloc();         // 새로운 노드를 생성
    cout << "이름을 입력해주세요 : ";
    cin >> temp->member.name;
    cout << "아이디를 입력해주세요 : ";
    cin >> temp->member.id;
    cout << "비밀번호를 입력해주세요 : ";
    cin >> temp->member.pw;
    // 새로운 노드를 기존 노드들에 연결
    temp->l_list = tail->l_list;
    tail->l_list = temp;
    temp->r_list = temp->l_list->r_list;
    temp->l_list->r_list = temp;
    cout << "~*~\t" << temp->member.name << "님, 회원 가입이 완료되었습니다!\t~*~" << endl << endl;

    intro_in();
}

void deleteMem() {  // 회원 탈퇴
    string t_name, t_id, t_pw;      // 회원 탈퇴 시 배열에 저장된 정보와의 일치 여부를 확인할 임시 변수들
    cout << "\t<   회   원   탈   퇴   >" << endl;
    cout << "\t\t회원 탈퇴를 선택하셨습니다." << endl;
    cout << "이름을 입력해주세요 : ";
    cin >> t_name;
    cout << "아이디를 입력해주세요 : ";
    cin >> t_id;
    cout << "비밀번호를 입력해주세요 : ";
    cin >> t_pw;

    // 새로운 노드 temp를 생성하여 head의 오른쪽 링크가 가리키게 한 다음, 마지막 요소가 될 때까지 차례대로 요소를 하나씩 옮기면서 반복
    for(Node *temp = head->r_list; temp != tail; temp = temp->r_list) {
        if(temp->member.name == t_name && temp->member.id == t_id && temp->member.pw == t_pw) {
            temp->r_list->l_list = temp->l_list;        // temp의 왼쪽 링크에 연결된 요소를 temp의 오른쪽 링크에 연결된 요소의 왼쪽 링크에 연결되게 함
            temp->l_list->r_list = temp->r_list;        // temp의 오른쪽 링크에 연결된 요소를 temp의 왼쪽 링크에 연결된 요소의 오른쪽 링크에 연결되게 함 --> 요소 삭제
            cout << "~*~\t" << temp->member.name << "님, 회원 탈퇴가 완료되었습니다!\t~*~" << endl << endl;
            break;      // for문 종료
        }
    }
    intro_in();
}

void point() {     // 포인트 충전
    int p = 0;
    cout << "\t<   포   인   트   충   전   >" << endl;
    cout << "\t\t포인트를 입력해주세요 : ";
    cin >> p;
    if(p > 0) {
        cout << "딜나(DN) 포인트가 " << p << "점 만큼 충전되었습니다." << endl;
        node[cur_index].member.po += p;     // 포인트 누적
        cout << "현재 " << node[cur_index].member.name << "님의 포인트는 ? " << endl;
        cout << (node[cur_index].member.po) << " 점입니다." << endl << endl;
    }
    intro_out();
};

void printBigMenu() {           // 음식의 대분류를 출력하는 함수
    cout << "1. 분식" << endl;
    cout << "2. 중식" << endl;
    cout << "3. 한식" << endl;
    cout << "4. 패스트푸드" << endl;
}

void choiceFood() {         // 사용자로부터 음식 종류의 선택을 받고 그에 맞는 함수를 실행하는 함수
    int choice;
    cout << "\t<   M   E   N   U   >" << endl;
    cout << "\t\t음식 종류를 선택해주세요 :-)" << endl;
    printBigMenu();     // 음식의 대분류를 출력
    cout << ">>>  ";
    cin >> choice;

    if (choice == 1) {      // 1. 분식
        choiceSnack();
    } else if (choice == 2) {   // 2. 중식
        choiceChineseFood();
    } else if (choice == 3) {   // 3. 한식
        choiceKoreanFood();
    } else if (choice == 4) {   // 4. 패스트푸드
        choiceFastFood();
    }
}

void chooseMoreOrNot() {        // 음식 선택이 끝난 후 더 고를 것인지를 묻는 함수
    int choice;
    cout << "음식을 더 고르시려면 1번, 주문하시려면 2번을 입력해주세요 :-)" << endl;
    cout << ">>>  ";
    cin >> choice;
    if (choice == 1) {
        choiceFood();
    } else {
        printOrderList();
    }
}

void printOrderList() {
    int choice;
    cout << node[cur_index].member.name << "님의 장바구니입니다 :-)" << endl;
    for (int i=stIndex; i < indexO; i++) {
        cout << node[cur_index].member.order[i].name << " : " << node[cur_index].member.order[i].count << "개" << endl;
    }
    cout << "주문하시겠다면 1번, 마이 페이지로 돌아가시려면 2번을 입력해주세요 :-)" << endl;
    cout << ">>>  ";
    cin >> choice;
    if (choice == 2) {      // 2번을 선택했을 경우
        cout << endl;
        intro_out();
    }
    else {      // 1번을 선택했을 경우
        cout << endl;
        setDeliveryInfo();
    }
}

void choiceSnack() {
    int chMenu[5] = {0};
    int indexM = 0;     // 메뉴 배열에서의 인덱스
    int choiceM;     // 사용자가 선택하는 메뉴 번호
    int choiceC;     // 사용자가 선택하는 음식 개수

    cout << "\t<   분   식   코   너   >" << endl;
    cout << "\t음식 종류를 선택해주세요 :-)" << endl;
    cout << "\t(최대 5개 / 중단하려면 -1)" << endl;
    cout << "1. 떡볶이" << endl;
    cout << "2. 김밥" << endl;
    cout << "3. 우동" << endl;
    cout << "4. 잔치국수" << endl;
    cout << "5. 돈까스" << endl;

    for(int i=0; i < 5; i++) {
        cout << ">>>  ";
        cin >> choiceM;
        if (choiceM == -1) {     // 사용자가 -1을 입력하면 종료
            cout << "종류 선택이 완료되었습니다 :-)" << endl << endl;
            break;
        }
        else    // 사용자의 입력이 -1이 아닐 경우
            chMenu[indexM++] = choiceM;
    }

    for(int i=0; i < indexM; i++) {
        if (chMenu[i] == 1) {
            node[cur_index].member.order[indexO].name = "떡볶이";
            cout << "떡볶이는 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 2) {
            node[cur_index].member.order[indexO].name = "김밥";
            cout << "김밥은 몇 줄로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 3) {
            node[cur_index].member.order[indexO].name = "우동";
            cout << "우동은 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 4) {
            node[cur_index].member.order[indexO].name = "잔치국수";
            cout << "잔치국수는 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else {
            node[cur_index].member.order[indexO].name = "돈까스";
            cout << "돈까스는 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        }
        indexO++;
    }
    chooseMoreOrNot();
}

void choiceChineseFood() {
    int chMenu[5] = {0};
    int indexM = 0;     // 메뉴 배열에서의 인덱스
    int choiceM;     // 사용자가 선택하는 메뉴 번호
    int choiceC;     // 사용자가 선택하는 음식 개수

    cout << "\t<   중   식   코   너   >" << endl;
    cout << "\t음식 종류를 선택해주세요 :-)" << endl;
    cout << "\t(최대 5개 / 중단하려면 -1)" << endl;
    cout << "1. 짜장면" << endl;
    cout << "2. 짬뽕" << endl;
    cout << "3. 탕수육" << endl;
    cout << "4. 마라탕" << endl;
    cout << "5. 해물우동" << endl;

    for(int i=0; i < 5; i++) {
        cout << ">>>  ";
        cin >> choiceM;
        if (choiceM == -1) {     // 사용자가 -1을 입력하면 종료
            cout << "종류 선택이 완료되었습니다 :-)" << endl << endl;
            break;
        }
        else    // 사용자의 입력이 -1이 아닐 경우
            chMenu[indexM++] = choiceM;
    }

    for(int i=0; i < indexM; i++) {
        if (chMenu[i] == 1) {
            node[cur_index].member.order[indexO].name = "짜장면";
            cout << "짜장면은 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 2) {
            node[cur_index].member.order[indexO].name = "짬뽕";
            cout << "짬뽕은 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 3) {
            node[cur_index].member.order[indexO].name = "탕수육";
            cout << "탕수육은 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 4) {
            node[cur_index].member.order[indexO].name = "마라탕";
            cout << "마라탕은 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else {
            node[cur_index].member.order[indexO].name = "해물우동";
            cout << "해물우동은 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        }
        indexO++;
    }
    chooseMoreOrNot();
}

void choiceKoreanFood() {
    int chMenu[5] = {0};
    int indexM = 0;     // 메뉴 배열에서의 인덱스
    int choiceM;     // 사용자가 선택하는 메뉴 번호
    int choiceC;     // 사용자가 선택하는 음식 개수

    cout << "\t<   한   식   코   너   >" << endl;
    cout << "\t음식 종류를 선택해주세요 :-)" << endl;
    cout << "\t(최대 5개 / 중단하려면 -1)" << endl;
    cout << "1. 보쌈" << endl;
    cout << "2. 제육볶음" << endl;
    cout << "3. 김치찌개" << endl;
    cout << "4. 콩나물불고기" << endl;
    cout << "5. 김치볶음밥" << endl;

    for(int i=0; i < 5; i++) {
        cout << ">>>  ";
        cin >> choiceM;
        if (choiceM == -1) {     // 사용자가 -1을 입력하면 종료
            cout << "종류 선택이 완료되었습니다 :-)" << endl << endl;
            break;
        }
        else    // 사용자의 입력이 -1이 아닐 경우
            chMenu[indexM++] = choiceM;
    }

    for(int i=0; i < indexM; i++) {
        if (chMenu[i] == 1) {
            node[cur_index].member.order[indexO].name = "보쌈";
            cout << "보쌈은 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 2) {
            node[cur_index].member.order[indexO].name = "제육볶음";
            cout << "제육볶음은 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 3) {
            node[cur_index].member.order[indexO].name = "김치찌개";
            cout << "김치찌개는 몇 그릇으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 4) {
            node[cur_index].member.order[indexO].name = "콩나물불고기";
            cout << "콩나물불고기는 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else {
            node[cur_index].member.order[indexO].name = "김치볶음밥";
            cout << "김치볶음밥은 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        }
        indexO++;
    }
    chooseMoreOrNot();
}

void choiceFastFood() {
    int chMenu[5] = {0};
    int indexM = 0;     // 메뉴 배열에서의 인덱스
    int choiceM;     // 사용자가 선택하는 메뉴 번호
    int choiceC;     // 사용자가 선택하는 음식 개수

    cout << "\t<   패   스   트   푸   드   코   너   >" << endl;
    cout << "\t음식 종류를 선택해주세요 :-)" << endl;
    cout << "\t(최대 5개 / 중단하려면 -1)" << endl;
    cout << "1. 햄버거" << endl;
    cout << "2. 감자튀김" << endl;
    cout << "3. 토스트" << endl;
    cout << "4. 닭꼬치" << endl;
    cout << "5. 타코야끼" << endl;

    for(int i=0; i < 5; i++) {
        cout << ">>>  ";
        cin >> choiceM;
        if (choiceM == -1) {     // 사용자가 -1을 입력하면 종료
            cout << "종류 선택이 완료되었습니다 :-)" << endl << endl;
            break;
        }
        else    // 사용자의 입력이 -1이 아닐 경우
            chMenu[indexM++] = choiceM;
    }

    for(int i=0; i < indexM; i++) {
        if (chMenu[i] == 1) {
            node[cur_index].member.order[indexO].name = "햄버거";
            cout << "햄버거는 몇 개로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 2) {
            node[cur_index].member.order[indexO].name = "감자튀김";
            cout << "감자튀김은 몇 봉지로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 3) {
            node[cur_index].member.order[indexO].name = "토스트";
            cout << "토스트는 몇 개로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else if (chMenu[i] == 4) {
            node[cur_index].member.order[indexO].name = "닭꼬치";
            cout << "닭꼬치 몇 개로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        } else {
            node[cur_index].member.order[indexO].name = "타코야끼";
            cout << "타코야끼는 몇 인분으로 할까요 ?" << endl;
            cout << ">>>  ";
            cin >> choiceC;
            node[cur_index].member.order[indexO].count = choiceC;
        }
        indexO++;
    }
    chooseMoreOrNot();
}

void setDeliveryInfo() {        // 주문 정보를 확인하고 배달/포장 여부를 선택해 주문을 완료하는 함수
    int choice;     // 사용자의 선택을 받는 정수형 변수
    string comment; // 사용자의 추가 요구사항을 받는 string형 변수
    srand((unsigned)time(NULL));    // 랜덤 함수 씨드 설정
    cout << node[cur_index].member.name << "님의 주문 목록입니다 :-)" << endl;
    for (int i=stIndex; i < indexO; i++) {
        // 현재 주문 목록 출력
        cout << node[cur_index].member.order[i].name << " : " << node[cur_index].member.order[i].count << "개" << endl;
    }

    cout << endl << "배달을 선택하시려면 1번, 포장을 선택하시려면 2번을 입력해주세요 :-)" << endl;
    cout << ">>>  ";
    cin >> choice;
    if (choice == 1) {
        cout << "배달을 선택하셨습니다." << endl;
    } else {
        cout << "포장을 선택하셨습니다." << endl;
    }

    cout << endl << "추가 요구 사항이 있으신가요 ? (Yes: 1 / No: 2)" << endl;
    cout << ">>>  ";
    cin >> choice;
    if (choice == 1) {
        cout << "추가 요구사항을 입력해주세요 :-)" << endl;
        cin.ignore();
        getline(cin, comment);
        cout << "요구사항이 저장되었습니다 :-)" << endl;
        cout << "*~ *~ 총 예상 소요 시간을 계산하는 중입니다 ~* ~*" << endl;
        cout << ". . . . . . . . . . . . . . . . . . . . " << endl;
        cout << "*~ *~ 총 예상 소요 시간을 계산하는 중입니다 ~* ~*" << endl;
        cout << ". . . . . . . . . . . . . . . . . . . . " << endl;
        cout << "*~ *~ 총 예상 소요 시간을 계산하는 중입니다 ~* ~*" << endl << endl;
    } else {
        cout << "*~ *~ 총 예상 소요 시간을 계산하는 중입니다 ~* ~*" << endl;
        cout << ". . . . . . . . . . . . . . . . . . . . " << endl;
        cout << "*~ *~ 총 예상 소요 시간을 계산하는 중입니다 ~* ~*" << endl;
        cout << ". . . . . . . . . . . . . . . . . . . . " << endl;
        cout << "*~ *~ 총 예상 소요 시간을 계산하는 중입니다 ~* ~*" << endl << endl;
    }

    cout << "총 예상 소요 시간은 " << (rand() % 61) + 20 << " 분입니다." << endl;
    if (choice == 1) cout << "추가 요구 사항은 \"" << comment << "\"입니다." << endl;
    cout << "주문이 완료되었습니다." << endl;
    cout << "또 다른 추가 주문을 원하시면 1번, 나의 주문을 확인하고 싶으시다면 2번, 프로그램을 종료하고 싶으시다면 3번을 입력해주세요 :-)" << endl;
    cout << ">>>  ";
    cin >> choice;
    if (choice == 1) {  // 추가 주문
        cout << "주문 페이지로 넘어갑니다." << endl << endl;   // 멘트 출력
        // 음식을 선택하는 함수로 넘어감
        choiceFood();
    } else if (choice == 2) {   // 나의 주문 확인하기
        cout << "나의 주문을 확인하러 가는 중입니다 :-)" << endl;
        cout << ". . . . . . . . . . . . . . . " << endl;
        cout << "나의 주문을 확인하러 가는 중입니다 :-)" << endl;
        cout << ". . . . . . . . . . . . . . . " << endl;
        cout << "나의 주문을 확인하러 가는 중입니다 :-)" << endl << endl;
        viewMyOrder();
    } else {    // 프로그램 종료
        cout << "프로그램을 종료합니다." << endl;
        cout << "이용해주셔서 감사합니다 :-)" << endl;
        return;
    }
}

void viewMyOrder() {
    int choice;
    if (indexO == 0) {
        cout << "현재 주문 목록이 없습니다." << endl;
    } else {
        cout << node[cur_index].member.name << "님의 주문 목록입니다." << endl;
        for (int i = stIndex; i < indexO; i++) {
            cout << "[ " << node[cur_index].member.order[i].name << " : " << node[cur_index].member.order[i].count << " ]" << endl;
        }
        stIndex = indexO;
    }
    cout << "----------------------------------------" << endl;
    cout << "마이 페이지로 돌아가시려면 1번, 프로그램을 종료하고 싶으시다면 2번을 눌러주세요 :-)" << endl;
    cout << ">>>  ";
    cin >> choice;
    if (choice == 1) {
        intro_out();
    } else {
        cout << endl << "프로그램이 종료되었습니다 :-)" << endl;
        return;
    }
}
