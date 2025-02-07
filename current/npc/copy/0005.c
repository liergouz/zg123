#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0450; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("逃亡的苦役");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        set_head_color(0x39eb);
        setup();
}

void do_look(object who)
{
	int id,level;
	object me=this_object();

	id = getoid(me);
	level = who->get_level();
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "副本系统尚未开放！");
		return;
	}  	
	if ( level > 70 && !who->get_vip() )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    在骊山陵墓的工作简直猪狗不如，经过千辛万苦终于逃了出来了。我发誓一定要向那些残酷的监工们报复。如果你想去骊山陵墓找那些监工的茬的话，我可以给你领路，不过你一定要保护我安全哦。\n"ESC"使用开门芝麻进入骊山陵墓\ntalk %x# welcome.85\n"ESC"骊山陵墓是什么地方？\ntalk %x# welcome.47\n"ESC"进入规则\ntalk %x# welcome.109\n"ESC"离开",id,id,id));
	else		
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    在骊山陵墓的工作简直猪狗不如，经过千辛万苦终于逃了出来了。我发誓一定要向那些残酷的监工们报复。如果你想去骊山陵墓找那些监工的茬的话，我可以给你领路，不过你一定要保护我安全哦。\n"ESC"进入骊山陵墓\ntalk %x# welcome.72\n"ESC"骊山陵墓是什么地方？\ntalk %x# welcome.47\n"ESC"进入规则\ntalk %x# welcome.109\n"ESC"离开",id,id,id));
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
        case 47:
        	if ( level > 70 && !who->get_vip() )
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    骊山陵墓是一个特殊的地方，里面有很多谜题等待大家去探索。有很多高级怪物等待大家去挑战，听说里面的怪物会掉落很多极品的装备呢！\n"ESC"进入规则\ntalk %x# welcome.109\n"ESC"使用开门芝麻进入骊山陵墓\ntalk %x# welcome.85\n"ESC"离开",id,id,));
        	else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    骊山陵墓是一个特殊的地方，里面有很多谜题等待大家去探索。有很多高级怪物等待大家去挑战，听说里面的怪物会掉落很多极品的装备呢！\n"ESC"进入规则\ntalk %x# welcome.109\n"ESC"进入骊山陵墓\ntalk %x# welcome.72\n"ESC"离开",id,id,));
        	break;
        case 109:
        	if ( (level >=50 && level <= 70) || (level>70&&who->get_vip()) )
        		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    玩家必需是队伍的形式进入骊山陵墓，骊山陵墓只能容纳"HIR"5位"NOR"同队伍的玩家。但陵墓可以容纳很多很多队伍。每个队伍都有特定的陵墓。队伍之间不会交叉碰面。每个队伍都独立存在于一个骊山陵墓内。骊山陵墓只能是人物"HIR"等级50-70的玩家"NOR"才可以进入。\n"ESC"进入骊山陵墓\ntalk %x# welcome.72\n"ESC"离开",id,));
		else
        		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"逃亡的苦役：\n    玩家必需是队伍的形式进入骊山陵墓，骊山陵墓只能容纳"HIR"5位"NOR"同队伍的玩家。但陵墓可以容纳很多很多队伍。每个队伍都有特定的陵墓。队伍之间不会交叉碰面。每个队伍都独立存在于一个骊山陵墓内。骊山陵墓只能是人物"HIR"等级50-70的玩家"NOR"才可以进入。\n"ESC"离开");
        	break; 
        case 72:
        	if ( level <50 || (level > 70 && !who->get_vip()) )
        	{
        		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"逃亡的苦役：\n    玩家必需是队伍的形式进入骊山陵墓，骊山陵墓只能容纳"HIR"5位"NOR"同队伍的玩家。但陵墓可以容纳很多很多队伍。每个队伍都有特定的陵墓。队伍之间不会交叉碰面。每个队伍都独立存在于一个骊山陵墓内。骊山陵墓只能是人物"HIR"等级50-70的玩家"NOR"才可以进入。\n"ESC"离开");
			return ;	
		}  
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    骊山陵墓的监工们很厉害，如果你要进去骊山陵墓教训那些监工，最好先找些伙伴组队再进入骊山陵墓。\n"));
			return;
		}
 	       	        	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB1);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/tomb"->new_copy_tomb1(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance1");
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;
	case 85:
		if ( level <= 70 || (level>70&&who->get_vip()) )
			return ;
		item = present("开门芝麻", who, 1, MAX_CARRY);
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    人物等级50-70的玩家可以进入骊山陵墓。超过70级的玩家需要使用开门芝麻才能进入。\n"));
			return ;	
		}
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    骊山陵墓的监工们很厉害，如果你要进去骊山陵墓教训那些监工，最好先找些伙伴组队再进入骊山陵墓。\n"));
			return;
		} 
		send_user( who, "%c%c%s", 0x59, 1, sprintf("您将通过"HIR"开门芝麻"NOR"进入骊山陵墓副本。\n"
                        ESC "%c\n"ESC"talk %x# welcome.95\n"
			, 1, getoid(me) ) );				
		break;
	case 95:
		if ( level <= 70 || (level>70&&who->get_vip()) )
			return ;
		item = present("开门芝麻", who, 1, MAX_CARRY);
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    人物等级50-70的玩家可以进入骊山陵墓。超过70级的玩家需要使用开门芝麻才能进入。\n"));
			return ;	
		} 
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("逃亡的苦役：\n    骊山陵墓的监工们很厉害，如果你要进去骊山陵墓教训那些监工，最好先找些伙伴组队再进入骊山陵墓。\n"));
			return;
		}
		legend = sprintf("进入副本使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);
		item->remove_from_user();
		destruct(item);	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB1);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/tomb"->new_copy_tomb1(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance1");
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "传送中……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}				
		break;
	}
}


