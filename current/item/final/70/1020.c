
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1003; }

// ���������촦��
void create()
{
        set_name("ͭȭ��");
        set_picid_1(7012);
        set_picid_2(7012);

        set_level(20);
        set_value(2000);
        set_max_lasting(3599);
        set("ap", 65);
        set("dp", 7);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_03; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
