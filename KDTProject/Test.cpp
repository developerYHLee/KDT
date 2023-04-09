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
// ������Ʈ 7. ���� �����
// ����.
// 1. ĳ����, ����, ��� Ŭ������ ������ش�.
// 2. ĳ���� Ŭ����
//      - �ʵ�
//      hp:100, level:1, �⺻���ݷ�:10, ġ��ŸȮ��:10%, ġ��Ÿ ������:100%, ��������(�븻, ����, ����ũ)
//      - �޼ҵ�(���)
//      ����â : �÷��̾� ������ ���
//      ���� ���� : �����ϰ� �ִ� ���� ���� �� ����
//      ����ϱ� : ���͸� ü��(100~10000)�������� ��ȯ�Ͽ� �÷��̾ �����Ͽ� ������ ü���� 0���ϰ� �Ǹ�
//              �������� �ǰ� ü��:10, �⺻���ݷ�:5, ġ��ŸȮ��:0.1, ġ��Ÿ ������:10% ����. �׸��� ���⸦ Ȯ�������� �����.
//      ������� : �� 10���� ������ �Ͽ� �ѵ����� �ջ� �� ���.
//      ���� : ������ ����
// 3. ���� Ŭ����
//      - �ʵ�
//      ���(�븻, ����, ����ũ), ������ݷ�, ġ��Ÿ Ȯ��, ġ��Ÿ ������
//      - �޼ҵ�(���)
//      ���� ���, ���ݷ�, ġ��Ÿ Ȯ��, ġ��Ÿ ������
// 4. ��� Ŭ����(���⿡ �����Լ��� ���) - �븻, ����, ����ũ, �������� ����.
//      - �ʵ�
//      ���, ������ݷ�, ġ��Ÿ Ȯ��, ġ��Ÿ ������
// 5. ���� �и��ϱ�
// 6. ĳ���� �������ͽ�â �ܺ� ���� �� �ҷ����� ��� ����.
// (���� 2) ĳ���� Ŭ���� ����.
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
    Normal() :Weapon("�븻", 20, 5, 10) {
        cout << grade << " ���� ����." << endl;
    }
};
class Rare : public Weapon {
public:
    Rare() :Weapon("����", 100, 15, 50) {
        cout << grade << " ���� ����!" << endl;
    }
};
class Unique : public Weapon {
public:
    Unique() :Weapon("����ũ", 300, 25, 100) {
        cout << grade << " ���� ����!!" << endl;
    }
};
class Legendary : public Weapon {
public:
    Legendary() :Weapon("��������", 1000, 40, 300) {
        cout << grade << " ���� ����!!!" << endl;
    }
};
class Mythic : public Weapon {
public:
    Mythic() :Weapon("��ȭ", 5000, 70, 500) {
        cout << grade << " ���� ����!!!!" << endl;
    }
};
class Character {
    // �ʵ�
    int hp = 100;
    int level = 1;
    int base_attack_damage = 10;
    double critical_hit = 5;
    int critical_damage = 100;
    string weapon_grade = "������";
    // ���
public:
    string Character_name; // �÷��̾� �̸�.
    vector <int> weapon_info; // ���ⵥ����, ���� ġ��ŸȮ��, ���� ġ��Ÿ ������
    vector <int> get_weapon; // �ε����� �븻 ���� ����ũ �������� ��ȭ
    // ĳ���� ó�� ����
    Character(string name) {
        this->Character_name = name;
        cout << name << " ĳ���Ͱ� �����Ǿ����ϴ�. " << endl;
        cout << endl;
    }
    // ĳ���� �ҷ� ���� ĳ���� �̸��� �����ߴ� ���⸸ �ҷ���. �׿ܴ� �ʱ�ȭ.
    Character(string CN, int N, int R, int U, int L, int M) {
        this->Character_name = CN;
        get_weapon.clear();
        get_weapon.push_back(N);
        get_weapon.push_back(R);
        get_weapon.push_back(U);
        get_weapon.push_back(L);
        get_weapon.push_back(M);
        cout << CN << " ĳ���� �ҷ����� �Ϸ�!" << endl;
    }
    // ����â ����
    void status() {
        cout << "==== " << Character_name << "�� ����â ====" << endl;
        cout << "���� ü�� : " << hp << endl;
        cout << "���� ���� : " << level << endl;
        cout << "�⺻ ���ݷ� : " << base_attack_damage << endl;
        if (weapon_grade == "������") {
            cout << "���� ���ݷ� : 0 - " << weapon_grade << endl;
        }
        else if (!weapon_info.empty()) {
            cout << "���� ���ݷ� : " << weapon_info[0] << " (" << weapon_grade << " ����) - ������" << endl;
        }
        cout << "�� ���ݷ� : " << getDamage() << endl;
        cout << "ġ��Ÿ Ȯ�� : " << getCritical_hit() << "%" << endl;
        cout << "ġ��Ÿ ������ : " << getCritical_damage_p() << "%" << endl;
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
        cout << "���� ���� ��Ȳ - �븻:" << get_weapon[0] << " ����:" << get_weapon[1] << " ����ũ:" << get_weapon[2] << " ��������:" << get_weapon[3] << " ��ȭ:" << get_weapon[4] << endl;
        cout << "� ���⸦ �����Ͻðڽ��ϱ�? (0: ������, 1:�븻, 2:����, 3:����ũ, 4:��������, 5:��ȭ ) ";
        int weapon_num;
        std::cin >> weapon_num;
        if (weapon_grade == "������" && weapon_num == 0) {
            cout << "�������� ���Ⱑ �����ϴ�." << endl;
        }
        else if (weapon_num == 0) {
            cout << "���⸦ ���������Ͽ����ϴ�." << endl;
            weapon_grade = "������";
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
            cout << "�����Ͻ� ���Ⱑ �����ϴ�." << endl;
        }
    }
    // ���� �����ϱ�
    int monster_attack(int critical_point, int monster_hp) {
        if (critical_point >= 1 && critical_point <= getCritical_hit()) {
            cout << "**** ũ��Ƽ��!! ****" << endl;
            cout << "�߻��� ���Ϳ��� " << getCritical_damage() << "�� �������� �������ϴ�!!" << endl;
            return monster_hp - getCritical_damage();
        }
        else if (getCritical_hit() < critical_point && critical_point <= 100) {
            cout << "�߻��� ���Ϳ��� " << getDamage() << "�� �������� �������ϴ�!!" << endl;
            return monster_hp - getDamage();
        }
        else {
            cout << "����1" << endl;
            return 0;
        }
    }
    // ���� ����.
    int boss_attack(int critical_point) {
        if (critical_point >= 1 && critical_point <= getCritical_hit()) {
            cout << "**** ũ��Ƽ��!! ****" << endl;
            cout << "���� ���� ���Ϳ��� " << getCritical_damage() << "�� �������� �������ϴ�!!" << endl;
            return getCritical_damage();
        }
        else if (getCritical_hit() < critical_point && critical_point <= 100) {
            cout << "���� ���� ���Ϳ��� " << getDamage() << "�� �������� �������ϴ�!!" << endl;
            return getDamage();
        }
        else {
            cout << "����1" << endl;
            return 0;
        }
    }
    // ����ϱ�
    static int monster_hp;
    void hunting() {
        srand(time(NULL));
        cout << "(���� Ȯ�� - �븻:56%, ����:30%, ����ũ:10%, ��������:3%, ��ȭ:1%)" << endl;
        cout << " �߻��� ���� ����!! " << endl;
        cout << "ü�� : " << monster_hp << endl;
        int weapon_point = rand() % 100 + 1; // 1~100���� �������� �����ؼ� ������ ������ �ش�ÿ� ���� ȹ��.
        int tmp_monster_hp = monster_hp;
        while (1) {
            cout << "������ �Ͻðڽ��ϱ�? (1: ����, 0: ����) : ";
            int action;
            std::cin >> action;
            if (action == 1) {
                int critical_point = rand() % 100 + 1; // 1~100���� �������� ����.
                tmp_monster_hp = monster_attack(critical_point, tmp_monster_hp);
                if (tmp_monster_hp <= 0) {
                    cout << "�߻��� ���� ó��!" << endl;
                    cout << "=== ������!!! ===" << endl;
                    this->level++;
                    this->hp = this->hp + 10;
                    this->base_attack_damage = this->base_attack_damage + 5;
                    this->critical_hit = (double)this->critical_hit + 0.1;
                    this->critical_damage = this->critical_damage + 10;
                    if (weapon_point >= 1 && weapon_point <= 56) {
                        cout << "�븻 ���⸦ ȹ���Ͽ����ϴ�!!" << endl;
                        get_weapon[0]++;
                    }
                    else if (weapon_point > 56 && weapon_point <= 86) {
                        cout << "���� ���⸦ ȹ���Ͽ����ϴ�!!" << endl;
                        get_weapon[1]++;
                    }
                    else if (weapon_point > 86 && weapon_point <= 96) {
                        cout << "����ũ ���� ȹ���Ͽ����ϴ�!!" << endl;
                        get_weapon[2]++;
                    }
                    else if (weapon_point > 97 && weapon_point <= 99) {
                        cout << "�������� ���� ȹ���Ͽ����ϴ�!!" << endl;
                        get_weapon[3]++;
                    }
                    else if (weapon_point > 99 && weapon_point <= 100) {
                        cout << "��ȭ ���� ȹ���Ͽ����ϴ�!!" << endl;
                        get_weapon[4]++;
                    }
                    else {
                        cout << "����2" << endl;
                    }
                    monster_hp = monster_hp + rand() % 250 + 50; // ���� ������ ���� 50~300 ��ŭ�� ü�� ����
                    break;
                }
                else {
                    cout << "�߻� ���� ���� ä�� : " << tmp_monster_hp << endl;
                }
            } // ����
            else if (action == 0) {
                cout << "���� ����" << endl;
                break;
            }
            else {
                cout << "����(1) �Ǵ� ����(0)�� �������ּ���." << endl;
            }
        }
    }
    // ���� ���� �����ͱ�
    void world_boss_dps() {
        srand(time(NULL));
        int total_damage = 0;
        cout << "10���� ������ �����մϴ�." << endl;
        for (int i = 1; i <= 10; i++) {
            int critical_point = rand() % 100 + 1;
            total_damage = total_damage + boss_attack(critical_point);
        }
        cout << "���� �������� ���� �� �������� " << total_damage << "�Դϴ�." << endl;
    }
};
int Character::monster_hp = 100;
Character* c1;

