
#include <ansi.h>
#include <task.h>
#include <skill.h>

#define MAX_MEMBER      5              // ��Ա��������
void group_info(object who);
void quest_group(object me,object who);

// �����������
int main( object me, string arg )
{
        object *team, *team2, *team3, who,oLeader,oJoiner,map,map1,map2;
        string id, id2, cmd, fam, name, name2;
        int level, z, i, size,tId1,tId2,gId1,gId2;

        if( gone_time( me->get_time("team") ) < 1 )    // ʱ������
                return 1;

        if( !arg ) return 1;

        if( !arg || sscanf( arg, "%s %s",arg, id2 ) != 2  ) return 1;
        if( arg != "follow" && arg != "bet" && arg != "gain" && arg != "give" && !objectp( who = find_player(id2) ) ) return 1;

        switch( arg )
        {
     case "follow":	//�������
     		if ( me->is_leader() )		//��Ա����ӳ�
     			return ;
     		if ( me->get("team_follow") )	//ȡ������
     		{
     			send_user( me, "%c%w%w%c", 0x81, 0011, 0, EFFECT_GOOD );
     			send_user( me, "%c%c%c", 0xA5, 3, 0 );
     			me->delete("team_follow");
     		}
     		else				//�������
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
        	send_user( who,"%c%s",'!',sprintf("%s�ܾ�������������",me->get_name()));
        	return 1;
     case "g@cancel" :
     		me->set("pending_time", 0);
        	send_user( me, "%c%c%c", 0x59, 1, 0);
        	send_user( who,"%c%s",'!',sprintf("%s�ܾ��������������",me->get_name()));
        	return 1;
     case "+" :
     case "++" :
        	me->set_time( "team", time() );
                if( me->get_no_team() )
                {
                        notify( "�����ȴ���ӿ��ء�" );
                        return 1;
                }
                if( !arrayp( team = me->get_team() ) && me == who )    // �Լ����
                {
                        id = sprintf( "%d", me->get_number() );
                        if ( TEAM_D->new_team(me) != 1 )
                        {
                        	notify( "���ʧ��" );
                        	return 1;
                        }
                        me->set_leader(id);
                        if ("/sys/sys/count"->get_new_person())
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_photo(), me->get_level(), me->get_name() );
                        else
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_armor_code(), me->get_level(), me->get_name() );
//			send_user( me, "%c%c%d%s", 0x54, 1, me->get_number(), me->get_name() );
                        send_user( me, "%c%c%d%s", 0x43, 7, 0, WHT "���Լ����һ֧���顣" );
			send_user( me, "%c%c%d%w%w", 0x54, 3, me->get_number(), me->get_hp(), me->get_max_hp() );
			send_user( me, "%c%c%d%w%w", 0x54, 4, me->get_number(), me->get_mp(), me->get_max_mp() );
			"/quest/help"->send_help_tips(me, 22);
			"/quest/help"->send_help_tips(me, 43);
			CHAR_CHAR_D->init_loop_perform(me);
                        return 1;
                }

                if( who->get_no_team() )
                {
                        notify( "%sû�д���ӿ��ء�", who->get_name() );
                        return 1;
                }

                if( !arrayp( team2 = who->get_team() ) && !arrayp(team) )
                {
                        id = sprintf( "%d", me->get_number() );
                        if ( TEAM_D->new_team(me) != 1 )
                        {
                        	notify( "���ʧ��" );
                        	return 1;
                        }
                        me->set_leader(id);
                        if ("/sys/sys/count"->get_new_person())
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_photo(), me->get_level(), me->get_name() );
                        else
                        	send_user( me, "%c%c%d%d%c%s", 0x54, 1, me->get_number(), me->get_armor_code(), me->get_level(), me->get_name() );
