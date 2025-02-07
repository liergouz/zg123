#include <npc.h>
#include <city.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <equip.h>
inherit SAVE_F;
inherit OFFICER;

int iStart_n,iFinish_n;
#define GUESS_TRUE_TIGER	"/sys/party/guess_true_tiger"


void do_bonus(string arg);
void do_tiger_bonus(string arg);


// 函数：获取人物造型
int get_char_picid() { return 0952; }
string get_save_file()	{ return "data/wg_national_ex"SAVE_EXTENSION;}
// 函数：构造处理
void create()
{
	restore();
        set_name("兑换天使");

        set_2( "talk", ([
                 "bonus"        : (: do_bonus :),
                 "tiger"	: (: do_tiger_bonus :),
        ]) );
//	iStart_n = mktime(2007,9,27,11,0,0);	
//	iFinish_n = mktime(2007,10,8,0,0,0);
        setup();
}

void do_look( object who )
{
	__FILE__->do_look_2(who, this_object());
}

void do_look_2( object who, object me )
{
	int id, iTime;
	string tiger_str = "",national="",ssss,national2="";
	id = getoid(me);
	iTime = get_party_time();
	if(GUESS_TRUE_TIGER->is_active_open()) {
		tiger_str = sprintf(ESC"真假虎王\ntalk %x# tiger.1\n",id);
	}
	ssss=":\n    你有啥好玩意儿都可以交给我兑换奖品噢～我这里奖品可丰厚了！\n";

	if(iTime<iFinish_n && iTime>iStart_n)
	{
		national2 = sprintf(ESC HIY"购买国庆疯狂大礼包\ntalk %x# bonus.43\n",id);
		national = sprintf(ESC HIY"领取猫扑大杂烩赠送大礼包\ntalk %x# bonus.34\n"
				   ESC HIY"领取校内网网赠送大礼包\ntalk %x# bonus.34\n"
				   ESC HIY"领取官方赠送新手礼包\ntalk %x# bonus.34\n",id,id,id);
//		national += sprintf(ESC"领取特殊修为奖\ntalk %x# bonus.36\n",id);
	}

	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		me->get_name()+ssss
		+ tiger_str + national+ national2
		+ sprintf(ESC"四色球\ntalk %x# bonus.1\n"
			  ESC"黄金圣衣称号兑换\ntalk %x# bonus.32\n"
			  ESC"查看我的任务积分\ntalk %x# bonus.33\n"
			  ESC"离开", id,id,id) );
}

//	真假虎王活动奖励领取
void do_tiger_bonus(string arg) {
	__FILE__->do_tiger_bonus_reflash(this_object(),arg);	
}

//	真假虎王活动的领取，在线更新
void do_tiger_bonus_reflash(object me,string arg) {
	object who;
	string say_word;
	string *active_bonus;
	int level,flag,id;
	who  = this_player();
	id   = getoid(me);
	flag = to_int(arg);
	level= who->get_save("guess_true_tiger");
	if(who->get_save("guess_true_tiger_fight")) {
		GUESS_TRUE_TIGER->delete_tigers_on_player(who);
		who->delete_save("guess_true_tiger");
		level = 0;
	}
	switch(flag) {
		case 1:
			if(level>0) {
				if(level >= 6 ) {
					say_word = "你太厉害了，居然过了6关，可以领取100万战国币与增加物防与法防称号的奖励！";
				} else {
					active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
					if(level > 1) {
						say_word = sprintf("你一共过了%d关，可以领取%s战国币和“"HIR"%s"NOR"”称号的奖励。",level,active_bonus[2],active_bonus[1]);
					} else {
						say_word = sprintf("你一共过了%d关，可以领取“"HIR"%s"NOR"”称号的奖励。",level,active_bonus[1]);
					}
				}
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n%s\n"
					ESC"领取奖励\ntalk %x# tiger.2\n"
					ESC"离开",me->get_name(),say_word,id
				));
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n你为什么不试着去玩玩这个闯关的游戏呢？\n"ESC"离开",me->get_name()));
			}
			break;
		case 2:
			if(level>0) {
				active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);				
				who->add_cash(to_int(replace_string(active_bonus[2],",","")));
				if(level >1) {
					send_user( who, "%c%s", '!', sprintf(HIY"您的金钱增加了 %s。",active_bonus[2]));
				}				
				who->delete_save("guess_true_tiger");
				if(who->have_title(active_bonus[0])) {
					send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你已经有这样的称号了！\n"ESC"离开",me->get_name()));
					return ;
				}
				who->add_title(active_bonus[0]);
				who->show_title(active_bonus[0]);
				send_user( who, "%c%s", ';', sprintf(HIY"您兑换了%s的称号。",who->get_title()));
			}
			break;
	}
}

