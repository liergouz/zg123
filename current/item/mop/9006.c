#include <ansi.h>
inherit ITEM;

int get_item_value() {return 5 ;}
int get_item_value_2() {return 5 ;}
int get_item_number() {return 10001100 ;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name("败类经验包");
        set_picid_1(3025);
        set_picid_2(3025);
        set_value(198);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "刷败类时增加百分之五十的经验";
}

string get_short()
{
	return "刷败类时增加百分之五十的经验";
}
	
string get_loop_desc(object me)
{
	return "刷败类时增加百分之五十的经验";
}

int give_item_to_user( object who) 
{
	who->set("wg_bl_15",1);
	send_user(who, "%c%s", ';', "您将按百分之五十经验加成的方式刷败类。");
	return 1;
}
//购买前提示
/*int question_before_buy(object who,string arg)
{
	if ( stringp(who->get("buy_vip_package")) )
	{
		who->delete("buy_vip_package");	
		return 0;
	}
	who->set("buy_vip_package",arg);
	send_user(who,"%c%c%w%s",':',3,0,sprintf("你是否确定对当前角色ID：%s（%d）绑定VIP包？\n"ESC"确定\nvip 1\n"ESC"取消\nvip 1\n",who->get_name(),who->get_number()));
	return 1;
}*/
//每次允许出售的数量
int get_sell_amount() { return 1;}
