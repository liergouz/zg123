
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7423);
        set_picid_2(7423);
        set_unit("��");

        set_level(130);
        set_value(57000);
        set_max_lasting(27599);
        set("ap", 286);
        set("!%", 20);
        set("spec.hp", 110);
        set("spec.hp*", 6);
        set("spec.mp*", 6);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return 23; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