void do_bonus(string arg)
{
	__FILE__->do_bonus_2(this_object(),arg);
}

void do_bonus_2(object me , string arg)
{
	int flag, p,iTime,i,j,size,id,x,y,z,level,rate,amount,count;
       	object who,item,*nTeam,member,npc,map,item_q,item_q2,item_q3,item_q4,*inv,*inv2;
       	string name,*nTmp,tmp,result="",result2="",cTmp,national2,ssss;
        string result_key="", *key=({});
	mixed *mxTime;  
	int *armor=({101,102,104,105,106});
	iTime = get_party_time();

	if (MAIN_D->get_host_type()==2)
		return ;
		
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);

        switch(flag)
        {
        case 1:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    大话战国的各路妖魔最近忙的不亦乐乎，正在积极准备开展职业足球联赛！不过他们比赛的场地破坏了很多战国百姓的良田，作为一名战国中的勇士，我们怎能袖手旁观！具知情人士透露，为了备战比赛，每个怪物都随身携带多个足球出门，只要我们将他们的足球抢过来，就能影响他们的比赛，保护百姓的田地！\n    如果你有花球与红、蓝、黑球都可以拿来和我兑换奖品，你可以自己选择兑换方式。\n"
			ESC"黑球兑换奖励\ntalk %x# bonus.2\n"
			ESC"蓝球兑换奖励\ntalk %x# bonus.7\n"
			ESC"红球兑换奖励\ntalk %x# bonus.12\n"
			ESC"花球兑换奖励\ntalk %x# bonus.17\n"
			ESC"两只球(黑+蓝)兑换2张藏宝图\ntalk %x# bonus.22\n"
			ESC"三只球(黑+蓝+红)兑换紫参丹\ntalk %x# bonus.24\n"
			ESC"四只球(黑+蓝+红+花)兑换金色装备\ntalk %x# bonus.26\n"
			ESC"两只球(黑+蓝)兑换随机奖品\ntalk %x# bonus.28\n"
			ESC"三只球(黑+蓝+红)兑换随机奖品\ntalk %x# bonus.30\n"
			ESC"离开",me->get_name(),id,id,id,id,id,id,id,id,id));
        	break;
        case 2:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你可以用一只黑球兑换以下奖励：\n"
			ESC"一只黑球兑换5张回帮符\ntalk %x# bonus.3\n"
			ESC"一只黑球兑换10张飞行符\ntalk %x# bonus.5\n"
			ESC"离开",me->get_name(),id,id));
        	break;
        case 3:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只黑球来兑换5张回帮符吗？\n"
			ESC"确定\ntalk %x# bonus.4\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 4:
        	if( !objectp( item_q = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/std/0410");//回帮符
		item->set_amount(5);
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "您用一只黑球兑换了5张回帮符");
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只黑球来兑换10张飞行符吗？\n"
			ESC"确定\ntalk %x# bonus.6\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 6:
        	if( !objectp( item_q = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/std/0409");//飞行符
		item->set_amount(10);
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "您用一只黑球兑换了10张飞行符");
        	break;
        case 7:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你可以用一只黑球兑换以下奖励：\n"
			ESC"一只蓝球兑换1张藏宝图\ntalk %x# bonus.8\n"
			ESC"一只蓝球兑换10颗活络丸\ntalk %x# bonus.10\n"
			ESC"离开",me->get_name(),id,id));
        	break;
        case 8:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只蓝球来兑换1张藏宝图吗？\n"
			ESC"确定\ntalk %x# bonus.9\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 9:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/std/8000");//藏宝图
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "您用一只蓝球兑换了1张藏宝图");
        	break;
        case 10:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只蓝球来兑换10颗活络丸吗？\n"
			ESC"确定\ntalk %x# bonus.11\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 11:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item = new ("item/91/9101");//活络丸
		item->set_amount(10);
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "您用一只蓝球兑换了10颗活络丸");
        	break;
        case 12:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你可以用一只红球兑换以下奖励：\n"
			ESC"一小时内增加气血上限200点\ntalk %x# bonus.13\n"
			ESC"一小时内增加法力上限200点\ntalk %x# bonus.15\n"
			ESC"离开",me->get_name(),id,id));
        	break;
        case 13:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只红球来兑换“一小时内增加气血上限200点”的临时效果吗？\n"
			ESC"确定\ntalk %x# bonus.14\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 14:
        	if( !objectp( item_q = present("红球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_HP) )
		{
			send_user(who, "%c%s", ';', "您已经拥有该临时效果了。");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_HP, 3600);//+HP
	        USER_ENERGY_D->count_max_hp(who);
		send_user( who, "%c%w%w%c", 0x81, 0443, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "你用一只红球兑换了“一小时内增加气血上限200点”的临时效果");
        	break;
        case 15:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只红球来兑换“一小时内增加法力上限200点”的临时效果吗？\n"
			ESC"确定\ntalk %x# bonus.16\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 16:
        	if( !objectp( item_q = present("红球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_MP) )
		{
			send_user(who, "%c%s", ';', "您已经拥有该临时效果了。");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_MP, 3600);//+MP
	        USER_ENERGY_D->count_max_mp(who);
		send_user( who, "%c%w%w%c", 0x81, 0444, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "你用一只红球兑换了“一小时内增加法力上限200点”的临时效果");
        	break;
        case 17:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你可以用一只花球兑换以下奖励：\n"
			ESC"一小时内增加物理攻击力100点\ntalk %x# bonus.18\n"
			ESC"一小时内增加法术攻击力100点\ntalk %x# bonus.20\n"
			ESC"离开",me->get_name(),id,id));
        	break;
        case 18:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只花球来兑换“一小时内增加物理攻击力100点”的临时效果吗？\n"
			ESC"确定\ntalk %x# bonus.19\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 19:
        	if( !objectp( item_q = present("花球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_AP) )
		{
			send_user(who, "%c%s", ';', "您已经拥有该临时效果了。");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_AP, 3600);//+AP
	        USER_ENERGY_D->count_ap(who);
		send_user( who, "%c%w%w%c", 0x81, 0445, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "你用一只花球兑换了“一小时内增加物理攻击力100点”的临时效果");
        	break;
        case 20:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只花球来兑换“一小时内增加法术攻击力100点”的临时效果吗？\n"
			ESC"确定\ntalk %x# bonus.21\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 21:
        	if( !objectp( item_q = present("花球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if( get_effect(who, EFFECT_USER_EXCHANGE_CP) )
		{
			send_user(who, "%c%s", ';', "您已经拥有该临时效果了。");
        		return;
		}
		item_q->add_amount(-1);
	        set_effect(who, EFFECT_USER_EXCHANGE_CP, 3600);//+CP
	        USER_ENERGY_D->count_cp(who);
		send_user( who, "%c%w%w%c", 0x81, 0446, 3600, EFFECT_GOOD );
		send_user(who, "%c%s", ';', "你用一只花球兑换了“一小时内增加法术攻击力100点”的临时效果");
        	break;
        case 22:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只黑球与一只蓝球来兑换2张藏宝图吗？\n"
			ESC"确定\ntalk %x# bonus.23\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 23:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 2 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item = new ("item/std/8000");//藏宝图
		p = item->move(who,-1);
		item->add_to_user(p);	
		item = new ("item/std/8000");//藏宝图
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "您用一只黑球与一只蓝球兑换了2张藏宝图");
        	break;
        case 24:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只黑球、一只蓝球与一只红球来兑换紫参丹吗？\n"
			ESC"确定\ntalk %x# bonus.25\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 25:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q3 = present("红球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item_q3->add_amount(-1);
		item = new ("item/91/9167");//紫参丹
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', "您用一只黑球、一只蓝球与一只红球兑换了紫参丹");
		CHAT_D->sys_channel( 0, CHAT+sprintf("恭喜"HIR"%s"NOR"获得奖品"HIR"%s" ,who->get_name(),item->get_name())); 
        	break;
        case 26:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用黑、蓝、红、花球各一只来兑换金色装备吗？\n"
			ESC"确定\ntalk %x# bonus.27\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 27:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q3 = present("红球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q4 = present("花球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item_q3->add_amount(-1);
		item_q4->add_amount(-1);
		level=who->get_level();
		if (level>120) level=120;
		if (level>50 && who->get_fam_name()=="") level=50;
		nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),level,armor[random(5)]);
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return ;
		item = new(tmp);
		item->set_record(1);
		ITEM_EQUIP_D->init_equip_prop_3(item);
		if (item->get_item_color() != 2) 
		{
			item->set_item_color(2);
			item->set_bind(1);
		}
		p = item->move(who,-1);
		item->add_to_user(p);
		send_user(who,"%c%s",';',sprintf("您用黑、蓝、红、花球各一只兑换了金色装备： %s",item->get_name()));
		CHAT_D->sys_channel( 0, CHAT+sprintf("恭喜"HIR"%s"NOR"获得奖品"HIR"%s" ,who->get_name(),item->get_name())); 
        	break;
        case 28:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用两只不同种类球（黑+蓝）来兑换随机奖品吗？\n"
			ESC"确定\ntalk %x# bonus.29\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 29:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);

		rate = random(10000);
		if (rate<3000)
		{
			amount = 5000+random(10001);
			who->add_cash(amount);
			result = result + sprintf(HIR"%d金",amount);
		}
		else if (rate>=3000 && rate<6000)
		{
			amount = 5000+random(5001);
			who->add_exp(amount);
			result = result + sprintf(HIR"%d经验",amount);
		}
		else if (rate>=6000 && rate<9000)
		{
			amount = 100+random(200);
			who->add_potential(amount);
			result = result + sprintf(HIR"%d潜能",amount);
		}
		else if (rate>=9000 && rate<9300)
		{
	        	item = new("item/std/6003");		//麻布包裹
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9300 && rate<9600)
		{
	        	item = new("item/44/4488");		//随机宠物技能丹
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9600 && rate<9800)
		{
	        	item = new("item/91/9125");		//再造丸
			result = result + sprintf(HIR"%s",item->get_name());
			result2 = result2 + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9800 && rate<9900)
		{
	        	item = new("item/91/9160");		//气脉丹
			result = result + sprintf(HIR"%s",item->get_name());
			result2 = result2 + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9900 && rate<10000)
		{
	        	item = new("item/91/9161");		//周天丹
			result = result + sprintf(HIR"%s",item->get_name());
			result2 = result2 + sprintf(HIR"%s",item->get_name());
		}
		if ( item )
		{
			p = item->move(who,-1);
			item->add_to_user(p);	
		}
		send_user(who, "%c%s", ';', sprintf("您用一只黑球与一只蓝球兑换了%s",result));
		if (result2 != "") CHAT_D->sys_channel( 0, CHAT+sprintf("恭喜"HIR"%s"NOR"获得奖品"HIR"%s" ,who->get_name(),result2)); 
        	break;
        case 30:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你确定要用一只黑球、一只蓝球与一只红球来兑换随机奖品吗？\n"
			ESC"确定\ntalk %x# bonus.31\n"
			ESC"离开",me->get_name(),id));
        	break;
        case 31:
        	if( !objectp( item_q = present("蓝球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q2 = present("黑球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
        	if( !objectp( item_q3 = present("红球", who, 1, MAX_CARRY) ) )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您身上的球不足以兑换该奖品，建议您多收集几个后再来找我吧！\n"ESC"离开",me->get_name()));
        		return;
        	}
		if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上的东西好像太多了，清理一下再来兑换奖品吧～\n"ESC"离开",me->get_name()));
	    		return;
		}
		item_q->add_amount(-1);
		item_q2->add_amount(-1);
		item_q3->add_amount(-1);

		rate = random(10000);
		if (rate<3600)
		{
			cTmp = BOOK_FILE->get_book_file();
			item = new (cTmp);//随机门派技能进阶书
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=3600 && rate<5000)
		{
			item = new ("item/91/9167");//紫参丹
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=5000 && rate<6100)
		{
			item = new ("item/91/9162");//逍遥散
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=6100 && rate<7200)
		{
			item = new ("item/91/9163");//金桑散
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=7200 && rate<8300)
		{
			item = new ("item/91/9164");//紫心丹
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=8300 && rate<9400)
		{
			item = new ("item/91/9165");//归元丹
			result = result + sprintf(HIR"%s",item->get_name());
		}
		else if (rate>=9400 && rate<10000)
		{
			level=who->get_level();
			if (level>120) level=120;
			if (level>50 && who->get_fam_name()=="") level=50;
			nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),level,armor[random(5)]);
			tmp = nTmp[random(sizeof(nTmp))];
			if ( !stringp(tmp) )
				return ;
			item = new(tmp);
			item->set_record(1);
			ITEM_EQUIP_D->init_equip_prop_3(item);
			if (item->get_item_color() != 2) 
			{
				item->set_item_color(2);
				item->set_bind(1);
			}
		}
		p = item->move(who,-1);
		item->add_to_user(p);	
		send_user(who, "%c%s", ';', sprintf("您用一只黑球、一只蓝球与一只红球兑换了%s",item->get_name()));
		CHAT_D->sys_channel( 0, CHAT+sprintf("恭喜"HIR"%s"NOR"获得奖品"HIR"%s" ,who->get_name(),item->get_name())); 
//		USER_D->user_channel(result);	
        	break;
        case 32:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    任务次数越多，你能够兑换到的称号越高级。\n"
		ESC"5次任务兑换“青铜圣斗士”称号\ntalk %x# bonus.1005\n"
		ESC"10次任务兑换“白银圣斗士”称号\ntalk %x# bonus.1010\n"
		ESC"50次任务兑换“黄金圣斗士”称号\ntalk %x# bonus.1050\n"
		ESC"100次任务兑换“暗黑圣斗士”称号\ntalk %x# bonus.1100\n"
		ESC"离开",me->get_name(),id,id,id,id,));
        	break;
        case 33:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您的任务积分为%d分。\n"ESC"离开",me->get_name(),who->get_save("warrior_title")));
        	break;
        case 34:
		if (who->get_level()>=40||who->get_level()<10)
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    这次的赠品是专门针对新手的，因此只有"HIR"10级～39级"NOR"的玩家才能领取这些礼物。\n"ESC"离开\n",me->get_name()));
			return;
		}
		if (who->get_save("wg_national_new"))
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    怎么？晶石的效果不错吧～精炼后的武器在消灭怪物之后的效率一定会更高。\n"ESC"离开\n",me->get_name()));
			return;
		}
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    到十级了，对武器装备都会有不同的要求了，我决定送你4颗可以给武器装备附加属性的"HIR"晶石"NOR"，如果你按照从低到高的等级顺序，依次将具有相同属性的2颗晶石附加在武器或者防具上，你会看到它们的功能增强不少哦～记住，这些晶石"HIR"只对20级以下"NOR"的装备生效。\n    除了这些晶石外，这位可爱的双鱼小姐在这14天内都会陪伴着你哦。\n"ESC"领取\ntalk %x# bonus.35\n",me->get_name(),id));
        	break;
        case 35:
		if( iTime<iFinish_n && iTime>iStart_n && !who->get_save("wg_national_new") && who->get_level()<40 && who->get_level()>=10 )
		{
			if(USER_INVENTORY_D->count_empty_carry(who) < 5 )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上没有足够的空位，清理一下再来领取吧～\n"ESC"离开",me->get_name()));
		    		return;
			}
			item = new ("item/08/0831");//双鱼宠物
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9343");//新手土晶石
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9345");//新手火晶石
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9343");//新手土晶石
			item->set_level(2);
			p = item->move(who,-1);
			item->add_to_user(p);	
			item = new ("item/93/9345");//新手火晶石
			item->set_level(2);
			p = item->move(who,-1);
			item->add_to_user(p);
			who->set_save("wg_national_new",1);
			send_user(who, "%c%s", ';', "您领取了四颗晶石和一个双鱼宠物");
		}
        	break;
