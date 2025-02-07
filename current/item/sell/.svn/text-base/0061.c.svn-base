#include <ansi.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;

#define VIP_TIME	3600*24*31	//vip绑定时间
//#define VIP_TIME	(who->get("test_vip")?who->get("test_vip"):3600*24*31)	//vip绑定时间

int get_item_value() {return 300 ;}
int get_item_value_2() {return 300 ;}
int get_item_number() {return 10001076 ;}
int get_item_color() {return 1 ;}
int check_revive(object who);
int add_revive(object who,int i);
void send_vip_to_friend(object who,int flag);
void effect_done( object who );
void set_vip_effect(object who);

// 函数：构造处理
void create()
{
        set_name("VIP包");
        set_picid_1(8615);
        set_picid_2(8615);
        set_value(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "VIP包，购买后即与购买玩家角色ID绑定，绑定后即可获得奇妙的效果和优厚的待遇，持续时间31天。";
}

string get_short()
{
	return "VIP包，购买后即与购买玩家角色ID绑定，持续时间31天。";
}
	
string get_loop_desc(object me)
{
	int iVipTime,i;
	mixed *mixTime;
	
	iVipTime = me->get_save_2("vip_package.time");
	if (iVipTime == 0)
		return "";
	i = check_revive(me);
	mixTime = localtime(iVipTime);
	return sprintf("VIP效果：\n    物理攻击力增加50点\n    法术攻击力增加50点\n    物理防御增加50点\n    法术防御增加50点\n    使用一般药品冷却时间缩短5秒\n    本日VIP免费复活次数剩余%d次\nVIP效果持续到:\n    %d-%02d-%02d %02d:%02d:%02d。"
		,i,mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],
		mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]);
}

int give_item_to_user( object who) 
{
	int iVip,iVipTime;
	object item=this_object();
	string legend;
	mixed *mixTime;
		
	iVip = who->get_vip();
	if ( iVip != 0 && iVip != 1 )
		return 0;
	iVipTime = who->get_save_2("vip_package.time");
	if ( iVipTime == 0 )
		iVipTime = time()+VIP_TIME;
	else 
		iVipTime += VIP_TIME;
	legend = sprintf("点数购买 @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "商店界面", who->get_name(), who->get_number(),	get_ip_name(who), who->get_id(), item->get_name(), "0", 1, "0", get_z(who), get_x(who), get_y(who) );
	"/sys/user/cmd"->log_item(legend);
	if ( iVip == 0 )
		who->delete_save_2("vip_package");
	who->delete_save_2("vip_package.trial");	//试用VIP包
	who->set_vip(1);
	who->add_save_2("vip_package.doubles",40);
	who->set_save_2("vip_package.time",iVipTime);
	who->add_title("V001");
	send_user( who, "%c%w%w%c", 0x81, 7401, 999, EFFECT_GOOD );
	
	USER_ENERGY_D->count_cp(who);
	USER_ENERGY_D->count_pp(who);
	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_dp(who);
	log_file("buyitem.dat",	sprintf("%s %s(%d) 购买%s成功 %d %d\n",	short_time(), who->get_id(), who->get_number(), item->get_name(),	1, 300));
//	send_user(who,  "%c%s", '!', sprintf("您买下%s。", item->get_name()) );
	mixTime = localtime(iVipTime);
	send_user(who,"%c%s",';',sprintf("你绑定了VIP包，VIP绑定的到期时间是%d-%02d-%02d %02d:%02d:%02d。观察VIP效果描述即可了解到期时间。你也可以去找神仙爷爷查询VIP绑定到期的时间。",mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],		mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]));
	send_user( who, "%c%w%s", 0x82, 7401, get_loop_desc(who));
	send_user( who, "%c%c%c", 0xA2, 4, 1);
	send_user( who, "%c%c%c", 0xA2, 3, 3-who->get_save_2("vip_package.revive.count"));
	send_vip_to_friend(who,1);
	
//	if ( USER_INVENTORY_D->count_empty_carry(who) )
//	{
//		item = new("item/08/shuiping");	
//		if ( item )
//		{
//			iVip = item->move(who,-1);	
//			item->add_to_user(iVip);
//			send_user(who,"%c%s",'!',"恭喜你得到宠物道具"HIR"水瓶");
//		}
//	}
	return 1;
}
//检查复活次数
int check_revive(object who)
{
	mixed *mxTmp;
	
	if ( who->get_vip() != 1 )
		return 0;
	mxTmp = localtime(time());
	if ( who->get_save_2("vip_package.revive.day") != mxTmp[TIME_YDAY] )
	{
		who->set_save_2("vip_package.revive.day",mxTmp[TIME_YDAY]);
		who->delete_save_2("vip_package.revive.count");	
		send_user( who, "%c%w%s", 0x82, 7401, "");
		send_user( who, "%c%c%c", 0xA2, 3, 3);
	}
	return 3-who->get_save_2("vip_package.revive.count");
}
//累计当天复活次数
int add_revive(object who,int i)
{
	int j;
	
	if ( who->get_vip() != 1 )
		return 0;
	j = check_revive(who);
	if ( i > j )
		return 0;
	j = who->add_save_2("vip_package.revive.count",i);	
	send_user( who, "%c%w%s", 0x82, 7401, "");
	send_user( who, "%c%c%c", 0xA2, 3, 3-j);

	return i;	
}


