
#include <equip.h>

inherit HEAD;

// ���������촦��
void create()
{
        set_name("����ñ");
        set_picid_1(6523);
        set_picid_2(6523);
        set_unit("��");

        set_level(30);
        set_value(2400);
        set_max_lasting(4899);
        set("dp", 14);
        set("pp", 14);
        set("hp", 20);
        set("mp", 20);

        setup();

        set_gender(1);
        set_head_code(M_WUSHENGMAO);
        set_head_color(0x420818c3);
}

// ��������ȡ����
string get_desc()
{
        return "����ñ";
}
