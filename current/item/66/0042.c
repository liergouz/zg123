
#include <equip.h>

inherit HEAD;

// ���������촦��
void create()
{
        set_name("��ñ");
        set_picid_1(6623);
        set_picid_2(6623);
        set_unit("��");

        set_level(40);
        set_value(3800);
        set_max_lasting(6099);
        set("dp", 17);
        set("pp", 17);
        set("hp", 25);
        set("mp", 25);

        setup();

        set_gender(2);
        set_head_code(F_WUSHENGMAO);
        set_head_color(0x420820c6);
}

// ��������ȡ����
string get_desc()
{
        return "��ñ";
}
