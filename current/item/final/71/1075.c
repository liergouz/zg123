
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1129; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(7117);
        set_picid_2(7117);

        set_level(75);
        set_value(7500);
        set_max_lasting(13099);
        set("ap", 185);
        set("dp", 12);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
