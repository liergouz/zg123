
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(70);
        set_value(15300);
        set_max_lasting(9699);
        set("dp", 34);
        set("sp", 40);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
