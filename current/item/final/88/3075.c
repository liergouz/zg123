
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2199; }

// ���������촦��
void create()
{
        set_name("���鳤ѥ");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(75);
        set_value(9500);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 28);
        set("cp", 0);
        set("pp", 0);
        set("sp", 33);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���鳤ѥ";
}
