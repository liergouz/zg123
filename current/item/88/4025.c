
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(25);
        set_value(2300);
        set_max_lasting(5599);
        set("dp", 7);
        set("sp", 16);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
