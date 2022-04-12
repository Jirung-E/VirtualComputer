# Code Style:

- - - 

  ### 1. 네이밍 스타일
  변수: snake_case
  ```cpp
  int integer;
  char* char_pointer;
  ```
  함수: camelCase
  ```cpp
  void function();
  int* getArray();
  ```
  class, enum 등: PascalCase
  ```cpp
  class PlayerController { ... };
  enum Direction { Up, Down, Left, Right };
  ```
  
  ### 2. 중괄호의 위치
  K&R 방식(같은줄에 한칸 띄고)
  ```c
  if(...) {
      ....
  }
  ```
  
  ### 3. 띄어쓰기 규칙
  if, for, 함수 등 이름과 괄호 사이에 공백 제거   
  여는 중괄호 앞에 띄어쓰기 1회   
  포인터형 변수 선언시 *는 변수 타입쪽에 붙임   
  , 및 ; 뒤에 띄어쓰기 1회, 앞 공백 제거   
  for문 안쪽 ; 뒤에 각각 띄어쓰기 1회   
  연산자의 경우 자유롭게 하되, 우선순위가 보이게 하면 좋음   
  중괄호는 안쪽 띄어쓰기 1회씩, (), [], <> 의 경우 안쪽 공백 제거   
  ```cpp
  CustomClass cc { };
  SampleClass<int> sc { 1, 2 };
  
  int array[3] = { 1, 2, 3 };
  int* arrp = array;
  
  for(int i=0; i<10; ++i) {
      if(sc.num1*sc.num2 + 15 >= arrp[2]) {
          cc.Bang();
      }
  }
  ```
      
  ### 4. 들여쓰기 규칙
  스페이스 4개로 통일   
  switch - case 의 경우 case는 들여쓰지 않음, case의 내용은 들여씀   
  ```c
  switch(num) {
  case 1:
      ...
      break;
  case 2:
      ....
      break;
  default:
      .....
      break;
  }
  ```
  
  ### 5. 줄바꿈 규칙
  
  ### 6. 기타
  class 안에서 private 멤버를 선언할때 private: 과 멤버 선언이 같은줄에 위치, 들여씀.   
  ```cpp
  class Sample {
      private: int num;
      private: int age;
      
  public:
      int Num() const;
  };
  ```