
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2205; }

// ���������촦��
void create()
{
        set_name("ҫ�ճ���");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(85);
        set_value(10000);
        set_max_lasting(24899);
        set("ap", 0);
        set("dp", 130);
        set("cp", 0);
        set("pp", 224);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ҫ�ճ���";
}
