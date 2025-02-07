#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>

inherit OFFICER;
inherit SAVE_F;

#define CHECK_TIME	3600
#define KEEP_TIME	3600*24

// 函数：获取人物造型
int get_char_picid() { return 9962; }
void do_welcome(string arg);
object search_my_hulu(object who);
object search_agent_hulu(object who);
int do_info(object who);
int get_exp(object who);

string get_save_file()	{ return "data/jishihulu"SAVE_EXTENSION;}
void send_info(object who);
// 函数：消除之前处理
void before_destruct()
{
	"item/04/0442"->set("savedata",get_dbase_2());
}
//恢复数据
void restore_savedata()
{
	int i,size;
	string *nTmp;
	mapping mpTmp;
	mpTmp = "item/04/0442"->get("savedata");
	if ( !mpTmp )
		return ;
	nTmp = keys(mpTmp);	
	size = sizeof(nTmp);
	for(i=0;i<size;i++)
		set_2(nTmp[i],mpTmp[nTmp[i]]);
}

// 函数：构造处理
void create()
{

        set_name("葫芦管理员");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
	if ( !clonep(this_object()) )
	{
		restore();
		restore_savedata();
		call_out("check_hulu",3);
	}
}

void do_look(object who)
{
	int id = getoid(this_object()),iTime;
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("葫芦管理员：\n    每领取一个济世葫芦带在身上，可以使你打怪获得的经验增加10％。你可以打开你人物属性界面中的济世葫芦设置按钮并点击“待领葫芦列表”按钮来打开葫芦领列表来领取济世葫芦，你也可以从我这里领取济世葫芦。怎么样?你现在要领取济世葫芦吗？\n"ESC"领取济世葫芦\ntalk %x# welcome.1\n"ESC"什么是济世葫芦？\ntalk %x# welcome.2\n"ESC"离开",id,id,));
	
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,id,i,size;
       	object who;
       	mapping mpInfo;
       	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
        	send_info(who);//葫芦列表
        	break;
        default:
        case 2:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("葫芦管理员：\n    相传济世葫芦是太上老君炼丹所用的法宝，凡人只要拿着济世葫芦，所做的事情都会事半功倍。只要你领取济世葫芦放在身上，在葫芦的经验累积到可存经验的上限时，就可以增加你打怪获得的经验的10％。你可以打开你人物属性界面中的葫芦设置并点击“待领葫芦列表”按钮来打开葫芦领列表，看看有没有其他玩家放出的济世葫芦。当然，你也可以在我这里领取济世葫芦。你现在要打开葫芦领取列表看看吗？\n"ESC"领取济世葫芦\ntalk %x# welcome.1\n"ESC"离开",id,));
        	break;
        case 3:
		mpInfo = get_save_2(sprintf("%d",who->get_number()));
		if ( mapp(mpInfo) )
		{
			send_user(who,"%c%s",'!',"请回收葫芦后再提取经验！");
			return ;
		}
		i = who->get_save_2("jishihulu.exp");
		if ( !i )
		{
			send_user(who,"%c%s",'!',"没有可以提取的经验！");
			return ;
		}		
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("葫芦管理员：\n    葫芦里面一共储存了%d点经验，提取经验后，将消耗你的济世葫芦%d点的可存经验上限。提取时请确保你提取经验后自身所存经验不超过你升级经验的10倍。\n"ESC"提取\nhulu 9\n"ESC"离开",i,i,));
        	break;

        }

}
//同级段寄存葫芦
int do_agend(object who)
{
	int id,flag;
	mapping mpInfo;
	object item;
	string legend;
	
	id = who->get_number();
	if ( !who->get_save_2("jishihulu.id") )	//是否首次寄存
	{
//		flag = 1;	初始化经验为50000
		mpInfo = ([]);
		mpInfo["limit"] = 50000;
	}
	else
	{
		id = who->get_number();
		mpInfo = get_save_2(sprintf("%d",id));
		if ( mapp(mpInfo) )
		{
			send_user(who,"%c%s",'!',"你已经在济世葫芦管理员处寄存了一个葫芦，不能再寄存了！");
			return 0;	
		}
		mpInfo = ([]);
		mpInfo["limit"] = who->get_save_2("jishihulu.limit") ;
		if ( mpInfo["limit"] < 10000 )
		{
			send_user(who,"%c%s",'!',"可存经验低于10000的济世葫芦不可以放出。");
			return 0;	
		}
	}
	if ( flag )
	{
		item = search_my_hulu(who);
		if ( !item  )
		{
			send_user(who,"%c%s",'!',"你身上没有济世宝玉！");
			return 0;
		}
		legend = sprintf("同级段寄存葫芦使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), who->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);

		item->remove_from_user();
		destruct(item);
	}
	mpInfo["exp"]	= who->get_save_2("jishihulu.exp");
	mpInfo["time"]	= time();
	mpInfo["name"] = who->get_name();
	mpInfo["level"]	= who->get_level();
	mpInfo["advance"] = 0;		//同级
	mpInfo["last_exp"] = -1;	//上次经验值
	mpInfo["account"] = who->get_id();	//帐号
	set_save_2(sprintf("%d",id),mpInfo);
	save();
	who->set_save_2("jishihulu.id",id);
	who->set_save_2("jishihulu.time",mpInfo["time"]);
	who->set_save_2("jishihulu.limit",mpInfo["limit"]);
	who->set_save_2("jishihulu.level",mpInfo["level"]);
	send_user(who,"%c%s",'!',"你在葫芦管理员处寄存了一个济世葫芦！");
	do_info(who);
	log_file("hulu.txt",sprintf("%s %s(%d) 同级寄存葫芦 %d/%d\n",short_time(),who->get_name(),id,mpInfo["exp"],mpInfo["limit"]));
	return 1;	
}

//高级段寄存葫芦
int do_advance_agend(object who)
{
	int id,flag;
	mapping mpInfo;
	object item;
	string legend;
	
	if ( who->get_level() >=140 )
	{
		send_user(who,"%c%s",';',"以你的等级，不能进行高级寄存！");
		return 0;	
	}
	if ( who->get_cash() < 50000 )
	{
		send_user(who,"%c%s",';',"高级段寄存葫芦需要50000金！");
		return 0;	
	}
	id = who->get_number();
	if ( !who->get_save_2("jishihulu.id") )	//是否首次寄存
	{
//		flag = 1;	初始化经验为50000
		mpInfo = ([]);
		mpInfo["limit"] = 50000;
	}
	else
	{
		mpInfo = get_save_2(sprintf("%d",id));
		if ( mapp(mpInfo) )
		{
			send_user(who,"%c%s",'!',"你已经在济世葫芦管理员处寄存了一个葫芦，不能再寄存了！");
			return 0;	
		}
		mpInfo = ([]);
		mpInfo["limit"] = who->get_save_2("jishihulu.limit") ;
		if ( mpInfo["limit"] < 10000 )
		{
			send_user(who,"%c%s",'!',"可存经验低于10000的济世葫芦不可以放出。");
			return 0;	
		}
	}
	if ( flag )
	{
		item = search_my_hulu(who);
		if ( !item  )
		{
			send_user(who,"%c%s",'!',"你身上没有济世宝玉！");
			return 0;
		}
		legend = sprintf("同级段寄存葫芦使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), who->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);

		item->remove_from_user();
		destruct(item);
	}
	who->add_cash(-50000);
	mpInfo["exp"]	= who->get_save_2("jishihulu.exp");
	mpInfo["time"]	= time();
	mpInfo["name"] = who->get_name();
	mpInfo["level"]	= who->get_level();
	mpInfo["advance"] = 1;		//高级
	mpInfo["last_exp"] = -1;	//上次经验值
	mpInfo["account"] = who->get_id();	//帐号
	set_save_2(sprintf("%d",id),mpInfo);
	save();
	who->set_save_2("jishihulu.id",id);
	who->set_save_2("jishihulu.time",mpInfo["time"]);
	who->set_save_2("jishihulu.limit",mpInfo["limit"]);
	who->set_save_2("jishihulu.level",mpInfo["level"]);
	send_user(who,"%c%s",'!',"你在葫芦管理员处寄存了一个济世葫芦！");
	do_info(who);
	log_file("hulu.txt",sprintf("%s %s(%d) 高级寄存葫芦 %d/%d\n",short_time(),who->get_name(),id,mpInfo["exp"],mpInfo["limit"]));
	return 1;	
}
//扩展葫芦
int do_expand(object who)
{
	int id,iTime,iAgent,iLimit,exp;
	mapping mpInfo;
	object item,player;
       	string legend;

	if ( !who->get_save_2("jishihulu") )
	{
		send_user(who,"%c%s",'!',"第一次扩展葫芦，请先把葫芦放出。");
		return 0;
	}	
	item = search_my_hulu(who);
	if ( !item )
	{
		send_user(who,"%c%s",'!',"扩展济世葫芦需要济世宝玉！");
		return 0;
	}
	id = who->get_number();
	mpInfo = get_save_2(sprintf("%d",id));
	if ( mapp(mpInfo) )
	{
		iAgent = 1;
		iLimit = mpInfo["limit"] + 50000;
		exp = mpInfo["exp"];
	}
	else
	{
		iLimit = who->get_save_2("jishihulu.limit") + 50000;
		exp = who->get_save_2("jishihulu.exp");
	}
		
	if ( iLimit >= 300000000 )
	{
		send_user(who,"%c%s",'!',"你的济世葫芦的可存经验已经到达上限，不能扩展！");
		return 0;	
	}
	legend = sprintf("扩展葫芦使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), who->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
	"/sys/user/cmd"->log_item(legend);
	item->remove_from_user();
	destruct(item);
	iTime = time();
	if ( iAgent )
	{
		mpInfo["time"]	= iTime;
		mpInfo["last_exp"] = -1;	//上次经验值
		mpInfo["limit"] = iLimit;
		set_save_2(sprintf("%d",id),mpInfo);
		save();
	}
	who->set_save_2("jishihulu.id",id);
	who->set_save_2("jishihulu.time",iTime);
	who->set_save_2("jishihulu.limit",iLimit);
	send_user(who,"%c%s",';',"你的济世葫芦可存经验增加了50000！");
	//刷新葫芦描述
	if ( iAgent && objectp(item=get_2(sprintf("%d.item",id))) && objectp(player=environment(item)) )
	{
		item->set("jishihulu.limit",mpInfo["limit"]);
		send_user( player, "%c%d%c", 0x31, getoid(item), 0 ); 
	}
	do_info(who);
	log_file("hulu.txt",sprintf("%s %s(%d) 扩展葫芦 %d/%d\n",short_time(),who->get_name(),id,exp,iLimit));
	return 1;	
}
//取回葫芦
int take_back(object who)
{
	int id,id1;
	mapping mpInfo;
	object player,item;
	
	id = who->get_number();
	mpInfo = get_save_2(sprintf("%d",id));
	if ( !mapp(mpInfo) )
	{
		send_user(who,"%c%s",'!',"你没有寄存中的济世葫芦！");
		return 0;	
	}
	if( (id1=get_2(sprintf("%d.id",id))) 
		&& objectp(player = find_player(sprintf("%d",id1)) ) 
		&& player->get_2("jishihulu.id") == who->get_number() )
	{
		item = search_agent_hulu(player);
		if ( item )
		{
			item->remove_from_user();
			destruct(item);	
		}
		player->delete_2("jishihulu");
		send_user(player,"%c%s",'!',sprintf("葫芦主人%s已经将济世葫芦回收。",who->get_name()));

	}
	delete_save_2(sprintf("%d",id));
	delete_2(sprintf("%d",id));
	delete_save_2(sprintf("%d",id));	
	save();
	who->set_save_2("jishihulu.id",id);
	who->delete_save_2("jishihulu.time");
	who->set_save_2("jishihulu.limit",mpInfo["limit"]);
	who->set_save_2("jishihulu.exp",mpInfo["exp"]);
	who->set_save_2("jishihulu.sum_exp",mpInfo["sum_exp"]);
	who->delete_save_2("jishihulu.level");
	send_user(who,"%c%s",'!',"济世葫芦回收成功！");
	do_info(who);
	log_file("hulu.txt",sprintf("%s %s(%d) 取回葫芦 %d/%d\n",short_time(),who->get_name(),id,mpInfo["exp"],mpInfo["limit"]));
	return 1;	
}
//提取经验
int get_exp(object who)
{
	int id,exp,max,sum,count;
	mapping mpInfo;
	object item,player;
	
	max = USER_EXP_D->get_upgrade_exp_limit(who);
	exp = who->get_upgrade_exp();
	exp = max - exp;
	if ( exp <= 0 )
		return 0;
	id = who->get_number();
	mpInfo = get_save_2(sprintf("%d",id));
	
	if ( mapp(mpInfo) )
	{
		send_user(who,"%c%s",'!',"请回收葫芦后再提取经验！");
		return 0;
	}
	sum = who->get_save_2("jishihulu.exp");		
	if ( sum > exp )
	{
		count = exp;
		sum -= exp;
	}
	else
	{
		count = sum;
		sum = 0;
	}
//	if ( mapp(mpInfo) )
//	{
//		mpInfo["exp"] = sum;
//		mpInfo["limit"] -= count;
//		set_save_2(sprintf("%d",id),mpInfo);
//		save();
//		//刷新葫芦描述
//		if ( objectp(item=get_2(sprintf("%d.item",id))) && objectp(player=environment(item)) )
//		{
//			item->set("jishihulu.limit",mpInfo["limit"]);
//			item->set("jishihulu.exp",mpInfo["exp"]);
//			send_user( player, "%c%d%c", 0x31, getoid(item), 0 ); 
//		}
//	}
//	else
//	{
//		who->set_save_2("jishihulu.exp",sum);	
//		who->add_save_2("jishihulu.limit",-count);	
//	}
	who->set_save_2("jishihulu.exp",sum);	
	who->add_save_2("jishihulu.limit",-count);
	who->add_exp(count);
	do_info(who);

	return 1;
}
//领取葫芦
int pick_hulu(object who, string arg)
{
	int level,p,i,size;
	mapping mpTmp,mpInfo;
	object item,*inv;
	
	if ( who->get_online_rate() == 50 )
	{
		send_user(who,"%c%s",'!',"疲劳游戏时间禁止领取济世葫芦。");
		return 0;	
	}
	else if ( who->get_online_rate() == 0 )
	{
		send_user(who,"%c%s",'!',"不健康游戏时间禁止领取济世葫芦。");
		return 0;	
	}
	if ( USER_INVENTORY_D->count_empty_carry(who) < 1 )
	{
		send_user(who,"%c%s",'!',"你身上道具栏已满！");
		return 0;	
	}
	if ( search_agent_hulu(who) )
	{
		send_user(who,"%c%s",'!',"济世葫芦不能重复领取！");
		return 0;	
	}
	mpTmp = get_2(arg);
	if ( mapp(mpTmp) && (item=mpTmp["item"]) )
	{
		send_user(who,"%c%s",'!',"这个葫芦已经被别人领取了！");
		return 0;	
	}
	mpInfo = get_save_2(arg);
	if ( !mapp(mpInfo) )
	{
		send_user(who,"%c%s",'!',"不存在这样的葫芦！");
		return 0;	
	}
	if ( mpInfo["limit"] == mpInfo["exp"] )
	{
		send_user(who,"%c%s",'!',"这个济世葫芦的累积经验已满，不能为你提供额外的经验奖励。");
		return 0;	
	}
	if ( to_int(arg) == who->get_number() )
	{
		send_user(who,"%c%s",'!',"你不可以领取自己的葫芦！");
		return 0;	
	}
	level = who->get_level()/10;
	if ( mpInfo["advance"] == 0 && level != mpInfo["level"]/10 )
	{
		send_user(who,"%c%s",'!',"以你的等级不适宜领取这个葫芦！");
		return 0;	
	}
	if ( mpInfo["advance"] == 1 && level < mpInfo["level"]/10+2 )
	{
		send_user(who,"%c%s",'!',"以你的等级不适宜领取这个葫芦！");
		return 0;	
	}	
	
	item = new("item/04/0442");
	item->set_no_save(1);		//不保存，下线就消失
	item->set("jishihulu.limit",mpInfo["limit"]);
	item->set("jishihulu.exp",mpInfo["exp"]);
	p = item->move(who,-1);
	item->add_to_user(p);
	who->set_2(sprintf("jishihulu.id"),to_int(arg));
	who->set_2(sprintf("jishihulu.time"),time());
	who->set_2(sprintf("jishihulu.item"),item);
	who->set_2(sprintf("jishihulu.level"),who->get_level());
	//设置临时数据
	set_2(sprintf("%s.id",arg),who->get_number());
	set_2(sprintf("%s.name",arg),who->get_name());
	set_2(sprintf("%s.item",arg),item);
	set_2(sprintf("%s.time",arg),time());
	send_user(who,"%c%s",'!',"你领取了济世葫芦！");
	log_file("hulu.txt",sprintf("%s %s(%d) 领取葫芦 %s(%s) %d/%d\n",short_time(),who->get_name(),who->get_number(),mpInfo["name"],arg,mpInfo["exp"],mpInfo["limit"]));
	return 1;
}
//归还葫芦
int return_hulu(object who)
{
	int id;
	object *inv,item;
	if ( !mapp(who->get_2("jishihulu")) )
		return 0;
	item = search_agent_hulu(who);
	if ( item )
	{
		item->remove_from_user();
		destruct(item);	
	}
	id = who->get_2(sprintf("jishihulu.id"));
	delete_2(sprintf("%d",id));
	who->delete_2("jishihulu");
	send_user(who,"%c%s",'!',"你归还了济世葫芦！");
	return 1;
}

//发送葫芦的信息
void send_info(object who)
{
	int i,size,level;
	string *nId;
	mapping mpInfo,mpTmp;
	nId = keys(get_save_dbase_2());
	send_user(who,"%c%c",0xA4,2, );
	size = sizeof(nId);
	if ( !size )
	{
		return ;
	}
	level = who->get_level()/10;
	for(i=0;i<size;i++)
	{
		if ( to_int(nId[i]) == who->get_number() )	//本人的不可见
			continue;
		mpTmp = get_2(nId[i]);
		if ( mapp(mpTmp) && objectp(mpTmp["item"]) )	//是否被领取
			continue;
		mpInfo = get_save_2(nId[i]);
		if ( !mapp(mpInfo) )
			continue;
		if ( mpInfo["advance"] == 0 && level != mpInfo["level"]/10 )
			continue;
		if ( mpInfo["advance"] == 1 && level < mpInfo["level"]/10+2 )
			continue;
		send_user(who,"%c%c%d%d%d%s",0xA4,2,to_int(nId[i]),mpInfo["limit"],mpInfo["exp"],mpInfo["name"] );
	}
	
}

//增加葫芦经验
int add_hulu_exp(object who, int exp)
{
	int exp1,level,id,max_exp,exp2;
	mapping mpInfo;
	object item;
	
	if ( exp <= 0 )
		return 0;
	if ( !objectp(item=who->get_2("jishihulu.item") ) )
		return 0;
	id = who->get_2("jishihulu.id");
	mpInfo = get_save_2(sprintf("%d",id));
	if ( !mapp(mpInfo) )
		return 0;
	max_exp = mpInfo["limit"] - mpInfo["exp"];	//最多可以充的经验值
	if ( max_exp <= 0 )
		return 0;
	level = who->get_2("jishihulu.level");	//玩家领取时等级
	if ( level > mpInfo["level"] )
		exp1 = exp * 15 / 100 * (mpInfo["level"]+10) / (level+10) ;
	else 
		exp1 = exp * 15 / 100 ;
	if (  exp1 > max_exp  )
		exp1 = max_exp;
//  if(is_god(who))
//	tell_user(who,"原始经验 %d 级别1 %d 级别2 %d 葫芦经验增加了%d",exp,mpInfo["level"],level,exp1);

	if ( exp1 == 0 )	//不能增加经验了
		return 0;
	exp2 = add_save_2(sprintf("%d.exp",id),exp1);
	save();
	//刷新葫芦的说明
	item->set("jishihulu.exp",exp2);
	if ( exp2 == item->get("jishihulu.limit") )
		send_user(who,"%c%s",';',"济世葫芦的累积经验已满，不再为你提供额外的经验奖励。");	
	send_user( who, "%c%d%c", 0x31, getoid(item), 0 ); 
	return exp1;	
}
//检查经验是否增加，不增加的返还给主人
int check_hulu()
{
	int i,size,iSave,iTime;
	string *nTmp,id,account;
	object item,user,user1,me;
	mapping mpInfo;
	
	remove_call_out("check_hulu");
	call_out("check_hulu",CHECK_TIME);
	nTmp = keys(get_save_dbase_2());
	iTime = time();
	for(i=0,size=sizeof(nTmp);i<size;i++)
	{
		id = nTmp[i];
		if ( mapp(get_2(id)) )
		{
			if ( objectp(item=get_2(sprintf("%s.item",id))) )	//有玩家领取
				continue;
		}
		mpInfo = get_save_2(id);
		if ( mpInfo["last_exp"] != mpInfo["exp"] )
		{
			set_save_2(sprintf("%s.last_exp",id),mpInfo["exp"]);
			set_save_2(sprintf("%s.checktime",id),iTime);
			iSave = 1;
			continue;
		}
		if ( gone_time(mpInfo["checktime"]) < KEEP_TIME )	//保存时间限制
			continue;
		//如果跟上次的经验值一致，则返回主人
		account = mpInfo["account"];
		if ( !objectp(user=find_player(id)) && user_exist(account) )
		{
			user1 = new( USER );
	                user1->set_id(account);
	                if( !user1->restore() )
	                	continue;
	                user = user1;
		}
		if ( !objectp(user) )
		{
			delete_save_2(id);
			iSave = 1;
			continue;	
		}
		user->set_save_2("jishihulu.id",to_int(id));
		user->delete_save_2("jishihulu.time");
		user->set_save_2("jishihulu.limit",mpInfo["limit"]);
		user->set_save_2("jishihulu.exp",mpInfo["exp"]);
		user->set_save_2("jishihulu.sum_exp",mpInfo["sum_exp"]);
		user->delete_save_2("jishihulu.level");
		delete_save_2(id);
		iSave = 1;
		if ( objectp(user1) )
		{
			user1->save();
			destruct(user1);	
		}
		MAILBOX->sys_mail(account,to_int(id),"你的济世葫芦放置期限已过，已经把葫芦归还给你了。");
		log_file("hulu.txt",sprintf("%s %s(%s) 寄存期限已过，归还\n",short_time(),mpInfo["name"],id));
	}
	if ( iSave )
		save();
	return 1;
}

//获取自己葫芦信息
int do_info(object who)
{
	int id,limit,exp,flag,flag1,id1;
	string name="";
	mapping mpInfo;
	object item,player;
	
	id = who->get_number();
	mpInfo = get_save_2(sprintf("%d",id));
	if ( mapp(mpInfo) )
	{
		flag = 1;
		exp = mpInfo["exp"];
		limit = mpInfo["limit"];
		if ( objectp(item=get_2(sprintf("%d.item",id))) )
		{
			flag1 = 1;
			name = get_2(sprintf("%d.name",id));
			id1 = get_2(sprintf("%d.id",id));
		}
	}
	else
	{
		exp = who->get_save_2("jishihulu.exp");	
		if ( !who->get_save_2("jishihulu.id") )	
			limit = 50000;
		else
			limit = who->get_save_2("jishihulu.limit");
		
	}
	send_user(who,"%c%c%d%d%d%d%d%s",0xA4,1,limit,exp,flag,flag1,id1,name);

	return 1;
}
//检查购买的济世宝玉
object search_my_hulu(object who)
{
	int i,size;
	object *inv,item,obj;

	inv = all_inventory(who, 1, MAX_CARRY);
	for(i=0,size=sizeof(inv);i<size;i++)	//拿走济世宝玉
	{
		if ( !objectp(item=inv[i]) )
			continue;
		if ( item->get_name() != "济世宝玉" || !item->is_jishihulu() )
			continue;
		obj = item;
		break;
	}
	return obj;
}
//检查领取的葫芦
object search_agent_hulu(object who)
{
	int i,size;
	object *inv,item,obj;

	inv = all_inventory(who, 0, 0);
	for(i=0,size=sizeof(inv);i<size;i++)	//拿走葫芦
	{
		if ( !objectp(item=inv[i]) )
			continue;
		if ( item->get_name() != "济世葫芦" || !item->is_agent() )
			continue;
		obj = item;
		break;
	}
	return obj;
}


//提升葫芦经验，测试用
int set_exp(object who,string id, int exp)
{
	int iTime;
	mapping mpInfo;
	object item;
       	string legend;
	
	if( !is_god(who) )
		return 0;
	if ( id == "0" )
		id = sprintf("%d",who->get_number());
	mpInfo = get_save_2(id);
	if ( !mapp(mpInfo) )
	{
		send_user(who,"%c%s",'!',"没有寄存中的济世葫芦！");
		return 0;
	}
	mpInfo["exp"] = exp;
	set_save_2(id,mpInfo);
	save();
	return 1;	
}