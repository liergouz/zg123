
// �Զ����ɣ�/make/weapon/make71

#include <equip.h>

inherit MISSILE;

// ��������������
int get_family() { return 2; }

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
        set("t!%%", %d);
        set("spec.hp", %d);
        set("spec.mp", %d);
        set("spec.mp*", %d);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return %d; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
