
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1033; }

// ���������촦��
void create()
{
        set_name("�ɰ���ì");
        set_picid_1(7418);
        set_picid_2(7418);

        set_level(70);
        set_value(7000);
        set_max_lasting(13599);
        set("ap", 177);
        set("dp", 20);
        set("cp", 0);
        set("pp", 0);

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
