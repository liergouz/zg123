#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("120神器大礼包");
        set_picid_1(8503);
        set_picid_2(8503);
        set_amount(1);
        set_value(100);
}

int is_usable() {return 1;}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{ 
        return "装有120紫色神器的礼包，右击即可打开。"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,level,exp,cash;
	object item;
       	string *nTmp,tmp,cTmp;
	string *nFamily = ({"桃花源","蜀山","禁卫军","唐门","茅山","昆仑山","云梦泽"});
	int *bian=({1267,1238,1225,1201,1200});
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"你的道具栏空间不足够哦，请整理一下吧。");
    		return 0;
	}
	rate = random(6);
	if (rate<2) 
		item = new ("/item/70/9075_1");
	else if (rate<3)
		item = new ("/item/71/9075_1");
	else if (rate<4)
		item = new ("/item/72/9075_1");
	else if (rate<5)
		item = new ("/item/73/9075_1");
	else if (rate<6)
		item = new ("/item/74/9075_1");
	else if (rate<7) 
		item = new ("/item/75/9075_1");
	if ( item )
	{
		CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG"玩家由于勇杀BOSS，特获得周王"HIY"%s"HIG"的奖励！",who->get_name(),item->get_name()));
		p = item->move2(who);
		item->add_to_user(p);	
	}
	else if ( cash )
	{
		who->add_cash(cash);
		send_user(who,"%c%s",'!',sprintf("获得金钱 %d",cash));
	}		
	else if ( exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",'!',sprintf("获得经验%d",exp));
//		CHAT_D->sys_channel(0,sprintf(HIY"%s"HIR"玩家由于勇杀BOSS，特获得周王"HIY"经验%d"HIR"的奖励！",who->get_name(),exp));
	}
	gift->add_amount(-1);
	return 0;
}