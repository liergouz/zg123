
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1059; }

// ���������촦��
void create()
{
        set_name("�ѻ���");
        set_picid_1(7121);
        set_picid_2(7121);

        set_level(110);
        set_value(11000);
        set_max_lasting(16099);
        set("ap", 220);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_12; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
