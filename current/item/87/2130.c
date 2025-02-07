
// 自动生成：/make/equip/87y

inherit WAIST;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("无极腰带");
        set_picid_1(8713);
        set_picid_2(8713);
        set_unit("条");

        set_level(130);
        set_value(26400);
        set_max_lasting(12099);
        set("dp", 35);
        set("pp", 24);
        set("spec.sp", 60);
        set("spec.hp%", 10);
        set("spec.mp%", 11);
        set("spec.-*%", 13);
        set("spec.-c*%", 6);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "无极腰带";
}
