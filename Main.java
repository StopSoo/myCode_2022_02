import java.util.Scanner;   // 사용자로부터 입력을 받기 위해 Scanner를 포함시킴

class Student {		// 학생의 정보를 받을 클래스 Student
    String name;	// 학생의 이름
    String number;	// 학생의 학번
    String major;   // 학생의 전공

    public Student() {  // 생성자를 통해 각 멤버 변수를 초기화
        name = "";
        number = "";
        major = "컴퓨터공학과";		// 학생의 전공은 '컴퓨터공학과'로 고정
    }
}

class Professor {	// 교수의 정보를 받을 클래스 Professor
    String name;	// 교수의 이름
    String subject;	// 교수의 수업 과목
    String[] place = new String[2];	// 교수의 수업 장소 --> 분반이 2개라 2개씩 할당시킴

    public Professor() {    // 생성자를 통해 각 멤버 변수를 초기화
        name = "";
        subject = "";
        place[0] = "";
        place[1] = "";
    }
}

class TimeTable {	// 학생이 수강 신청한 수업 정보를 담을 클래스 timeTable
    String [] name = new String[3];     // 수업 교수님의 성함을 담을 배열 name
    String [] subject = new String[3];  // 수업 과목의 이름을 담을 배열 subject
    String [] place = new String[3];    // 수업 과목의 강의실 장소를 담을 배열 place

