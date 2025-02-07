
#include <item.h>

inherit ITEM;

private int Money;
private int OrginMoney;

// 函数：商人钱票
// int is_cheque() { return 1; }

// 函数：商人钱票
int get_item_type() { return ITEM_TYPE_CHEQUE; }

// 函数：获取钱票金额
int get_money() { return Money; }

// 函数：设置钱票金额
int set_money( int gold ) { return Money = gold; }

// 函数：增加钱票金额
int add_money( int gold ) { return Money += gold; }

// 函数：获取钱票本金
int get_orgin_money() { return OrginMoney; }

// 函数：设置钱票本金
int set_orgin_money( int gold ) { return OrginMoney = gold; }

// 函数：构造处理
void create()
{
        set_name("钱票");
        set_picid_1(0008);
        set_picid_2(0008);
        set_unit("张");

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
        set_no_sell(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return sprintf( "帮派商人专用银票，在各国商人买卖物品来获得任务金钱。" ); 
}