//登录时设置vip
void vip_effect(object who)
{
	int iVipTime,i;
	if ( who->get_vip() != 1 )
		return ;
	iVipTime = who->get_save_2("vip_package.time");
	i = iVipTime-time();
	if ( i <= 0 )
	{
		effect_done(who);
		return ;	
	}
	send_user( who, "%c%w%w%c", 0x81, 7401, 999, EFFECT_GOOD );
	send_user( who, "%c%c%c", 0xA2, 4, 1);
	send_user( who, "%c%c%c", 0xA2, 3, 3-who->get_save_2("vip_package.revive.count"));
}
//vip结束,清除状态
void effect_done( object who )
{
	if ( who->get_vip() != 1 )
		return ;
	who->set_vip(0);
	who->delete_title("V001");
	who->delete_save_2("vip_package");	
	send_user( who, "%c%w%w%c", 0x81, 7401, 0, EFFECT_GOOD );
	send_user( who, "%c%c%c", 0xA2, 4, 0);	
	//重新计算属性
	USER_ENERGY_D->count_cp(who);
	USER_ENERGY_D->count_pp(who);
	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_dp(who);
	send_vip_to_friend(who,0);

}
//购买前提示
int question_before_buy(object who,string arg)
{
	if ( stringp(who->get("buy_vip_package")) )
	{
		who->delete("buy_vip_package");	
		return 0;
	}
	who->set("buy_vip_package",arg);
	send_user(who,"%c%c%w%s",':',3,0,sprintf("你是否确定对当前角色ID：%s（%d）绑定VIP包？\n"ESC"确定\nvip 1\n"ESC"取消\nvip 1\n",who->get_name(),who->get_number()));
	return 1;
}
//每次允许出售的数量
int get_sell_amount() { return 1;}

//发送(10)/取消(11)vip标志给朋友
void send_vip_to_friend(object who,int flag)
{
	int i,size,id;
	mapping mpFriend;
	string *nTmp;
	object obj;
	
	mpFriend = who->get_friend_dbase();
	nTmp = keys(mpFriend);
	size = sizeof(nTmp);
	if ( !size )
		return ;
	id = who->get_number();
	if ( flag == 1 )
		flag = 10;
	else
		flag = 11;
	for(i=0;i<size;i++)
	{
		if( !objectp( obj = find_player( nTmp[i] ) )  ) 
			continue;
		send_user( obj, "%c%c%d", 0x46, flag, id );	
	}
}

void check_vip(object who)
{
	check_revive(who);
	if ( who->get_save_2("vip_package.time") <= time() )
		effect_done(who);
}

int give_trial_vip(object me , object who)
{
	int iVip,iVipTime;
	mixed *mixTime;
	if ( who->get_level() < 30 )
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),me->get_name()+":\n    你的等级不够30级，不能领取。");
		return 0;
	}
	if ( who->get_save("vip_trial") )
	{
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),me->get_name()+":\n    你已经领过试用VIP包了。");
		return 0;
	}
	iVip = who->get_vip();
	if ( iVip != 0 && iVip != 1 )
		return 0;
	if ( iVip == 0 )
	{
		who->delete_save_2("vip_package");
		who->set_save_2("vip_package.trial",1);	//试用VIP包
		who->set_vip(1);
		iVipTime = time()+3600*24*3;
	}
	else
		iVipTime = who->get_save_2("vip_package.time")+3600*24*3;
	who->set_save("vip_trial",time());
	who->add_save_2("vip_package.doubles",20);
	who->set_save_2("vip_package.time",iVipTime);
	who->add_title("V001");
	send_user( who, "%c%w%w%c", 0x81, 7401, 999, EFFECT_GOOD );
	
	USER_ENERGY_D->count_cp(who);
	USER_ENERGY_D->count_pp(who);
	USER_ENERGY_D->count_ap(who);
	USER_ENERGY_D->count_dp(who);
	mixTime = localtime(iVipTime);
	send_user(who,"%c%s",';',sprintf("你绑定了VIP包，VIP绑定的到期时间是%d-%02d-%02d %02d:%02d:%02d。观察VIP效果描述即可了解到期时间。你也可以去找神仙爷爷查询VIP绑定到期的时间。",mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],		mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]));
	send_user( who, "%c%w%s", 0x82, 7401, get_loop_desc(who));
	send_user( who, "%c%c%c", 0xA2, 4, 1);
	send_user( who, "%c%c%c", 0xA2, 3, 3-who->get_save_2("vip_package.revive.count"));
	send_vip_to_friend(who,1);	
	send_user(who, "%c%s", '!',"恭喜您已经获得了三天的VIP包试用服务");
	return 1;	
}