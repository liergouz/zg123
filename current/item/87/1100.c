
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("龙鳞腰带");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(100);
        set_value(22500);
        set_max_lasting(13899);
        set("dp", 100);
        set("pp", 85);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "龙鳞腰带";
}