//        case 36:
//		if (who->get_save_2("online_rank.level")<27 )
//		{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您的修为等级还不足27级，达到27级之后再来领取吧。\n"ESC"离开\n",me->get_name()));
//			return;
//		}
//		if (who->get_save("wg_national_new"))
//		{
//			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您已经领取过双鱼宠物了\n"ESC"离开\n",me->get_name()));
//			return;
//		}
//		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    为了回赠老玩家对大话战国的支持，只要修为等级达到了27级，便可以在我这里领取一只特殊的双鱼座观赏宠物。\n"ESC"领取\ntalk %x# bonus.37\n",me->get_name(),id));
//        	break;
//        case 37:
//		if( iTime<iFinish_n && iTime>iStart_n && !who->get_save("wg_national_new") && who->get_save_2("online_rank.level")>=27 )
//		{
//			if(USER_INVENTORY_D->count_empty_carry(who) < 1 )
//			{
//				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你身上没有足够的空位，清理一下再来领取吧～\n"ESC"离开",me->get_name()));
//		    		return;
//			}
//			item = new ("item/08/0831");//双鱼宠物
//			p = item->move(who,-1);
//			item->add_to_user(p);	
//			who->set_save("wg_national_new",1);
//			send_user(who, "%c%s", ';', "您领取了一个双鱼宠物");
//		}
//        	break;
        case 38:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    大礼包包含物品：一个干将宝石、一张年兽卡、一个鲁班宝石、一条紫金钥匙、一张瞒天过海符、一张保底符、一个战国令、一个芝麻开门、一块济世宝玉、一把尚方宝剑、一个人参王、一个锦囊和一把魔力锤，同时附送一个内含200元宝的大红包。\n    要领取这个大礼包，我会收取您390元宝，你确定需要吗？\n"
			ESC"果然物超所值，我要马上购买\ntalk %x# bonus.42\n"
			ESC"我先考虑一下",me->get_name(),id));
        	break;
        case 39:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    这个礼包所有物品都不绑定，可以送给朋友，让你的朋友可以和你一起欢度国庆。同时也可以交易和摆摊出售哦。因为是很珍贵的礼物，所以只会在国庆期间内出售。\n"
			ESC"我明白了",me->get_name()));
        	break;
        case 40:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    大礼包包含物品：一个干将宝石、一张年兽卡、一个鲁班宝石、一条紫金钥匙、一张瞒天过海符、一张保底符、一个战国令、一个芝麻开门、一块济世宝玉、一把尚方宝剑、一个人参王、一个锦囊和一把魔力锤，一个内含200个元宝的红包。\n"
			ESC"看起来礼物很丰富哦",me->get_name()));
        	break;
        case 41:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    好哦，不过这礼包只在国庆期间出售哦，错过了就太可惜了。要不要我偷偷为你预留一份？嘿嘿！\n"
			ESC"离开",me->get_name()));
        	break;
        case 42:
		if (who->get_pay_money_buy_item()>0)
		{
			send_user(who,"%c%s",'!',"您的申请正在处理中，请稍候。");
			return ;
		}
		who->set_pay_money_buy_item(1);    // 查询余额
		who->set_pay_type(8);
		who->set_buy_item_cmd_string( sprintf("%x# bonus", getoid(me) ) );
		db_user_pay( who, sprintf( "%s:80\n"
			"GET http:/""/%s/querybalance.php?t=%s&u=%d\r\n", MAIN_D->get_php_ip(),
			MAIN_D->get_php_ip(), short_time_2(), who->get_acountid() ) );
        	break;
	case 43:
		ssss=":\n    秋色渐浓，喜庆渐现。中秋正刚刚在甜蜜的滋味中度过了，国庆又在热闹的气氛里来临了。在此普天同庆的日子里，大话战国的世界里更是热闹非凡。为什么呢？就因为有我手中这个国庆疯狂大礼包嘛！特别的日子特惠的价格，每套大礼包仅售390元宝，绝对物超所值。喂喂喂，不要挤不要抢，排队一个一个来哦。\n";
		national2 = sprintf(ESC HIY"手快有手慢无，马上点击进入购买\ntalk %x# bonus.38\n"
				    ESC"我想了解更详细的情况\ntalk %x# bonus.39\n"
				    ESC"我想看一下大礼包里有什么东东哦\ntalk %x# bonus.40\n"
				    ESC"等我充值了再说\ntalk %x# bonus.41\n",id,id,id,id);
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s："+ssss+national2+
			ESC"离开",me->get_name()));
		break;


        case 1005:
        case 1010:
        case 1050:
        case 1100:
        	count = flag - 1000;
        	if ( count == 5 )
        		tmp = "A009";
        	else if ( count == 10 )
        		tmp = "A010";
        	else if ( count == 50 )
        		tmp = "A011";
        	else if ( count == 100 )
        		tmp = "A012";
		if ( who->have_title(tmp) )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    你已经有这样的称号了！\n"ESC"离开",me->get_name()));
			return ;
		} 
		amount = who->get_save("warrior_title");
		if ( amount < count )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s：\n    您的积分不足以兑换该称号\n"ESC"离开",me->get_name()));
			return ;	
		}
		who->add_save("warrior_title",-count);
		who->add_title(tmp);
		who->show_title(tmp);
		send_user( who, "%c%s", ';', sprintf(HIY"您兑换了%s的称号。",who->get_title()) );
		break;
	}
}

