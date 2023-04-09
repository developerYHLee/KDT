#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
// #include "weapon.h"
// #include "normal.h"
// #include "rare.h"
// #include "unique.h"
// #include "legendary.h"
// #include "mythic.h"
// #include "character.h"
using namespace std;
// 프로젝트 7. 게임 만들기
// 설정.
// 1. 캐릭터, 무기, 등급 클래스를 만들어준다.
// 2. 캐릭터 클래스
//      - 필드
//      hp:100, level:1, 기본공격력:10, 치명타확률:10%, 치명타 데미지:100%, 보유무기(노말, 레어, 유니크)
//      - 메소드(기능)
//      상태창 : 플레이어 정보를 출력
//      무기 장착 : 소유하고 있는 무기 장착 및 해제
//      사냥하기 : 몬스터를 체력(100~10000)랜덤으로 소환하여 플레이어가 공격하여 몬스터의 체력이 0이하가 되면
//              레벨업이 되고 체력:10, 기본공격력:5, 치명타확률:0.1, 치명타 데미지:10% 증가. 그리고 무기를 확률적으로 드랍함.
//      보스잡기 : 총 10번의 공격을 하여 총데미지 합산 및 출력.
//      종료 : 게임을 종료
// 3. 무기 클래스
//      - 필드
//      등급(노말, 레어, 유니크), 무기공격력, 치명타 확률, 치명타 데미지
//      - 메소드(기능)
//      무기 등급, 공격력, 치명타 확률, 치명타 데미지
// 4. 등급 클래스(무기에 가상함수로 상속) - 노말, 레어, 유니크, 레전더리 생성.
//      - 필드
//      등급, 무기공격력, 치명타 확률, 치명타 데미지
// 5. 파일 분리하기
// 6. 캐릭터 스테이터스창 외부 저장 및 불러오기 기능 구현.
// (설정 2) 캐릭터 클래스 생성.
class Weapon {
public:
    string grade;
    int weapon_damage;
    int weapon_critical_hit;
    int weapon_critical_damage;
    Weapon(string g, int wd, int wch, int wcd) {
        this->grade = g;
        this->weapon_damage = wd;
        this->weapon_critical_hit = wch;
        this->weapon_critical_damage = wcd;
    }
};
class Normal : public Weapon {
public:
    Normal() :Weapon("노말", 20, 5, 10) {
        cout << grade << " 무기 장착." << endl;
    }
};
class Rare : public Weapon {
public:
    Rare() :Weapon("레어", 100, 15, 50) {
        cout << grade << " 무기 장착!" << endl;
    }
};
class Unique : public Weapon {
public:
    Unique() :Weapon("유니크", 300, 25, 100) {
        cout << grade << " 무기 장착!!" << endl;
    }
};
class Legendary : public Weapon {
public:
    Legendary() :Weapon("레전더리", 1000, 40, 300) {
        cout << grade << " 무기 장착!!!" << endl;
    }
};
class Mythic : public Weapon {
public:
    Mythic() :Weapon("신화", 5000, 70, 500) {
        cout << grade << " 무기 장착!!!!" << endl;
    }
};
class Character {
    // 필드
    int hp = 100;
    int level = 1;
    int base_attack_damage = 10;
    double critical_hit = 5;
    int critical_damage = 100;
    string weapon_grade = "미장착";
    // 기능
public:
    string Character_name; // 플레이어 이름.
    vector <int> weapon_info; // 무기데미지, 무기 치명타확률, 무기 치명타 데미지
    vector <int> get_weapon; // 인덱스순 노말 레어 유니크 레전더리 신화
    // 캐릭터 처음 생성
    Character(string name) {
        this->Character_name = name;
        cout << name << " 캐릭터가 생성되었습니다. " << endl;
        cout << endl;
    }
    // 캐릭터 불러 오기 캐릭터 이름과 소지했던 무기만 불러움. 그외다 초기화.
    Character(string CN, int N, int R, int U, int L, int M) {
        this->Character_name = CN;
        get_weapon.clear();
        get_weapon.push_back(N);
        get_weapon.push_back(R);
        get_weapon.push_back(U);
        get_weapon.push_back(L);
        get_weapon.push_back(M);
        cout << CN << " 캐릭터 불러오기 완료!" << endl;
    }
    // 상태창 보기
    void status() {
        cout << "==== " << Character_name << "의 상태창 ====" << endl;
        cout << "현재 체력 : " << hp << endl;
        cout << "현재 레벨 : " << level << endl;
        cout << "기본 공격력 : " << base_attack_damage << endl;
        if (weapon_grade == "미장착") {
            cout << "무기 공격력 : 0 - " << weapon_grade << endl;
        }
        else if (!weapon_info.empty()) {
            cout << "무기 공격력 : " << weapon_info[0] << " (" << weapon_grade << " 무기) - 착용중" << endl;
        }
        cout << "총 공격력 : " << getDamage() << endl;
        cout << "치명타 확률 : " << getCritical_hit() << "%" << endl;
        cout << "치명타 데미지 : " << getCritical_damage_p() << "%" << endl;
    }
    int getDamage() {
        return base_attack_damage + weapon_info[0];
    }
    double getCritical_damage() {
        return getDamage() * (100 + critical_damage + weapon_info[2]) / 100;
    }
    double getCritical_hit() {
        return critical_hit + (double)weapon_info[1];
    }
    double getCritical_damage_p() {
        return critical_damage + weapon_info[2];
    }
    void weapon_swaping(Weapon W) {
        weapon_info.clear();
        weapon_grade = W.grade;
        weapon_info.push_back(W.weapon_damage);
        weapon_info.push_back(W.weapon_critical_hit);
        weapon_info.push_back(W.weapon_critical_damage);
    }
    void weapon_equip() {
        cout << "현재 무기 현황 - 노말:" << get_weapon[0] << " 레어:" << get_weapon[1] << " 유니크:" << get_weapon[2] << " 레전더리:" << get_weapon[3] << " 신화:" << get_weapon[4] << endl;
        cout << "어떤 무기를 착용하시겠습니까? (0: 미착용, 1:노말, 2:레어, 3:유니크, 4:레전더리, 5:신화 ) ";
        int weapon_num;
        std::cin >> weapon_num;
        if (weapon_grade == "미장착" && weapon_num == 0) {
            cout << "착용중인 무기가 없습니다." << endl;
        }
        else if (weapon_num == 0) {
            cout << "무기를 장착해제하였습니다." << endl;
            weapon_grade = "미장착";
            weapon_info.assign(4, 0);
        }
        else if (get_weapon[0] >= 1 && weapon_num == 1) {
            Normal N = Normal();
            weapon_swaping(N);
        }
        else if (get_weapon[1] >= 1 && weapon_num == 2) {
            Rare R = Rare();
            weapon_swaping(R);
        }
        else if (get_weapon[2] >= 1 && weapon_num == 3) {
            Unique U = Unique();
            weapon_swaping(U);
        }
        else if (get_weapon[3] >= 1 && weapon_num == 4) {
            Legendary L = Legendary();
            weapon_swaping(L);
        }
        else if (get_weapon[4] >= 1 && weapon_num == 5) {
            Mythic M = Mythic();
            weapon_swaping(M);
        }
        else {
            cout << "선택하신 무기가 없습니다." << endl;
        }
    }
    // 몬스터 공격하기
    int monster_attack(int critical_point, int monster_hp) {
        if (critical_point >= 1 && critical_point <= getCritical_hit()) {
            cout << "**** 크리티컬!! ****" << endl;
            cout << "야생의 몬스터에게 " << getCritical_damage() << "의 데미지를 입혔습니다!!" << endl;
            return monster_hp - getCritical_damage();
        }
        else if (getCritical_hit() < critical_point && critical_point <= 100) {
            cout << "야생의 몬스터에게 " << getDamage() << "의 데미지를 입혔습니다!!" << endl;
            return monster_hp - getDamage();
        }
        else {
            cout << "오류1" << endl;
            return 0;
        }
    }
    // 보스 어택.
    int boss_attack(int critical_point) {
        if (critical_point >= 1 && critical_point <= getCritical_hit()) {
            cout << "**** 크리티컬!! ****" << endl;
            cout << "월드 보스 몬스터에게 " << getCritical_damage() << "의 데미지를 입혔습니다!!" << endl;
            return getCritical_damage();
        }
        else if (getCritical_hit() < critical_point && critical_point <= 100) {
            cout << "월드 보스 몬스터에게 " << getDamage() << "의 데미지를 입혔습니다!!" << endl;
            return getDamage();
        }
        else {
            cout << "오류1" << endl;
            return 0;
        }
    }
    // 사냥하기
    static int monster_hp;
    void hunting() {
        srand(time(NULL));
        cout << "(무기 확률 - 노말:56%, 레어:30%, 유니크:10%, 레전더리:3%, 신화:1%)" << endl;
        cout << " 야생의 몬스터 등장!! " << endl;
        cout << "체력 : " << monster_hp << endl;
        int weapon_point = rand() % 100 + 1; // 1~100까지 랜덤으로 저장해서 지정된 구간에 해당시에 무기 획득.
        int tmp_monster_hp = monster_hp;
        while (1) {
            cout << "무엇을 하시겠습니까? (1: 공격, 0: 도망) : ";
            int action;
            std::cin >> action;
            if (action == 1) {
                int critical_point = rand() % 100 + 1; // 1~100까지 랜덤으로 저장.
                tmp_monster_hp = monster_attack(critical_point, tmp_monster_hp);
                if (tmp_monster_hp <= 0) {
                    cout << "야생의 몬스터 처지!" << endl;
                    cout << "=== 레벨업!!! ===" << endl;
                    this->level++;
                    this->hp = this->hp + 10;
                    this->base_attack_damage = this->base_attack_damage + 5;
                    this->critical_hit = (double)this->critical_hit + 0.1;
                    this->critical_damage = this->critical_damage + 10;
                    if (weapon_point >= 1 && weapon_point <= 56) {
                        cout << "노말 무기를 획득하였습니다!!" << endl;
                        get_weapon[0]++;
                    }
                    else if (weapon_point > 56 && weapon_point <= 86) {
                        cout << "레어 무기를 획득하였습니다!!" << endl;
                        get_weapon[1]++;
                    }
                    else if (weapon_point > 86 && weapon_point <= 96) {
                        cout << "유니크 무기 획득하였습니다!!" << endl;
                        get_weapon[2]++;
                    }
                    else if (weapon_point > 97 && weapon_point <= 99) {
                        cout << "레전더리 무기 획득하였습니다!!" << endl;
                        get_weapon[3]++;
                    }
                    else if (weapon_point > 99 && weapon_point <= 100) {
                        cout << "신화 무기 획득하였습니다!!" << endl;
                        get_weapon[4]++;
                    }
                    else {
                        cout << "오류2" << endl;
                    }
                    monster_hp = monster_hp + rand() % 250 + 50; // 몬스터 잡을때 마다 50~300 만큼의 체력 증가
                    break;
                }
                else {
                    cout << "야생 몬스터 현재 채력 : " << tmp_monster_hp << endl;
                }
            } // 종료
            else if (action == 0) {
                cout << "도망 성공" << endl;
                break;
            }
            else {
                cout << "공격(1) 또는 도망(0)을 선택해주세요." << endl;
            }
        }
    }
    // 월드 보스 딜미터기
    void world_boss_dps() {
        srand(time(NULL));
        int total_damage = 0;
        cout << "10번의 공격을 진행합니다." << endl;
        for (int i = 1; i <= 10; i++) {
            int critical_point = rand() % 100 + 1;
            total_damage = total_damage + boss_attack(critical_point);
        }
        cout << "월드 보스에게 가한 총 데미지는 " << total_damage << "입니다." << endl;
    }
};
int Character::monster_hp = 100;
Character* c1;