int main() {
    cout << "������ �����մϴ�! �ɼ��� �������ּ���. " << endl;
    cout << " 1. ���ν���  2. �ҷ����� (�׿� �Է½� ȫ�浿 �̸� ���ǻ���) :  ";
    int Option;
    std::cin >> Option;
    int N, R, U;
    if (Option == 1) {
        cout << "���� ������ ĳ���� �̸��� �Է����ּ���. : ";
        string name;
        std::cin >> name;
        c1 = new Character(name);
        c1->get_weapon.assign(5, 0);
    }
    else if (Option == 2) {
        cout << "�ҷ��� ĳ������ �̸��� �Է����ּ���. : ";
        string tmp_name;
        cin >> tmp_name;
        ifstream i_player_file("player_lst.txt");
        string CN;
        int N, R, U, L, M;
        cin.ignore();
        while (i_player_file >> CN >> N >> R >> U >> L >> M) {
            if (CN == tmp_name) {
                cout << "�÷��̾� ���� : " << CN << " �븻����:" << N << " �����:" << R << " ����ũ����:" << L << " ������������:" << M << " ��ȭ����:" << U << endl;
                c1 = new Character(CN, N, R, U, L, M);
                c1->get_weapon = { N,R,U,L,M }; // ���� ���� ��Ȳ ���� �ʱ�ȭ
            }
            else {
                cout << "����� ĳ���Ͱ� �����ϴ�. �Խ�Ʈ ��� ȫ�浿���� �����մϴ�. " << endl;
                c1 = new Character("ȫ�浿");
                c1->get_weapon.assign(5, 0);
            }
        }
    }
    else {
        cout << "�Խ�Ʈ ��� ȫ�浿���� �����մϴ�." << endl;
        c1 = new Character("ȫ�浿");
    }
    c1->weapon_info.assign(3, 0); // ���� ���� �ʱ�ȭ
    while (1) {
        cout << endl;
        cout << "---- �κ� (���ڷ� �Է�) ---- " << endl;
        cout << "     1. �� �� â        " << endl;
        cout << "     2. �� �� �� ��      " << endl;
        cout << "     3. �� �� �� ��      " << endl;
        cout << "     4. �� �� �� ��      " << endl;
        cout << "     0. �� �� �� ��      " << endl;
        cout << " �Է�â : ";
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
            cout << "������ �����մϴ�. " << endl;
            cout << "�÷��̾��� �̸��� ���⸸ ������ �˴ϴ�. " << endl;
            cout << "���������� �Ͻðڽ��ϱ�? ( Y / N ) ";
            break;
        }
    }
    string s;
    cin >> s;
    if (s == "Y") {
        ofstream o_player_file("player_lst.txt");
        o_player_file << c1->Character_name << " " << c1->get_weapon[0] << " " << c1->get_weapon[1] << " " << c1->get_weapon[2] << " " << c1->get_weapon[3] << " " << c1->get_weapon[4] << endl;
        o_player_file.close();
        cout << "����Ϸ�." << endl;
    }
    delete c1;
}