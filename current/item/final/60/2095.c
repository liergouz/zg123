
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2224; }

// ���������촦��
void create()
{
        set_name("������װ");
        set_picid_1(6082);
        set_picid_2(6082);

        set_level(95);
        set_value(10000);
        set_max_lasting(24899);
        set("ap", 0);
        set("dp", 221);
        set("cp", 0);
        set("pp", 137);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������װ";
}
