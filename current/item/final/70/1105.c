
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1148; }

// ���������촦��
void create()
{
        set_name("��ʯ�ǳ�");
        set_picid_1(7023);
        set_picid_2(7023);

        set_level(105);
        set_value(10500);
        set_max_lasting(14599);
        set("ap", 235);
        set("dp", 90);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
