#include <ansi.h>
#include <npc.h>
#include <city.h>
#include <time.h>
#include <task.h>
inherit OFFICER;

void do_reincarnation( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5101; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("周王");
	set_real_name("姬延");
        set_city_name("周国");

        set_2( "talk", ([
		"welcome"	: (: do_welcome :),
        ]) );
	set("mpLegend2",([0:({32*50+22}),10:({32*50+25}),]));
        setup();
}

void do_look( object who ) 
{
	int id;
	string cmd = "";
        object me = this_object();
        if ( "/sys/task/master"->do_look2(who, me)==1 )
        	return ;           
        id = getoid(me);
	if ( who->get_legend(TASK_2_00,18) && !who->get_legend(TASK_2_00,19) ) 
		cmd = sprintf(ESC HIY "前来拜访\ntalk %x# welcome.11\n",id);
	if ( who->get_legend(TASK_2_00,19) && !who->get_legend(TASK_2_00,20) ) 
		cmd = sprintf(ESC HIY "访问生活技能师傅\ntalk %x# welcome.13\n",id);
	if ( who->get_legend(TASK_2_00,21) && !who->get_legend(TASK_2_00,22) ) 
		cmd = sprintf(ESC HIY "完成拜访\ntalk %x# welcome.15\n",id);
	if ( who->get_legend(TASK_2_00,22) && !who->get_legend(TASK_2_00,23) ) 
		cmd = sprintf(ESC HIY "访问周国名士\ntalk %x# welcome.17\n",id);
	if ( who->get_legend(TASK_2_00,24) && !who->get_legend(TASK_2_00,25) ) 
		cmd = sprintf(ESC HIY "完成拜访\ntalk %x# welcome.19\n",id);
	if ( who->get_legend(TASK_2_00,25) && !who->get_legend(TASK_2_00,26) ) 
		cmd = sprintf(ESC HIY "给楚管家的口信\ntalk %x# welcome.21\n",id);
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    世道变换，本王封下各诸侯竟对本王置之不理，如今本王颁布法令在各诸侯辖邑内毫无威信可言，大周在本王之手成如此现状，真乃惭愧！\n    本王顺应世时，推出新一代保险系统，欢迎众卿家前来投保。\n"+cmd+ESC"投保\ntalk %x# welcome.1\n"ESC"赔偿\ntalk %x# welcome.2\n"ESC"查询保险过期日期\ntalk %x# welcome.3\n"ESC"领取修为奖励\ntalk %x# welcome.80\n"ESC"申请攻占无双城\ntalk %x# welcome.73\n"ESC"了解“无双城”\ntalk %x# welcome.74\n"ESC"离开", me->get_name(),id,id,id,id,id,id ) );
}



