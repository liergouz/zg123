
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
        set_picid_1(7016);
        set_picid_2(7016);

        set_level(60);
        set_value(22000);
        set_max_lasting(18599);
        set("ap", 145);
        set("dp", 14);
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
