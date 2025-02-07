
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <time.h>

#define TREASURE        "/item/std/8000"

#define LT_SEC          0
#define LT_MIN          1
#define LT_HOUR         2
#define LT_MDAY         3
#define LT_MON          4
#define LT_YEAR         5
#define LT_WDAY         6
#define LT_YDAY         7
#define LT_GMTOFF       8
#define LT_ZONE         9

inherit OFFICER;

int iStart2,iFinish2,close_val,open_val;
void do_look( object who );
void do_welcome( string arg );
int is_holiday();

// 函数：获取人物造型
int get_char_picid() { return 6008; }

// 函数：构造处理
void create()
{
        set_name( "神仙爷爷" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//	set("mpLegend",([0:({32*48+1}),10:({11,}),30:({9,13})]));
//	set("mpLegend2",([0:({24,2}),]));
        setup();
	set("mpLegend",([0:({32}),]));	//不需要其他标记了

        iStart2 = mktime(2007,2,16,0,0,0);
        iFinish2 = mktime(2007,2,21,0,0,0);


}

// 函数：对话处理
void do_look( object who )
{
	int x;
	x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if (who->get_save_2("double_time.week")!=x)
	{
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);		//双
		who->set_save_2("double_time.time1", 0);	//战国令
		who->set_save_2("double_time.time2", 0);	//战国号角
		who->set_save_2("double_time.time3", 0);	//额外换取的3小时双倍时间
		who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
	}
        do_welcome("99");
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item, item2;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, result;
        mixed mxTime;
	int iVipTime;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        p = 0;
        z = get_z(me);
	x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if (who->get_save_2("double_time.week")!=x)
	{
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);		//双
		who->set_save_2("double_time.time1", 0);	//战国令
		who->set_save_2("double_time.time2", 0);	//战国号角
		who->set_save_2("double_time.time3", 0);	//额外领双
		who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
	}
        switch(flag)
        {
        case 1:
        	if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
        	{
	                cmd1 = sprintf("talk %x# welcome.2\n", getoid(me));
	                result =  get_name() + "：\n    呵呵～看见一个又一个的勇士到来，我真的感觉很开心。你的冒险才刚开始，你不妨先在新手村多了解一下各个功能，如果你有什么不明白的地方，你可以去找指引仙子问一下。\n"
	                		ESC "完成任务\n" + cmd1 +
	                		ESC "关闭\nCLOSE\n";
	                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
		}
                break;
        case 2:
                if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
                {
			if (who->get_save_2("double_time.freeze")>0)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     你的"HIR"双倍经验时间已经冻结"NOR"，请解除冻结状态后再领取额外的双倍经验吧。\n"
			                ESC "关闭\nCLOSE\n", me->get_name() ) );
				return;
			}                	
                	// 收去百合仙子的信件
			TASK_LEGEND_D->task_finish(who);
                        who->set_legend(TASK_NEWBIE_00, 2);
                        who->add_exp(20);
                        who->add_cash(500);
                        who->add_potential(20);
                        "/quest/help"->send_help_tips(who, 2);

	        	mxTime = localtime(time());
	        	if ( who->get_save("dbtime_s") == mxTime[TIME_YDAY] )
	        	{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+"：\n    你已经将我送给你的双倍领完了呀！");
	        		return ;
	        	}
	        	i = gone_time( who->get_login_time() );

	        	who->set_save("dbtime_s",mxTime[TIME_YDAY]);
	        	if ( i+ who->get_game_time()<who->get_double_time())
	        		who->set_double_time(who->get_double_time()+1800);
			else
				who->set_double_time(i+ who->get_game_time()+1800);
			who->delete("tasklist");
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "双倍时间" );
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);
			"/quest/help"->send_help_tips(who, 3);
                        result = "您得到了神仙爷爷的奖励 20 点经验、20 点潜能、500 金和半小时双倍经验";
                        send_user( who, "%c%s", ';', result);
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+"：\n    我送了你30分钟的双倍经验时间，好好把握吧。");

			send_user( who, "%c%c%c%w%c", 0x51, 2, 1,TID_NEWBIE_00,0 );
			send_user( who, "%c%c%c%w%w%c", 0x51, 2, 2,TID_NEWBIE_00,1,0 );
                        "/sys/sys/count"->add_task("送信使命", 1);
	        	if (who->get_legend(TASK_48, 1))  return;
	                cmd1 = sprintf("talk %x# welcome.21\n", getoid(me));
	                result =  get_name() + "：\n    在这个新手村外，分布着一些很奇怪的动物，他们不像普通的小鸡、小兔、稻草人一样的友善，他们会攻击人，除掉这些怪物是我们一直以来在做的事情，如果你能够协助我除掉这些奇怪的小怪物就好了！\n    武器店老板会很乐意给你一些东西的，你杀完后去找他吧。\n"

	                		ESC "领取任务\n" + cmd1 +
	                		ESC "关闭\nCLOSE\n";
	                send_user( who, "%c%c%w%s", ':', 3, 6008, result );

                }
                else
                	send_user( who, "%c%s", '!', "您身上没有送信任务");
                break;
        case 3:
        	if (who->get_legend(TASK_NEWBIE_00, 3))  return;
                cmd1 = sprintf("talk %x# welcome.4\n", getoid(me));
                result =  get_name() + "：\n    你刚刚来到这个村子，可能还不太熟悉这里的环境，这样吧，你顺着我身旁的这条青石小径一直往上走，过了当铺，找到武器店老板，替我找他索取一柄木剑，他会很痛快的交给你的！\n"
                		ESC "领取任务\n" + cmd1 +
                		ESC "关闭\nCLOSE\n";
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 4:
                if (!who->get_legend(TASK_NEWBIE_00, 3)) who->set_legend(TASK_NEWBIE_00, 3);
                send_user( who, "%c%s", '!', "你领取了神仙爷爷的嘱托的任务！");
                send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,1,"神仙爷爷的嘱托" );
                break;
        case 5:
        	if (!who->get_legend(TASK_NEWBIE_00, 4))
        	{
	                result =  get_name() + "：\n    怎么？那武器店老板不给？不然你怎么还没拿过来呀。难道我看错人了？应该不会的呀！\n"
	                		ESC "离开\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6008, result );
        		return;
        	}
        	if (who->get_legend(TASK_NEWBIE_00, 5))  return;
                cmd1 = sprintf("talk %x# welcome.6\n", getoid(me));
                result =  get_name() + "：\n    武器店老板痛快吧！呵呵，说过了，他是个痛快人。我就喜欢和这样的人打交道。这柄木剑虽然不值什么钱，但是对我用途大着呢，具体有什么用，我可不告诉你，嘿嘿。这是俺老头儿的一点秘密！\n"
                		ESC "完成任务\n" + cmd1;
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
	case 6:
                cmd1 = sprintf("talk %x# welcome.7\n", getoid(me));
                cmd2 = sprintf("talk %x# welcome.8\n", getoid(me));
                cmd3 = sprintf("talk %x# welcome.9\n", getoid(me));
                result =  get_name() + "：\n    请你选择一种物品做为奖励：\n"
                		ESC "初学者木刀\n" + cmd1 +
                		ESC "长木棍\n" + cmd2 +
                		ESC "竹矛\n" + cmd3;
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 7:
        case 8:
        case 9:
        	if (who->get_legend(TASK_NEWBIE_00, 4) && !who->get_legend(TASK_NEWBIE_00, 5))
        	{
                	// 收去神仙爷爷的木剑
                	if( !objectp( item = present("神仙爷爷的木剑", who, 1, MAX_CARRY) ) )
                	{
                		send_user( who, "%c%s", '!', "您身上没有神仙爷爷的木剑");
                		return;
                	}
                	item->remove_from_user();
                	destruct(item);
                	switch(flag)
                	{
                	case 7:
                		item = new ("item/01/7200");
                		break;
                	case 8:
                		item = new ("item/01/7500");
                		break;
                	case 9:
                		item = new ("item/01/7400");
                		break;
                	}
                        result = "你获得 30 点经验";
                        if (item)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
                                {
                                        p =item->move(who, -1);
                                        item->add_to_user(p);
		                        result += sprintf("和 %s", item->get_name());
                                }
                                else
                                	destruct(item);
                        }
                        result += "。";
                        send_user( who, "%c%s", ';', result);
                        who->add_exp(30);
                	who->set_legend(TASK_NEWBIE_00, 5);
	                send_user( who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_01, 0 );
	                send_user( who, "%c%c%c%w%w%c", 0x51, 2, 2,TID_NEWBIE_01, 1, 0 );
	                "/sys/sys/count"->add_task("神仙爷爷的嘱托", 1);

                }
                break;
        case 20:
        	if (who->get_legend(TASK_48, 1))  return;
                cmd1 = sprintf("talk %x# welcome.21\n", getoid(me));
                result =  get_name() + "：\n    在这个新手村外，分布着一些很奇怪的动物，他们不像普通的小鸡、小兔、稻草人一样的友善，他们会攻击人，除掉这些怪物是我们一直以来在做的事情，如果你能够协助我除掉这些奇怪的小怪物就好了！\n    武器店老板会很乐意给你一些东西的，你杀完后去找他吧。\n"

                		ESC "领取任务\n" + cmd1 +
                		ESC "关闭\nCLOSE\n";
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 21:
        	if (who->get_legend(TASK_48, 1))  return;
		if (who->get_save_2("task.story")>=20)
		{
                	send_user( who, "%c%s", '!', "你已领取了20个剧情任务，不能再领取了！");
	                return;
		}
                if (!who->get_legend(TASK_48, 1)) who->set_legend(TASK_48, 1);
                who->delete_save("new_sj");
                send_user( who, "%c%s", '!', "你领取了小试身手的任务！");
                send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,101,"小试身手" );
                who->add_save_2("task.story",1);
                break;
	case 26:
                cmd1 = sprintf("talk %x# welcome.27\n", getoid(me));
                cmd2 = sprintf("talk %x# welcome.28\n", getoid(me));
                result =  get_name() + "：\n    请你选择一种物品做为奖励：\n"
                		ESC "男装布衣\n" + cmd1 +
                		ESC "女装布衣\n" + cmd2 ;
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 27:
        case 28:
        	if (who->get_legend(TASK_NEWBIE_00, 6) && who->get_legend(TASK_NEWBIE_00, 7) && !who->get_legend(TASK_NEWBIE_00, 8))
        	{
                        if (flag==27)
                        	item = new ("/item/01/6000");    // 男布衣
                        else
                        	item = new ("/item/01/6100");    // 女布衣
			result = "你获得 80 点经验";
                        if (item)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item)  >=2 )
                                {
                                        p =item->move(who, -1);
                                        item->add_to_user(p);
		                        result += sprintf("、%s", item->get_name());
                                }
                                else
                                {
                                	destruct(item);
                                	send_user( who, "%c%s", '!', "您身上没有足够的空位！");
                                	return ;
                                }
                        }
                        item = new ("/item/32/3282");    // 桔子
                        if (item)
                        {
                        	item->set_amount(6);
                                if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
                                {
                                        p =item->move(who, -1);
                                        item->add_to_user(p);
		                        result += sprintf("、%s", item->get_name());
                                }
                                else
                                	destruct(item);
                        }
                        result += "。";
                        send_user( who, "%c%s", ';', result);
                        who->add_exp(80);
                	who->set_legend(TASK_NEWBIE_00, 8);
	                send_user( who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_01, 0 );
	                send_user( who, "%c%c%c%w%w%c", 0x51, 2, 2,TID_NEWBIE_01, 2, 0 );
	                "/sys/sys/count"->add_task("小试身手", 1);
                }
                break;
	case 30:
		if (  get_z(who) != 80 )
			return ;
		if ( who->get_level() >= 30 && !who->get_legend(TASK_NEWBIE_00, 9) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    衙门里的师爷可是个传奇人物，有人说他贪污受贿，可也有人说他是个好官，做了不少让人称赞的好事，关于这些传言他却从不为自己澄清，听说最近出现不少匪徒，师爷正到处寻人帮忙呢，你去看看吧！过了我身后的这座桥，一直往前走，就能找到衙府了。\n"ESC"领取任务\ntalk %x# welcome.31\n"ESC"离开",me->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_NEWBIE_00, 10) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    你没去拜访师爷？你不觉得可惜吗？难道你就一点都不好奇吗？那样的一个传奇人物，你不想见识见识他到底是何方神圣吗？\n"ESC"离开",me->get_name()));
		break;
	case 31:
		if (  get_z(who) != 80 )
			return ;
		if (who->get_level()>=30&&!who->get_legend(TASK_NEWBIE_00, 9) )
		{
			who->set_legend(TASK_NEWBIE_00, 9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,3,"拜访师爷" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"拜访师爷");
		}
		break;
	case 32:
		if (  get_z(who) != 80 )
			return ;
		if ( !who->get_legend(TASK_NEWBIE_00, 11) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    王捕头那里最近接到一批差事，人手也不够，听说是因为犯人逃跑了，周王悬赏捉拿这些人，想想看，王都下命令了，那奖赏肯定不少，你去了可得机灵点，给王捕头一点小意思，道理就不用我说了吧。王捕头周国城内的驿站旁边，还挺近的，你好好找找吧！\n"ESC"领取任务\ntalk %x# welcome.33\n"ESC"离开",me->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_NEWBIE_00, 12) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    咦，你怎么还没去王捕头那呀？去晚了可不好，到时候差事都让别人给做了，你不就失去了一次发财的机会吗？\n"ESC"离开",me->get_name()));
		break;
	case 33:
		if (  get_z(who) != 80 )
			return ;
		if (who->get_level()>=10&&!who->get_legend(TASK_NEWBIE_00, 11) )
		{
			who->set_legend(TASK_NEWBIE_00, 11);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,1,"王捕头的美差" );
		}
		break;
	case 34:
		if (  get_z(who) != 80 )
			return ;
		if ( !who->get_legend(TASK_NEWBIE_00, 13) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    尉迟老镖头可是个让劫匪闻风丧胆的人物，年轻时便是一条好汉，他保的镖还从来没丢过，现在年纪大了，便自己开了一家镖局，最近局势不好，听说他生意太好，人手不够，你去看看，能不能帮上忙。记得了，那镖局叫镇威镖局，就在我的西北方。\n"ESC"领取任务\ntalk %x# welcome.35\n"ESC"离开",me->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_NEWBIE_00, 14) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    怎样？尉迟老镖头看样子就知道是条好汉吧！什么？你还没见到他？还不快去，唉，年轻人做事要有冲劲呀！这也是尉迟老镖头经常说的一句话！\n"ESC"离开",me->get_name()));
		break;
	case 35:
		if (  get_z(who) != 80 )
			return ;
		if (who->get_level()>=30&&!who->get_legend(TASK_NEWBIE_00, 13) )
		{
			who->set_legend(TASK_NEWBIE_00, 13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,2,"找尉迟老镖头谈谈" );
		}

		break;
	case 36:
		if (  get_z(who) != 80 )
			return ;
		if ( who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80 )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    哦～你来了。我找你其实也没别的事情，只是想锻炼锻炼你，周国的天地比新手村要广，你应该把目光放远一点哦。譬如说，周国的师爷、尉迟老镖头、王捕头等，他们可都是了不起的大人物呀！\n"ESC"完成任务\ntalk %x# welcome.37\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 37:
		if (  get_z(who) != 80 )
			return ;
		if ( who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80 )
		{
			who->set_legend(TASK_NEWBIE_01, 24);
			who->add_exp(250);
			who->add_potential(30);
			who->add_cash(5000);
			send_user(who,"%c%s",';',"锻炼的机会 经验 250 潜能 30 金钱 5000 ");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,13,"" );
		}
		break;
        case 40:
		x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
		if (who->get_save_2("double_time.week")!=x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//双
			who->set_save_2("double_time.time1", 0);	//战国令
			who->set_save_2("double_time.time2", 0);	//战国号角
			who->set_save_2("double_time.time3", 0);
			who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
		}
		if (who->get_save_2("double_time.time")>=8)
		{
			y = 7*24*3600 - ((time() - 4 * 24*3600+8*3600) % (7*24*3600));
			if (y<24*3600)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     这个星期你已经累积领取超过四个小时双倍经验的奖励时间了，你还是等%d小时后再来领取吧。 \n"
			                ESC "关闭\nCLOSE\n", me->get_name(), y/3600 ) );
			}
			else
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     这个星期你已经累积领取超过四个小时双倍经验的奖励时间了，你还是等%d天后再来领取吧。 \n"
			                ESC "关闭\nCLOSE\n", me->get_name(), y / (24*3600) ) );
			}
			return;
		}
                cmd1 = sprintf("talk %x# welcome.41\n", getoid(me));
                cmd2 = sprintf("talk %x# welcome.42\n", getoid(me));
                cmd3 = sprintf("talk %x# welcome.43\n", getoid(me));
                result =  get_name() + "：\n    我可以利用仙术帮助你更快地提升等级，在一定的时间之内你消灭怪物后所能获得的经验与潜能奖励都是加倍的。你还可以领取" + sprintf("%d",(8-who->get_save_2("double_time.time"))*30 )+ " 分钟的双倍时间。那么现在从下面选择一个适合自己练级的时间吧。\n"
                		ESC "一个小时\n" + cmd1 +
                		ESC "两个小时\n" + cmd2 +
                		ESC "四个小时\n" + cmd3 +
                		ESC "关闭\nCLOSE\n";
                send_user( who, "%c%s", ':', result);
                break;
	case 43:
		p += 4;
	case 42:
		p += 2;
	case 41:
		p += 2;
		i = gone_time( who->get_login_time() );
		x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
		if (who->get_save_2("double_time.week")!=x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//双
			who->set_save_2("double_time.time1", 0);	//战国令
			who->set_save_2("double_time.time2", 0);	//战国号角
			who->set_save_2("double_time.time3", 0);
			who->set_save_2("double_time.freeze", 0);	//冻结的双倍时间
		}
		if (who->get_save_2("double_time.freeze")>0)
		{
		        send_user( who, "%c%c%w%s", ':', 3, 6008,
		        	sprintf("%s：\n     你的"HIR"双倍经验时间已经冻结"NOR"，请解除冻结状态后再领取额外的双倍经验吧。\n"
		                ESC "关闭\nCLOSE\n", me->get_name() ) );
			return;
		}				
		if (who->get_save_2("double_time.time")>=8)
		{
			y = 7*24*3600 - ((time() - 4 * 24*3600+8*3600) % (7*24*3600));
			if (y<24*3600)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     这个星期你已经累积领取超过四个小时双倍经验的奖励时间了，你还是等%d小时后再来领取吧。 \n"
			                ESC "关闭\nCLOSE\n", me->get_name(), y/3600 ) );
			}
			else
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     这个星期你已经累积领取超过四个小时双倍经验的奖励时间了，你还是等%d天后再来领取吧。 \n"
			                ESC "关闭\nCLOSE\n", me->get_name(), y / (24*3600) ) );
			}
			return;
		}
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"疲劳游戏时间禁止领取双倍经验。");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"不健康游戏时间禁止领取双倍经验。");
			return ;	
		}		
		if (who->get_save_2("double_time.time")+p>8)
		{
		        p = 8 - who->get_save_2("double_time.time");
		}
		send_user( who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s：\n     你领取了 %d 分钟的双倍经验奖励时间，好好把握吧。\n"
		        ESC "关闭\nCLOSE\n", me->get_name(), p * 30 ) );
		who->add_save_2("double_time.time", p);
		p *= 1800;
		if ( i+ who->get_game_time()<who->get_double_time())
			who->set_double_time(who->get_double_time()+p);
		else
			who->set_double_time(i+ who->get_game_time()+p);
		send_user( who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s：\n     你已经累计领取了%d分钟的双倍经验时间，好好把握吧。\n"
		        ESC "关闭\nCLOSE\n", me->get_name(), (who->get_double_time()-i-who->get_game_time()) / 60 ) );			
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "双倍时间" );
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		break;
	case 50:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    帮派暂时没有开放。",me->get_name() ));
			return;
		}
		if ( who->get_level() >= 40 && !who->get_legend(TASK_40,5) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    建帮需要王之号角，而关于王之号角，似乎只剩下了传说……\n    在几十年前，有一个姓李的人家，他们拥有一门江湖上早已失传的手艺——制作号角。连年战乱，事过境迁，李姓人家的孩子长大了，却厌倦了江湖上的动荡生活，挑了一个有花有草有瀑布流水的世外桃源定居下来，从此不再过问江湖之事。\n    我想，民间的势力是不容忽视的，如果你想建帮，你去找李隐士吧，用你的真诚打动他，叫他给你做一个号角，当然这个号角还需要工匠加工后才能成为王之号角，你先去海滨的东莱山顶找到他吧。\n"ESC"接受任务\ntalk %x# welcome.51\n"ESC"离开",me->get_name(),getoid(me)));
		break;
	case 51:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    帮派暂时没有开放。",me->get_name() ));
			return;
		}
		if ( who->get_level() >= 40 && !who->get_legend(TASK_40,5) )
		{
        		who->set_legend(TASK_40,5);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,10,"建帮的号角" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"建帮的号角");
		}
		break;


	case 60:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    唉，农历春节本来是普天同庆的日子，但是在数百年前被封印的年兽竟然脱困而出，正在各国城外和新手村到处作乱。是你们这些勇士拿起爆竹，奋勇驱逐年兽的时候了！现在爆竹都遗落在各国的周边，赶快去找到这些爆竹，用它去驱逐年兽，还我们一个高高兴兴发红包的春节吧！\n"
			                ESC "交纳年兽的角\ntalk %x# welcome.61\n"
			                ESC "离开", me->get_name(), getoid(me) ) );
		break;
	case 61:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
		{
                	if( !objectp( item = present("年兽的角", who, 1, MAX_CARRY) ) )
                	{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    你身上没有年兽的角呀！现在各国到处都是年兽，你赶快去找爆竹驱赶年兽，然后拿年兽身上的角回来给我吧！\n"
			                ESC "离开", me->get_name(), getoid(me) ) );
                	}
                	else
                	{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    哈哈，看来年兽又一次被我们赶走了！你想要红包吗？现在是新春佳节，想要红包的话你要跟我说什么话呀？呵呵~~\n"
			                ESC "恭喜发财\ntalk %x# welcome.62\n"
			                ESC "福如东海\ntalk %x# welcome.62\n"
			                ESC "万事如意\ntalk %x# welcome.62\n"
			                ESC "圣诞快乐\ntalk %x# welcome.63\n", me->get_name(), getoid(me), getoid(me), getoid(me), getoid(me) ) );
			}
		}
		break;
	case 62:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
		{


                	if( !objectp( item = present("年兽的角", who, 1, MAX_CARRY) ) )
                	{
                		send_user( who, "%c%s", '!', "您身上没有年兽的角");
                		return;
                	}
                       	item2 = new ("/item/04/0434");    // 给红包
                        if (item2)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item2)  >=1 )
                                {
                                        p =item2->move(who, -1);
                                        item2->add_to_user(p);
                                }
                                else
                                {
                                	destruct(item2);
				        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    你身上现在连红包都放不下了，想领红包的话快去腾个空位出来吧！\n"
			                ESC "确定", me->get_name(), getoid(me) ) );
                                	return ;
                                }
                        }
                	// 收去年兽的角一只
	                item->add_amount(-1);
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    哈哈哈，来来来，我给你红包。我神仙爷爷也祝愿你在新的一年可以万事如意。\n"
			                ESC "确定", me->get_name(), getoid(me) ) );
	                send_user( who, "%c%s", '!', "获得红包");
		}
		break;
	case 63:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
		{


                	if( !objectp( item = present("年兽的角", who, 1, MAX_CARRY) ) )
                	{
                		send_user( who, "%c%s", '!', "您身上没有年兽的角");
                		return;
                	}
                       	item2 = new ("/item/04/0434");    // 给红包
                        if (item2)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item2)  >=1 )
                                {
                                        p =item2->move(who, -1);
                                        item2->add_to_user(p);
                                }
                                else
                                {
                                	destruct(item2);
				        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    你身上现在连红包都放不下了，想领红包的话快去腾个空位出来吧！\n"
			                ESC "确定", me->get_name(), getoid(me) ) );
                                	return ;
                                }
                        }
                	// 收去年兽的角一只
	                item->add_amount(-1);
