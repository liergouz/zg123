
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(100);
        set_value(24600);
        set_max_lasting(11899);
        set("dp", 47);
        set("sp", 54);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
