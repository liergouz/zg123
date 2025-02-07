
#include <npc.h>
#include <ansi.h>
#include <music.h>
#include <equip.h>
#include <task.h>

#define CRIMINAL        "/npc/task/8000"
#define TREASURE        "/item/std/8000"

//#define _CRIMINAL_TEST
#define TASK_TIME_LIMIT	1800

inherit OFFICER;

void do_quest();
void accept_task();
void task_info();
void task_bonus();
void do_visit(string arg);
void do_thief(string arg);
void accept_thief();
void give_thief_bonus();
void do_treasure();
void get_hoe();

// 函数：获取人物造型
int get_char_picid() { return 5205; }

// 函数：构造处理
void create()
{
        set_name( "王捕头" );

        set_2( "talk", ([
                "quest" : (: do_quest() :),
                "accept": (: accept_task() :),
                "info"	: (: task_info() :),
                "bonus"	: (: task_bonus() :),
                "visit"	: (: do_visit :),
                "thief" : (: do_thief :),
                "accept_thief"	: (: accept_thief :),
                "bonus_thief"	: (: give_thief_bonus :),
                "hoe"		: (: get_hoe :),
                "treasure"	: (: do_treasure :),

        ]));        	
        setup();
        set("mpLegend",([0:({32,}),]));
}

