#include <ansi.h>
#include <item.h>
#include <skill.h>

inherit COMBINED;
inherit ITEM;

int get_item_type() { return ITEM_TYPE_SPECIAL; }

// 函数：构造处理
void create()
{
        set_name("喜糖");
        set_picid_1(4253);
        set_picid_2(4253);
        set_value(1000);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{
	string name1,name2,x,y,z;
	int iLast;
	string tmp = HIR"结婚喜糖。\n使用后气血和魔法恢复全满，并有一定几率获得额外奖励。";
	name1 = get("special");
	if ( !stringp(name1) || sscanf(name1,"%s|%s|%s|%s|%s",name1,name2,x,y,z) != 5 )
		return tmp;
		
	return sprintf(HIR"%s与%s于%s年%s月%s日的结婚喜糖。\n使用后气血和魔法恢复全满，并有一定几率获得额外奖励。",name1,name2,x,y,z);
}
string get_special_desc(string cSpecial) 
{
	string name1,name2,x,y,z;
	int iLast;
	string tmp = "［可使用］"HIR"结婚喜糖。\n使用后气血和魔法恢复全满，并有一定几率获得额外奖励。";
	name1 = cSpecial;
	if ( !stringp(name1) || sscanf(name1,"%s|%s|%s|%s|%s",name1,name2,x,y,z) != 5 )
		return tmp;
		
	return sprintf("［可使用］"HIR"%s与%s于%s年%s月%s日的结婚喜糖。\n使用后气血和魔法恢复全满，并有一定几率获得额外奖励。",name1,name2,x,y,z);
}
int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	string name1,name2,x,y,z,cSpecial;
	object item;
	
	if ( gone_time(who->get_save("xitang")) < 3600 )
	{
		send_user(who,"%c%s",'!',"离你上次食用喜糖还不到一小时，此时你还不能食用！");
		return 0;	
	}
	who->set_hp(who->get_max_hp());
	who->set_mp(who->get_max_mp());
	who->set_save("xitang",time());
        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9154, 1, OVER_BODY, PF_ONCE );      
	cSpecial = gift->get("special");
	gift->add_amount(-1);
	rate = random(100);
	if ( rate < 30 )
		cash = 10000;
	else if ( rate < 55 )	//藏宝图
	{
		item = new("item/std/8000");
	}
	else if ( rate < 58 )	//复生丹
	{
		item = new("item/91/9178");
	}
	else if ( rate < 59 )	//血石
	{
		item = new("item/08/0003");
	}
	else if ( rate < 60 )	//法力石
	{
		item = new("item/08/0004");
	}
	
	if ( item )
	{
		p = item->move(who,-1);
		if ( !p )
		{
			destruct(item);
		}
		else
		{
			item->add_to_user(p);	
			if ( stringp(cSpecial) && sscanf(cSpecial,"%s|%s|%s|%s|%s",name1,name2,x,y,z) == 5 )
				CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG"玩家使用喜糖得到"HIY"%s"HIG"与"HIY"%s"HIG"的祝福，同时得到"HIR"%s"HIG"的意外惊喜！",who->get_name(),name1,name2,item->get_name()));
			
		}
	}
	else if (  cash )
	{
		who->add_cash(cash);
		if ( stringp(cSpecial) && sscanf(cSpecial,"%s|%s|%s|%s|%s",name1,name2,x,y,z) == 5 )
			CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG"玩家使用喜糖得到"HIY"%s"HIG"与"HIY"%s"HIG"的祝福，同时得到"HIR"%d金"HIG"的意外惊喜！",who->get_name(),name1,name2,cash));

	}	
	return 0;
}
