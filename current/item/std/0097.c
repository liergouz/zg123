#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 1; }

// 函数：构造处理
void create()
{
        set_name("英雄符纹");
        set_picid_1(4952);
        set_picid_2(4952);
        set_amount(1);
        set_unit("块");
        set_value(20);
//        set_no_give(1);
//        set_no_sell(1); 
}

int is_usable() {return 1;}

int get_item_color() {return 1;}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "战国英雄常带的一种配饰。相传英雄在战斗时，英雄符纹聚集了大量的灵气。\n（右键点击使用可以获取对应自身等级的经验值）";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,level,exp,cash,limit_exp;
	object item;
       	string *nTmp,tmp,cTmp,result="";
	if ( (level=who->get_level() )<=10 )
	{
		send_user(who,"%c%s",';',"你的等级太低，不能使用英雄符纹。");
		return 0;
	}
	exp = 10000+level*level*50;
	limit_exp=USER_EXP_D->get_upgrade_exp_limit(who);
	if (exp+who->get_upgrade_exp()>limit_exp)
	{
		send_user(who,"%c%s",';',"您所获得的经验，将会超过您的经验上限，请处理您的经验！！" );
		return 0;
	}
	result += sprintf("你获得了%d点的经验。",exp);
	who->add_exp(exp);
	send_user(who,"%c%s",';',result);
	gift->add_amount(-1);
	return 0;
}