
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1135; }

// ���������촦��
void create()
{
        set_name("�����滨��");
        set_picid_1(7116);
        set_picid_2(7116);

        set_level(85);
        set_value(8500);
        set_max_lasting(13599);
        set("ap", 191);
        set("dp", 15);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
