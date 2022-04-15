#include "LoginModule.hpp"
#include "../DataBase.hpp"
#include "../../Utils/Util.hpp"

using namespace DataBase;
using namespace Utils;
using namespace std;


namespace LoginModule {
    void login() {
        string id;
        string pw;

        while(true) {
            print("ID: ");
            cin >> id;

            if(user_data.findUserId(id) == failed()) {
                println("Invalid User ID");
                println("[1]Try Again  [2]Sign Up  [3]Find Id  [OtherKeys]Quit Program");

                int again;
                print(": "); cin >> again;

                if(again == 1) {
                    continue;
                }
                if(again == 2) {
                    signUp();
                    continue;
                }
                if(again == 3) {
                    findId();
                }
                else {
                    break;
                }
            }
            else {//아이디를 찾았으면
                print("PW: ");
                cin >> pw;

                if(user_data.getUser(id).matchingPw(pw) == false) {
                    // 실패. 다시? / 비밀번호 변경하기
                    // 5회 실패시 1분간 락
                    // 또 5회 실패시 30분간 락
                }
                else { // 비밀번호 일치
                    // 로그인.
                }
            }
        }
    }
}