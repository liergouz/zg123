
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

        set_level(60);
        set_value(12200);
        set_max_lasting(8899);
        set("dp", 29);
        set("sp", 30);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
