
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�ɰ���ì");
        set_picid_1(7415);
        set_picid_2(7415);

        set_level(65);
        set_value(24000);
        set_max_lasting(18099);
        set("ap", 157);
        set("dp", 0);
        set("cp", 0);
        set("sp", -28);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
