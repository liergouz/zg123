
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("׷������");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(45);
        set_value(9150);
        set_max_lasting(7399);
        set("dp", 35);
        set("pp", 35);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "׷������";
}
