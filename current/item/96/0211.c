
// 自动生成：/make/item/make96

inherit "/inh/item/book2";
int get_item_color() { return 2; }
// 函数：构造处理
void create()
{
        set_name("太古神拳秘籍");
        set_picid_1(9604);
        set_picid_2(9604);
        set_unit("本");
        set_value(50000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "武功秘籍，提升一级技能"; 
}

// 函数：获取门派名称
string get_family_name() { return " 桃花源"; }

// 函数：获取技能号码
int get_skill_id() { return 0211; }

// 函数：获取技能名称
string get_skill_name() { return "太古神拳"; }
