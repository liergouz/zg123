
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1282; }

// ���������촦��
void create()
{
        set_name("̤��ѥ");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 24);
        set("cp", 0);
        set("pp", 0);
        set("sp", 24);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "̤��ѥ";
}
