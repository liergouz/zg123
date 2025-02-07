
// 自动生成：/make/item/make95

inherit "/inh/item/book";
int get_item_color() { return 1; }
// 函数：构造处理
void create()
{
        set_name("漫天花雨进阶");
        set_picid_1(9504);
        set_picid_2(9504);
        set_unit("本");
        set_value(10000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "武功书籍，提升技能熟练度"; 
}

// 函数：获取门派名称
string get_family_name() { return " 唐门"; }

// 函数：获取技能号码
int get_skill_id() { return 0261; }

// 函数：获取技能名称
string get_skill_name() { return "漫天花雨"; }
