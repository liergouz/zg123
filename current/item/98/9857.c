
inherit ITEM;
inherit "/inh/item/task2";

// 函数：构造处理
void create()
{
        set_name("皂角");
        set_picid_1(9857);
        set_picid_2(9857);
        set_unit("块");
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
