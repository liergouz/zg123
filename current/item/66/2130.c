
#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��ħս��");
        set_picid_1(6662);
        set_picid_2(6662);
        set_unit("��");

        set_level(130);
        set_value(36000);
        set_max_lasting(12099);
        set("dp", 65);
        set("pp", 90);
        set("spec.hp", 60);
        set("spec.mp", 48);
        set("spec.??%", 30);
        set("spec.-*%", 9);
        set("spec.-c*%", 7);

        setup();

        set_gender(2);
        set_head_code(F_ZHANKUI);
        set_head_color(0x42289048);
}

// ��������ȡ����
string get_desc()
{
        return "��ħս��";
}
