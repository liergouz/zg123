
#include <equip.h>

inherit HEAD;

// ���������촦��
void create()
{
        set_name("��ʿñ");
        set_picid_1(6513);
        set_picid_2(6513);
        set_unit("��");

        set_level(40);
        set_value(3800);
        set_max_lasting(6099);
        set("dp", 17);
        set("pp", 17);
        set("hp", 25);
        set("mp", 25);

        setup();

        set_gender(1);
        set_head_code(M_WUSHENGMAO);
        set_head_color(0x42086240);
}

// ��������ȡ����
string get_desc()
{
        return "��ʿñ";
}
