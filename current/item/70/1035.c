
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ȭ��");
        set_picid_1(7006);
        set_picid_2(7006);

        set_level(35);
        set_value(8500);
        set_max_lasting(14099);
        set("ap", 95);
        set("dp", 9);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_00; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