    public TimeTable() {    // 생성자를 통해 각 멤버 변수를 초기화
        name[0] = "";
        name[1] = "";
        name[2] = "";
        subject[0] = "";
        subject[1] = "";
        subject[2] = "";
        place[0] = "";
        place[1] = "";
        place[2] = "";
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);    // 사용자로부터 입력을 받기 위해 Scanner 생성
        while (true) {
            // 학생 객체 배열을 선언하고, 각 객체의 멤버 변수들을 초기화함.
            Student[] student = new Student[10];
            for (int i = 0; i < student.length; i++) {    // 클래스 초기화
                student[i] = new Student();
            }
            student[0].name = "공유";
            student[0].number = "01234567";
            student[1].name = "박서준";
            student[1].number = "12345670";
            student[2].name = "박보검";
            student[2].number = "23456701";
            student[3].name = "이준기";
            student[3].number = "34567012";
            student[4].name = "고경표";
            student[4].number = "45670123";
            student[5].name = "김고은";
            student[5].number = "56701234";
            student[6].name = "문채원";
            student[6].number = "67012345";
            student[7].name = "공효진";
            student[7].number = "70123456";
            student[8].name = "김유정";
            student[8].number = "12345678";
            student[9].name = "김혜수";
            student[9].number = "23456781";

            // 교수 객체 배열을 선언하고, 각 객체의 멤버 변수들을 초기화함.
            Professor[] professor = new Professor[3];
            for (int i = 0; i < professor.length; i++) {    // 클래스 초기화
                professor[i] = new Professor();
            }
            professor[0].name = "도경수";
            professor[0].subject = "객체지향언어";
            professor[0].place[0] = "혜화관 1호";
            professor[0].place[1] = "혜화관 2호";
            professor[1].name = "남지현";
            professor[1].subject = "자료구조";
            professor[1].place[0] = "명진관 1호";
            professor[1].place[1] = "명진관 2호";
            professor[2].name = "지창욱";
            professor[2].subject = "운영체제";
            professor[2].place[0] = "학림관 1호";
            professor[2].place[1] = "학림관 2호";

            // 수강 신청할 학생의 정보를 입력 받음.
            int index = 0;    // 수강신청하는 학생의 배열 인덱스를 담을 변수
            System.out.println("\t*~ *~ 수강 신청 프로그램 ~* ~*"); // 기본 멘트 출력
            System.out.print("* 수강 신청을 진행할 학생의 학번을 입력하세요: ");
            String tempNum = in.nextLine();        // 학번을 입력 받음.
            for (int i = 0; i < 10; i++) {    // 해당 학번에 일치하는 학생을 찾음.
                if (tempNum.equals(student[i].number)) {
                    index = i;
                    break;
                }
            }
            System.out.println("* " + student[index].name + "님의 수강 신청 화면입니다."); // 기본 멘트 출력
            System.out.print("* 학번을 입력해주세요 : ");
            tempNum = in.nextLine();        // 학번을 입력 받음.
            if (!tempNum.equals(student[index].number)) {    // 이름에 맞는 학번이 일치하지 않는다면
                System.out.println("* 학번이 일치하지 않습니다.");    // 경고 멘트를 출력
                System.out.println("* 초기 화면으로 넘어갑니다.");    // 화면 전환 안내 멘트를 출력
                System.out.println();   // 한 줄 개행
                continue;   // 다음 반복으로 넘어감
            }
            System.out.println("* 학번이 일치합니다. 수강 신청 화면으로 넘어갑니다.");    // 학번 일치를 알리는 멘트를 출력
            System.out.println();

            System.out.println("* " + student[index].name + "님의 수강 신청 가능한 강의 목록입니다.");  // 기본 멘트 출력
            for (int i = 0; i < 3; i++) {   // 학생이 수강 신청한 과목의 정보를 출력
                System.out.println((i + 1) + ". 교수: " + professor[i].name + ", 과목: " + professor[i].subject + ", 장소: " + professor[i].place[0] + " / " + professor[i].place[1]);
            }
            System.out.println();   // 한 줄 개행

            // 학생의 수강 신청 정보를 담을 배열을 선언
            TimeTable[] timetable = new TimeTable[10];
            for (int i = 0; i < timetable.length; i++) {    // 클래스 초기화
                timetable[i] = new TimeTable();
            }
            // 수강 신청 진행
            int classIndex = 0; // 학생이 수강 신청한 수업을 담을 배열의 인덱스를 선언하고 초기화
            while (classIndex < 3) {    // 최대 3개의 수업 신청 가능
                System.out.print("* 수강 신청하려는 과목의 번호를 입력하세요: "); // 기본 멘트 출력
                int tempClass = in.nextInt();   // 정수를 입력 받고 변수에 담음
                if (tempClass == 1) {   // 첫 번째 수업을 선택했을 경우
                    System.out.print("* 혜화관 1호 / 2호 중 하나를 선택해주세요 (1 or 2 입력): ");
                    int tempPlace = in.nextInt();   // 강의실 번호를 입력 받음
                    // 수업 정보를 학생이 수강 신청한 수업을 담는 배열에 차례대로 담음
                    timetable[index].name[classIndex] = professor[0].name;
                    timetable[index].subject[classIndex] = professor[0].subject;
                    if (tempPlace == 1)
                        timetable[index].place[classIndex] = professor[0].place[0];
                    else
                        timetable[index].place[classIndex] = professor[0].place[1];
                    System.out.println(professor[0].name + " 교수님의 " + professor[0].subject + " 과목 수강 신청이 완료되었습니다.");
                } else if (tempClass == 2) {    // 두 번째 수업을 선택했을 경우
                    System.out.print("* 명진관 1호 / 2호 중 하나를 선택해주세요 (1 or 2 입력): ");
                    int tempPlace = in.nextInt();   // 강의실 번호를 입력 받음
                    // 수업 정보를 학생이 수강 신청한 수업을 담는 배열에 차례대로 담음
                    timetable[index].name[classIndex] = professor[1].name;
                    timetable[index].subject[classIndex] = professor[1].subject;
                    if (tempPlace == 1)
                        timetable[index].place[classIndex] = professor[1].place[0];
                    else
                        timetable[index].place[classIndex] = professor[1].place[1];
                    System.out.println(professor[1].name + " 교수님의 " + professor[1].subject + " 과목 수강 신청이 완료되었습니다.");
                } else {    // 세 번째 수업을 선택했을 경우
                    System.out.print("* 학림관 1호 / 2호 중 하나를 선택해주세요 (1 or 2 입력): ");
                    int tempPlace = in.nextInt();   // 강의실 번호를 입력 받음
                    // 수업 정보를 학생이 수강 신청한 수업을 담는 배열에 차례대로 담음
                    timetable[index].name[classIndex] = professor[2].name;
                    timetable[index].subject[classIndex] = professor[2].subject;
                    if (tempPlace == 1)
                        timetable[index].place[classIndex] = professor[2].place[0];
                    else
                        timetable[index].place[classIndex] = professor[2].place[1];
                    System.out.println(professor[2].name + " 교수님의 " + professor[2].subject + " 과목 수강 신청이 완료되었습니다.");
                }

                System.out.print("* 수강신청을 계속하시겠습니까(Yes: 1, No: 2)? : ");    // 추가 수강 신청 여부를 받음
                int answer = in.nextInt();
                if (answer == 2)    // No를 선택했을 경우
                    break;  // while문 종료
                else    // Yes를 선택했을 경우
                    classIndex++;   // 학생이 선택한 수업의 개수를 1 증가시킴
            }
            System.out.println();   // 한 줄 개행

            // 수강 신청 목록 출력하기
            System.out.println("[ " + student[index].name + ", " + student[index].number + ", " + student[index].major + " ] 님의 수강 신청 목록입니다.");
            for (int i = 0; i <= classIndex; i++) {
                System.out.println("교수: " + timetable[index].name[i] + ", 과목: " + timetable[index].subject[i] + ", 장소: " + timetable[index].place[i]);
            }
            System.out.println();   // 한 줄 개행

            System.out.print("* 다른 학생의 수강 신청을 원하시면 1번, 프로그램을 종료하시려면 2번을 눌러주세요: ");  // 추가 수강 신청 여부 or 프로그램 종료 여부를 받음
            int choice = in.nextInt();  // 정수를 입력 받고 변수에 담음
            if (choice == 2) {  // 프로그램 종료 선택 시
                System.out.println("* 프로그램을 종료합니다.");   // 기본 멘트 출력
                break;  // 전체 while문 종료
            }
            // 다른 학생의 수강 신청 선택 시
            System.out.println("* 수강 신청 화면으로 넘어갑니다.");
            System.out.println();
        }
    }
}