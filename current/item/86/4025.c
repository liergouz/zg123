
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("黑铁项链");
        set_picid_1(8607);
        set_picid_2(8607);

        set_level(25);
        set_value(11100);
        set_max_lasting(5599);
        set("cp", 0);
        set("pp", 27);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "黑铁项链";
}
