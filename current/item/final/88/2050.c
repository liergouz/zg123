
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1277; }

// ���������촦��
void create()
{
        set_name("��ХЬ");
        set_picid_1(8809);
        set_picid_2(8809);

        set_level(50);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 25);
        set("cp", 0);
        set("pp", 0);
        set("sp", 25);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ХЬ";
}
