
#include <equip.h>

inherit HEAD;

// ���������촦��
void create()
{
        set_name("�ֲ�ñ");
        set_picid_1(6510);
        set_picid_2(6510);
        set_unit("��");

        set_level(0);
        set_value(950);
        set_max_lasting(2499);
        set("dp", 5);
        set("pp", 5);
        set("hp", 5);
        set("mp", 5);

        setup();

        set_gender(1);
        set_head_code(M_ZHANMAO);
        set_head_color(0x42083140);
}

// ��������ȡ����
string get_desc()
{
        return "�ֲ�ñ";
}
