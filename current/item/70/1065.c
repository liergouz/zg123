
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("��ȸȭ��");
        set_picid_1(7017);
        set_picid_2(7017);

        set_level(65);
        set_value(24000);
        set_max_lasting(19599);
        set("ap", 155);
        set("dp", 15);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_00; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
