
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("黑铁项链");
        set_picid_1(8607);
        set_picid_2(8607);

        set_level(25);
        set_value(10000);
        set_max_lasting(6799);
        set("cp", 0);
        set("pp", 20);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "黑铁项链";
}
