
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("Ծ����");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(50);
        set_value(11000);
        set_max_lasting(6099);
        set("dp", 12);
        set("sp", 19);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ծ����";
}
