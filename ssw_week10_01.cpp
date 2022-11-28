#include <iostream>             // 기본 입출력 라이브러리
#include <fstream>              // 파일 입출력을 위한 fstream
#include <sstream>              // ostringstream을 사용하기 위한 sstream
using namespace std;            // 이름 공간으로 std 선언

class store {                   // 클래스 store
public:                         // 접근 지정자 public
    string label[12];           // label을 저장할 string형 배열 label
    string opcode[12];          // opcode를 저장할 string형 배열 opcode
    string operand[12];         // operand를 저장할 string형 배열 operand
    int hexlocctr[12];          // locctr의 16진수 형태를 저장할 int형 배열 hexlocctr
    string objectCode[12];      // 최종 오브젝트 코드를 저장할 string형 배열
};

int main() {
    /*--- optab.txt 파일에서 instruction과 code 분리해서 배열에 저장하기 ---*/
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
    string fileName;// 사용자로부터 입력 받는 파일 이름을 담을 string형 변수 fileName 선언
    int k = 0;      // 배열들의 인덱스 k를 선언하고 0으로 초기화
    string op;      // 분리된 operand를 담을 string형 변수 op를 선언
    string line;    // 파일을 한 줄 단위로 받아 오기 위한 string형 변수 line 선언
    do {
        cout << "파일 이름 입력: ";       // 사용자로부터 파일 이름을 입력 받음
        getline(cin, fileName);
        if (fileName != "SRCFILE")    // 사용자로부터 받은 파일 이름이 "SRCFILE"이 아니라면 해당 멘트를 출력
            cout << "[Error] '" << fileName << "' File Not Found" << endl;
    } while (fileName != "SRCFILE");
    ifstream readFile2;          // 파일 입력을 위한 클래스 선언
    readFile2.open("/Users/jisoojeong/Desktop/SRCFILE");       // 해당 경로에 있는 파일을 열기

    while(!readFile2.eof()) {
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
        if (i > 1 && i < 10)
            arr.hexlocctr[i] = arr.hexlocctr[i-1] + 3;
        else if (i == 10 || i == 11)    // 크기가 5 바이트인 경우
            arr.hexlocctr[i] = arr.hexlocctr[i-1] + 5;
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
    int ch1 = 'h';
    int ch2 = 'e';
    int ch3 = 'l';
    int ch4 = 'l';
    int ch5 = 'o';
    // 아스키코드로 바꿔서 저장
    ss << hex << ch1;   // 'h' 아스키 코드로 저장
    temp += ss.str();
    ss.str("");
    ss.clear();
    ss << hex << ch2;   // 'e' 아스키 코드로 저장
    temp += ss.str();
    ss.str("");
    ss.clear();
    ss << hex << ch3;   // 'l' 아스키 코드로 두 번 저장
    temp += ss.str();
    temp += ss.str();
    ss.str("");
    ss.clear();
    ss << hex << ch5;   // 'o' 아스키 코드로 저장
    temp += ss.str();
    ss.str("");
    ss.clear();

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


    /*--- objfile 출력 ---*/
    for (int i=0; i < arr.label[0].size(); i++) {       // 프로그램 이름 대문자로 변경
        arr.label[0][i] = toupper(arr.label[0][i]);
    }
    for (int i=0; i < 12; i++) {                        // objectCode 배열 원소들을 모두 대문자로 변경
         for (int j=0; j < arr.objectCode[i].size(); j++) {
            arr.objectCode[i][j] = toupper(arr.objectCode[i][j]);
        }
    }

    ofstream writeFile;         // 파일 작성을 위한 클래스 선언
    writeFile.open("OBJFILE.txt", ios::out);        // 해당 이름의 파일을 생성 후 열기
    if(writeFile.is_open()) {   // 해당 파일이 열린다면 아래 내용을 파일에 작성
        // 첫 번째 줄 출력
        writeFile << "H" << arr.label[0] << "  00" << hex << arr.hexlocctr[0];  // H 레코드와 시작 주소를 포맷에 맞게 출력
        ss << hex << (arr.hexlocctr[11] - arr.hexlocctr[0]); // 프로그램 길이를 16진수로 계산해서 ss에 저장
        writeFile << ss.str() << endl;  // ss에 있는 내용을 string형으로 변환해서 파일에 출력
        ss.str(""); // 스트림 버퍼에 있는 내용 지우기
        ss.clear();
        // 두 번째 줄 출력
        writeFile << "T00" << hex << arr.hexlocctr[0];  // T 레코드와 시작 주소를 포맷에 맞게 출력
        ss << hex << (arr.hexlocctr[9] - arr.hexlocctr[1]); // 프로그램 길이를 16진수로 계산해서 ss에 저장
        writeFile << ss.str();  // ss에 있는 내용을 string형으로 변환해서 파일에 출력
        for(int i=1; i < 10; i++) { // for문을 반복하며 object code를 출력
            writeFile << arr.objectCode[i];
        }
        // 세 번째 줄 출력
        writeFile << endl << "E00" << arr.hexlocctr[0] << endl; // E 레코드와 시작 주소를 포맷에 맞게 출력
    }
    writeFile.close();           // 읽은 파일을 닫음
    return 0;       // 0을 반환하고 프로그램 종료
}