
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("麒麟彩衣");
        set_picid_1(6180);
        set_picid_2(6180);

        set_level(90);
        set_value(50500);
        set_max_lasting(28599);
        set("dp", 219);
        set("pp", 130);

        setup();

        set_gender(2);
        set_armor_code(26);
}

// 函数：获取描述
string get_desc()
{
        return "麒麟彩衣";
}
