
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1154; }

// ���������촦��
void create()
{
        set_name("����֮צ");
        set_picid_1(7022);
        set_picid_2(7022);

        set_level(115);
        set_value(11500);
        set_max_lasting(15599);
        set("ap", 260);
        set("dp", 100);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_12; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
