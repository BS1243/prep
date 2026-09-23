#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


// 함수 선언
int add(int a, int b);


// 클래스 예시
class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void introduce() {
        cout << "이름: " << name << '\n';
        cout << "나이: " << age << '\n';
    }
};


int main() {

    // =========================
    // 1. 출력
    // =========================

    cout << "Hello World!" << '\n';
    cout << "C++ 시작!" << '\n';


    // =========================
    // 2. 변수
    // =========================

    int number = 10;

    double decimal = 3.14;

    float f = 1.5f;

    char character = 'A';

    string text = "Hello";

    bool isTrue = true;


    cout << number << '\n';
    cout << decimal << '\n';
    cout << character << '\n';
    cout << text << '\n';
    cout << isTrue << '\n';


    // =========================
    // 3. 입력
    // =========================

    int inputNumber;

    cout << "숫자를 입력하세요: ";
    cin >> inputNumber;

    cout << "입력한 숫자: "
         << inputNumber
         << '\n';


    // =========================
    // 4. 문자열 입력
    // =========================

    string name;

    cout << "이름 입력: ";
    cin >> name;

    cout << "안녕하세요 "
         << name
         << "!\n";


    // 공백 포함 문자열
    cin.ignore();

    string sentence;

    cout << "문장 입력: ";

    getline(cin, sentence);

    cout << sentence << '\n';


    // =========================
    // 5. 연산자
    // =========================

    int a = 10;
    int b = 3;

    cout << a + b << '\n';
    cout << a - b << '\n';
    cout << a * b << '\n';
    cout << a / b << '\n';
    cout << a % b << '\n';


    // =========================
    // 6. 조건문 if
    // =========================

    int score = 85;

    if (score >= 90) {

        cout << "A\n";

    }
    else if (score >= 80) {

        cout << "B\n";

    }
    else {

        cout << "C 이하\n";

    }


    // =========================
    // 7. switch
    // =========================

    int menu = 2;

    switch (menu) {

        case 1:
            cout << "1번 메뉴\n";
            break;

        case 2:
            cout << "2번 메뉴\n";
            break;

        case 3:
            cout << "3번 메뉴\n";
            break;

        default:
            cout << "잘못된 메뉴\n";
            break;
    }


    // =========================
    // 8. for 반복문
    // =========================

    for (int i = 0; i < 5; i++) {

        cout << i << '\n';

    }


    // =========================
    // 9. while 반복문
    // =========================

    int count = 0;

    while (count < 5) {

        cout << count << '\n';

        count++;
    }


    // =========================
    // 10. do while
    // =========================

    int n = 0;

    do {

        cout << n << '\n';

        n++;

    } while (n < 3);


    // =========================
    // 11. 배열
    // =========================

    int arr[5] = {
        10,
        20,
        30,
        40,
        50
    };

    cout << arr[0] << '\n';


    for (int i = 0; i < 5; i++) {

        cout << arr[i] << ' ';

    }

    cout << '\n';


    // =========================
    // 12. range based for
    // =========================

    for (int value : arr) {

        cout << value << ' ';

    }

    cout << '\n';


    // =========================
    // 13. vector
    // =========================

    vector<int> numbers = {
        5,
        2,
        8,
        1,
        3
    };


    numbers.push_back(10);


    cout << "vector 크기: "
         << numbers.size()
         << '\n';


    for (int value : numbers) {

        cout << value << ' ';

    }

    cout << '\n';


    // =========================
    // 14. 정렬
    // =========================

    sort(
        numbers.begin(),
        numbers.end()
    );


    for (int value : numbers) {

        cout << value << ' ';

    }

    cout << '\n';


    // =========================
    // 15. 함수
    // =========================

    int result = add(10, 20);

    cout << "함수 결과: "
         << result
         << '\n';


    // =========================
    // 16. 참조
    // =========================

    int original = 10;

    int& reference = original;

    reference = 20;

    cout << original << '\n';


    // =========================
    // 17. 포인터
    // =========================

    int value = 100;

    int* ptr = &value;

    cout << "value: "
         << value
         << '\n';

    cout << "주소: "
         << ptr
         << '\n';

    cout << "포인터가 가리키는 값: "
         << *ptr
         << '\n';


    // =========================
    // 18. 구조체
    // =========================

    struct Student {

        string name;

        int age;

    };


    Student student;

    student.name = "티티";

    student.age = 20;


    cout << student.name << '\n';

    cout << student.age << '\n';


    // =========================
    // 19. 클래스
    // =========================

    Person person(
        "티티",
        20
    );

    person.introduce();


    // =========================
    // 20. map
    // =========================

    map<string, int> scores;

    scores["Alice"] = 90;

    scores["Bob"] = 80;


    cout << scores["Alice"]
         << '\n';


    // =========================
    // 21. set
    // =========================

    set<int> uniqueNumbers;

    uniqueNumbers.insert(1);

    uniqueNumbers.insert(2);

    uniqueNumbers.insert(2);


    for (int x : uniqueNumbers) {

        cout << x << ' ';

    }

    cout << '\n';


    // =========================
    // 22. 상수
    // =========================

    const double PI = 3.141592;

    cout << PI << '\n';


    // =========================
    // 23. 삼항 연산자
    // =========================

    int age = 20;

    string adult =
        age >= 19
        ? "성인"
        : "미성년자";


    cout << adult << '\n';


    // =========================
    // 24. 논리 연산
    // =========================

    int x = 10;

    if (x >= 0 && x <= 100) {

        cout << "0~100 사이\n";

    }


    if (x == 10 || x == 20) {

        cout << "10 또는 20\n";

    }


    if (!(x == 0)) {

        cout << "0이 아님\n";

    }


    // =========================
    // 프로그램 정상 종료
    // =========================

    return 0;
}


// 함수 정의
int add(int a, int b) {

    return a + b;

}