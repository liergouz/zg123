
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1283; }

// ���������촦��
void create()
{
        set_name("ս��ѥ");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 23);
        set("cp", 0);
        set("pp", 0);
        set("sp", 23);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ս��ѥ";
}