void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,id,iMoney,iTime,iExp,maxExp,maxMoney;
        object who;
        mapping mpTmp; 
        mixed *mxTmp,mxTmp1;   
        string cTmp;
         
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    该保险为周保险，从您购买的那一刻开始，一个星期内，您的金钱与经验将由本王承担一半的的风险，您只要付出少量的费用，就不必为意外而失去巨额的金钱与经验感到心疼！\n"ESC"购买\ntalk %x# welcome.4\n"ESC"离开", me->get_name(),id, ) );
     		break;
        case 2:
        	mpTmp = who->get_save_2("insurance");
        	if ( !mapp(mpTmp) )
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您并没有购买过任何保险啊！\n"ESC"离开", me->get_name(), ) );
			return ;
        	}
        	if ( mpTmp["timeover"] < time() )
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您的保险已经过期了，不能领取赔偿！\n"ESC"离开", me->get_name(), ) );
			return ;
		}
		if ( mpTmp["money"] <= 0 && mpTmp["exp"] <= 0 ) 	
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您目前没有任何赔偿可以领取！\n"ESC"离开", me->get_name(), ) );
			return ;
		}
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    非常遗憾听到这个消息，当然，您的损失我会补偿一半，这份保险的好处您总归是知道了，希望下个星期还能见到您来购买！\n    您有%d金和%d点经验的赔偿可以领取。\n"ESC"领取\ntalk %x# welcome.5\n"ESC"离开", me->get_name(),mpTmp["money"],mpTmp["exp"],id) );
     		break;
        case 3:
        	mpTmp = who->get_save_2("insurance");
        	if ( !mapp(mpTmp) )
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您并没有购买过任何保险啊！\n"ESC"离开", me->get_name(), ) );
			return ;
        	}
        	if ( mpTmp["timeover"] < time() ) 	
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您的保险已经过期了！\n"ESC"离开", me->get_name(), ) );
			return ;
		}
		mxTmp = localtime(mpTmp["time"]);
		mxTmp1 = localtime(mpTmp["timeover"]);
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您于%d年%d月%d日%d时成功投保，该保险的过期日期为%d年%d月%d日%d时。如有需要，保险过期后您还可以继续投保。\n"ESC"离开", me->get_name(),mxTmp[TIME_YEAR],mxTmp[TIME_MON]+1,mxTmp[TIME_MDAY],mxTmp[TIME_HOUR],mxTmp1[TIME_YEAR],mxTmp1[TIME_MON]+1,mxTmp1[TIME_MDAY],mxTmp1[TIME_HOUR] ) );
     		break;
     	case 4:		//购买
     		if ( ( who->get_save_2("insurance.timeover") /3600 ) > (time()/3600) ) 	//整点
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您的保险还未过期，等待过期后再来找我继续投保吧！\n"ESC"离开", me->get_name(), ) );
			return ;
		}
     		iMoney = who->get_level()*1000;
     		if ( iMoney < 10000 )
     			iMoney = 10000;
     		if ( who->get_cash() < iMoney )
     		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    不好意思，您身上所带资金不够用来购买这份保险，请您带齐了钱再来找我吧！\n"ESC"离开", me->get_name(), ) );
			return ;
		}
		who->add_cash(- iMoney);
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您花费%d金购买了保险。虽然购买了保险，但是还是要注意安全哦～\n"ESC"离开", me->get_name(),iMoney ) );
		who->delete_save_2("insurance");
		iTime = time();
		who->set_save_2("insurance.time",iTime);
		who->set_save_2("insurance.timeover",iTime+3600*24*7);
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 3, "保险时间" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3, 0001, 3, "" ); 
		log_file("insurance.txt",sprintf("%s %s(%d %s) 投保\n",short_time(),who->get_name(),who->get_number(),who->get_id()));
		"/sys/sys/count"->add_use("insurance", iMoney);
     		break;
	case 5:
		mpTmp = who->get_save_2("insurance");
        	if ( !mapp(mpTmp)  )
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您并没有购买过任何保险啊！\n"ESC"离开", me->get_name(), ) );
			return ;
        	}
        	if ( mpTmp["money"] <= 0 && mpTmp["exp"] <= 0 )
        	{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您目前没有任何赔偿可以领取！\n"ESC"离开", me->get_name(), ) );
			return ;
        	}
		//原来写法导致int溢出