//                	item->remove_from_user();
//                	destruct(item);
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s：\n    现在可不是圣诞节哦，新年说错话本来是没有红包的。但是我希望新年大家都开开心心，这次也把红包给你吧！\n"
			                ESC "确定", me->get_name(), getoid(me) ) );
                	send_user( who, "%c%s", '!', "获得红包");
		}
		break;
	case 70:
                cmd1 = sprintf( "talk %x# welcome.71\n", getoid( me ) );
                cmd2 = sprintf( "talk %x# welcome.72\n", getoid( me ) );
                result =  get_name() + "：\n    您可以利用"HIR"功德点或者门派贡献点"NOR"换取额外的双倍经验时间。但是"HIR"一周最多只能换取3次，每次一小时"NOR"。可千万别错过这宝贵的机会哦。\n" ;
                result += ESC "3点功德换取1小时双倍经验\n" + cmd1 ;
                result += ESC "3点门派贡献换取1小时双倍经验\n" + cmd2 ;
                result += ESC "离开\nCLOSE\n";
                send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 71:
	case 72:
		i = gone_time( who->get_login_time() );
		if (who->get_save_2("double_time.freeze")>0)
		{
		        send_user( who, "%c%c%w%s", ':', 3, 6008,
		        	sprintf("%s：\n     你的"HIR"双倍经验时间已经冻结"NOR"，请解除冻结状态后再领取额外的双倍经验吧。\n"
		                ESC "关闭\nCLOSE\n", me->get_name() ) );
			return;
		}				
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"疲劳游戏时间禁止领取双倍经验。");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"不健康游戏时间禁止领取双倍经验。");
			return ;	
		}
		if (who->get_save_2("double_time.time3")>=3)
		{
		        send_user( who, "%c%c%w%s", ':', 3, 6008,
		        	sprintf("%s：\n     你本周已经没有剩余的额外双倍经验时间了，还是等下周一再过来吧。\n"
		                ESC "关闭\nCLOSE\n", me->get_name() ) );
			return;
		}
		if (flag==71)
		{
			if (who->get_bonus() / 10<3)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     你的功德好像不足3点。获得功德点的方法就是在你50级之后多带30级以下的新手升级，或者你的徒弟出师之后也能获得不少的功德点。\n"
			                ESC "关闭\nCLOSE\n", me->get_name() ) );
				return;
			}
			who->add_bonus(-30);
		}
		else
		{
			if (who->get_fam_contribute()<3)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s：\n     你的门派贡献点不足3点。获得门派贡献点的唯一途径就是完成门派师傅交托给你的任务，每天只要你勤奋地完成师门任务，便可获得相应的门派贡献点。\n"
			                ESC "关闭\nCLOSE\n", me->get_name() ) );
				return;
			}
			who->set_fam_contribute(who->get_fam_contribute()-3);
		}
		who->add_save_2("double_time.time3", 1);
		p = 3600;
		if ( i+ who->get_game_time()<who->get_double_time())
			who->set_double_time(who->get_double_time()+p);
		else
			who->set_double_time(i+ who->get_game_time()+p);
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "双倍时间" );
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		p = who->get_save_2("double_time.time3");
		if (p<3)
			result =  sprintf(get_name() + "：\n    你已经成功换取了1个小时的经验双倍时间，你本周还剩余"HIR"%d小时"NOR"的额外双倍时间可领取，好好把握吧。\n", 3 - p);
		else
			result =  get_name() + "：\n    你已经成功换取了1个小时的经验双倍时间，你本周已经没有额外双倍时间可领取了，好好把握最后的一个小时双倍经验时间吧。\n" ;
		result += ESC "离开\nCLOSE\n";
		send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 80:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s：\n     VIP，是英语Very Important Person的缩写，意思就是很重要的人，通常说的“要员”。别问我为什么会英文，我是神仙嘛，上知天文，下知地理，通古今中外，晓过去未来。在这战国纷争的时代，你是属于最尊贵的VIP的一分子吗？\n"
	                ESC "VIP有什么好处？\ntalk %x# welcome.81\n"
	                ESC "我怎样成为VIP？\ntalk %x# welcome.82\n"
	                ESC "查询我的VIP绑定到期时间\ntalk %x# welcome.83\n"
	                ESC "关闭\nCLOSE\n", me->get_name(),getoid(me),getoid(me),getoid(me) ) );
		
		break;	
	case 100:
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"疲劳游戏时间禁止解除双倍经验冻结。");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"不健康游戏时间禁止解除双倍经验冻结。");
			return ;	
		}
		result =  get_name() + "：\n    你确定现在要解除双倍经验冻结吗？当然，你需要冻结双倍经验的话可以随时回来找我。\n";
		result += ESC "请帮我解除双倍经验冻结\n"+sprintf( "talk %x# welcome.101\n", getoid( me ) );
		result += ESC "离开\nCLOSE\n";
		send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;			
	case 101:
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"疲劳游戏时间禁止解除双倍经验冻结。");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"不健康游戏时间禁止解除双倍经验冻结。");
			return ;	
		}
		if (who->get_save_2("double_time.freeze")>0)
		{
			i = gone_time( who->get_login_time() );
			if ( i+ who->get_game_time()<who->get_double_time())
				who->set_double_time(who->get_double_time()+who->get_save_2("double_time.freeze"));
			else
				who->set_double_time(i+ who->get_game_time()+who->get_save_2("double_time.freeze"));
			who->set_save_2("double_time.freeze", 0);
			result =  get_name() + sprintf("：\n    你已经成功解除了双倍经验的冻结时间，你现在已经领取了"HIR" %d秒 "NOR"的双倍经验时间，如果需要冻结的话可随时过来找我。\n", who->get_double_time() -i -who->get_game_time());
			result += ESC "离开\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6008, result);			
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "双倍时间" );
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);			
		}
		break;
	case 102:	//	战国宝典的领取操作
		if(objectp(item = "/quest/zg_dict"->want_an_zgdict(me,who))) {
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",'!',"您获得了战国宝典。");
		}
		break;
	case 90:
		result =  get_name() + "：\n    你希望冻结你的双倍经验时间吗？一旦你当前的双倍经验时间被冻结，那么你就无法再领取新的双倍经验时间。在双倍经验时间冻结之后，需要的话，你随时可以再来我这里将冻结的双倍经验时间解冻。\n    但是你必须注意，冻结后的双倍经验时间，我只能为你"HIR"保存到每周星期天的23：59分，一旦超出了这个时间，冻结的时间将会被全部清空。\n";
		result += ESC "请帮我冻结双倍经验时间\n"+sprintf( "talk %x# welcome.91\n", getoid( me ) );
		result += ESC "离开\nCLOSE\n";
		send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;		
	case 91:
		i = gone_time( who->get_login_time() );
		if ( i+ who->get_game_time()<who->get_double_time())
		{
			who->set_save_2("double_time.freeze", who->get_double_time() - i - who->get_game_time() );
			result =  get_name() + sprintf("：\n    你已经成功冻结了"HIR" %d秒 "NOR"的双倍经验时间，如果需要解冻的话可随时过来找我。\n", who->get_double_time() -i -who->get_game_time());
			result += ESC "离开\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6008, result);			
			who->set_double_time(0);
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "双倍时间" );
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);						
		}
		break;		
	case 81:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s：\n     VIP嘛，好处实在是很多啊。\n    首先，成为VIP期间可以拥有VIP的称谓、好友突显VIP；拥有专享的发言频道、专享的改变发言字色的命令。\n    其次，获赠双倍时间；获得增加固定攻击防御值和缩短药品冷却时间的状态效果，每天还能获得三次免费复活，复活后不会有任何损失；取消副本的等级限制，可以随意进入高于或者低于自己等级段的副本。\n    再次，每天的前20轮师门任务的奖励提升；师爷杀囚任务潜能奖励加倍；VIP玩家在队伍中时能给全队增加额外经验。\n    此外，VIP玩家在使用生活技能制造成品、使用晶石精炼装备、使用锻造石提升装备属性时，成功率都会提升！\n    哎呀，我说得好累，让我休息会吧。具体的好处你也可以去官方查询呀。\n"
	                ESC "我怎样成为VIP？\ntalk %x# welcome.82\n"
	                ESC "关闭\nCLOSE\n", me->get_name(),getoid(me) ) );
		
		break;
	case 82:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s：\n     成为VIP么？你可以去官方网站zg.mop.com 购买元宝。在战国珍宝铺VIP服务包栏目下选择购买VIP包，就可以与你的角色ID相绑定了。\n    不过要注意的是，元宝是充在账户中的，但VIP是与购买的角色ID相绑定的，可不要绑错了呀。\n"
	                ESC "查询我的VIP绑定到期时间\ntalk %x# welcome.83\n"
	                ESC "关闭\nCLOSE\n", me->get_name(),getoid(me) ) );
		
		break;
	case 83:
		if ( !who->get_vip() )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    您似乎不是VIP会员呢。\n"ESC"离开",me->get_name()));
			return ;
		}
		iVipTime = who->get_save_2("vip_package.time");
		mxTime = localtime(iVipTime);
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s：\n     欢迎您，您的VIP绑定时间将持续到%d-%02d-%02d %02d:%02d:%02d，需要什么帮助吗？\n"
	                ESC "获赠VIP双倍时间\ntalk %x# welcome.84\n"
	                ESC "关闭\nCLOSE\n", me->get_name(),mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],		mxTime[TIME_HOUR],mxTime[TIME_MIN],mxTime[TIME_SEC],getoid(me) ) );
		
		break;
	case 84:
		if ( !who->get_vip() )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    您似乎不是VIP会员呢。\n"ESC"离开",me->get_name()));
			return ;
		}
		x = who->get_save_2("vip_package.doubles");
		y = x / 2;
		z = x % 2;
		if ( z )
			cmd1 = sprintf("%s：\n     VIP绑定时间内您共可领取VIP双倍时间"HIR"%d小时30分钟"NOR"。请问您是否要领取VIP双倍时间？\n",me->get_name(),y);
	        else   	
			cmd1 = sprintf("%s：\n     VIP绑定时间内您共可领取VIP双倍时间"HIR"%d小时"NOR"。请问您是否要领取VIP双倍时间？\n",me->get_name(),y);
	                	
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf(cmd1+
	                ESC "领取三十分钟VIP双倍时间\ntalk %x# welcome.85\n"
	                ESC "领取一小时VIP双倍时间\ntalk %x# welcome.86\n"
	                ESC "领取二小时VIP双倍时间\ntalk %x# welcome.87\n"
	                ESC "关闭\nCLOSE\n",getoid(me),getoid(me),getoid(me) ) );
		break;
	case 87:
		p += 2;
	case 86:
		p += 1;
	case 85:
		p += 1;
		if ( !who->get_vip() )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    您似乎不是VIP会员呢。\n"ESC"离开",me->get_name()));
			return ;
		}
		if ( who->get_save_2("vip_package.doubles") < p )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    您的VIP双倍时间已经用完了。\n"ESC"离开",me->get_name()));
			return ;
		}
		i = gone_time( who->get_login_time() );
		x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
		if (who->get_save_2("double_time.week")!=x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//双
			who->set_save_2("double_time.time1", 0);	//战国令
			who->set_save_2("double_time.time2", 0);	//战国号角
			who->set_save_2("double_time.time3", 0);
		}
		who->add_save_2("vip_package.doubles",-p);
		send_user( who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s：\n     你领取了 %d 分钟的VIP双倍经验奖励时间，好好把握吧。\n"
		        ESC "关闭\nCLOSE\n", me->get_name(), p * 30 ) );

		p *= 1800;
	        if ( i+ who->get_game_time()<who->get_double_time())
	        	who->set_double_time(who->get_double_time()+p);
		else
			who->set_double_time(i+ who->get_game_time()+p);		
		send_user( who, "%c%c%c%w%c", 0x51, 1, 1,0001, 0 );
		send_user( who, "%c%c%c%w%w%c", 0x51, 1, 2, 0001, 1, 0 );
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"游戏辅助" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "双倍时间" );
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		break;
	case 88:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s：\n     为了回馈大话战国的老玩家和帮助新手玩家，本仙人特意举行这个"HIR"VIP试用包"NOR"大赠送的服务。\n    只要任何等级满足30级或以上的玩家，都可以在我这里领取一个"HIR"VIP试用包"NOR"。当然，因为是试用包，与真正的VIP包会有一定差别。\n    一、试用包的使用时间只有"HIR"3天（从领取开始计算）。\n    二、在试用包发生作用的三天时间内，你可以在我这里累计领取额外的"HIR"10个小时双倍经验时间。\n    三、在制作生活技能成品、装备精炼和锻造装备的时候，"HIR"不会增加5％的成功几率。\n"
	                ESC HIY"领取VIP试用包\ntalk %x# welcome.89\n"
	                ESC "关闭\nCLOSE\n", me->get_name(),getoid(me) ) );
		break;
	case 89:
		"item/sell/0061"->give_trial_vip(me,who);
		break;
        case 99:
                cmd1 = sprintf( "talk %x# welcome.1\n", getoid( me ) );
                cmd2 = sprintf( "talk %x# welcome.3\n", getoid( me ) );
                cmd3 = sprintf( "talk %x# welcome.20\n", getoid( me ) );
                cmd4 = sprintf( "talk %x# welcome.30\n", getoid( me ) );
                cmd5 = sprintf( "talk %x# welcome.40\n", getoid( me ) );
                cmd6 = sprintf( "talk %x# welcome.70\n", getoid( me ) );
                cmd7 = sprintf( "talk %x# welcome.100\n", getoid( me ) );
                cmd8 = sprintf( "talk %x# welcome.90\n", getoid( me ) );
                if ( get_z(who) == 80 )
                	result =  get_name() + "：\n    这里是周国，你来过吗？我这儿可是周国最中心的地方，四通八达的，去哪儿都得经过我这。你问我这里叫什么名字？天坛，知道吧？可是个响当当的名字！\n" ;
                else
			result =  get_name() + "：\n    凡是新手来到新手村都会经过我这儿，嗯，你刚刚来我们这儿，肯定什么都不了解，需要我给你介绍一下吗？\n" ;
		if ( z == 1 || z == 4 ||  z == 7 )
		{
			if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2) )
				result = result +  ESC +HIY+ "送信使命\n" + cmd1;
			if (who->get_legend(TASK_NEWBIE_00, 3) && !who->get_legend(TASK_NEWBIE_00, 5)	)
				result = result +  ESC "交出木剑\n" + sprintf("talk %x# welcome.5\n", getoid( me ));
			if (!who->get_legend(TASK_48, 1))
				result = result +  ESC +HIY+ "小试身手\n" + cmd3;
		}
		else
		{
//			if (who->get_level()>=30&&(!who->get_legend(TASK_NEWBIE_00, 9)||!who->get_legend(TASK_NEWBIE_00, 10))&& get_z(who) == 80 )
//				result = result + ESC +HIY+ "拜访师爷\n" + sprintf("talk %x# welcome.30\n", getoid( me ));
//			if (who->get_level()>=10&&(!who->get_legend(TASK_NEWBIE_00, 11)||!who->get_legend(TASK_NEWBIE_00, 12)) && get_z(who) == 80)
//				result = result + ESC +HIY+ "王捕头的美差\n" + sprintf("talk %x# welcome.32\n", getoid( me ));
//			if (who->get_level()>=30&&(!who->get_legend(TASK_NEWBIE_00, 13)||!who->get_legend(TASK_NEWBIE_00, 14))&& get_z(who) == 80 )
//				result = result + ESC +HIY+ "找尉迟老镖头谈谈\n" + sprintf("talk %x# welcome.34\n", getoid( me ));
			if ( who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80 )
				result = result + ESC +HIY+ "锻炼的机会\n" + sprintf("talk %x# welcome.36\n", getoid( me ));
			if ( who->get_level() >= 40 && !who->get_legend(TASK_40,5) )
				result = result + ESC +HIY+ "建帮的传说\n" + sprintf("talk %x# welcome.50\n", getoid( me ));
		}
                if (is_holiday()) result += sprintf( ESC "我想领取礼物\n%s\n" , cmd4 );
                result += ESC "领取双倍时间\n" + cmd5 ;
                result += ESC "换取额外的双倍时间\n" + cmd6 ;
	        i = gone_time( who->get_login_time() );
		if (who->get_save_2("double_time.freeze")>0)
			result += ESC +HIY+"请解除我的双倍经验冻结\n" + cmd7 ;
		else
		if ( i+ who->get_game_time()<who->get_double_time())
			result += ESC HIY"冻结双倍经验时间\n" + cmd8 ;
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
			result += sprintf(ESC "神仙爷爷春节好！\ntalk %x# welcome.60\n",getoid(me));
                result += sprintf(ESC HIG"VIP是什么？\ntalk %x# welcome.80\n",getoid(me));
                result += sprintf(ESC HIG"获赠VIP双倍时间\ntalk %x# welcome.84\n",getoid(me));
                result += sprintf(ESC HIY"VIP试用包\ntalk %x# welcome.88\n",getoid(me));
                result += sprintf(ESC "领取《战国宝典》\ntalk %x# welcome.102\n",getoid(me));
                result += ESC "离开\nCLOSE\n";

                send_user( who, "%c%s", ':', result);
                break;
        }
}


int is_holiday()
{
        return 0;
}

//设置春节活动的开启和关闭
int set_newyear(int open,int close)
{
	open_val = open;
	close_val = close;
	return 1;
}