// 函数：获取描述(持续)
string get_loop_desc1( object me )
{
        return "一小时内增加气血上限200点\n";
}

string get_loop_desc2( object me )
{
        return "一小时内增加法力上限200点\n";
}

string get_loop_desc3( object me )
{
        return "一小时内增加物理攻击100点\n";
}

string get_loop_desc4( object me )
{
        return "一小时内增加法术攻击100点\n";
}

//开启任务
void set_open(object who,string arg)
{
	int year,mon,day,hour,min;
	string cTmp1,cTmp2;
	if ( sscanf(arg ,"%s-%s",cTmp1,cTmp2) != 2 )
	{
		send_user(who,"%c%s",'!',"错误的格式！");	
		return 0;
	}
	//20070518 2000
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);
	iStart_n = mktime(year,mon,day,hour,min,0);	//活动开始时间

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);
	iFinish_n = mktime(year,mon,day,hour,min,0);	//结束时间

	if ( !iStart_n || !iFinish_n )
	{
		send_user(who,"%c%s",'!',"错误的时间！");	
		return 0;
	}
	if ( iStart_n > iFinish_n || iFinish_n < time() )
	{
		send_user(who,"%c%s",'!',"错误的时间！！");	
		return 0;
	}
	tell_user(who,"国庆赠礼活动开启：%s！",arg);	
	send_user(who,"%c%s",'!',"国庆赠礼活动开启！");
	save();
}

//关闭任务
void set_close(object who)
{
	iStart_n = 0;
	iFinish_n = 0;
	send_user(who,"%c%s",'!',"国庆赠礼活动关闭！");
	save();
}
//是否开启活动。
int is_open()
{
	int iHour = time();
	if(!iStart_n || !iFinish_n)
	{
		return 0;
	}
	if(iHour >= iStart_n && iHour < iFinish_n)
	{
		return 1;
	}
	else if(iHour >= iFinish_n)
	{
		return 0;
	}	
}