// 函数：对话处理
void do_look( object who )
{
	object npc,me=this_object();
	int id = getoid( me ),i;
	string criminal,result;
        string cmd1 = sprintf( "talk %x# quest\n",  id);
        string cmd2 = sprintf( "talk %x# info\n",id );
        string cmd3 = sprintf( "talk %x# thief\n", id );
        string cmd4 = sprintf( "talk %x# treasure\n",id);
	string tmp ="";

        if ( (i = who->get_quest("thief.flag")) && (TASK_TIME_LIMIT - gone_time( who->get_quest("thief.time")) > 0) )
        {
        	if ( i == 1 )
			tmp = ESC "教训小偷\n" + cmd3;
		else if ( i == 2 )
			tmp = ESC "找回丢失的物品\n" + cmd3;
		else if ( i == 3 )
			tmp = ESC "物品采购\n" + cmd3;
		else if ( i == 4 )
			tmp = ESC "追捕窃贼\n" + cmd3;
	}
        else 
        	tmp =	ESC "王捕头的任务。\n" + cmd3;
	/*
	如果活动时间还没有到或者活动时间已经结束，这里样的就不出现这个获取挖宝小锄头选项
	*/
	if ( who->get_task("criminal.bonus") && (criminal = who->get_task("criminal.name")) && stringp(criminal) )
		tmp += ESC +sprintf("追捕%s。\n",criminal ) + cmd2;
	else if(     stringp( criminal = who->get_task("criminal") ) 
        &&    ( npc = find_char(criminal) ) && npc->is_criminal() )
		tmp += ESC +sprintf("追捕%s。\n",npc->get_name()) + cmd2;
        else    
		tmp += ESC "追捕逃犯任务。\n" + cmd1;
	if ( who->get_level()>=10 && who->get_legend(TASK_2_00,10) && !who->get_legend(TASK_2_00,11) ) 
		tmp += sprintf(ESC HIY "王捕头的美差\ntalk %x# visit.1\n",getoid(this_object()));
	if ( who->get_legend(TASK_2_00,11) && !who->get_legend(TASK_2_00,12) ) 
		tmp += sprintf(ESC HIY "拜访师爷\ntalk %x# visit.3\n",getoid(this_object()));
	if("sys/party/treasure"->is_open())
	{
		tmp += ESC"极限挖宝。\n"+ cmd4;
	}
	send_user( who, "%c%s", ':', get_name() + "：\n    前段时间监狱墙壁破损，几个逃犯居然乘机逃跑，大王悬赏全力捉拿，并吩咐我负责此事，你要愿意去追捕这逃犯，得先给我500金意思意思，我就把这美差交给你，奖励可不少哦！\n" +
                        tmp +
                        ESC "离开。\nCLOSE\n" );		
}
//极限挖宝
void do_treasure()
{
	object me = this_object();
	object player = this_player();
	string tmp ="";
	string cmd4 = sprintf( "talk %x# hoe\n",getoid(me));
        if("sys/party/treasure"->is_open())
	{
		tmp += ESC"领取挖宝小锄头。\n"+ cmd4;
		send_user(player,"%c%s",':',get_name() +":\n "HIR"每个星期六与星期日的16：00—17：00"NOR"，你都可以来我这里领取挖宝小锄头，"HIR"每次只可领取一把，但是次数无上限"NOR"，一个小时内挖宝小锄头任你领！\n"+
			tmp +
			ESC"离开。\nCLOSE\n");
	}
	
}
// 函数：任务处理
void do_quest()
{
        object me, who, npc, map, item;
        string criminal;
        int level, z, x, y, p;

        me = this_object();  who = this_player();

        if( who->get_cash() < 500 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() +":\n    嘿！你小子耍我是不是，穷鬼一个，你还想跑这趟美差呀，我怀疑你连出门的路费都没有，你要怎样捉拿逃犯！" );
                return;
        }

        if(     stringp( criminal = who->get_task("criminal") )
        &&      ( npc = find_char(criminal) ) && npc->is_criminal() )
        {
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() +":\n    赶快去追缉逃犯吧！" );
		return ;
        }

        if( gone_time(who->get_task("criminal.time")) < 180 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    你看看你，晚来一步，让别人捷足先登了，早就跟你说过了，这可是趟美差，人家抢着要，你倒好，还挑三拣四的，现在后悔了吧？\n" 
                	ESC "离开。\nCLOSE\n" );
                return;
        }
        level = who->get_level() - random(6);
        if( level < 0 ) level = 0;

        if( !( p = XY_D->get_city_point( -1, IS_CHAR_BLOCK ) ) ) return;

        z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;

        if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;

	criminal = NPC_NAME_D->get_criminal_name();	

	who->set("criminal.name",criminal);        
	who->set("criminal.x",x);        
	who->set("criminal.y",y);        
	who->set("criminal.z",z);        
	who->set_task("criminal.time",time());
	x = x + random(30)-15;
	y = y + random(30)-15;
	if ( x < 1 ) x = 1;
	if ( y < 1 ) y = 1;
        item = who->get_equip(HAND_TYPE);
	if (item && item->get_item_number()==10001078)
	{	
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
			sprintf(": \n    最近收到确切的情报，相信大盗"HIR"%s"NOR"就藏匿在"HIR"%s(%d,%d)"NOR"一带。 如果你有一种称为“缉捕公文”的书卷，我相信要发现"HIR"%s"NOR"大至的藏身位置也不是一件难事。如果你能顺利的把逃犯追捕回来，我会给你应得的赏银。\n",criminal,map->get_name(),x,y,criminal) +
			 ESC "接受\n" + sprintf("talk %x# accept\n",getoid(me)) +
	                 ESC "离开。\n"+ sprintf("talk %x# visit.cancel\n",getoid(me)) );
	}
	else
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
			sprintf(": \n    最近收到确切的情报，相信大盗"HIR"%s"NOR"就藏匿在"HIR"%s(%d,%d)"NOR"一带。 如果你有一种称为“缉捕公文”的书卷，我相信要发现"HIR"%s"NOR"大至的藏身位置也不是一件难事。如果你能顺利的把逃犯追捕回来，我会给你应得的赏银。\n",criminal,map->get_name(),x,y,criminal) +
			 ESC "接受\n" + sprintf("talk %x# accept\n",getoid(me)) +
	                 ESC "离开。\nCLOSE\n" );		
	}
	who->set("criminal.x1",x);        
	who->set("criminal.y1",y);  
}

void accept_task()
{
        object me, who, npc, map;
        string criminal;
        int level, z, x, y, p;

        me = this_object();  who = this_player();

        if( who->get_cash() < 500 )
        {
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() +":\n    嘿！你小子耍我是不是，穷鬼一个，你还想跑这趟美差呀，我怀疑你连出门的路费都没有，你要怎样捉拿逃犯！" );
                return;
        }

        if(     stringp( criminal = who->get_task("criminal") )
        &&      ( npc = find_char(criminal) ) && npc->is_criminal() )
        {
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() +":\n    赶快去追缉逃犯吧！" );
		return ;
        }

        level = who->get_level() - random(6);

        if( level < 0 ) level = 0;
	x = who->get("criminal.x");y = who->get("criminal.y");z = who->get("criminal.z");
	criminal = who->get("criminal.name");
        if( !stringp(criminal) || !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
	who->delete("criminal.x");who->delete("criminal.y");who->delete("criminal.z");who->delete("criminal.name");
        npc = new( CRIMINAL );
        npc->set_name("重犯" + criminal);
        NPC_ENERGY_D->init_level(npc, level);
        npc->add_max_hp(750);
        npc->add_dp( level * 5 / 10 );
        npc->add_pp( level * 15 / 10 );
        npc->add_ap( level * 15 / 10 );
        npc->add_to_scene(z, x, y, 3);

        npc->set( "user", ({ sprintf( "%d", who->get_number() ) }) );
        map->add_reset(npc);    // 加入复位列表


        who->add_cash( -500 );  who->add_gold_log("pay", 500);
        who->log_money("重犯", -500);                
        "/sys/sys/count"->add_use("criminal", 500);
        who->set_task("criminal", sprintf( "%x#", getoid(npc) ) );
        who->set_task("criminal.x", who->get("criminal.x1") );
        who->set_task("criminal.y", who->get("criminal.y1"));
        npc->set( "task", who->get_number() );
        npc->set("xy.z", z);
        npc->set("xy.x", x);
        npc->set("xy.y", y);
        npc->set("level", who->get_level());
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_CRIMINAL,"挖宝任务" );   
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_CRIMINAL,1,"剿灭逃犯" ); 
}

