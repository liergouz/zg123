
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(120);
        set_value(35500);
        set_max_lasting(9199);
        set("dp", 26);
        set("sp", 47);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
