
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("ڤ����");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(90);
        set_value(25000);
        set_max_lasting(7899);
        set("dp", 20);
        set("sp", 35);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ڤ����";
}
