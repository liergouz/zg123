
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2241; }

// ���������촦��
void create()
{
        set_name("Ծ��ѥ");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(95);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 32);
        set("cp", 0);
        set("pp", 0);
        set("sp", 41);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ծ��ѥ";
}
