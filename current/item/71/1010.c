
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ʯ��");
        set_picid_1(7100);
        set_picid_2(7100);

        set_level(10);
        set_value(1000);
        set_max_lasting(12099);
        set("ap", 30);
        set("dp", -6);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_00; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
