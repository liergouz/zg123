
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("冥光冠");
        set_picid_1(6560);
        set_picid_2(6560);

        set_level(90);
        set_value(40000);
        set_max_lasting(9099);
        set("dp", 61);
        set("pp", 109);

        setup();

        set_gender(1);
        set_head_code(46);
}

// 函数：获取描述
string get_desc()
{
        return "冥光冠";
}
