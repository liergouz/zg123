
// 自动生成：/make/item/make95

inherit "/inh/item/book3";

// 函数：构造处理
void create()
{
        set_name("强化银针渡厄");
        set_picid_1(9808);
        set_picid_2(9808);
        set_unit("本");
        set_value(3000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "记载着云梦泽专用法术强化银针渡厄的书籍。云梦泽使用后可学会法术强化银针渡厄。"; 
}

// 函数：获取门派名称
string get_family_name() { return " 云梦泽"; }

// 函数：获取技能号码
int get_skill_id() { return 0501; }

// 函数：获取技能要求等级
int get_skill_level() { return 21; }

// 函数：获取特技标志
string get_perform_id() { return "05018"; }

// 函数：获取技能名称
string get_skill_name() { return "中医药理"; }
