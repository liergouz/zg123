
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1160; }

// ���������촦��
void create()
{
        set_name("����ȭ��");
        set_picid_1(7023);
        set_picid_2(7023);

        set_level(120);
        set_value(12000);
        set_max_lasting(16099);
        set("ap", 270);
        set("dp", 110);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_13; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
