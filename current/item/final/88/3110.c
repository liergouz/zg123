
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2108; }

// ���������촦��
void create()
{
        set_name("����֮ѥ");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(110);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 35);
        set("cp", 0);
        set("pp", 0);
        set("sp", 47);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����֮ѥ";
}
