
// �Զ����ɣ�/make/weapon/make70b

#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%04d);
        set_picid_2(%04d);
        set_unit("%s");

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("ap", %d);
        set("!%%", %d);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return %d; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
