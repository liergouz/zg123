
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2086; }

// ���������촦��
void create()
{
        set_name("����ѥ");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(100);
        set_value(7500);
        set_max_lasting(18899);
        set("ap", 0);
        set("dp", 33);
        set("cp", 0);
        set("pp", 0);
        set("sp", 43);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ѥ";
}
