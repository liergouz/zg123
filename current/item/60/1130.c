
#include <equip.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6042);
        set_picid_2(6042);
        set_unit("��");

        set_level(130);
        set_value(80000);
        set_max_lasting(40599);
        set("dp", 242);
        set("pp", 108);
        set("spec.hp", 220);
        set("spec.mp", 60);
        set("spec.-*%", 15);

        setup();

        set_gender(1);
        set_armor_code(M_ZHANJIA);
        set_armor_color_1(0x308150e0);
        set_armor_color_2(0x00004208);
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
