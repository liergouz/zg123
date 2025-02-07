
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 1; }

// 函数：成品编号
int get_fin_type() { return 2229; }

// 函数：构造处理
void create()
{
        set_name("帝王之盔");
        set_picid_1(6562);
        set_picid_2(6562);

        set_level(95);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 185);
        set("cp", 0);
        set("pp", 59);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "帝王之盔";
}
