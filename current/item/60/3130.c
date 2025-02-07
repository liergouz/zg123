
#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("九天战甲");
        set_picid_1(6082);
        set_picid_2(6082);
        set_unit("件");

        set_level(130);
        set_value(86500);
        set_max_lasting(18099);
        set("dp", 200);
        set("pp", 230);
        set("spec.hp", 220);
        set("spec.mp", 340);
        set("spec.-*%", 13);

        setup();

        set_gender(1);
        set_armor_code(M_ZHANJIA);
        set_armor_color_1(0x19a211a0);
        set_armor_color_2(0x00004208);
}

// 函数：获取描述
string get_desc()
{
        return "九天战甲";
}
