
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2245; }

// ���������촦��
void create()
{
        set_name("������װ");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(105);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 241);
        set("cp", 0);
        set("pp", 152);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������װ";
}
