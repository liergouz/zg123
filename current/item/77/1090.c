
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("ն����");
        set_picid_1(7314);
        set_picid_2(7314);

        set_level(90);
        set_value(48000);
        set_max_lasting(8599);
        set("ap", 180);
        set("dp", 0);
        set("cp", 280);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
