
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�¸���֮��");
        set_picid_1(7225);
        set_picid_2(7225);

        set_level(0);
        set_value(1);
        set_max_lasting(1099);
        set("ap", 30);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);
	set_no_give(1);
        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ����
string get_desc()
{
        return "���¸���ʹ�ã��޵ȼ����ơ����������ơ�";
}
