
// 自动生成：/make/equip/88b

inherit BOOTS;

// 函数：构造处理
void create()
{
        set_name("皮靴");
        set_picid_1(8805);
        set_picid_2(8805);
        set_unit("双");

        set_level(50);
        set_value(2800);
        set_max_lasting(7299);
        set("dp", 12);
        set("pp", 12);
        set("X@%", 7);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "皮靴";
}
