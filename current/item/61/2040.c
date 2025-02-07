
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("舞天裙");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(40);
        set_value(12500);
        set_max_lasting(13599);
        set("dp", 99);
        set("pp", 63);

        setup();

        set_gender(2);
        set_armor_code(23);
}

// 函数：获取描述
string get_desc()
{
        return "舞天裙";
}
