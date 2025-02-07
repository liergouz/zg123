
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 4; }
// 有自己的do_look函数
int is_self_look() { return 1; }
// 函数：获取人物造型
int get_char_picid() { return 5405; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("防具店老板");
        set_city_name("新手村");

        set_2( "good", ([
                "01" : "/item/60/0005",
                "02" : "/item/61/0005",
                "03" : "/item/65/0005",
                "04" : "/item/66/0005",
                "05" : "/item/88/0005",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//        set("level", 0);
//        set("legend", ({ 32+5,32+7 }));
//	set("mpLegend",([0:({32+5, }),]));
	set("mpLegend2",([0:({32*48+5,32*48+7,}),]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	string result;
	"/quest/help"->send_help_tips(who, 40);
	result = sprintf("%s：\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	result += sprintf(ESC "哪里有适合我的装备？\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	if (who->get_legend(TASK_48, 4) && !who->get_legend(TASK_48, 5))
	{
		result = result + sprintf( ESC  +HIY+ "合作事宜\ntalk %x# welcome.1\n", getoid(me) );
	}
	if (who->get_legend(TASK_48, 5) && !who->get_legend(TASK_48, 6))
	{
		result = result + sprintf( ESC  +HIY+ "寻宝历险\ntalk %x# welcome.3\n", getoid(me) );
	}
	if (who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7))
	{
		result = result + sprintf( ESC  +HIY+ "寻宝历险\ntalk %x# welcome.9\n", getoid(me) );
	}
	if ( (who->get_legend(TASK_48, 7) && !who->get_legend(TASK_48, 8)) )
	{
		result = result + sprintf( ESC  +HIY+ "家族玉佩\ntalk %x# welcome.6\n", getoid(me) );
	}
	if (who->get_legend(TASK_NEWBIE_01, 7) && !who->get_legend(TASK_NEWBIE_01, 8))
	{
		result = result + sprintf( ESC  +HIY+ "家族玉佩\ntalk %x# welcome.8\n", getoid(me) );
	}	
	result = result + sprintf( ESC "交易\nlist %x#\n" ESC "我只是随便看看\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

}
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
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( who->get_legend(TASK_48, 4) && !who->get_legend(TASK_48, 5))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    哎呀！这武器店老板与我可谓是一拍即合呀！我也老早就有了这样的想法，感谢你来做他的说客，这样吧，我和他再约个时间好好谈谈，拿好你的报酬吧！\n"ESC"完成任务\ntalk %x# welcome.2\n",me->get_name(),getoid(me)));
		break;
	case 2:
		if ( who->get_legend(TASK_48, 4) && !who->get_legend(TASK_48, 5))
		{
			if(who->get_gender()==1) item = new("item/60/0001");
				else item = new("item/61/0001");
			if ( !item ) break;
			if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
			{
                                p =item->move(who, -1);
                                item->add_to_user(p);			
				TASK_LEGEND_D->task_finish(who);
				who->set_legend(TASK_48, 5);
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,102,"" );
				who->add_cash(500);
				who->add_exp(120);
				who->add_potential(20);
				send_user(who,"%c%s",';',sprintf("合作事宜 经验 120 潜能 20 金钱 500 新手衣服 1"));
				me->do_welcome(3);
			}
			else
			{
                                	destruct(item); 
                                	send_user( who, "%c%s", '!', "您身上没有空位！");				
			}
		}
		break;
	case 3:
		if (who->get_legend(TASK_48, 5) && !who->get_legend(TASK_48, 6))
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    要想享受寻宝历险的刺激，你首先得去找到一张藏宝图，有了这张藏宝图，你才能继续寻宝，好了，如果你能找到藏宝图，你再回我这里吧，我会告诉你下一条线索。\n"ESC"领取任务\ntalk %x# welcome.4\n"ESC"离开",me->get_name(),getoid(me)));
		}
		break;
	case 4:
		if (who->get_legend(TASK_48, 5) && !who->get_legend(TASK_48, 6))
		{	//打开宝箱
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_48, 6);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,103,"寻宝历险" ); 
			send_user( who, "%c%s", '!', "你接受了"HIY"寻宝历险"NOR"任务");                       
		}
		break;
	case 5 :
		if ( who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7))
		{
			if( !objectp( item = present("藏宝图", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
			{
				send_user(who,"%c%s",'!',"你的藏宝图呢?");
				return;	
			}
	//		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    拿着你手上的藏宝图一直向南走，到野外最突出那个岛上去找找，就在那个草丛里（88，62），找到那里，你就能挖宝了。这次的奖励可丰厚了，你找到宝物后，去找药店老板，他会给你奖励的。\n"ESC"领取任务\ntalk %x# welcome.7\n"ESC"离开",me->get_name(),getoid(me)));
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 7);
			who->add_exp(180);
			who->add_potential(40);
			who->add_cash(1000);
			send_user(who,"%c%s",';',"寻宝历险 经验 180 潜能 40 金钱 1000");
//			send_user( who, "%c%c%c%w%c", 0x51, 2, 1,TID_NEWBIE_01,"" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,103,"" );
			me->do_welcome(6);
		}
		break;
	case 6:
		if (!who->get_legend(TASK_48, 7) )
			return ;		
		if( !objectp( item = present("藏宝图", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			send_user(who,"%c%s",'!',"你的藏宝图呢?");
			return;	
		}
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    拿着你手上的藏宝图一直向南走，到清溪最突出那个岛上好好找找，就在那个草丛里（88，62），找到那里，你就可以挖宝了！当然，这个任务比找到藏宝图的奖励会更多，你是否愿意挑战呢？你找到宝物后，去找药店老板，他会给你想要的东西。\n    做完任务后，用alt+w打开人物属性界面，再使用新手信物就可以快速回到新手村哦！\n"ESC"领取任务\ntalk %x# welcome.7\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 7:
		if (!who->get_legend(TASK_48, 7))
			return ;		
		if( !objectp( item = present("藏宝图", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
		{
			send_user(who,"%c%s",'!',"你的藏宝图呢?");
			return;	
		}
		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
		who->set_legend(TASK_48, 8);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,104,"家族玉佩" );
		send_user( who, "%c%s", '!', "你接受了"HIY"家族玉佩"NOR"任务");
		break;		
	case 8:
		if ( (who->get_legend(TASK_NEWBIE_01, 7) && !who->get_legend(TASK_NEWBIE_01, 8)))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    为什么还不去挖宝呢？把挖到的宝物交给药店老板，得拿到多少奖励呀！\n"ESC"离开",me->get_name(),));
		break;
	case 9:
		if (who->get_legend(TASK_48, 6) && !who->get_legend(TASK_48, 7))
		{
			if( !objectp( item = present("藏宝图", who, 1, MAX_CARRY) ) || item->is_xunbao() != 1 )
			{
				send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    你找不到那张藏宝图？是不是那陈老头偷偷藏起来了？这样吧，你再去找找！仔细点！\n"ESC"离开",me->get_name()));
			}
			else 
				send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    这么快就回来？嗯，对的，你手上的藏宝图就是你现在需要的那张，干得不错。\n"ESC"完成任务\ntalk %x# welcome.5\n",me->get_name(),getoid(me)));
		}
		break;
	case 99:
		result = sprintf("%s：\n    不知道去哪里买称心的装备？我告诉你好了。\n"
			"    在新手村和楚国你都能买到通用的装备。新手村都是0级的，而楚国则是贩卖10级的装备。\n"
			"    在"HIR" 赵国 "NOR"可以买到"HIR" 桃花源 "NOR"的装备；\n"
			"    "HIR" 周国 "NOR"有"HIR" 禁卫军 "NOR"装备的专门店；\n"
			"    "HIR" 蜀山 "NOR"的装备可以在"HIR" 燕国 "NOR"购买；\n"
			"    到"HIR" 韩国 "NOR"就可以找到"HIR" 唐门 "NOR"的装备专门店；\n"
			"    在"HIR" 秦国 "NOR"能买到"HIR" 昆仑山 "NOR"的装备；\n"
			"    "HIR" 茅山 "NOR"的装备可以到"HIR" 齐国 "NOR"寻寻看；\n"
			"    最后"HIR" 云梦泽 "NOR"的装备你只要到"HIR" 魏国 "NOR"便可以找到了。"
			"\n", me->get_name() );
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
		break;		
	}
}	               
