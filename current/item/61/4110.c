
// 自动生成：/make/equip/60b

#include <equip.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("轩缘战袍");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(110);
        set_value(54000);
        set_max_lasting(39099);
        set("dp", 192);
        set("pp", 151);

        setup();

        set_gender(2);
        set_armor_code(28);
}

// 函数：获取描述
string get_desc()
{
        return "轩缘战袍";
}
