
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2023; }

// ���������촦��
void create()
{
        set_name("����սѥ");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(70);
        set_value(6000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 27);
        set("cp", 0);
        set("pp", 0);
        set("sp", 31);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����սѥ";
}