void task_info()
{
        object me, who, npc, map;
        string criminal;
        int level, z, x, y, p;

        me = this_object();  who = this_player();
	if ( who->get_task("criminal.bonus") )
	{
                send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + "：\n    嗯，不错不错，这么快就逃犯给剿灭了，你可是为民除害的大英雄啊。这是你的赏银，大王御赐的。看看，这500金花得值得吧！\n" 
                        ESC "完成任务\n" + sprintf( "talk %x# bonus\n", getoid(me) ) +                        
                        ESC "离开。\nCLOSE\n" );	
		return ;	
	}
	criminal = who->get_task("criminal");

	npc = find_char(criminal);
	if ( !objectp(npc)  )
	{
		return ;
	}
	if (  npc->is_criminal() == 0 )
	{
		return ;
	}
	z = get_z(npc);
      	if( !objectp( map = get_map_object(z) ) || !map->is_scene() ) return;
      	x = who->get_task("criminal.x");
      	y = who->get_task("criminal.y");
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), me->get_name() + 
		sprintf(": \n    事情进行得怎么样了？那个"HIR"%s"NOR"应该就在"HIR"%s(%d,%d)"NOR"一带出没。如果你手中有“缉捕公文”，应该很容易就能找到那贼。\n",npc->get_name(),map->get_name(),x,y,npc->get_name()) +
                 ESC "离开。\nCLOSE\n" );
	
}

void task_bonus(){__FILE__->task_bonus_callout(this_object(),this_player());}

void task_bonus_callout(object me,object who)
{
	int level, exp, pot,money;
	string name;	
//	object who = this_player();
	
	if ( who->get_task("criminal.bonus") == 0 ) 
		return;

	level = who->get_task("criminal.level");
	name = who->get_task("criminal.name");
	
	who->delete_task("criminal.bonus");
	who->delete_task("criminal.level");
	who->delete_task("criminal.name");
	who->delete_task("criminal.map");
	who->delete_task("criminal");
	
        exp = level * level /5 + 200;  
        exp = exp * who->get_online_rate()/100;
        who->add_exp(exp);    // add_exp(exp, 1);
        pot = level * 2;  
        pot = pot * who->get_online_rate()/100;
        who->add_potential(pot);
        money = 1500 * who->get_online_rate()/100;
	who->add_cash(money);
	who->log_money("重犯", money);                
	"/sys/sys/count"->add_income("criminal", money);
	
        who->add_log("&criminal", exp);
        who->add_log("*criminal", pot);
	who->add_log("$criminal", money);
	
        send_user( who, "%c%w", 0x0d, MUSIC_TASK );

        send_user( who, "%c%s", ';',sprintf("您完成捉拿%s任务，经验 %+d, 潜能 %+d, 金钱 +%d。", name, exp, pot,money) );
        send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3,TID_CRIMINAL,1,"" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_CRIMINAL,1,"" );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_CRIMINAL,"" );   

}

void task_giveup(object who,int iKind)
{
	object npc, item;
	string id,*member;
	
	if ( who->get_task("criminal.bonus") )  
	{
	 	send_user( who, "%c%s", '!', "任务已经完成了，请向王捕头报告。" );	
	 	return ;
	}
	if( gone_time(who->get_task("criminal.time")) < 180 )
        {
		item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{
                        send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
                        	ESC "%c\n"ESC"use %x# criminal2\n"
                                , 1, getoid(item) ) );			
			return;
		}
		send_user( who, "%c%s", '!', "请稍后再取消任务" );
                return;
        }
	id = who->get_task("criminal");
	who->delete_task("criminal");
	
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 3,TID_CRIMINAL,1,"" );
        send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_CRIMINAL,1,"" );  	
        send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_CRIMINAL,"" );              
        
        if(    !stringp( id )
        ||     !objectp( npc = find_char(id) )
        ||     !npc->is_criminal() )
        { 
                return;
        }
        member = npc->get("user");
        id = sprintf("%d",who->get_number());
        member -= ({id});
        if ( sizeof(member) == 0 )
        {
	        npc->remove_from_scene();
	        destruct(npc);        	
        }
        else
        	npc->set("user", member);
                
}

