
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2246; }

// ���������촦��
void create()
{
        set_name("������װ");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 250);
        set("cp", 0);
        set("pp", 162);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������װ";
}
