
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_task_start(string arg);
void accept_task();
void join_task();
void do_welcome( string arg );
void do_task_list();

// 函数：获取人物造型
int get_char_picid() { return 6800; }

// 函数：构造处理
void create()
{
        set_name("尉迟老镖头");
        set_city_name("－－");

        set_2( "talk", ([
                "task"          : (: do_task_start :),
                "accept"        : (: accept_task :),
                "join"		: (: join_task :),
                "welcome"          : (: do_welcome :),
                "tasklist"          : (: do_task_list :),
        ]));      
	set("mpLegend",([30:({32}),]));
        setup();
}

// 函数：对话处理
   void do_look( object who ) { TASK_ESCORT_D->do_look( who, this_object() ); }

// 函数：开始任务
   void do_task_start(string arg) { TASK_ESCORT_D->do_task_start( this_player(), this_object(),arg ); }
// 函数：接受任务
   void accept_task() { TASK_ESCORT_D->accept_task( this_player(), this_object() ); }
// 函数：加入任务
   void join_task() { TASK_ESCORT_D->join_task( this_player(), this_object() ); }

   void do_task_list() { TASK_ESCORT_D->do_task_list( this_player(), this_object() ); }
   
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
	if (arg=="cancel")
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
	                	ESC "%c\n"ESC"use %x# escort2\n"
	                        , 1, getoid(item) ) );			
			return;
		}		
	}        
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    最近神仙爷爷介绍了不少人来我这，可有些人实在是……唉，不说也罢，你可别再叫我失望了！年轻人做事要有冲劲，知道吗，想当初，我年轻的时候……\n"ESC"完成任务\ntalk %x# welcome.2\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 2:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		TASK_LEGEND_D->task_finish(who);
		who->set_legend(TASK_NEWBIE_00, 14);
		who->add_exp(250);
		who->add_potential(30);
		send_user(who,"%c%s",';',"找尉迟老镖头谈谈 经验 250 潜能 30");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,2,"" );		
		me->do_welcome(3);
		break;		
	case 3:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    我这里本是可以提供给你们一个赚钱的机会，可近些日子，有一些无能无德之鼠辈，打着给我帮忙的旗号，从我这骗走了不少镖银，所以，以后凡是想在我这运镖的人，都得先通过我的测试这一关。\n    你先替我把这镖银运到韩城外梨花村的马大汉处，这次我不收你的押金，但你切记，在运镖过程中是不能使用驿站或道具法术等传送功能，否则你的任务就会失败！\n"ESC"接受任务\ntalk %x# welcome.4\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 4:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
	                {
	                        send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n    你身上的东西那么多，估计没有一个安全的地方能放下这个贵重物品，想想还是不交给你吧。等你能放下这个物品了，你再来找我。");
	                        return;
	                }
			
	                item = new( "/item/98/0237" );
	                if( p = item->move(who, -1) ) item->add_to_user(p);
			who->set_legend(TASK_49,13);
		        who->set_quest("escort.time", time() );
			send_user( who, "%c%s", '!', "你接受了"HIY"一探虚实"NOR"任务");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,15,"一探虚实" );
		}
		break;		
	case 5:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    最近师爷徐福介绍了不少人来我这，可有些人实在是……唉，不说也罢，你可别再叫我失望了！年轻人做事要有冲劲，知道吗，想当初，我年轻的时候……\n"ESC"完成任务\ntalk %x# welcome.6\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 6:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,15);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("拜访尉迟老镖头 经验 300 潜能 35 金钱 500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,17,"" );
			me->do_welcome(7);
		}
		break;		
	case 7:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    听说最近出现了一面叫封妖镜的上古遗物，里面封存了数百年以来因战争而产生的镜妖。这个宝物目前落在一个叫左丘明的人手里，他正招募各方英雄好汉进封妖镜消灭妖怪，你有兴趣的话过去找他聊聊吧。从我前面的大门出去，顺着大路往东走就可以看到左丘明了，他站在一棵大树下面。\n"ESC"接受任务\ntalk %x# welcome.8\n"ESC"离开",me->get_name(),getoid(me)));
		break;		
	case 8:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,18,"拜访左丘明" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"拜访左丘明");
		}
		break;	

	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		TASK_ESCORT_D->biaowang(me,who,flag);
		break;

	}
}