//			send_user( me, "%c%c%d%s", 0x54, 1, me->get_number(), me->get_name() );
                        send_user( me, "%c%c%d%s", 0x43, 7, 0, WHT "���Լ����һ֧���顣" );
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
                if( arrayp(team) )    // �����ж���
                {
                        if( !me->is_leader() )
                        {
                                notify( "�ӳ����������Ա��" );
                                return 1;
                        }
                        if( member_array(who, team) != -1 )
                        {
                                notify( "%s�Ѿ��ڶ������ˡ�", who->get_name() );
                                return 1;
                        }
                        if( arrayp(team2) )
                        {
                        	if( sizeof(team) >= 2 )
                        	{
//	                                notify( "%s����һ֧�����С�", who->get_name() );
					quest_group(me,who);
	                                return 1;                        		
                        	}
                        	if (arg=="+")
	                        {
	                                send_user( me, "%c%c%s", 0x59, 1, sprintf("�����µĶ���ǰ������Ƚ���Լ�����ӣ���ȷ��Ҫ����Լ��Ķ�����\n"
	                                	ESC "%c\n"ESC"team ++ %d\n", 
	                                	1, who->get_number(), 2) );
	                                return 1;
	                        }                        	

                        }
                        if( sizeof(team) >= MAX_MEMBER )
                        {
                                notify( "��������������ࡣ" );
                                return 1;
                        }
                        map1 = get_map_object(get_z(me));
                        map2 = get_map_object(get_z(who));
                        if ( map1->is_changping() || map2->is_changping() )
                        {
                        	if ( map1 != map2 )
                        	{
	                                notify( "ս������Ҳ�������ս�������ҽ�ɶ��飡" );
	                                return 1;
                        	}		
                        	if ( me->can_fight(who) )
                        	{
	                                notify( "ս���в���������˽�ɶ��飡" );
	                                return 1;
                        	}	
                        }
                }
                else if( arrayp(team2) )    // �Է��ж���
                {
//                        if( !who->is_leader() )
//                        {
//                                notify( "%s���Ƕ���Ķӳ���", who->get_name() );
//                                if( who = find_player( who->get_leader() ) )
//                                        printf( ECHO "�öӶӳ���%s(%d)��", who->get_name(), who->get_number() );
//                                return 1;
//                        }
	                if( !who->is_leader() && !objectp( who = find_player( who->get_leader() ) ) )
                        {
                                notify( "�Ҳ����ö���ӳ���" );
                                return 1;
                        }
                        if( sizeof(team2) >= MAX_MEMBER )
                        {
                                notify( "�ö�����������ࡣ" );
                                return 1;
                        }
                        map1 = get_map_object(get_z(me));
                        map2 = get_map_object(get_z(who));
                        if ( map1->is_changping() || map2->is_changping() )
                        {
                        	if ( map1 != map2 )
                        	{
	                                notify( "ս������Ҳ�������ս�������ҽ�ɶ��飡" );
	                                return 1;
                        	}		
                        	if ( me->can_fight(who) )
                        	{
	                                notify( "ս���в���������˽�ɶ��飡" );
	                                return 1;
                        	}	
                        }
                }

                if( who->get_no_team() )
                {
                        notify( "%sû�д���ӿ��ء�", who->get_name() );
                        return 1;
                }
                if (time()- who->get("pending_time")<60)
                {
//                        notify( "%sæµ�С�", who->get_name() );
//                        return 1;                	
                }

                if( arrayp( team3 = who->get("pending_team") ) && member_array(me, team3) != -1 )    // ��Ӧ
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
	                                notify( "ս���е���Ҳ�������ս�������ҽ�ɶ��飡" );
	                                return 1;
                        	}		
                        	if ( oLeader->can_fight(oJoiner) )
                        	{
	                                notify( "ս���в���������˽�ɶ��飡" );
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
                                if( team[i] != oJoiner && get_z( team[i] ) == z )    // ���¶�Ա����
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

                        send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "%s(%d)��%s�������¼�����顣",
                                oJoiner->get_name(), oJoiner->get_number(), oLeader->get_name() ) );

                        team -= ({ oJoiner });
                        team = filter_array( team, (: $1 && get_z($1) == $2 :), z );    // ���¶�Ա����
                        send_user( team, "%c%c%d%w%w", 0x54, 10, oJoiner->get_number(), get_x(oJoiner), get_y(oJoiner) );
                        oJoiner->add_to_scene( get_z(oJoiner), get_x(oJoiner), get_y(oJoiner), get_d(oJoiner) );    // �ؽ�����
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
                else    // ����
                {
                        if( arrayp(team) || !arrayp(team2) )
                        {
                                name = me->get_name();
                                name = replace_string(name, "#", "��");      
                                name2 = who->get_name();                  	
                                name2 = replace_string(name2, "#", "��");      
                                printf( ECHO "������%s������顣", name2 );
                                write_user( who, ECHO "%s(%d)��������������顣", name, me->get_number() );

                                send_user( who, "%c", 0x54 );
                                who->set("pending_time", time());
                                send_user( who, "%c%c%d%s", 0x4d, 0xff, me->get_number(),
                                        sprintf( "%s(%d)��������������顣", name, me->get_number() ) );
                                send_user( who, "%c%d%w%c%c%c", 0x6f, getoid(me), 9001, 1, OVER_BODY, PF_LOOP );
                                fam = me->get_fam_name();
                                if (fam==""||!fam) fam = "������";

                                send_user( who, "%c%c%s", 0x59, 1, sprintf("%d��%s��%s������������飬���Ƿ�ͬ�⣿\n"
                                	ESC "%c\n"ESC"team + %d\n"
                                	ESC "%c\n"ESC"team cancel %d\n",
                                	me->get_level(), fam, name, 1, me->get_number(), 2,me->get_number()) );
                        }
                        else
                        {
                                name = me->get_name();
                                name = replace_string(name, "#", "��");                              	
                                name2 = who->get_name();                  	
                                name2 = replace_string(name2, "#", "��");                           	
                                printf( ECHO "���������%s�Ķ��顣",name2 );
                                write_user( who, ECHO "%s(%d)����������Ķ��顣", name, me->get_number() );

                                send_user( who, "%c", 0x54 );
                                send_user( who, "%c%c%d%s", 0x4d, 0xff, me->get_number(),
                                        sprintf( "%s(%d)����������Ķ��顣", name, me->get_number() ) );
                                send_user( who, "%c%d%w%c%c%c", 0x6f, getoid(me), 9001, 1, OVER_BODY, PF_LOOP );
                                fam = me->get_fam_name();
                                if (fam==""||!fam) fam = "������";
//				send_user(who,"%c%c%w%s",':',3,0,sprintf("%s���������Ķ��飬��ͬ����\n"ESC"ͬ��\nteam + %d\n"ESC"�ܾ�\nteam refuse %d\n",me->get_name(),me->get_number(),me->get_number()));
                                name = me->get_name();
                                name = replace_string(name, "#", "��");
                                send_user( who, "%c%c%s", 0x59, 1, sprintf("%d��%s��%s����������Ķ��飬���Ƿ�ͬ�⣿\n"
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
                        notify( "�����ڲ��ڶ��鵱�С�" );
                        return 1;
                }
                if( !me->is_leader() )    // ���Ƕӳ����������
                {
                        if( me != who )
                        {
                                notify( "�����Ǳ�����Ķӳ�����ֻ��ʹ�Լ�������顣" );
                                return 1;
                        }
                        send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "%s(%d)�Ѿ��뿪�������ˡ�", me->get_name(), me->get_number() ) );
                        TEAM_D->remove_member( who->get_leader(), who );
                        who->add_to_scene( get_z(who), get_x(who), get_y(who), get_d(who) );    // �ؽ�����
                        return 1;
                }
                if( sprintf( "%d", me->get_number() ) != who->get_leader() )
                {
                        notify( "%s���ڱ����鵱�С�", who->get_name() );
                        return 1;
                }
                if( me != who )
                        send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "�ӳ�%s(%d)��%s(%d)�����������ˡ�",
                                me->get_name(), me->get_number(), who->get_name(), who->get_number() ) );
                else    send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "�ӳ�%s(%d)�Ѿ��뿪�������ˡ�", me->get_name(), me->get_number() ) );
                TEAM_D->remove_member( who->get_leader(), who );
                who->add_to_scene( get_z(who), get_x(who), get_y(who), get_d(who) );    // �ؽ�����
                return 1;

     case "-" :
                if( !arrayp( team = me->get_team() ) )
                {
                        notify( "�����ڲ��ڶ��鵱�С�" );
                        return 1;
                }
                if( !me->is_leader() )    // ���Ƕӳ����������
                {
                        if( me != who )
                        {
                                notify( "�����Ǳ�����Ķӳ�����ֻ��ʹ�Լ�������顣" );
                                return 1;
                        }
                        send_user( me, "%c%s", ':', "��ȷ��Ҫ�뿪������\n"
                                ESC "�ǵġ�\nteam x " + sprintf( "%d", me->get_number() ) + "\n"
                                ESC "�������롭��\nCLOSE\n" );
                        return 1;
                }
                if( sprintf( "%d", me->get_number() ) != who->get_leader() )
                {
                        notify( "%s���ڲ��ڶ��鵱�С�", who->get_name() );
                        return 1;
                }
                cmd = sprintf( "team x %d\n", who->get_number() );
                if( me != who )
                        send_user( me, "%c%s", ':', "�ӳ���ȷ��Ҫ��" + who->get_name() + "������ȥ��\n"
                                ESC "�ǵġ�\n" + cmd +
                                ESC "�������롭��\nCLOSE\n" );
                else    send_user( me, "%c%s", ':', "�ӳ���ȷ��Ҫ�뿪������\n"
                                ESC "�ǵġ�\n" + cmd +
                                ESC "�������롭��\nCLOSE\n" );
                return 1;

     case "=" :
                if( !arrayp( team = me->get_team() ) )
                {
                        notify( "�����ڲ��ڶ��鵱�С�" );
                        return 1;
                }
                if( !me->is_leader() )
                {
                        notify( "�����Ǳ�����Ķӳ���" );
                        return 1;
                }
                if( me == who )
                {
                        notify( "���Ѿ��Ǳ�����Ķӳ��ˡ�" );
                        return 1;
                }
                if( sprintf( "%d", me->get_number() ) != who->get_leader() )
                {
                        notify( "%s���ڲ��ڶ��鵱�С�", who->get_name() );
                        return 1;
                }
                send_user( team, "%c%c%d%s", 0x43, 7, 0, sprintf( WHT "�ӳ�%s(%d)������λ��%s(%d)��",
                        me->get_name(), me->get_number(), who->get_name(), who->get_number() ) );
                TEAM_D->change_leader(me, who);

                return 1;
	case "gain" :
		if( !arrayp( team = me->get_team() ) )
                {
                        notify( "�����ڲ��ڶ��鵱�С�" );
                        return 1;
                }
                if( !me->is_leader() )
                {
                        notify( "�����Ǳ�����Ķӳ���" );
                        return 1;
                }
                TEAM_D->change_gain_mode(me,me->get_leader(),id2);
                return 1;                
	case "give" :
		if( !arrayp( team = me->get_team() ) )
                {
                        notify( "�����ڲ��ڶ��鵱�С�" );
                        return 1;
                }
                
		TEAM_D->leader_give_item(me,id2);
		return;
	case "bet":
		if( !arrayp( team = me->get_team() ) )
                {
                        notify( "�����ڲ��ڶ��鵱�С�" );
                        return 1;
                }
                TEAM_D->add_bet(me,id2);
                return ;
	 case "refuse" :
	 	if( arrayp( team3 = who->get("pending_team") ) )
                                who->set( "pending_team", team3 - ({ me, 0 })  );
		write_user( who, ECHO "%s(%d)�ܾ������������롣", me->get_name(), me->get_number() );
		send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(who), 9001, 1, OVER_BODY, PF_STOP );
		return;
	case "g+":	//��������
		if ( is_god(me) )
			quest_group(me,who);
		break;
	case "g@+":
		if ( !me->is_leader() )
		{
                        notify( "�����Ǳ�����Ķӳ���" );
                        return 1;
                }
                if ( !stringp(id=who->get_leader()) || !objectp(who=find_char(id)) )
		{
                        notify( "�Է����ڶ��鵱�С�" );
                        return 1;
                }
		gId1 = me->get_group_id();
		gId2 = who->get_group_id();
		if ( gId1 && gId2 )
		{
                        notify( "˫���Ѿ����Ŷ������ˡ�" );
                        return 1;
                }
		tId1 = me->get_team_id();
		tId2 = who->get_team_id();
		if ( who->get("pending_group") != tId1 )
		{
                        notify( "�Է����������Ŷӡ�" );
                        return 1;
        	}
        	who->delete("pending_group");   
                if ( gId1 && !gId2 )	//���ܶԷ�����
		{
			if ( TEAM_D->get_group_amount(gId1) >= 8 )
	                {
	                 	send_user(me,"%c%s",'!',"��ǰ�Ŷ��Ѵﵽ������ޣ������ټ�����飡");	
	                }
			TEAM_D->add_group_team(gId1,tId2);
                }
                else if ( !gId1 && gId2 )	//����Է�
		{
			if ( TEAM_D->get_group_amount(gId2) >= 8 )
	                {
	                 	send_user(me,"%c%s",'!',"�Է��Ŷ��Ѵﵽ������ޣ�����ʧ�ܣ�");	
	                }
			TEAM_D->add_group_team(gId2,tId1);
                }
                else if ( !gId1 && !gId2 )	//�½��Ŷ�
		{
			gId2 = TEAM_D->add_group_team(0,tId2);
			TEAM_D->add_group_team(gId2,tId1);
                }
		send_user(me,"%c%s",'!',who->get_name()+"�Ķ����������Ŷӣ�");	
		send_user(who,"%c%s",'!',me->get_name()+"�Ķ����������Ŷӣ�");	
		break;
	case "gInfo":
		group_info(me);
		break;
	case "gl":
		if ( !me->is_leader() )
		{
                        notify( "�����Ǳ�����Ķӳ���" );
                        return 1;
                }
                if ( !me->get_group_id() )
		{
                        notify( "�������Ŷ��ڡ�" );
                        return 1;
                }
		TEAM_D->leave_group(me->get_team_id());
		send_user(me,"%c%c",0xA2,8);
		notify( "���������Ŷӡ�" );
		break;	            
	case "g-":
		if ( !me->is_leader() )
		{
                        notify( "�����Ǳ�����Ķӳ���" );
                        return 1;
                }
                if ( !(gId1=me->get_group_id()) )
		{
                        notify( "�������Ŷ��ڡ�" );
                        return 1;
                }
                if ( TEAM_D->get_first_group_team(gId1) != me->get_team_id() )
		{
                        notify( "�������ų���" );
                        return 1;
                }
		TEAM_D->leave_group(who->get_team_id());
		send_user(me,"%c%c",0xA2,8);
		notify( "���"+who->get_name()+"�Ķ����������Ŷӡ�" );
		break;	
        }

                
        return 1;
}
//�����Ŷ���Ϣ���Ŷӳ�Ա
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
					cName = player->get_name()+"(�ų�)";
				else
					cName = player->get_name();
				send_user(who,"%c%c%c%d%d%s",
					0xA2,7,i+1,player->get_number(),player->get_level(),cName);
			}
	}
}
//�齨����
void quest_group(object me,object who)
{
	int tId1,tId2,gId1,gId2;
	
	if ( !me->is_leader() )
	{
                notify( "�����Ǳ�����Ķӳ���" );
                return ;
        }
	gId1 = me->get_group_id();
	if ( TEAM_D->get_group_amount(gId1) >= 8 )
        {
         	send_user(me,"%c%s",'!',"��ǰ�Ŷ��Ѵﵽ������ޣ������ټ�����飡");	
        }
        if( !who->is_leader() && !objectp( who = find_player( who->get_leader() ) ) )
        {
                notify( "�Ҳ����ö���ӳ���" );
                return ;
        }
	tId1 = me->get_team_id();
	tId2 = who->get_team_id();
	gId2 = who->get_group_id();
	if ( gId1 && gId2 )
	{
                notify( "�Է��Ķ����Ѿ������Ŷӣ�����������롣" );
                return ;
        }
        printf( ECHO "������%s�Ķ������Ŷӡ�", who->get_name() );
	me->set("pending_group",tId2);
        send_user( who, "%c%c%s", 0x59, 1, sprintf("%s�Ķ������������Ŷӣ����Ƿ�ͬ�⣿\n"
        	ESC "%c\n"ESC"team g@+ %d\n"
        	ESC "%c\n"ESC"team g@cancel %d\n",
        	me->get_name(),1,me->get_number(),2,who->get_number() ) );	
	
	
}