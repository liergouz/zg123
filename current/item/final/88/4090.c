
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2066; }

// ���������촦��
void create()
{
        set_name("����ѥ");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(90);
        set_value(7000);
        set_max_lasting(17899);
        set("ap", 0);
        set("dp", 25);
        set("cp", 0);
        set("pp", 0);
        set("sp", 50);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ѥ";
}
