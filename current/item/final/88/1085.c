
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2219; }

// ���������촦��
void create()
{
        set_name("����ѥ");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(85);
        set_value(10000);
        set_max_lasting(24899);
        set("ap", 0);
        set("dp", 31);
        set("cp", 0);
        set("pp", 0);
        set("sp", 38);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ѥ";
}
