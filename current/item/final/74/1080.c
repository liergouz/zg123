
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1039; }

// ���������촦��
void create()
{
        set_name("ף�ڻ�ǹ");
        set_picid_1(7418);
        set_picid_2(7418);

        set_level(80);
        set_value(8000);
        set_max_lasting(14099);
        set("ap", 197);
        set("dp", 30);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
