
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2370; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(106);
        set_value(1000);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 28);
        set("cp", 0);
        set("pp", 0);
        set("sp", 65);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
