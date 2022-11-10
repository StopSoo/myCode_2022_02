#include <iostream>             // 기본 입출력 라이브러리
#include <fstream>              // 파일 입출력을 위한 fstream
using namespace std;            // 이름 공간으로 std 선언

int main() {
    string instruction[14];     // instruction을 담을 string형 배열
    string code[14];            // code를 담을 string형 배열
    ifstream readFile;          // 파일 입력을 위한 클래스 선언
    readFile.open("/Users/jisoojeong/Desktop/optab.txt");       // 해당 경로에 있는 파일을 열기

    int i=0, j=0;               // 분리된 문자열의 인덱스를 위한 정수형 변수 i, j 선언 후 0으로 초기화
    string word;                // 분리된 문자열을 담을 word
    while(!readFile.eof()) {    // 해당 파일이 끝(EOF)이 아닐 경우
        readFile >> word;       // 한 줄을 읽어서 word에 담음
        if(i%2 == 0) {          // word가 짝수 번째 문자열이라면
            instruction[j] = word;      // word를 instruction 배열의 j번째 공간에 담음
        } else {                // word가 홀수 번째 문자열이라면
            code[j++] = word;   // word를 code 배열의 j번째 공간에 담고 j 값을 1 증가시킴
        }
        i++;                    // 한 번 반복할 때마다 i를 증가시킴
    }
    readFile.close();           // 읽은 파일을 닫음

    while(1) {                  // 무한 반복
        string input;           // 사용자가 입력한 instruction을 담을 문자열 변수 input을 선언
        int fIndex = -1;         // 사용자가 입력한 문자열과 일치하는 instruction의 인덱스를 담기 위한 fIndex 선언 및 초기화
        cout << "instruction : ";       // 사용자의 입력을 받기 위한 멘트 출력
        cin >> input;           // 문자열 input에 사용자의 입력을 받음

        // for문을 수행하여 instruction 배열에서 사용자의 입력과 일치하는 문자열을 찾아 그 인덱스를 fIndex에 대입함
        for(int i=0; i<14; i++) {
            if(input.compare(instruction[i]) == 0)
                fIndex = i;
        }
        if(fIndex == -1) {      // 배열 instruction 내에 사용자가 입력한 문자열이 존재하지 않을 경우
            cout << "잘못된 instruction을 입력하셨습니다." << endl;        // 에러 메시지를 출력
            continue;           // 다음 루프로 넘어감
        }
        cout << "code: " << code[fIndex] << endl;      // code 배열에서 해당 인덱스를 가진 문자열을 멘트와 함께 출력함
    }
}
