
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("����սЬ");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(90);
        set_value(21500);
        set_max_lasting(11199);
        set("dp", 43);
        set("sp", 46);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����սЬ";
}
