
// 自动生成：/make/equip/87z

inherit WAIST;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("无极腰带");
        set_picid_1(8713);
        set_picid_2(8713);
        set_unit("条");

        set_level(130);
        set_value(39500);
        set_max_lasting(8299);
        set("dp", 24);
        set("pp", 35);
        set("spec.sp", 58);
        set("spec.hp%", 6);
        set("spec.mp%", 21);
        set("spec.-*%", 7);
        set("spec.-c*%", 8);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "无极腰带";
}
