
#include <equip.h>

inherit HEAD;

// ���������촦��
void create()
{
        set_name("���ӹ�");
        set_picid_1(6505);
        set_picid_2(6505);
        set_unit("��");

        set_level(50);
        set_value(5500);
        set_max_lasting(7299);
        set("dp", 20);
        set("pp", 20);
        set("hp", 30);
        set("mp", 30);

        setup();

        set_gender(1);
        set_head_code(M_PINGMAO);
        set_head_color(0x42082901);
}

// ��������ȡ����
string get_desc()
{
        return "���ӹ�";
}
