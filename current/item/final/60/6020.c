
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1206; }

// ���������촦��
void create()
{
        set_name("ϸ����");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(20);
        set_value(1000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 42);
        set("cp", 0);
        set("pp", 70);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ϸ����";
}
