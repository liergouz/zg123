
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1263; }

// ���������촦��
void create()
{
        set_name("̤�Ƽ�");
        set_picid_1(6056);
        set_picid_2(6056);

        set_level(50);
        set_value(4000);
        set_max_lasting(9899);
        set("ap", 0);
        set("dp", 130);
        set("cp", 0);
        set("pp", 83);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "̤�Ƽ�";
}
