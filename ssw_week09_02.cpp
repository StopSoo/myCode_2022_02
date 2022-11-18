#include <iostream>             // 기본 입출력 라이브러리
#include <fstream>              // 파일 입출력을 위한 fstream
#include <string>
#include <sstream>
#include <cctype>
using namespace std;            // 이름 공간 std 선언

class store {                   // 클래스 store
public:                         // 접근 지정자 public
    string label[12];           // label을 저장할 string형 배열 label
    string opcode[12];          // opcode를 저장할 string형 배열 opcode
    string operand[12];         // operand를 저장할 string형 배열 operand
    int hexlocctr[12];          // locctr의 16진수 형태를 저장할 int형 배열 hexlocctr
    string objectCode[12];      // 최종 오브젝트 코드를 저장할 string형 배열
};

int main() {
    /*--- optab.txt 파일에서 instruction과 code 분리해서 배열에 저장하기 (OK)---*/
    string instruction[14];     // instruction을 담을 string형 배열
    string code[14];            // code를 담을 string형 배열

    ifstream readFile1;          // 파일 입력을 위한 클래스 선언
    readFile1.open("/Users/jisoojeong/Desktop/optab.txt");       // 해당 경로에 있는 파일을 열기

    int i=0, j=0;               // 분리된 문자열의 인덱스를 위한 정수형 변수 i, j 선언 후 0으로 초기화
    string word;                // 분리된 문자열을 담을 word
    while(!readFile1.eof()) {    // 해당 파일이 끝(EOF)이 아닐 경우
        readFile1 >> word;       // 한 줄을 읽어서 word에 담음
        if(i%2 == 0) {          // word가 짝수 번째 문자열이라면
            instruction[j] = word;      // word를 instruction 배열의 j번째 공간에 담음
        } else {                // word가 홀수 번째 문자열이라면
            code[j++] = word;   // word를 code 배열의 j번째 공간에 담고 j 값을 1 증가시킴
        }
        i++;                    // 한 번 반복할 때마다 i를 증가시킴
    }
    readFile1.close();           // 읽은 파일을 닫음

    /*--- SRCFILE 파일에서 label, opcode, operand 분리해서 배열에 저장하기 ---*/
    store arr;      // 클래스 store형의 객체 arr 선언
    ifstream readFile2;          // 파일 입력을 위한 클래스 선언
    readFile2.open("/Users/jisoojeong/Desktop/SRCFILE");       // 해당 경로에 있는 파일을 열기

    int k = 0;      // 배열들의 인덱스 k를 선언하고 0으로 초기화
    string op;      // 분리된 operand를 담을 string형 변수 op를 선언
    string line;    // 파일을 한 줄 단위로 받아 오기 위한 string형 변수 line 선언
    while (!readFile2.eof()) {    // 해당 파일이 끝(EOF)이 아닐 경우
        int nPos;
        getline(readFile2, line); // 한 줄을 받아옴

        arr.label[k] = line.substr(0, 9);   // 한 줄에서 인덱스 0번부터 글자 9개를 잘라, 객체 arr의 멤버 변수 label의 i번째 원소에 대입
        nPos = arr.label[k].find_last_not_of(' ');
        arr.label[k].erase(nPos+1);
        if(k == 2 || k == 4 || k == 5 || k == 6 || k == 11)     // 만약 i가 2,4,5,6,11일 경우
            arr.label[k] = "-\t";     // 원소를 주어진 문자열로 변경

        arr.opcode[k] = line.substr(9, 7);  // 한 줄에서 인덱스 9번부터 글자 7개를 잘라, 객체 arr의 멤버 변수 opcode의 i번째 원소에 대입
        nPos = arr.opcode[k].find_last_not_of(' ');
        arr.opcode[k].erase(nPos+1);

        op = line.substr(17);      // 한 줄에서 인덱스 17번부터 끝까지 잘라, string형 변수 op에 대입
        arr.operand[k] = op;          // op에 저장된 문자열을 객체 arr의 멤버 변수 operand의 i번째 원소에 대입
        nPos = arr.operand[k].find_last_not_of(' ');
        arr.operand[k].erase(nPos+1);
        k++;
    }
    readFile2.close();           // 읽은 파일을 닫음

    /*--- opcode의 모든 문자들을 대문자로 바꿈 ---*/
    string tempOpcode[12];
    for (int l=0; l<12; l++) {
        for (int n=0; n < arr.opcode[l].size(); n++) {
            tempOpcode[l] += toupper(arr.opcode[l][n]);
        }
    }

    /*--- locctr 설정하기 ---*/
    arr.hexlocctr[0] = 4096;    // 배열 hexlocctr의 인덱스 0번째 원소를 초기화
    for (int i=0; i<12; i++) {
        if (i > 1)
            arr.hexlocctr[i] = arr.hexlocctr[i-1] + 3;
        else
            arr.hexlocctr[1] = arr.hexlocctr[0];
    }

    /*--- objectCode 배열 채우기 ---*/
    string stAlpha = "alpha";
    string stWord = "WORD";
    string stByte = "BYTE";
    arr.objectCode[0] = "X";
    ostringstream ss;
    // instruction에 맞는 code 추가하기
    for(int i=1; i<7; i++) {
        for (int j = 0; j < 14; j++) {
            if (tempOpcode[i].compare(instruction[j]) == 0) {
                arr.objectCode[i] = code[j];
                break;
            } else
                arr.objectCode[i] = "X";
        }
    }
    // address로 objectCode 배열 완성하기
    for(i=1; i<7; i++) {
        if (i == 1) {
            ss << hex << arr.hexlocctr[7];
            arr.objectCode[i] += ss.str();
            ss.str("");
            ss.clear();
        }
        else if (i == 3) {
            ss << hex << arr.hexlocctr[9];
            arr.objectCode[i] += ss.str();
            ss.str("");
            ss.clear();
        } else if (i == 4) {
            ss << hex << arr.hexlocctr[10];
            arr.objectCode[i] += ss.str();
            ss.str("");
            ss.clear();
        } else {
            for (j = 0; j < 12; j++) {
                if (arr.operand[i].compare(arr.label[j]) == 0) {
                    ss << hex << arr.hexlocctr[j];
                    arr.objectCode[i] += ss.str();
                    ss.str("");
                    ss.clear();
                    break;
                }
            }
        }
    }

    /*--- byte 자리의 address 구하기 ---*/
    string temp = "";
    int ch1 = 'h'-36;
    int ch2 = 'e'-36;
    int ch3 = 'l'-36;
    int ch4 = 'l'-36;
    int ch5 = 'o'-36;
    temp += to_string(ch1);
    temp += to_string(ch2);
    temp += to_string(ch3);
    temp += to_string(ch4);
    temp += to_string(ch5);

    // address로 objectCode 배열 완성하기
    for(i=7; i<12; i++) {
        if (tempOpcode[i].compare(stWord) == 0) {
            if (arr.label[i] == stAlpha)
                arr.objectCode[i] = "000005";
            else
                arr.objectCode[i] = "000000";
        }
        else if (tempOpcode[i].compare(stByte) == 0)
            arr.objectCode[i] = temp;
        else
            arr.objectCode[i] = "X";
    }

    /*--- 테이블 출력하기 ---*/
    cout << hex << arr.hexlocctr[0] << "\t" << arr.objectCode[0] << "\t\t\t" << arr.label[0] << "\t " << arr.opcode[0] << "\t" << arr.operand[0] << endl;
    for (k=1; k<9; k++) {
        cout << hex << arr.hexlocctr[k] << "\t" << arr.objectCode[k] << "\t\t" << arr.label[k] << "\t " << arr.opcode[k] << "\t" << arr.operand[k] << endl;
    }
    cout << hex << arr.hexlocctr[9] << "\t" << arr.objectCode[9] << "\t" << arr.label[9] << "\t " << arr.opcode[9] << "\t" << arr.operand[9] << endl;
    for (k=10; k<12; k++) {
        cout << hex << arr.hexlocctr[k] << "\t" << arr.objectCode[k] << "\t\t\t" << arr.label[k] << "\t " << arr.opcode[k] << "\t" << arr.operand[k] << endl;
    }

    return 0;       // 0을 반환하고 프로그램 종료
}
