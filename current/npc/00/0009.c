
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <cmd.h>
#include <task.h>
inherit OFFICER;

private static int min10 = -1;                   // 复位次数

// 函数：功德老人识别
int is_bonus_seller() { return 1; }

// 有自己的do_look函数
int is_self_look() { return 1; }

void reset();
void do_buy( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5901; }

// 函数：构造处理
void create()
{
        set_name("功德老人");

        set_2( "talk", ([
                "buy"           : (: do_buy :),
        ]));
        reset();
	set("mpLegend2",([0:({32*48+22,32*48+25,}),]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6,cmd101="",tmp;
        int id;
	"/quest/help"->send_help_tips(who, 29);
        id = getoid( this_object() );
        cmd1 = sprintf( "talk %x# buy.1\n", id );
        cmd2 = sprintf( "talk %x# buy.2\n", id );
        cmd3 = sprintf( "talk %x# buy.3\n", id );
        cmd4 = sprintf( "talk %x# buy.4\n", id );
        cmd5 = sprintf( "talk %x# buy.6\n", id );
        cmd6 = sprintf( "talk %x# buy.8\n", id );
	if ( who->get_legend(TASK_48, 21) && !who->get_legend(TASK_48, 22))
        cmd101 = sprintf(ESC HIY "疑难杂症（1）\ntalk %x# buy.101\n",id);
	if ( who->get_legend(TASK_48, 22) && !who->get_legend(TASK_48, 23))
        cmd101 = sprintf(ESC HIY "疑难杂症（2）\ntalk %x# buy.101\n",id);
	if ( who->get_legend(TASK_48, 24) && !who->get_legend(TASK_48, 25) )
        cmd101 = sprintf(ESC HIY "疑难杂症（2）\ntalk %x# buy.101\n",id);
	if ( who->get_legend(TASK_48, 25) && !who->get_legend(TASK_48, 26) )
        cmd101 = sprintf(ESC HIY "疑难杂症（3）\ntalk %x# buy.101\n",id);
        if (MAIN_D->get_host_type() != 4)
        {
	        if ( who->get_save_2("chain.save") )
	        	tmp = ESC "继续任务链。\n" + sprintf( "talk %x# buy.82\n", id );
	        else if ( who->get_save_2("chain.type") )
	        	tmp = ESC "保存任务链。\n" + sprintf( "talk %x# buy.83\n", id );
		else
			tmp = ESC "领取任务链。\n" + sprintf( "talk %x# buy.81\n", id ) ;
	}
        send_user( who, "%c%s", ':', sprintf( get_name() + "：\n    您有 %d 点功德，有什么我可以帮你的吗？\n", who->get_bonus() / 10 ) + cmd101+
//                ESC "兑换宝石、装备。\n" + cmd1 +
                ESC "兑换潜能。\n" + cmd2 +
                ESC "兑换金钱。\n" + cmd3 +
                ESC "兑换储备箱。\n" + cmd4 +
//                ESC "洗红名。\n" + cmd5 +
                ESC "用功德点洗点。\n" + cmd6 +
                ESC "了解跑环任务。\n" + sprintf( "talk %x# buy.80\n", id ) +
                tmp +
                ESC "离开。\nCLOSE\n" );
}

string *StoneTable = ({
        "/item/89/8901",
        "/item/89/8902",
        "/item/89/8903",
        "/item/89/8904",
        "/item/89/8905",
        "/item/89/8906",
        "/item/89/8907",
        "/item/89/8908",
        "/item/89/8909",
        "/item/89/8910",
        "/item/89/8911",
        "/item/89/8912",
        "/item/89/8913",
        "/item/89/8914",
        "/item/89/8915",
        "/item/89/8916",
        "/item/89/8917",
        "/item/89/8918",
        "/item/89/8919",
        "/item/89/8920",
        "/item/89/8921",
//      "/item/89/8922",
        "/item/89/8923",
});

int sizeof_stone = sizeof(StoneTable);

// 函数：复位处理
void reset()
{
        string *stone, *equip, file;

        if( ++ min10 % 6 == 0 )    // １小时处理(10min * 6)
        {
                reset_eval_cost();
/*
                stone = ({ });                
                while( sizeof(stone) < 3 )
                {
                        file = StoneTable[ random(sizeof_stone) ];
                        if( member_array(file, stone) == -1 ) stone = stone + ({ file }) - ({ 0 });
                }
                add_2( "good", ([
                        "01" : stone[0],
                        "02" : stone[1],
                        "03" : stone[2],
                ]) );
                add_2( "list", ([
                        "01" : 3,
                        "02" : 3,
                        "03" : 3,
                ]) );
*/
                equip = ({ });
                while( sizeof(equip) < 5 )
                {
                        switch( random(4) )
                        {
                      default : file = WEAPON_FILE->get_weapon_file_2(60);  break;
                       case 1 : file = WEAPON_FILE->get_weapon_file_2(70);  break;
                       case 2 : file = ARMOR_FILE->get_armor_file_2(60);  break;
                       case 3 : file = ARMOR_FILE->get_armor_file_2(70);  break;
                        }
                        if( member_array(file, equip) == -1 ) equip = equip + ({ file }) - ({ 0 });
                }
                add_2( "good", ([
                        "04" : equip[0],
                        "05" : equip[1],
                        "06" : equip[2],
                        "07" : equip[3],
                        "08" : equip[4],
                ]) );
                add_2( "list", ([
                        "04" : 2,
                        "05" : 2,
                        "06" : 2,
                        "07" : 2,
                        "08" : 2,
                ]) );
        }
}

// 函数：兑换功德点
void do_buy( string arg )
{
        object me, who;
        string cmd1, cmd2, cmd3;
        int id, type, type2, p1, p2, time, i, p;
        object item;

        me = this_object();  who = this_player();

        if( !arg ) type = 1;
        else if( sscanf(arg, "%d.%d", type, type2) ) ;
        else { type = to_int(arg);  type2 = 0; }
        
        if (type>=2 && type<=100)
        {
		if (MAIN_D->get_host_type()==6012)
		{
			send_user(who, "%c%s", '!', "功能尚未开放！");
			return;
		}         	
        }

        switch( type )
        {
      default : LIST_CMD->main( who, sprintf( "%x#", getoid(me) ) );
                return;

       case 2 : switch( type2 )
                {
              default : id = getoid(me);
                        cmd1 = sprintf( "talk %x# buy.2.1\n", id );
                        cmd2 = sprintf( "talk %x# buy.2.2\n", id );
                        cmd3 = sprintf( "talk %x# buy.2.3\n", id );
                        send_user( who, "%c%s", ':', get_name() + "：\n１点功德可以兑换 55 潜能，你想如何兑换？\n"
                                ESC "10 功德换 550 潜能。\n" + cmd1 +
                                ESC "20 功德换 1100 潜能。\n" + cmd2 +
                                ESC "40 功德换 2200 潜能。\n" + cmd3 +
                                ESC "离开。\nCLOSE\n" );
                        return;
               case 1 : p1 = 100;  p2 = 550;  break;
               case 2 : p1 = 200;  p2 = 1100;  break;
               case 3 : p1 = 400;  p2 = 2200;  break;
                }

                if( who->get_bonus() < p1 )
                {
                        send_user( who, "%c%s", '!', "您的功德点数不够。" );
                        return;
                }

                who->add_bonus( -p1 );
                who->add_potential(p2);
                write_user(who, ECHO "您用 %d 点功德兑换了 %d 潜能。", p1 / 10, p2);

                return;

       case 3 : switch( type2 )
                {
              default : id = getoid(me);
                        cmd1 = sprintf( "talk %x# buy.3.1\n", id );
                        cmd2 = sprintf( "talk %x# buy.3.2\n", id );
                        cmd3 = sprintf( "talk %x# buy.3.3\n", id );
                        send_user( who, "%c%s", ':', get_name() + "：\n１点功德可以兑换 1500 金，你想如何兑换？\n"
                                ESC "20 功德换 30000 金。\n" + cmd1 +
                                ESC "40 功德换 60000 金。\n" + cmd2 +
                                ESC "80 功德换 120000 金。\n" + cmd3 +
                                ESC "离开。\nCLOSE\n" );
                        return;
               case 1 : p1 = 200;  p2 = 30000;  break;
               case 2 : p1 = 400;  p2 = 60000;  break;
               case 3 : p1 = 800;  p2 = 120000;  break;
                }

                if( who->get_bonus() < p1 )
                {
                        send_user( who, "%c%s", '!', "您的功德点数不够。" );
                        return;
                }

                who->add_bonus( -p1 );
                who->add_cash(p2);  who->add_gold_log("sell", p2);
                who->log_money("功德", p2);                
                "/sys/sys/count"->add_income("bonus", p2);
                write_user(who, ECHO "您用 %d 点功德兑换了 %d 金。", p1 / 10, p2);

                return;
	case 4:
		send_user( who, "%c%s", ':', me->get_name() + "：\n    兑换帮派储备任务的代替品必须消耗5点的功德值。你确定要兑换吗？\n"+
			ESC "确定\n" + sprintf("talk %x# buy.5\n", getoid(me)) +
                	ESC "离开。\nCLOSE\n" );			
		break;
	case 5:
/*	
		if (who->get_save_2("orgtask.type")==0)
		{
			send_user( who, "%c%s", ':', me->get_name() + "：\n    你在与老夫开玩笑吧？要兑换替代品你就得先去帮派帐房先生处领取储备任务\n"+
                		ESC "离开。\nCLOSE\n" );
                	return ;
		}	
*/		
		if( who->get_bonus() < 50 )
		{
			send_user( who, "%c%s", ':', me->get_name() + "：\n    你的功德还是不够啊，多带带徒弟存点功德再来老夫这里吧。\n"+
                		ESC "离开。\nCLOSE\n" );
                	return;
		}			
                if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
                {
			send_user( who, "%c%s", ':', me->get_name() + "：\n    请整理整理你身上的东西再来吧。\n"+
                		ESC "离开。\nCLOSE\n" );
                        return ;
                }	
                item = new ("/item/01/0006");
                if (item)
                {                	                	
                        p =item->move(who, -1);
                        item->add_to_user(p);        
			send_user( who, "%c%s", ':', me->get_name() + "：\n    这就是你要的储备箱，快快回去帐房先生处交差吧。\n"+
                		ESC "离开。\nCLOSE\n" );       
                	send_user( who, "%c%s", '!', "得到一个储备箱" );                         	
                	who->add_bonus( -50 );
                }	
		break;        
/*		       
	case 6:		//洗红名
		if ( who->get_pk() <= 0 )
		{
			send_user( who, "%c%s", ':', get_name() + "：\n    你在和老夫开玩笑吧？\n"
                        	ESC "返回\nCLOSE\n" );
			return ;
		}
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s\n    你已经造了%d个杀孽，你愿意花费20点功德来减轻自己的罪孽吗？\n"ESC"确定\ntalk %x# buy.7\n"ESC"离开",get_name(),who->get_pk(),getoid(this_object())));
		break;			
	case 7:
		if ( who->get_bonus() < 200 )
		{
                        send_user( who, "%c%s", ':', get_name() + ":\n    你的功德还是不足……年轻人还得多行善果，协助新人修炼才可以得到更多的功德啊。" );
                        return;
                }
                if ( who->get_pk() <= 0 )
                	return; 
                who->add_pk(-1);
                who->add_bonus(-200);         
                send_user( who, "%c%s", ':', get_name() + ":\n    你花费20点功德洗掉一个红名。" ) ;   	
		break;		
*/		       
	case 8:
		time = who->get_save("bonus_time");
		p1 = 100;
		if (time>0) for (i = 0;i<time;i++) p1 *= 2;
		if (p1>1600) p1 = 1600;
		id = getoid(me);
		cmd1 = sprintf( "talk %x# buy.9\n", id );
                send_user( who, "%c%s", ':', sprintf(get_name() + "：\n    你愿意消耗 %d 点功德来重新分配你的属性点吗？\n"
                        ESC "确定\n" + cmd1 +
                        ESC "离开\nCLOSE\n", p1 ) );				
		break;		
	case 9:
		time = who->get_save("bonus_time");
		p1 = 1000;
		if (time>0) for (i = 0;i<time;i++) p1 *= 2;
		if (p1>16000) p1 = 16000;	
                if( who->get_bonus() < p1 )
                {
                        send_user( who, "%c%s", ':', get_name() + "\n    你的功德还是不足……年轻人还得多行善果，协助新人修炼才可以得到更多的功德啊。" );
                        return;
                }		
                who->add_bonus( -p1 );
                who->add_save("bonus_time", 1);
                "/cmd/user/gift"->init_gift_point(who);
		id = getoid(me);
		cmd1 = sprintf( "look %x#\n", id );
                send_user( who, "%c%s", ':', get_name() + "：\n    老夫已经帮你实现了愿望，还有什么需要老夫帮忙的地方吗？\n"
                        ESC "返回\n" + cmd1 );	                
		who->log_legend("您在功德老人处洗属性点。");
		break;
	case 80:
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(),
			sprintf("%s\n    跑环任务可是一个连续性的任务链哦～！当你接取第一个任务时，就要做好把所有任务做完的打算哦！当你接到索取物品的任务，你可以考虑去与你对应等级场景打传说获得，所谓打传说是指：打与自身等级相对应的怪物，系统有一定几率会给予你任务所需要的物品。如果你接到杀恶霸任务，当你无法完成的时候，你可以考虑寻找高手帮忙哦～！如果你能连续做完50环任务，你将会获得丰富的经验奖励和物品奖励。此外一人当天只能接取一次跑完任务，当你放弃或者完成一次跑环任务，那么当天你就等第二天再来领取任务吧～！\n"ESC"离开",me->get_name())
		);
		break;
	case 81:
		CHAIN_D->new_chain(who,me);
		break;
	case 82:
		CHAIN_D->query_resume_chain(who,me);
		break;						        	
	case 83:
		CHAIN_D->query_save_chain(who,me);
		break;
	case 84:
		CHAIN_D->save_chain(who,me);
		break;
	case 85:
		CHAIN_D->resume_chain(who,me);
		break;						        	
        case 101: 
		if ( who->get_legend(TASK_48, 21) && !who->get_legend(TASK_48, 22) )
			send_user(who,"%c%s",':',sprintf("%s:\n    根据你描述的情况来看，村民们根本就不是生病，而是中毒了，你待我想想解毒的方法，再来找我吧。\n"ESC"完成任务\ntalk %x# buy.102\n"ESC"离开",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 22) && !who->get_legend(TASK_48, 23) )
			send_user(who,"%c%s",':',sprintf("%s:\n    据我估计，村民们应该是中了一种名为软骨散的毒，而毒源就是村后的那口水井，中毒的村民都是饮用过村后那口水井里的水后，才出现此症状的。\n    解此毒必需雄黄散，并且要与其他药物配合才有疗效，这药配好后不止要给村民们服下，还得洒入水井中作解毒用。\n    你先去找来雄黄散吧，我听说幽谷一带的小蜜蜂、小蚂蚁、斑点蛙身上都带有雄黄散。\n    做完任务后，用alt+w打开人物属性界面，再使用新手信物就可以快速回到新手村哦！\n"ESC"接受任务\ntalk %x# buy.103\n"ESC"离开",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 24) && !who->get_legend(TASK_48, 25) )
			send_user(who,"%c%s",':',sprintf("%s:\n    我配药还需要一定的时间，你过会儿再来找我拿药吧！\n"ESC"完成任务\ntalk %x# buy.104\n"ESC"离开",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_48, 25) && !who->get_legend(TASK_48, 26) )
			send_user(who,"%c%s",':',sprintf("%s:\n    你将这包解药拿给卫队长，并且告诉他，千万要记得叮嘱村里人最近两天不要去村后的那口水井里打水饮用，记得要将解药拿给村民服用，还要将解药洒到水井内，这样才能治标又治本！\n    还有一件事，你千万不得声张，你告诉卫队长，我疑心是有人在水井里下了毒，还想请村长查明此事，揪出下毒的狠心之人。\n"ESC"接受任务\ntalk %x# buy.105\n"ESC"离开",me->get_name(),getoid(me)));
        	break;
        case 102:
		if ( who->get_legend(TASK_48, 21) && !who->get_legend(TASK_48, 22) )
        	{
        		TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48,22);
			who->add_exp(350);
			who->add_potential(20);
			who->add_cash(500);
			send_user(who,"%c%s",';',"疑难杂症（1） 经验 350 潜能 20 金钱 500");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,109,"" );
			me->do_buy("101");
		}
        	break;
        case 103: 
		if ( who->get_legend(TASK_48, 22) && !who->get_legend(TASK_48, 23) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_48,23);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,110,"疑难杂症（2）" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"疑难杂症（2）");
        	}
        	break;
        case 104: 
		if ( who->get_legend(TASK_48, 24) && !who->get_legend(TASK_48, 25) )
		{
			if( !objectp( item = present("雄黄散", who, 1, MAX_CARRY) ) )
			{
				send_user(who,"%c%s",'!',"你的雄黄散呢?");
				return;	
			}
			TASK_LEGEND_D->task_finish(who);
			item->remove_from_user();
			destruct(item);	
			who->add_exp(300);
			who->add_bonus(100);
			who->add_cash(1800);
			who->set_legend(TASK_48, 25);
			send_user(who,"%c%s",';',"疑难杂症（2） 经验 300 功德 10 金钱 1800");			
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,110,"" );
			me->do_buy("101");
		}
		break;
        case 105: 
		if ( who->get_legend(TASK_48, 25) && !who->get_legend(TASK_48, 26) )
        	{
        		if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->give_item(who,"item/98/0200",1);
        		who->set_legend(TASK_48,26);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"新手村" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,111,"疑难杂症（3）" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"疑难杂症（3）");
        	}
        	break;
        }
}
