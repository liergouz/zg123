
// �Զ����ɣ�/make/weapon/make76

#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("ap", %d);
        set("!%%", %d);
        set("cp", %d);
        set("c!%%", %d);
        set("spec.mp", %d);
        set("spec.hp*", %d);
        set("spec.mp*", %d);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return %d; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
