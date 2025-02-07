#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;
int host_type;

// 函数：获取人物造型
int get_char_picid() { return 650; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("讨逆将军");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        setup();
	host_type = MAIN_D->get_host_type();
}

void do_look(object who)
{
	int id;
	object me=this_object();

	id = getoid(me);
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "副本系统尚未开放！");
		return;
	}	
	if (who->get_level()>60 && !who->get_vip() )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    成峤这个逆贼，竟然不承认大王的国君地位，勾结外族发动叛乱，我奉大王之命，招募各地勇士平定叛乱，你要去成峤军营平乱吗？\n"ESC"成峤军营是什么地方？\ntalk %x# welcome.1\n"ESC"进入军营的规则？\ntalk %x# welcome.2\n"ESC"使用开门芝麻进入成峤军营\ntalk %x# welcome.3\n"ESC"离开",id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    成峤这个逆贼，竟然不承认大王的国君地位，勾结外族发动叛乱，我奉大王之命，招募各地勇士平定叛乱，你要去成峤军营平乱吗？\n"ESC"成峤军营是什么地方？\ntalk %x# welcome.1\n"ESC"进入军营的规则？\ntalk %x# welcome.2\n"ESC"进入成峤军营\ntalk %x# welcome.3\n"ESC"离开",id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy, level;
       	object who, item,map;
       	string legend;
        who = this_player();
        flag = to_int(arg);
        level = who->get_level();
        who->set_time( "talk",  0);
        id = getoid(me);
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "副本系统尚未开放！");
		return;
	}        
        switch(flag)
        {
        case 1:
        	if (level>60 && !who->get_vip())
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    成峤军营是一个特殊的地方，里面有很多谜题等待大家去探索。有很多高级怪物等待大家去挑战，听说里面的怪物会掉落很多极品的装备呢！\n"ESC"进入军营的规则？\ntalk %x# welcome.2\n"ESC"使用开门芝麻进入成峤军营\ntalk %x# welcome.3\n"ESC"离开",id,id,));
		else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    成峤军营是一个特殊的地方，里面有很多谜题等待大家去探索。有很多高级怪物等待大家去挑战，听说里面的怪物会掉落很多极品的装备呢！\n"ESC"进入军营的规则？\ntalk %x# welcome.2\n"ESC"进入成峤军营\ntalk %x# welcome.3\n"ESC"离开",id,id,));
        	break;
        case 2:
        	if (level>60 && !who->get_vip())
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    玩家必需是队伍的形式进入成峤军营，成峤军营只能容纳5位同队伍的玩家。但军营可以容纳很多很多队伍。每个队伍都有特定的军营。队伍之间不会交叉碰面。每个队伍都独立存在于一个成峤军营内。成峤军营只能是人物等级40-60的玩家才可以进入。\n"ESC"使用开门芝麻进入成峤军营\ntalk %x# welcome.3\n"ESC"离开",id,));
		else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    玩家必需是队伍的形式进入成峤军营，成峤军营只能容纳5位同队伍的玩家。但军营可以容纳很多很多队伍。每个队伍都有特定的军营。队伍之间不会交叉碰面。每个队伍都独立存在于一个成峤军营内。成峤军营只能是人物等级40-60的玩家才可以进入。\n"ESC"进入成峤军营\ntalk %x# welcome.3\n"ESC"离开",id,));
        	break; 
        case 3:        	
        	if (level>60 && !who->get_vip())
        	{
        		item = present("开门芝麻", who, 1, MAX_CARRY);
        	}
        	
		if ( who->get_level() < 40 || (who->get_level() > 60 && !item && !who->get_vip()) )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    人物等级40-60的玩家可以进入成峤军营。超过60级的玩家需要使用开门芝麻才能进入。\n"));
			return ;	
		}     
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    成峤军营只能是组队进入。\n"));
			return;
		}
		if (level>60 && !who->get_vip() && item)
		{
			send_user( who, "%c%c%s", 0x59, 1, sprintf("您将通过"HIR"开门芝麻"NOR"进入成峤军营副本。\n"
	                        ESC "%c\n"ESC"talk %x# welcome.4\n"
				, 1, getoid(me) ) );				
			return;
		}   	       	        	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_BARRACK);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/barrack"->new_copy(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance");
//        		who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;
        case 4:        	
        	item = present("开门芝麻", who, 1, MAX_CARRY);        	
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    人物等级40-60的玩家可以进入成峤军营。超过60级的玩家需要使用开门芝麻才能进入。\n"));
			return ;	
		}     
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("讨逆将军：\n    成峤军营只能是组队进入。\n"));
			return;
		}
		legend = sprintf("进入副本使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);
		item->remove_from_user();
		destruct(item);	       	        	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_BARRACK);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/barrack"->new_copy(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance");
//        		who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;		
	}
}


