
#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��Ůս��");
        set_picid_1(6682);
        set_picid_2(6682);
        set_unit("��");

        set_level(130);
        set_value(62000);
        set_max_lasting(11499);
        set("dp", 52);
        set("pp", 130);
        set("spec.hp", 55);
        set("spec.mp", 70);
        set("spec.??%", 40);
        set("spec.-*%", 7);
        set("spec.-c*%", 7);

        setup();

        set_gender(2);
        set_head_code(F_ZHANKUI);
        set_head_color(0x39e119a8);
}

// ��������ȡ����
string get_desc()
{
        return "��Ůս��";
}
