
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8803);
        set_picid_2(8803);

        set_level(55);
        set_value(10600);
        set_max_lasting(8599);
        set("dp", 27);
        set("sp", 27);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