int main() {
    cout << "게임을 시작합니다! 옵션을 선택해주세요. " << endl;
    cout << " 1. 새로시작  2. 불러오기 (그외 입력시 홍길동 이름 임의생성) :  ";
    int Option;
    std::cin >> Option;
    int N, R, U;
    if (Option == 1) {
        cout << "새로 생성할 캐릭터 이름을 입력해주세요. : ";
        string name;
        std::cin >> name;
        c1 = new Character(name);
        c1->get_weapon.assign(5, 0);
    }
    else if (Option == 2) {
        cout << "불러올 캐릭터의 이름을 입력해주세요. : ";
        string tmp_name;
        cin >> tmp_name;
        ifstream i_player_file("player_lst.txt");
        string CN;
        int N, R, U, L, M;
        cin.ignore();
        while (i_player_file >> CN >> N >> R >> U >> L >> M) {
            if (CN == tmp_name) {
                cout << "플레이어 정보 : " << CN << " 노말무기:" << N << " 레어무기:" << R << " 유니크무기:" << L << " 레전더리무기:" << M << " 신화무기:" << U << endl;
                c1 = new Character(CN, N, R, U, L, M);
                c1->get_weapon = { N,R,U,L,M }; // 무기 소유 현황 개수 초기화
            }
            else {
                cout << "저장된 캐릭터가 없습니다. 게스트 모드 홍길동으로 시작합니다. " << endl;
                c1 = new Character("홍길동");
                c1->get_weapon.assign(5, 0);
            }
        }
    }
    else {
        cout << "게스트 모드 홍길동으로 시작합니다." << endl;
        c1 = new Character("홍길동");
    }
    c1->weapon_info.assign(3, 0); // 무기 정보 초기화
    while (1) {
        cout << endl;
        cout << "---- 로비 (숫자로 입력) ---- " << endl;
        cout << "     1. 상 태 창        " << endl;
        cout << "     2. 사 냥 하 기      " << endl;
        cout << "     3. 무 기 착 용      " << endl;
        cout << "     4. 월 드 보 스      " << endl;
        cout << "     0. 게 임 종 료      " << endl;
        cout << " 입력창 : ";
        int exe;
        std::cin >> exe;
        cout << endl;
        switch (exe) {
        case 0: {
            break;
        }
        case 1: {
            c1->status();
            break;
        }
        case 2: {
            c1->hunting();
            break;
        }
        case 3: {
            c1->weapon_equip();
            break;
        }
        case 4: {
            c1->world_boss_dps();
        }
        default:
            break;
        }
        if (exe == 0) {
            cout << "게임을 종료합니다. " << endl;
            cout << "플레이어의 이름과 무기만 저장이 됩니다. " << endl;
            cout << "게임저장을 하시겠습니까? ( Y / N ) ";
            break;
        }
    }
    string s;
    cin >> s;
    if (s == "Y") {
        ofstream o_player_file("player_lst.txt");
        o_player_file << c1->Character_name << " " << c1->get_weapon[0] << " " << c1->get_weapon[1] << " " << c1->get_weapon[2] << " " << c1->get_weapon[3] << " " << c1->get_weapon[4] << endl;
        o_player_file.close();
        cout << "저장완료." << endl;
    }
    delete c1;
}