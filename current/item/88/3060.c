
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ս��Ь");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(60);
        set_value(12200);
        set_max_lasting(8899);
        set("dp", 29);
        set("sp", 28);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ս��Ь";
}
