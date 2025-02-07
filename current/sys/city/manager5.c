
#include <ansi.h>
#include <map.h>
#include <city.h>
#include <skill.h>
#include <time.h>

#define DAY             86400

// 函数：生成二进制码
void SAVE_BINARY() { }

int is_war_time()
{
	mixed *mxTime;
	int iTime, day, hour;
	iTime = time();
	mxTime = localtime(iTime);
	day = mxTime[TIME_WDAY];
	hour = mxTime[TIME_HOUR];
	switch(day)
	{
	case 5:
	case 6:
		if (hour>=17 && hour<=18) return 1;
		break;
	case 0:
		if (hour>=11 && hour<=12) return 1;
		break;
	}
	return 0;
}

// 函数：发动战争
void do_war( object who, object me, string arg )
{
        object map, *char, npc, soldier, orgnpc;
        mapping org;
        string name1, name2, name, cmd, result;
        int id, z, x, y, p, i, size, time, number;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();
        if( stringp(name1) && stringp(name2) && name1 == name2 )    // 本帮帮众
        {
                if( gone_time( me->get_war() ) > DAY )    // 没有发生战争(开战超过一天)
                {
                        if( !arg || arg == "" )
                        {
                                send_user( who, "%c%c%d%c%c%s", 0x95, 50, id, who->get_org_position(), 0, me->get_org_name() );

                                if(     who->get_org_position() > ORG_PRESBYTER    // 本帮副帮主
                                &&      mapp( org = CITY_ZHOU->get_2("org") ) && arrayp( char = values(org) ) )
                                        for( i = 0, size = sizeof(char); i < size; i ++ ) if( objectp( npc = char[i] ) )
                                {
                                        if( me == npc ) continue;    // 不显示本帮

                                        send_user( who, "%c%c%d%d%s", 0x95, 51, getoid(npc), npc->get_power(),
                                                sprintf( "%-12s%s", npc->get_org_name(), npc->get_master_name() ) );
                                }

                                return;
                        }
                        else if( who->get_org_position() > ORG_PRESBYTER )    // 本帮副帮主
                        {
                                if(     sscanf( arg, "@.%s", name )
                                &&      objectp( npc = find_char(name) )
                                &&      npc->is_org_officer()
                                &&      npc != me )
                                {
					if (me->get_war())
	                                {
	                                	npc = me->get_enemy_95();
	                                	if (npc)
	                                	{
		                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "你们将与"+npc->get_org_name()+"展开一场决战，你无法再向其他帮会挑战。\n"ESC"离开\nCLOSE\n");
		                                        return;
						}
	                                }
	                                if (time() <me->get_create_time()+30*24*3600)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "本帮成立尚未满一个月，不能开战。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
	                                if (time() <npc->get_create_time()+30*24*3600)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "对方帮派成立尚未满一个月，不能开战。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
	                                if (abs(me->get_grade()-npc->get_grade())>1)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "宣战的目标必须与己方帮派规模等级相差不能超过一级。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }	                                
					if (!is_war_time())
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "现在不是开战的时间。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
	                                if( who->get_strength() < 200 )
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "大人的体力不足200，无法发动战争。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
					if (who->get_cash()<1000000)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "你的现金不足100万，无法发动战争。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
					if (me->get_stable()<100)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "本帮派当前的安定度太低，不宜发动战争。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
					if (me->get_favour()<50)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "本帮派当前的人气度太低，不宜发动战争。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }

                                        name = npc->get_org_name();
                                        if(  npc->get_war() )
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "“" + name + "”已经参与了其他帮派战争，无法对其宣战。");
	                                        return;
	                                }
                                        if( !( z = find_map_flag(BATTLE_MAP_BEGIN, BATTLE_MAP_END, 0) ) )    // 查找空白战场
                                        {
                                                send_user( who, "%c%s", '!', "不能向“" + name + "”发动战争。" );
                                                return;
                                        }
/*
                                        switch( get_z(npc) )    // 查找对应战场
                                        {
                                      case 10 : p = 910;  break;
                                      case 20 : p = 920;  break;
                                      case 30 : p = 930;  break;
                                      case 40 : p = 940;  break;
                                      case 50 : p = 950;  break;
                                      case 60 : p = 960;  break;
                                      case 70 : p = 970;  break;
                                      default : send_user( who, "%c%s", '!', "不能向“" + name + "”发动战争。" );
                                                return;
                                        }
*/                                      p = 910;
/*
					if (MAIN_D->get_host()==1) p = 910;
					else
					{
						send_user( who, "%c%s", '!', "不能向“" + name + "”发动战争。" );
						return;
					}
*/
					who->set_strength(0);
					who->add_cash(-1000000);

                                        init_virtual_map(z, p);    // 生成虚拟地图

                                        map = new(BATTLE);    // 生成虚拟对象
                                        map->set_client_id(p);
                                        set_map_object( map, map->set_id(z) );
					time = time()/3600;
					if (time%2==1) time += 3;
					else time += 2;
                                        me->set_war( time*3600 );  npc->set_war( time*3600 );    // 记录战争时间
                                        me->set_battle(z);  npc->set_battle(z);    // 记录战场编号
                                        me->set_enemy_95(npc);  npc->set_enemy_95(me);    // 记录敌方总管
                                        me->set_wood(0); npc->set_wood(0);
                                        me->set_level1(1); npc->set_level1(1);
                                        me->set_level2(1); npc->set_level2(1);
                                        me->set_level3(1); npc->set_level3(1);
                                        map->set_war_attack(name2);  map->set_war_defense(name);    // 记录战争双方
                                        map->set_heart_sec(0);    // 校正时钟
                                        map->set_war(WAR_READY);    // 记录战争准备
                                        map->set_starttime(time*3600);
/*
                                        if (MAIN_D->get_host()==1)
                                        {
                                        	me->set_war( time()+60 );  npc->set_war( time()+60 ); map->set_starttime( time()+60 );
                                        	if (MAIN_D->get_host_type()==1)
                                        	{
                                        		me->set_war( time()+3600 );  npc->set_war( time()+3600 );  map->set_starttime( time()+3600 );
                                        	}
                                        }
*/
                                        NPC_BATTLE_D->war_ready_notice(map);

                                        // 重新刷新窗口

                                        send_user( who, "%c%c%d%c%c%s", 0x95, 50, id, who->get_org_position(), 1, me->get_org_name() );

                                        send_user( who, "%c%c%d%d%s", 0x95, 51, getoid(npc), npc->get_power(),
                                                sprintf( "%-12s%s", npc->get_org_name(), npc->get_master_name() ) );
                                        send_user( who, "%c%c%s", 0x95, 52, short_time( npc->get_create_time() ) );
                                }
                                else
                                if(     sscanf( arg, "?.%s", name )
                                &&      objectp( npc = find_char(name) )
                                &&      npc->is_org_officer()
                                &&      npc != me )
                                {
                                	if (me->get_battle()>0 && me->get_war()>0 && me->get_battle()==npc->get_battle() ) ;
                                	else
                                	{
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "和对方帮派不处于开战状态！\n"ESC"离开\nCLOSE\n");
	                                        return;
                                	}
                                	if (time()<me->get_war())
                                	{
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "战争已经开始了，不能中止。\n"ESC"离开\nCLOSE\n");
	                                        return;
                                	}

	                                if( who->get_strength() < 100 )
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "大人的体力不足100，无法中止战争。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }
					if (me->get_gold()<300000)
	                                {
	                                        send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), "本帮派当前的资金不足30万，无法中止战争。\n"ESC"离开\nCLOSE\n");
	                                        return;
	                                }

                                	z = me->get_battle();
                                	map = get_map_object(z);
                                	if (map) map->destruct_virtual_map(map, z);
					who->add_strength(-100);
					me->add_gold(-300000);
                                        me->set_war( 0 );  npc->set_war( 0 );
                                        me->set_battle(0);  npc->set_battle(0);
                                        me->set_enemy_95(0);  npc->set_enemy_95(0);

                                        NPC_BATTLE_D->war_stop_notice(map);

                                        // 重新刷新窗口

                                        send_user( who, "%c%c%d%c%c%s", 0x95, 50, id, who->get_org_position(), 0, me->get_org_name() );

                                        send_user( who, "%c%c%d%d%s", 0x95, 51, getoid(npc), npc->get_power(),
                                                sprintf( "%-12s%s", npc->get_org_name(), npc->get_master_name() ) );
                                        send_user( who, "%c%c%s", 0x95, 52, short_time( npc->get_create_time() ) );
                                }
                                else if( objectp( npc = find_char(arg) )
                                &&      npc->is_org_officer()
                                &&      npc != me )
                                {
                                	if (me->get_battle()>0 && me->get_war()>0 && me->get_battle()==npc->get_battle() && time()>me->get_war())	// 宣战但是还没有开打
                                	{
                                		cmd = sprintf( "talk %x# war.?.%s\n", getoid(me), arg );
	                                        send_user( who, "%c%s", ':', "如果现在取消对“" HIR + npc->get_org_name() + NOR "”的宣战，我们必须赔偿30万帮派资金给予对方，同时大人必须消耗100点体力，您真的确定吗？\n"
	                                                ESC "确定\n" + cmd +
	                                                ESC "离开\nCLOSE\n" );
						return;
                                	}

                                        cmd = sprintf( "talk %x# war.@.%s\n", getoid(me), arg );
                                        send_user( who, "%c%s", ':', "对“" HIR + npc->get_org_name() + NOR "”发动战争必须消耗自身资金100万，减少帮派人气度50点，减少帮派安定度100点。每次宣战会消耗体力200点。\n你确定要对“" HIR + npc->get_org_name() + NOR "”发动战争吗？\n"
                                                ESC "确定\n" + cmd +
                                                ESC "离开\nCLOSE\n" );
					return;
                                }
                        }
                }
                else    // 已经发生战争
                {
                        if( !arg || arg == "" )
                        {
                                send_user( who, "%c%c%d%c%c%s", 0x95, 50, id, who->get_org_position(), 1, me->get_org_name() );

                                if( objectp( npc = me->get_enemy_95() ) )
                                {
                                        send_user( who, "%c%c%d%d%s", 0x95, 51, getoid(npc), npc->get_power(),
                                                sprintf( "%-12s%s", npc->get_org_name(), npc->get_master_name() ) );
                                        send_user( who, "%c%c%s", 0x95, 52, short_time( npc->get_create_time() ) );
                                }

                                return;
                        }
                        else if( objectp( npc = me->get_enemy_95() ) && arg == sprintf( "%x#", getoid(npc) )
                        &&    ( z = me->get_battle() ) && objectp( map = get_map_object(z) ) )
                        {
				orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name1 ) );
				if (!objectp(orgnpc)) return;
				number = who->get_number();
				if (time() - orgnpc->get_member_time()<7*3600*24)
				{
					send_user( who, "%c%s", '!', "你加入帮派的时间还没超过1星期，无法参加帮战。" );
					return;
				}
                                if( name1 == map->get_war_attack() )
                                {
                                        if( map->get_war() != WAR_BEGIN )
                                        {
                                                send_user( who, "%c%s", '!', "现在不能进入战场！" );
                                                return;
                                        }
                                        if (time()<who->get_save("org_die")+120)
                                        {
                                        	send_user( who, "%c%s", '!', sprintf("你还必须等待%d秒才能重新进入战场。", who->get_save("org_die")+120 - time()) );
                                        	return;
                                        }
                                        who->delete_save("org_die");
                                        map->sub_user(who);
                                        if( map->sizeof_user_dbase() >= 20 )
                                        {
                                                send_user( who, "%c%s", '!', "现在参战人数已经足够了，还是稍后再来吧。" );
                                                return;
                                        }
                                        else
                                        if( p = get_jumpin(z, 1) )
                                        {
                                                x = p / 1000;  y = p % 1000;
						who->set_2("jiguan.z", get_z(who) );
						who->set_2("jiguan.x", get_x(who) );
						who->set_2("jiguan.y", get_y(who) );
						soldier = who->get("soldier");
						if (soldier) soldier->set_manager( map->get_manager() );
                                                who->set_manager( map->get_manager() );
                                                who->add_to_scene(z, x, y, 3, 40971, 0, 40971, 0);
                                                map->add_user(who);
                                                CHAR_CHAR_D->init_loop_perform(who);
                                                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9005, 1, OVER_BODY, PF_LOOP );

                                                map->show_to_user(who);
                                                map->show_to_scene(who);
                                                send_user(who, "%c%c", 0x95, 255);

                                                switch( who->get_level() )    // 设置玩家种类
                                                {
                                            case 0..9 : USER_D->sub_level_a_user(who);  break;
                                          case 10..29 : USER_D->sub_level_b_user(who);  break;
                                              default : USER_D->sub_level_c_user(who);  break;
                                                }
                                                USER_D->add_battle_user(who);
                                        }
                                }
                                else if( name1 == map->get_war_defense() )
                                {
                                        if( map->get_war() != WAR_BEGIN )
                                        {
                                                send_user( who, "%c%s", '!', "现在不能进入战场！" );
                                                return;
                                        }
                                        map->sub_user_2(who);
                                        if( map->sizeof_user_2_dbase() >= 20 )
                                        {
                                                send_user( who, "%c%s", '!', "现在参战人数已经足够了，还是稍后再来吧。" );
                                                return;
                                        }
                                        if (time()<who->get_save("org_die")+120)
                                        {
                                        	send_user( who, "%c%s", '!', sprintf("你还必须等待%d秒才能重新进入战场。", who->get_save("org_die")+120 - time()) );
                                        	return;
                                        }
                                        who->delete_save("org_die");
                                        if( p = get_jumpin(z, 2) )
                                        {
                                                x = p / 1000;  y = p % 1000;
						who->set_2("jiguan.z", get_z(who) );
						who->set_2("jiguan.x", get_x(who) );
						who->set_2("jiguan.y", get_y(who) );
						soldier = who->get("soldier");
						if (soldier) soldier->set_manager( map->get_manager_2() );
                                                who->set_manager( map->get_manager_2() );
                                                who->add_to_scene(z, x, y, 3, 40971, 0, 40971, 0);
                                                map->add_user_2(who);
                                                CHAR_CHAR_D->init_loop_perform(who);
                                                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9006, 1, OVER_BODY, PF_LOOP );


                                                map->show_to_user(who);
                                                map->show_to_scene(who);
                                                send_user(who, "%c%c", 0x95, 255);

                                                switch( who->get_level() )    // 设置玩家种类
                                                {
                                            case 0..9 : USER_D->sub_level_a_user(who);  break;
                                          case 10..29 : USER_D->sub_level_b_user(who);  break;
                                              default : USER_D->sub_level_c_user(who);  break;
                                                }
                                                USER_D->add_battle_user(who);
                                        }
                                }
                        }
                }
        }
}

// 函数：帮派信息
void do_org( object who, object me, string arg )
{
        object npc;
        string name1, name2;
        int id, time;

        id = getoid(me);

        name1 = who->get_org_name();
        name2 = me->get_org_name();
        time = me->get_gradetime();
	if (time>0)
	{
		if (time <time())
		{
			me->set_gradetime(0);
			me->set_grade(me->get_grade()+1);
			FAMILY_D->org_channel( name2, 0, sprintf( HIR "帮派规模上升1，现帮派的规模为%d。",
				me->get_grade() ) );
		}
	}

        if( stringp(name1) && stringp(name2) && name1 == name2  )
        {
                send_user( who, "%c%c%d%d%d%s", 0x95, 70, getoid(me), me->get_member_contribute(who->get_number()), me->get_member_all_contribute(who->get_number()), sprintf("%-12s%s", name1, who->get_org_title()) );
               	send_user( who, "%c%c%c%c%c%d%d%d%d%d", 0x95, 71, me->get_grade(), me->get_science(), me->get_train(), me->get_power(), me->get_favour(), me->get_stable(), me->get_store(), me->get_gold()  );
               	send_user( who, "%c%c%w%w", 0x95, 14, me->sizeof_member_dbase(), me->get_max_number() );
        }
}
