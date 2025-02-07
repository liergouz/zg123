
#include <ansi.h>
#include <task.h>
#include <skill.h>

#define MAX_MEMBER      5              // 队员人数上限
void group_info(object who);
void quest_group(object me,object who);

// 函数：命令处理
int main( object me, string arg )
{
        object *team, *team2, *team3, who,oLeader,oJoiner,map,map1,map2;
        string id, id2, cmd, fam, name, name2;
        int level, z, i, size,tId1,tId2,gId1,gId2;

        if( gone_time( me->get_time("team") ) < 1 )    // 时间限制
                return 1;

        if( !arg ) return 1;

        if( !arg || sscanf( arg, "%s %s",arg, id2 ) != 2  ) return 1;
        if( arg != "follow" && arg != "bet" && arg != "gain" && arg != "give" && !objectp( who = find_player(id2) ) ) return 1;

        switch( arg )
        {
     case "follow":	//队伍跟随
     		if ( me->is_leader() )		//队员跟随队长
     			return ;
     		if ( me->get("team_follow") )	//取消跟随
     		{
     			send_user( me, "%c%w%w%c", 0x81, 0011, 0, EFFECT_GOOD );
     			send_user( me, "%c%c%c", 0xA5, 3, 0 );
     			me->delete("team_follow");
     		}
     		else				//队伍跟随
     		{
     			send_user( me, "%c%w%w%c", 0x81, 0011, -1, EFFECT_GOOD );
     			send_user( me, "%c%c%c", 0xA5, 3, 1 );
     			me->set("team_follow",1);
     		}
     		return ;
     case "cancel" :
     		if( arrayp( team3 = who->get("pending_team") ) )
			who->set( "pending_team", team3 - ({ me, 0 })  );
     		me->set("pending_time", 0);
        	send_user( me, "%c%c%c", 0x59, 1, 0);
        	send_user( who,"%c%s",'!',sprintf("%s拒绝了你的组队申请",me->get_name()));
        	return 1;
     case "g@cancel" :
     		me->set("pending_time", 0);
        	send_user( me, "%c%c%c", 0x59, 1, 0);
        	send_user( who,"%c%s",'!',sprintf("%s拒绝了你的组团申请",me->get_name()));
        	return 1;
     case "+" :
     case "++" :
        	me->set_time( "team", time() );
                if( me->get_no_team() )
                {
                        notify( "您得先打开组队开关。" );
                        return 1;
                }
                if( !arrayp( team = me->get_team() ) && me == who )    // 自己组队
                {
                        id = sprintf( "%d", me->get_number() );
                        if ( TEAM_D->new_team(me) != 1 )
                        {
                        	notify( "组队失败" );
                        	return 1;
                        }
                        me->set_leader(id);
                        if ("/sys/sys/count"->get_new_person())
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_photo(), me->get_level(), me->get_name() );
                        else
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_armor_code(), me->get_level(), me->get_name() );
//			send_user( me, "%c%c%d%s", 0x54, 1, me->get_number(), me->get_name() );
                        send_user( me, "%c%c%d%s", 0x43, 7, 0, WHT "您自己组成一支队伍。" );
			send_user( me, "%c%c%d%w%w", 0x54, 3, me->get_number(), me->get_hp(), me->get_max_hp() );
			send_user( me, "%c%c%d%w%w", 0x54, 4, me->get_number(), me->get_mp(), me->get_max_mp() );
			"/quest/help"->send_help_tips(me, 22);
			"/quest/help"->send_help_tips(me, 43);
			CHAR_CHAR_D->init_loop_perform(me);
                        return 1;
                }

                if( who->get_no_team() )
                {
                        notify( "%s没有打开组队开关。", who->get_name() );
                        return 1;
                }

                if( !arrayp( team2 = who->get_team() ) && !arrayp(team) )
                {
                        id = sprintf( "%d", me->get_number() );
                        if ( TEAM_D->new_team(me) != 1 )
                        {
                        	notify( "组队失败" );
                        	return 1;
                        }
                        me->set_leader(id);
                        if ("/sys/sys/count"->get_new_person())
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_photo(), me->get_level(), me->get_name() );
                        else
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_armor_code(), me->get_level(), me->get_name() );
//			send_user( me, "%c%c%d%s", 0x54, 1, me->get_number(), me->get_name() );
                        send_user( me, "%c%c%d%s", 0x43, 7, 0, WHT "您自己组成一支队伍。" );
			send_user( me, "%c%c%d%w%w", 0x54, 3, me->get_number(), me->get_hp(), me->get_max_hp() );
			send_user( me, "%c%c%d%w%w", 0x54, 4, me->get_number(), me->get_mp(), me->get_max_mp() );
			team = me->get_team();
			"/quest/help"->send_help_tips(me, 22);
			"/quest/help"->send_help_tips(me, 43);
			CHAR_CHAR_D->init_loop_perform(me);
                }
                if (arrayp(team) && sizeof(team)==1 && arg=="++")
                {
                	TEAM_D->remove_member( me->get_leader(), me );
                	team = 0;
                }
                if( arrayp(team) )    // 本人有队伍
                {
                        if( !me->is_leader() )
                        {
                                notify( "队长才能增添队员。" );
                                return 1;
                        }
                        if( member_array(who, team) != -1 )
                        {
                                notify( "%s已经在队伍中了。", who->get_name() );
                                return 1;
                        }
                        if( arrayp(team2) )
                        {
                        	if( sizeof(team) >= 2 )
                        	{
//	                                notify( "%s在另一支队伍中。", who->get_name() );
					quest_group(me,who);
	                                return 1;                        		
                        	}
                        	if (arg=="+")
	                        {
	                                send_user( me, "%c%c%s", 0x59, 1, sprintf("加入新的队伍前你必须先解除自己的组队，你确定要解除自己的队伍吗？\n"
	                                	ESC "%c\n"ESC"team ++ %d\n", 
	                                	1, who->get_number(), 2) );
	                                return 1;
	                        }                        	

                        }
                        if( sizeof(team) >= MAX_MEMBER )
                        {
                                notify( "本队伍的人数过多。" );
                                return 1;
                        }
                        map1 = get_map_object(get_z(me));
                        map2 = get_map_object(get_z(who));
                        if ( map1->is_changping() || map2->is_changping() )
                        {
                        	if ( map1 != map2 )
                        	{
	                                notify( "战场中玩家不允许与战场外的玩家结成队伍！" );
	                                return 1;
                        	}		
                        	if ( me->can_fight(who) )
                        	{
	                                notify( "战场中不允许与敌人结成队伍！" );
	                                return 1;
                        	}	
                        }
                }
                else if( arrayp(team2) )    // 对方有队伍
                {
//                        if( !who->is_leader() )
//                        {
//                                notify( "%s不是队伍的队长。", who->get_name() );
//                                if( who = find_player( who->get_leader() ) )
//                                        printf( ECHO "该队队长：%s(%d)。", who->get_name(), who->get_number() );
//                                return 1;
//                        }
	                if( !who->is_leader() && !objectp( who = find_player( who->get_leader() ) ) )
                        {
                                notify( "找不到该队伍队长。" );
                                return 1;
                        }
                        if( sizeof(team2) >= MAX_MEMBER )
                        {
                                notify( "该队伍的人数过多。" );
                                return 1;
                        }
                        map1 = get_map_object(get_z(me));
                        map2 = get_map_object(get_z(who));
                        if ( map1->is_changping() || map2->is_changping() )
                        {
                        	if ( map1 != map2 )
                        	{
	                                notify( "战场中玩家不允许与战场外的玩家结成队伍！" );
	                                return 1;
                        	}		
                        	if ( me->can_fight(who) )
                        	{
	                                notify( "战场中不允许与敌人结成队伍！" );
	                                return 1;
                        	}	
                        }
                }

                if( who->get_no_team() )
                {
                        notify( "%s没有打开组队开关。", who->get_name() );
                        return 1;
                }
                if (time()- who->get("pending_time")<60)
                {
//                        notify( "%s忙碌中。", who->get_name() );
//                        return 1;                	
                }

                if( arrayp( team3 = who->get("pending_team") ) && member_array(me, team3) != -1 )    // 回应
                {
			if( me->is_leader() && !who->is_leader() )
			{
				oLeader = me;
				oJoiner = who;
			}
			else
			{
				oLeader = who;
				oJoiner = me;
			}
			map1 = get_map_object(get_z(oLeader));
			map2 = get_map_object(get_z(oJoiner));
                        if ( map1->is_changping() || map2->is_changping() )
                        {
                        	if ( map1 != map2 )
                        	{
	                                notify( "战场中的玩家不允许与战场外的玩家结成队伍！" );
	                                return 1;
                        	}		
                        	if ( oLeader->can_fight(oJoiner) )
                        	{
	                                notify( "战场中不允许与敌人结成队伍！" );
	                                return 1;
                        	}	
                        }			
                        id = sprintf( "%d", oLeader->get_number() );
                        if ( TEAM_D->add_member(id, oJoiner) != 1 )
                        	return 1;
                        oJoiner->set_leader(id);
			oJoiner->set("templeader", 0);
                        z = get_z(oJoiner);
                        team = oLeader->get_team();  size = sizeof(team);
                        if ("/sys/sys/count"->get_new_person())
                        	send_user( team - ({ oJoiner }), "%c%c%d%d%c%s", 0x54, 2, oJoiner->get_number(), oJoiner->get_photo(), oJoiner->get_level(), oJoiner->get_name() );
                        else
                        	send_user( team - ({ oJoiner }), "%c%c%d%d%c%s", 0x54, 2, oJoiner->get_number(), oJoiner->get_armor_code(), oJoiner->get_level(), oJoiner->get_name() );
                        for( i = 0; i < size; i ++ ) if( team[i] )
                        {
                        	if ("/sys/sys/count"->get_new_person())
                                	send_user( oJoiner, "%c%c%d%d%c%s", 0x54, team[i] == oLeader ? 1 : 2, team[i]->get_number(), team[i]->get_photo(), team[i]->get_level(), team[i]->get_name() );
                                else
                                	send_user( oJoiner, "%c%c%d%d%c%s", 0x54, team[i] == oLeader ? 1 : 2, team[i]->get_number(), team[i]->get_armor_code(), team[i]->get_level(), team[i]->get_name() );
                                if( team[i] != oJoiner && get_z( team[i] ) == z )    // 更新队员坐标
                                {
                                        send_user( oJoiner, "%c%c%d%w%w", 0x54, 10, team[i]->get_number(), get_x( team[i] ), get_y( team[i] ) );
					send_user( oJoiner, "%c%c%d%w%w", 0x54, 3, team[i]->get_number(), team[i]->get_hp(), team[i]->get_max_hp() );
					send_user( oJoiner, "%c%c%d%w%w", 0x54, 4, team[i]->get_number(), team[i]->get_mp(), team[i]->get_max_mp() );
					send_user( team[i], "%c%c%d%w%w", 0x54, 3, oJoiner->get_number(), oJoiner->get_hp(), oJoiner->get_max_hp() );
					send_user( team[i], "%c%c%d%w%w", 0x54, 4, oJoiner->get_number(), oJoiner->get_mp(), oJoiner->get_max_mp() );
				}
				else
				{
					send_user( oJoiner, "%c%c%d%w%w", 0x54, 3, team[i]->get_number(), team[i]->get_hp(), team[i]->get_max_hp() );
					send_user( oJoiner, "%c%c%d%w%w", 0x54, 4, team[i]->get_number(), team[i]->get_mp(), team[i]->get_max_mp() );						
				}
				
                        }                                

                        send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "%s(%d)在%s的邀请下加入队伍。",
                                oJoiner->get_name(), oJoiner->get_number(), oLeader->get_name() ) );

                        team -= ({ oJoiner });
                        team = filter_array( team, (: $1 && get_z($1) == $2 :), z );    // 更新队员坐标
                        send_user( team, "%c%c%d%w%w", 0x54, 10, oJoiner->get_number(), get_x(oJoiner), get_y(oJoiner) );
                        oJoiner->add_to_scene( get_z(oJoiner), get_x(oJoiner), get_y(oJoiner), get_d(oJoiner) );    // 重进场景
                        me->to_front_eachother(who);

                        if( arrayp( team3 = who->get("pending_team") ) && sizeof( team3 -= ({ 0 }) ) > 0 )
                                send_user( team3, "%c%d%w%c%c%c", 0x6f, getoid(who), 9001, 1, OVER_BODY, PF_STOP );
                        who->delete( "pending_team" );
                        who->set("pending_time", 0);
                        me->set("pending_time", 0);
			"/quest/help"->send_help_tips(oJoiner, 22);
			"/quest/help"->send_help_tips(oJoiner, 43);
                        return 1;
                }
                else    // 邀请
                {
                        if( arrayp(team) || !arrayp(team2) )
                        {
                                name = me->get_name();
                                name = replace_string(name, "#", "＃");      
                                name2 = who->get_name();                  	
                                name2 = replace_string(name2, "#", "＃");      
                                printf( ECHO "您邀请%s加入队伍。", name2 );
                                write_user( who, ECHO "%s(%d)邀请您加入其队伍。", name, me->get_number() );

                                send_user( who, "%c", 0x54 );
                                who->set("pending_time", time());
                                send_user( who, "%c%c%d%s", 0x4d, 0xff, me->get_number(),
                                        sprintf( "%s(%d)邀请您加入其队伍。", name, me->get_number() ) );
                                send_user( who, "%c%d%w%c%c%c", 0x6f, getoid(me), 9001, 1, OVER_BODY, PF_LOOP );
                                fam = me->get_fam_name();
                                if (fam==""||!fam) fam = "无门派";

                                send_user( who, "%c%c%s", 0x59, 1, sprintf("%d级%s的%s邀请您加入队伍，您是否同意？\n"
                                	ESC "%c\n"ESC"team + %d\n"
                                	ESC "%c\n"ESC"team cancel %d\n",
                                	me->get_level(), fam, name, 1, me->get_number(), 2,me->get_number()) );
                        }
                        else
                        {
                                name = me->get_name();
                                name = replace_string(name, "#", "＃");                              	
                                name2 = who->get_name();                  	
                                name2 = replace_string(name2, "#", "＃");                           	
                                printf( ECHO "您申请加入%s的队伍。",name2 );
                                write_user( who, ECHO "%s(%d)申请加入您的队伍。", name, me->get_number() );

                                send_user( who, "%c", 0x54 );
                                send_user( who, "%c%c%d%s", 0x4d, 0xff, me->get_number(),
                                        sprintf( "%s(%d)申请加入您的队伍。", name, me->get_number() ) );
                                send_user( who, "%c%d%w%c%c%c", 0x6f, getoid(me), 9001, 1, OVER_BODY, PF_LOOP );
                                fam = me->get_fam_name();
                                if (fam==""||!fam) fam = "无门派";
//				send_user(who,"%c%c%w%s",':',3,0,sprintf("%s申请加入你的队伍，你同意吗？\n"ESC"同意\nteam + %d\n"ESC"拒绝\nteam refuse %d\n",me->get_name(),me->get_number(),me->get_number()));
                                name = me->get_name();
                                name = replace_string(name, "#", "＃");
                                send_user( who, "%c%c%s", 0x59, 1, sprintf("%d级%s的%s申请加入您的队伍，您是否同意？\n"
                                	ESC "%c\n"ESC"team + %d\n"
                                	ESC "%c\n"ESC"team cancel %d\n",
                                	me->get_level(), fam, name, 1, me->get_number(), 2,me->get_number()) );

                        }
                        if( arrayp( team3 = me->get("pending_team") ) )
                                me->set( "pending_team", team3 - ({ who, 0 }) + ({ who }) );
                        else    me->set( "pending_team", ({ who }) );

                        return 1;
                }
                return 1;

     case "x" :
                me->set_time( "team", time() );
                if( !arrayp( team = me->get_team() ) )
                {
                        notify( "您现在不在队伍当中。" );
                        return 1;
                }
                if( !me->is_leader() )    // 不是队长，脱离队伍
                {
                        if( me != who )
                        {
                                notify( "您不是本队伍的队长，您只能使自己脱离队伍。" );
                                return 1;
                        }
                        send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "%s(%d)已经离开本队伍了。", me->get_name(), me->get_number() ) );
                        TEAM_D->remove_member( who->get_leader(), who );
                        who->add_to_scene( get_z(who), get_x(who), get_y(who), get_d(who) );    // 重进场景
                        return 1;
                }
                if( sprintf( "%d", me->get_number() ) != who->get_leader() )
                {
                        notify( "%s不在本队伍当中。", who->get_name() );
                        return 1;
                }
                if( me != who )
                        send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "队长%s(%d)将%s(%d)开除出队伍了。",
                                me->get_name(), me->get_number(), who->get_name(), who->get_number() ) );
                else    send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "队长%s(%d)已经离开本队伍了。", me->get_name(), me->get_number() ) );
                TEAM_D->remove_member( who->get_leader(), who );
                who->add_to_scene( get_z(who), get_x(who), get_y(who), get_d(who) );    // 重进场景
                return 1;

     case "-" :
                if( !arrayp( team = me->get_team() ) )
                {
                        notify( "您现在不在队伍当中。" );
                        return 1;
                }
                if( !me->is_leader() )    // 不是队长，脱离队伍
                {
                        if( me != who )
                        {
                                notify( "您不是本队伍的队长，您只能使自己脱离队伍。" );
                                return 1;
                        }
                        send_user( me, "%c%s", ':', "您确定要离开队伍吗？\n"
                                ESC "是的。\nteam x " + sprintf( "%d", me->get_number() ) + "\n"
                                ESC "我再想想……\nCLOSE\n" );
                        return 1;
                }
                if( sprintf( "%d", me->get_number() ) != who->get_leader() )
                {
                        notify( "%s现在不在队伍当中。", who->get_name() );
                        return 1;
                }
                cmd = sprintf( "team x %d\n", who->get_number() );
                if( me != who )
                        send_user( me, "%c%s", ':', "队长您确定要将" + who->get_name() + "开除出去吗？\n"
                                ESC "是的。\n" + cmd +
                                ESC "我再想想……\nCLOSE\n" );
                else    send_user( me, "%c%s", ':', "队长您确定要离开队伍吗？\n"
                                ESC "是的。\n" + cmd +
                                ESC "我再想想……\nCLOSE\n" );
                return 1;

     case "=" :
                if( !arrayp( team = me->get_team() ) )
                {
                        notify( "您现在不在队伍当中。" );
                        return 1;
                }
                if( !me->is_leader() )
                {
                        notify( "您不是本队伍的队长。" );
                        return 1;
                }
                if( me == who )
                {
                        notify( "您已经是本队伍的队长了。" );
                        return 1;
                }
                if( sprintf( "%d", me->get_number() ) != who->get_leader() )
                {
                        notify( "%s现在不在队伍当中。", who->get_name() );
                        return 1;
                }
                send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "队长%s(%d)决定让位给%s(%d)。",
                        me->get_name(), me->get_number(), who->get_name(), who->get_number() ) );
                TEAM_D->change_leader(me, who);

                return 1;
	case "gain" :
		if( !arrayp( team = me->get_team() ) )
                {
                        notify( "您现在不在队伍当中。" );
                        return 1;
                }
                if( !me->is_leader() )
                {
                        notify( "您不是本队伍的队长。" );
                        return 1;
                }
                TEAM_D->change_gain_mode(me,me->get_leader(),id2);
                return 1;                
	case "give" :
		if( !arrayp( team = me->get_team() ) )
                {
                        notify( "您现在不在队伍当中。" );
                        return 1;
                }
                
		TEAM_D->leader_give_item(me,id2);
		return;
	case "bet":
		if( !arrayp( team = me->get_team() ) )
                {
                        notify( "您现在不在队伍当中。" );
                        return 1;
                }
                TEAM_D->add_bet(me,id2);
                return ;
	 case "refuse" :
	 	if( arrayp( team3 = who->get("pending_team") ) )
                                who->set( "pending_team", team3 - ({ me, 0 })  );
		write_user( who, ECHO "%s(%d)拒绝了你的入队申请。", me->get_name(), me->get_number() );
		send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(who), 9001, 1, OVER_BODY, PF_STOP );
		return;
	case "g+":	//组团邀请
		if ( is_god(me) )
			quest_group(me,who);
		break;
	case "g@+":
		if ( !me->is_leader() )
		{
                        notify( "您不是本队伍的队长。" );
                        return 1;
                }
                if ( !stringp(id=who->get_leader()) || !objectp(who=find_char(id)) )
		{
                        notify( "对方不在队伍当中。" );
                        return 1;
                }
		gId1 = me->get_group_id();
		gId2 = who->get_group_id();
		if ( gId1 && gId2 )
		{
                        notify( "双方已经在团队里面了。" );
                        return 1;
                }
		tId1 = me->get_team_id();
		tId2 = who->get_team_id();
		if ( who->get("pending_group") != tId1 )
		{
                        notify( "对方不想你结成团队。" );
                        return 1;
        	}
        	who->delete("pending_group");   
                if ( gId1 && !gId2 )	//接受对方申请
		{
			if ( TEAM_D->get_group_amount(gId1) >= 8 )
	                {
	                 	send_user(me,"%c%s",'!',"当前团队已达到组队上限，不可再加入队伍！");	
	                }
			TEAM_D->add_group_team(gId1,tId2);
                }
                else if ( !gId1 && gId2 )	//加入对方
		{
			if ( TEAM_D->get_group_amount(gId2) >= 8 )
	                {
	                 	send_user(me,"%c%s",'!',"对方团队已达到组队上限，加入失败！");	
	                }
			TEAM_D->add_group_team(gId2,tId1);
                }
                else if ( !gId1 && !gId2 )	//新建团队
		{
			gId2 = TEAM_D->add_group_team(0,tId2);
			TEAM_D->add_group_team(gId2,tId1);
                }
		send_user(me,"%c%s",'!',who->get_name()+"的队伍与你结成团队！");	
		send_user(who,"%c%s",'!',me->get_name()+"的队伍与你结成团队！");	
		break;
	case "gInfo":
		group_info(me);
		break;
	case "gl":
		if ( !me->is_leader() )
		{
                        notify( "您不是本队伍的队长。" );
                        return 1;
                }
                if ( !me->get_group_id() )
		{
                        notify( "您不在团队内。" );
                        return 1;
                }
		TEAM_D->leave_group(me->get_team_id());
		send_user(me,"%c%c",0xA2,8);
		notify( "您脱离了团队。" );
		break;	            
	case "g-":
		if ( !me->is_leader() )
		{
                        notify( "您不是本队伍的队长。" );
                        return 1;
                }
                if ( !(gId1=me->get_group_id()) )
		{
                        notify( "您不在团队内。" );
                        return 1;
                }
                if ( TEAM_D->get_first_group_team(gId1) != me->get_team_id() )
		{
                        notify( "您不是团长。" );
                        return 1;
                }
		TEAM_D->leave_group(who->get_team_id());
		send_user(me,"%c%c",0xA2,8);
		notify( "你把"+who->get_name()+"的队伍请离了团队。" );
		break;	
        }

                
        return 1;
}
//发送团队信息给团队成员
void group_info(object who)
{
	int gId,*nTeam,i,size,m,n,tId;
	object *nObj,player;
	string cName;
	
	gId = who->get_group_id();
	if ( !gId )
		return ;
	nTeam = TEAM_D->get_group_member(gId);
	if ( !nTeam )
		return ;
	for(i=0,size=sizeof(nTeam);i<size;i++)
	{
		tId = nTeam[i];
		nObj = TEAM_D->get_team_by_id(tId);
		nObj -= ({0});
		for(m=0,n=sizeof(nObj);m<n;m++)
			if ( objectp(player=nObj[m]) )
			{
				if ( i==0 && m==0 )
					cName = player->get_name()+"(团长)";
				else
					cName = player->get_name();
				send_user(who,"%c%c%c%d%d%s",
					0xA2,7,i+1,player->get_number(),player->get_level(),cName);
			}
	}
}
//组建邀请
void quest_group(object me,object who)
{
	int tId1,tId2,gId1,gId2;
	
	if ( !me->is_leader() )
	{
                notify( "您不是本队伍的队长。" );
                return ;
        }
	gId1 = me->get_group_id();
	if ( TEAM_D->get_group_amount(gId1) >= 8 )
        {
         	send_user(me,"%c%s",'!',"当前团队已达到组队上限，不可再加入队伍！");	
        }
        if( !who->is_leader() && !objectp( who = find_player( who->get_leader() ) ) )
        {
                notify( "找不到该队伍队长。" );
                return ;
        }
	tId1 = me->get_team_id();
	tId2 = who->get_team_id();
	gId2 = who->get_group_id();
	if ( gId1 && gId2 )
	{
                notify( "对方的队伍已经加入团队，不能邀请加入。" );
                return ;
        }
        printf( ECHO "您邀请%s的队伍结成团队。", who->get_name() );
	me->set("pending_group",tId2);
        send_user( who, "%c%c%s", 0x59, 1, sprintf("%s的队伍想与你结成团队，你是否同意？\n"
        	ESC "%c\n"ESC"team g@+ %d\n"
        	ESC "%c\n"ESC"team g@cancel %d\n",
        	me->get_name(),1,me->get_number(),2,who->get_number() ) );	
	
	
}