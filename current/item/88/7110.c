
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(110);
        set_value(32000);
        set_max_lasting(8799);
        set("dp", 24);
        set("sp", 43);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
