
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1117; }

// ���������촦��
void create()
{
        set_name("��ħ�����");
        set_picid_1(7114);
        set_picid_2(7114);

        set_level(55);
        set_value(5500);
        set_max_lasting(6599);
        set("ap", 151);
        set("dp", 10);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
