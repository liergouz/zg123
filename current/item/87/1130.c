
// 自动生成：/make/equip/87x

inherit WAIST;

// 函数：适用门派
int get_family() { return 1; }

// 函数：构造处理
void create()
{
        set_name("无极腰带");
        set_picid_1(8713);
        set_picid_2(8713);
        set_unit("条");

        set_level(130);
        set_value(27500);
        set_max_lasting(15699);
        set("dp", 33);
        set("pp", 10);
        set("spec.sp", 25);
        set("spec.hp%", 12);
        set("spec.mp%", 6);
        set("spec.-*%", 13);
        set("spec.-c*%", 6);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "无极腰带";
}
