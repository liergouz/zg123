
#include <equip.h>

inherit HEAD;

// ���������촦��
void create()
{
        set_name("ϸ��ñ");
        set_picid_1(6600);
        set_picid_2(6600);
        set_unit("��");

        set_level(20);
        set_value(1800);
        set_max_lasting(4299);
        set("dp", 11);
        set("pp", 11);
        set("hp", 15);
        set("mp", 15);

        setup();

        set_gender(2);
        set_head_code(F_PINGMAO);
        set_head_color(0x4208226d);
}

// ��������ȡ����
string get_desc()
{
        return "ϸ��ñ";
}
