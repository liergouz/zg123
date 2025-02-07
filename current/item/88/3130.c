
// 自动生成：/make/equip/88z

inherit BOOTS;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("追风履");
        set_picid_1(8813);
        set_picid_2(8813);
        set_unit("双");

        set_level(130);
        set_value(39000);
        set_max_lasting(9699);
        set("dp", 24);
        set("pp", 35);
        set("spec.??%", 15);
        set("spec.?%", 15);
        set("spec.c?%", 8);
        set("spec.X@%", 8);
        set("spec./%", 8);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "追风履";
}
