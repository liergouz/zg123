
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1020; }

// ���������촦��
void create()
{
        set_name("�඿��");
        set_picid_1(7221);
        set_picid_2(7221);

        set_level(50);
        set_value(5000);
        set_max_lasting(8099);
        set("ap", 130);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
