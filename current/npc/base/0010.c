
// 自动生成：/make/npc/make0010

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

void do_goto( string arg );
void do_welcome( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5410; }

// 函数：构造处理
void create()
{
        set_name("驿站老板");
        set_city_name("新手村");

        set_2( "talk", ([
                "goto"    : (: do_goto :),
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 2);
//        set("legend", ({ 44 }));
//	set("mpLegend",([0:({32*48+12, 32*1+12,}),]));
	set("mpLegend2",([0:({32*48+12,}),]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	string tmp;
//	if ( who->get_legend(TASK_NEWBIE_01, 10)&&!who->get_legend(TASK_NEWBIE_01, 11) )
	if ( who->get_legend(TASK_48, 11) && !who->get_legend(TASK_48, 12) )
	{
		tmp = get_name() + "：\n    "+"/quest/word"->get_normal_word(this_object()) + "\n"+
               		sprintf(ESC  +HIY+ "打听消息\ntalk %x# welcome.1\n",getoid(this_object())) ;	
	}
//	if ( !who->get_legend(TASK_NEWBIE_01, 12) )
	if ( who->get_legend(TASK_48, 12) && !who->get_legend(TASK_48, 13) )
	{
		if ( !stringp(tmp) )
			tmp = get_name() + "：\n    "+"/quest/word"->get_normal_word(this_object()) + "\n"+
               			sprintf(ESC  +HIY+ "飞鸽传书\ntalk %x# welcome.3\n",getoid(this_object())) ;	
			
		else
			tmp +=	 sprintf(ESC  +HIY+ "飞鸽传书\ntalk %x# welcome.3\n",getoid(this_object())) ;	
	}
	if ( stringp(tmp) )
	{
		tmp += ESC"离开";
		send_user( who, "%c%s", ':',tmp);
	}	
	else
		"/sys/task/travel"->do_look(this_object(), who);        
}

// 函数：移动处理
void do_goto( string  arg )
{
	"/sys/task/travel"->do_goto(this_object(), this_player(), arg);     
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p;
        object who, item;     
        string result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:	
//		if ( !who->get_legend(TASK_NEWBIE_01, 10)||who->get_legend(TASK_NEWBIE_01, 11) )
//			return;
		if ( who->get_legend(TASK_48, 11) && !who->get_legend(TASK_48, 12) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    这药店老板还真是尽心尽责，这事就交给我了，你放心吧，等我打听到他的消息，我会找人把口信带给药店老板的，你先收好你的报酬，忙去吧！\n"ESC"完成任务\ntalk %x# welcome.2\n"ESC"离开",me->get_name(),getoid(me)));
			
		break;        	
	case 2:	
//		if ( !who->get_legend(TASK_NEWBIE_01, 10)||who->get_legend(TASK_NEWBIE_01, 11) )
//			return;
//		item = new("/item/91/9110");
//		if ( !item )
//			return ;
//		item->set_amount(10);
//                p =item->move(who, -1);
//                if ( p == 0 )
//                {
//                	destruct(item); 
//                	send_user( who, "%c%s", '!', "您身上没有足够的空位！");
//                	return ;
//                }
//                item->add_to_user(p);

		if ( who->get_legend(TASK_48, 11) && ! who->get_legend(TASK_48, 12))
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 12);
			who->add_exp(290);
			who->add_potential(20);
			who->add_cash(500);
			send_user(who,"%c%s",';',"探望病人 经验 290 潜能 20 金钱 500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,105,"" );		
		me->do_welcome(3);
		}
		break;
	case 3:	
//		if ( who->get_legend(TASK_NEWBIE_01, 12)&&who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
//		if ( !who->get_legend(TASK_NEWBIE_01, 12) )
		if ( who->get_legend(TASK_48, 12) && !who->get_legend(TASK_48, 13) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你终于来了，我等了好久，今天早上有一封飞鸽传书，是给杂货店老板的出货单，我一直找不到人替我送过去，你看我这儿，忙得跟什么似的，你愿意帮我这个忙吗？杂货店老板就在我的西北方，你能替我安全送到这封飞鸽传书的话，他会奖励你的。\n"ESC"接受任务\ntalk %x# welcome.4\n"ESC"离开",me->get_name(),getoid(me)));
//		else if ( !who->get_legend(TASK_NEWBIE_01, 13) ) 
//			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    信送到了吗？是出货单哦，应该比较急的，你可得尽快，耽误了别人发货做生意可就不好了。\n"ESC"离开",me->get_name()));
		break;     
	case 4 :
//		if ( who->get_legend(TASK_NEWBIE_01, 12)&&who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
		if ( who->get_legend(TASK_48, 12) && !who->get_legend(TASK_48, 13) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			item = new("/item/98/9881");
			if ( !item )
				return ;
	                p =item->move(who, -1);
	                if ( p == 0 )
	                {
	                	destruct(item); 
	                	send_user( who, "%c%s", '!', "您身上没有足够的空位！");
	                	return ;
	                }
	                item->add_to_user(p);
			who->set_legend(TASK_48, 13);	
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,106,"飞鸽传书" );
			send_user(who,"%c%s",';',"你得到"HIY"出货单");
			send_user( who, "%c%s", '!', "你接受了"HIY"飞鸽传书"NOR"任务");
		}
		break;
	}		
}
