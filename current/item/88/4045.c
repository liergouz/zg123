
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("׷��Ь");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(45);
        set_value(7300);
        set_max_lasting(7399);
        set("dp", 11);
        set("sp", 40);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "׷��Ь";
}
