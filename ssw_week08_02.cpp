#include <iostream>             // 기본 입출력 라이브러리
#include <fstream>              // 파일 입출력을 위한 fstream
using namespace std;            // 이름 공간 std 선언

class store {                   // 클래스 store
public:                         // 접근 지정자 public
    string label[12];           // label을 저장할 string형 배열 label
    string opcode[12];          // opcode를 저장할 string형 배열 opcode
    string operand[12];         // operand를 저장할 string형 배열 operand
};

int main() {
    ifstream readFile;          // 파일 입력을 위한 클래스 선언
    readFile.open("/Users/jisoojeong/Desktop/SRCFILE");       // 해당 경로에 있는 파일을 열기

    store arr;      // 클래스 store형의 객체 arr 선언
    int i = 0;      // 배열들의 인덱스 i를 선언하고 0으로 초기화
    string op;      // 분리된 operand를 담을 string형 변수 op를 선언
    string line;    // 파일을 한 줄 단위로 받아 오기 위한 string형 변수 line 선언
    while (!readFile.eof()) {    // 해당 파일이 끝(EOF)이 아닐 경우
        getline(readFile, line); // 한 줄을 받아옴

        arr.label[i] = line.substr(0, 9);   // 한 줄에서 인덱스 0번부터 글자 9개를 잘라, 객체 arr의 멤버 변수 label의 i번째 원소에 대입
        if(i == 2 || i == 4 || i == 5 || i == 6 || i == 11)     // 만약 i가 2,4,5,6,11일 경우
            arr.label[i] = "-\t\t";     // 원소를 주어진 문자열로 변경
        arr.opcode[i] = line.substr(9, 7);  // 한 줄에서 인덱스 9번부터 글자 7개를 잘라, 객체 arr의 멤버 변수 opcode의 i번째 원소에 대입
        op = line.substr(17);      // 한 줄에서 인덱스 17번부터 끝까지 잘라, string형 변수 op에 대입
        arr.operand[i++] = op;          // op에 저장된 문자열을 객체 arr의 멤버 변수 operand의 i번째 원소에 대입
    }
    readFile.close();           // 읽은 파일을 닫음

    for (int i = 0; i < 12; i++) {      // for문을 12번 반복하며 아래 배열 원소들을 출력
        cout << "Label: " << arr.label[i] << ",Opcode: " << arr.opcode[i] << ",Operand: " << arr.operand[i] << endl;
    }

    return 0;
}
