
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2377; }

// ���������촦��
void create()
{
        set_name("����սѥ");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(116);
        set_value(1000);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 54);
        set("cp", 0);
        set("pp", 0);
        set("sp", 60);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����սѥ";
}
