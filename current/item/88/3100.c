
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(100);
        set_value(24600);
        set_max_lasting(11899);
        set("dp", 47);
        set("sp", 52);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
