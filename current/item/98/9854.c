
inherit ITEM;
inherit "/inh/item/task2";

// 函数：构造处理
void create()
{
        set_name("棉线");
        set_picid_1(9854);
        set_picid_2(9854);
        set_unit("条");
        set_value(1);

//      set_no_drop(1);
//      set_no_get(1);
        set_no_give(1);
        set_no_sell(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "特殊任务物品"; 
}
