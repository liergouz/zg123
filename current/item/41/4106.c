
// 自动生成：/make/item/make30

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 236; }

// 函数：构造处理
void create()
{
        set_name("动物皮毛");
        set_picid_1(4106);
        set_picid_2(4106);
        set_unit("张");
        set_value(150);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "动物身上御寒防护之体肤"; 
}