//		maxExp = 10 * USER_EXP_D->get_level_exp(who->get_reincarnation(), who->get_level());
		maxExp = USER_EXP_D->get_upgrade_exp_limit(who);
		maxMoney = who->get_max_cash();
		if ( mpTmp["money"] > 0 )
		{
			if ( who->get_cash() + mpTmp["money"] <= maxMoney )
			{
				iMoney = mpTmp["money"];
			}
			else
			{
				iMoney = maxMoney - who->get_cash();
			}
			if ( iMoney < 0 )
				return ;
			who->add_cash(iMoney);
			who->add_save_2("insurance.money",-iMoney);
			"/sys/sys/count"->add_income("insurance", iMoney);
		}
		if ( mpTmp["exp"] > 0 )
		{
			////原来写法可能导致int溢出
//			if ( who->get_upgrade_exp() + mpTmp["exp"] <= maxExp )
			if ( mpTmp["exp"] <= maxExp - who->get_upgrade_exp() )
			{
				iExp = mpTmp["exp"];
			}
			else
			{
				iExp = maxExp - who->get_upgrade_exp();
			}
			if ( iExp < 0 )
				return ;
			who->add_exp(iExp);
			who->add_save_2("insurance.exp",-iExp);
		}
		cTmp = "";
		if ( who->get_save_2("insurance.money") >0 && who->get_save_2("insurance.exp") >0 )
			cTmp = sprintf("您还有%d金和%d点经验的赔偿未领取。",who->get_save_2("insurance.money"),who->get_save_2("insurance.exp"));
		else if ( who->get_save_2("insurance.money") >0 )
			cTmp = sprintf("您还有%d金的赔偿未领取。",who->get_save_2("insurance.money"));
		else if ( who->get_save_2("insurance.exp") >0 )
			cTmp = sprintf("您还有%d点经验的赔偿未领取。",who->get_save_2("insurance.exp"));
			
		if ( iMoney && iExp )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您领取了%d金和%d点经验的赔偿！%s\n"ESC"离开", me->get_name(),iMoney,iExp,cTmp ) );
		else if ( iMoney )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您领取了%d金的赔偿！%s\n"ESC"离开", me->get_name(),iMoney,cTmp ) );
		else if ( iExp )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    您领取了%d点经验的赔偿！%s\n"ESC"离开", me->get_name(),iExp,cTmp ) );
		else
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    对不起，您身上似乎放不下我给您的赔偿，最好清空了再来找我。%s\n"ESC"离开", me->get_name(), cTmp ) );
		log_file("insurance.txt",sprintf("%s %s(%d %s) 获得赔偿 %d 金 %d 经验\n",short_time(),who->get_name(),who->get_number(),who->get_id(),iMoney,iExp));
		break;
	case 11:
		if ( who->get_legend(TASK_2_00,18) && !who->get_legend(TASK_2_00,19) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你是左丘明介绍来的？看看寡人推出的保险系统吧，会对你有所帮助的。\n"ESC"完成任务\ntalk %x# welcome.12\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 12:
		if ( who->get_legend(TASK_2_00,18) && !who->get_legend(TASK_2_00,19) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,19);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("拜访周王 经验 300 潜能 35 金钱 500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,19,"" );
			me->do_welcome(13);
		}
		break;
	case 13:
		if ( who->get_legend(TASK_2_00,19) && !who->get_legend(TASK_2_00,20) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    别看现在周国势力减弱，但人才并不少，各种奇人异士都有。其中周国大厨、周国裁缝、周国采药师、周国铁匠、周国采矿师、周国机关师、周国炼丹师，周国石刻师每人都会一种生活技能，能制造出各种武器道具，你去拜访他们一下，对你的将来大有帮助。\n"ESC"接受任务\ntalk %x# welcome.14\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 14:
		if ( who->get_legend(TASK_2_00,19) && !who->get_legend(TASK_2_00,20) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,20);
			who->delete_save("baifang_js_0");
			who->delete_save("baifang_js_1");
			who->delete_save("baifang_js_2");
			who->delete_save("baifang_js_3");
			who->delete_save("baifang_js_4");
			who->delete_save("baifang_js_5");
			who->delete_save("baifang_js_6");
			who->delete_save("baifang_js_7");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,20,"访问生活技能师傅" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"访问生活技能师傅");
		}
		break;	
	case 15:
		if ( who->get_legend(TASK_2_00,21) && !who->get_legend(TASK_2_00,22) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你现在对生活技能有一定了解了吧，去挑几种学习吧。\n"ESC"完成任务\ntalk %x# welcome.16\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 16:
		if ( who->get_legend(TASK_2_00,21) && !who->get_legend(TASK_2_00,22) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,22);
			who->delete_save("baifang_js_0");
			who->delete_save("baifang_js_1");
			who->delete_save("baifang_js_2");
			who->delete_save("baifang_js_3");
			who->delete_save("baifang_js_4");
			who->delete_save("baifang_js_5");
			who->delete_save("baifang_js_6");
			who->delete_save("baifang_js_7");

			who->add_exp(800);
			who->add_potential(50);
			who->add_cash(1500);
			send_user(who,"%c%s",';',sprintf("访问生活技能师傅 经验 800 潜能 50 金钱 1500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,20,"" );
			me->do_welcome(17);
		}
		break;	
	case 17:
		if ( who->get_legend(TASK_2_00,22) && !who->get_legend(TASK_2_00,23) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    除了这些能工巧匠，周国还隐居着不少奇人异士，孔夫子能帮助拜师收徒，公输班能用晶石强化装备，申公豹能让你放弃不需要的生活技能，而月老和红娘能够让你和心上人喜结良缘，你去访问下他们，了解更详细的情况吧。\n"ESC"接受任务\ntalk %x# welcome.18\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 18:
		if ( who->get_legend(TASK_2_00,22) && !who->get_legend(TASK_2_00,23) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,23);
			who->delete_save("baifang_ms_1");
			who->delete_save("baifang_ms_2");
			who->delete_save("baifang_ms_3");
			who->delete_save("baifang_ms_4");
			who->delete_save("baifang_ms_5");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,21,"访问周国名士" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"访问周国名士");
		}
		break;	
	case 19:
		if ( who->get_legend(TASK_2_00,24) && !who->get_legend(TASK_2_00,25) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    现在你对周国的名士应该有个大概了解了，以后有需要你就来这里找他们吧。\n"ESC"完成任务\ntalk %x# welcome.20\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 20:
		if ( who->get_legend(TASK_2_00,24) && !who->get_legend(TASK_2_00,25) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,25);
			who->delete_save("baifang_ms_1");
			who->delete_save("baifang_ms_2");
			who->delete_save("baifang_ms_3");
			who->delete_save("baifang_ms_4");
			who->delete_save("baifang_ms_5");

			who->add_exp(800);
			who->add_potential(50);
			who->add_cash(1500);
			send_user(who,"%c%s",';',sprintf("访问周国名士 经验 800 潜能 50 金钱 1500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,21,"" );
			me->do_welcome(21);
		}
		break;
	case 21:
		if ( who->get_legend(TASK_2_00,25) && !who->get_legend(TASK_2_00,26) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    楚国的楚管家当年访问周国，和寡人很是谈得来，这么几年不见，寡人还真是有点想念他。你去楚国替我拜望一下他，叫他有机会再来周国看望寡人。\n"ESC"接受任务\ntalk %x# welcome.22\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 22:
		if ( who->get_legend(TASK_2_00,25) && !who->get_legend(TASK_2_00,26) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,26);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,22,"给楚管家的口信" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"给楚管家的口信");
		}
		break;
	case 73:
		WUSHUANG->query_join_attack(me,who);
		break;
	case 74:
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    无双城乃是实力和地位的象征！如果你想傲视战国，那么你就做无双城的主人吧～！此外，凡是拥有无双城称谓的玩家，只要将称谓表现出来，据说可以威慑怪物，消灭怪物可以获得相应的经验加成。\n"ESC"离开",me->get_name()));
		break;	
	case 75:
		WUSHUANG->join_attack(me,who);
		break;
	case 80:
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s：\n    所有大话战国的玩家每提升一次修为等级，都可以找我领取礼物，你的修为等级提升了吗？想要我给你的礼物吧？\n"ESC"领取礼物\ntalk %x# welcome.81\n"ESC"离开", me->get_name(),id, ) );
		break;
	case 81:
		USER_RANK_D->get_rank_bonus(who,me);
		break;
	}
}
