
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1051; }

// ���������촦��
void create()
{
        set_name("�����ɻ�");
        set_picid_1(7420);
        set_picid_2(7420);

        set_level(100);
        set_value(10000);
        set_max_lasting(15599);
        set("ap", 249);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
