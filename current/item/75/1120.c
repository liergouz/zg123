
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7516);
        set_picid_2(7516);

        set_level(120);
        set_value(52000);
        set_max_lasting(26099);
        set("ap", 280);
        set("dp", -50);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_14; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
