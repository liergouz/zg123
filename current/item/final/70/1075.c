
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1130; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(7018);
        set_picid_2(7018);

        set_level(75);
        set_value(7500);
        set_max_lasting(13099);
        set("ap", 175);
        set("dp", 60);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
