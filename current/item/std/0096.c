
inherit ITEM;

// 函数：构造处理
void create()
{
        set_name("天恩令");
        set_picid_1(0096);
        set_picid_2(0096);
        set_unit("块");
        set_value(50);
        set_no_give(1);
        set_no_sell(1); 
}


int get_item_color() {return 2;}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "学习强化门派技能的信物。\n相传战国习武之人以能学习到门派强化技能为上天的恩赐，故而有了天恩令一说。";
}