void do_visit(string arg)
{
	int i,exp,pot,money;
	object who,npc, item;
	who=this_player();
	npc=this_object();
	
	if (arg=="cancel")	// 拒绝任务转到这里进行
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("你是否使用'瞒天过海符'来消除你的任务间隔时间？\n"
	                	ESC "%c\n"ESC"use %x# criminal\n"
	                        , 1, getoid(item) ) );			
			return;
		}
	}		
	if ( who->get_level()>=10 && who->get_legend(TASK_2_00,10) && !who->get_legend(TASK_2_00,11) ) 
	{
		i = to_int(arg);
		if ( i == 1 )
		{
			if( who->get_fam_name() == "" )
				send_user( who, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("%s\n    看你无门无派的，是不是还不够力量为我所用啊，先去学学武艺吧。\n",npc->get_name(),));	
			else
				send_user( who, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("%s\n    是门派向导介绍你来的？看你也是名门弟子，我的确有用得上你的地方。不过有些事情……看你也是个聪明人，就不用我明说了吧。\n"ESC"完成任务\ntalk %x# visit.2\n",npc->get_name(),getoid(npc)));	
		}
		else if ( i == 2 && who->get_fam_name() != "")
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,11);
			exp = 300 ;
			pot = 35 ;
			money = 500 ;
			who->add_exp(exp);
			who->add_potential(pot);
			who->add_cash(money);
			send_user(who,"%c%s",';',sprintf("王捕头的美差 经验 %d 潜能 %d 金钱 %d",exp,pot,money));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,119,"" );
			npc->do_visit(3);
		}
	}
	if ( who->get_legend(TASK_2_00,11) && !who->get_legend(TASK_2_00,12) ) 
	{
		i = to_int(arg);
		if ( i == 3 )
			send_user( who, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("%s\n    衙门里的师爷可是个传奇人物，有人说他贪污受贿，可也有人说他是个好官，做了不少让人称赞的好事，关于这些传言他却从不为自己澄清，听说最近出现不少匪徒，师爷正到处寻人帮忙呢，你去看看吧！从我背后这扇门进去，一直往前走，就能找到他了。\n"ESC"接受任务\ntalk %x# visit.4\n",npc->get_name(),getoid(npc)));	
		else if ( i == 4 )
		{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,12);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"周国" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,16,"拜访师爷" );
			send_user( who, "%c%s", '!', "得到任务 "HIY"拜访师爷");
		}
	}
}

void do_thief(string arg){ TASK_THIEF_D->do_task_start( this_player(), this_object() ); }

void accept_thief(){ TASK_THIEF_D->accept_task( this_player(), this_object() ); }
void give_thief_bonus(){ TASK_THIEF_D->give_bonus( this_player() ); }

//获得锄头
void get_hoe()
{
	object player = this_player();
	object npc = 	this_object();
	int index,size,flag = 0;//flag标志判断是否可以获得锄头,0为可以获得,1为不可以获得。
	object* all_inv;
	if("sys/party/treasure"->is_open()== 0)//现在活动还没有开始,不能领取锄头。
	{
		return;
	}
	if ( player->get_online_rate() != 100 )
	{
		send_user(player,"%c%s",'!',"你现在是非健康游戏时间，不能参加活动！");
		return;
	}
	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n	您身上的道具栏空间不够，请您空出一格的位置再来领取挖宝小锄头。");
		flag = 1;
	}
	all_inv = all_inventory(player,1,MAX_CARRY*4);
	size = sizeof(all_inv); 
	if(size > 0)
	{
		for(index = 0; index < size;index++)
		{
			if(all_inv[index]->get_name() == "挖宝小锄头" )
			{
				send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n	您已经领取了挖宝小锄头，请您使用小锄头挖宝后再来找我领取。");
 				flag = 1;
			}
		}
	}
	if(flag == 0)
	{
		"sys/party/treasure"->generate_chutou(player);
		send_user(player,"%c%s",'!',"你获得了一把挖宝小锄头！");
	}
	
}
