
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1118; }

// ���������촦��
void create()
{
        set_name("��צȭ��");
        set_picid_1(7013);
        set_picid_2(7013);

        set_level(55);
        set_value(5500);
        set_max_lasting(6599);
        set("ap", 135);
        set("dp", 40);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
