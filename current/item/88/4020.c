
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("���Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(20);
        set_value(1100);
        set_max_lasting(5199);
        set("dp", 6);
        set("sp", 10);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���Ь";
}
