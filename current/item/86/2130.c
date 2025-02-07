
// 自动生成：/make/equip/86y

inherit NECK;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("无极项链");
        set_picid_1(8613);
        set_picid_2(8613);
        set_unit("串");

        set_level(130);
        set_value(84750);
        set_max_lasting(8499);
        set("ap", 64);
        set("cp", 65);
        set("spec.??%", 15);
        set("spec.pp", 55);
        set("spec.@%", 28);
        set("spec./%", 15);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "无极项链";
}
