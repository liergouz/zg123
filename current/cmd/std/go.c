
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// �����������
varargs int main( object me, string arg, int server )    // server �Ƿ�ϵͳ����·������ EFFECT_CHAR_DREAM
{
        object map, *user, *user2, *npc, *item, who;
        string chan,id;
        int z0, x0, y0, z1, x1, y1, z, x, y, dx, dy, d, walk, time2;
        int busy, p, i, size;
        int current_count, heart, count;
	int jump;
	
        if( !arg || arg == "" ) return 1;

        if( sscanf(arg, ">%d", d) )    // ת��ָ��(����æ��)
        {
                switch( d )
                {
               case 1 : me->to_front(1);  break;
              default : me->to_front(2);  break;
               case 3 : me->to_front(3);  break;
               case 4 : me->to_front(4);  break;
               case 5 : me->to_front(5);  break;
               case 6 : me->to_front(6);  break;
               case 7 : me->to_front(7);  break;
               case 8 : me->to_front(8);  break;
                }
                return 1;
        }
        // �޸ĳ������˫��ʱ��
/*        
        if ( gone_time( me->get_login_time())+ me->get_game_time()+2*3600<me->get_double_time())
        {
        	me->set_double_time(gone_time( me->get_login_time())+ me->get_game_time()+2*3600);
        }
*/        
        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( me->is_store_open() )
        {
//              notify( "���ڰ�̯���������ܡ�" );
                send_user(me, "%c%w%w", 0x07, x0, y0);    // ��������
                return 1;
        }
        if( busy = get_effect(me, EFFECT_CHAR_BUSY) )
        {
                notify( "������æ %d ���ӡ�", busy );
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 1);    // ��������
                return 1;
        }
        if(     get_effect(me, EFFECT_CHAR_FAINT)
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_CHAR_NO_MOVE)
        ||      get_effect(me, EFFECT_CHAR_FREEZE)
        ||      get_effect(me, EFFECT_CHAR_SHUT) )
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 2);    // ��������
                return 1;
        }
        if( ( get_effect(me, EFFECT_CHAR_DREAM_1) || get_effect(me, EFFECT_CHAR_DREAM) ) && !server )    // ����(�����·)ʧ��
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 3);    // ��������
                return 1;
        }
//if (me->get_2("gocount.count2")>0) tell_user(me, ECHO "time %d count %d avg %d��", get_heart_timer(me)-me->get_2("gocount.time2"), me->get_2("gocount.count2"), (get_heart_timer(me)-me->get_2("gocount.time2"))*10/me->get_2("gocount.count2") );        
//if (me->get_2("gocount.count2")>0) tell_user(me, "time=%d count=%d avg=%d", time()-me->get_2("gocount.time2"), me->get_2("gocount.count2"), (time()-me->get_2("gocount.time2"))*100/me->get_2("gocount.count2") );
	// �ж��Ƿ���·����
	if (me->get_2("gocount.time2") && me->get_2("gocount.count2")>30)
	{
		if ((time()-me->get_2("gocount.time2"))*100/me->get_2("gocount.count2")<20)		
		{
	                send_user(me, "%c%w%w%c", 0x07, x0, y0, 4);    // ��������
//tell_user(me, ECHO "!!!! time %d count %d avg %d��", get_heart_timer(me)-me->get_2("gocount.time2"), me->get_2("gocount.count2"), (get_heart_timer(me)-me->get_2("gocount.time2"))*10/me->get_2("gocount.count2") );	                
	                return 1;			
		}
	}

	if (me->get_2("gocount.count2")>10)
	{
		if ((time()-me->get_2("gocount.time2"))*100/me->get_2("gocount.count2")>=40)
		{
			me->set_2("gocount.time2", 0);
			me->set_2("gocount.count2", 0);
		}
	}	
        CHAR_CHAR_D->stop_loop_perform_go(me);    // �ж���·��Ӱ���Ч��
        // �ж��ж�Ч���Ƿ�Ӱ����λ��
        if (get_z(me)!=z0||get_x(me)!=x0||get_y(me)!=y0) return 1;

        if( get_heart_state(me) == FIGHT_STAT )    // ��·ȡ��ս��
        {
                me->set_perform_file(0);    // ������⼼
                set_heart_state(me, WALK_STAT);
                set_heart_count_2(me, 0);
/*
		me->set_force_command("go "+arg);
		return 1;
*/		
        }
        else if( get_heart_state(me) == MAGIC_STAT )    // ��·ȡ������
        {
                me->set_cast_file(0);    // ��������ؼ�
                me->set_cast_arg("");

                user = get_scene_object_2(me, USER_TYPE);
                send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );    // ����ʩ������
                send_user( user, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                        41100, 1, UNDER_FOOT, 42100, 1, UNDER_FOOT, PF_STOP );    // ��������Ч��  get_cast_seal()

                set_heart_state(me, WALK_STAT);
                set_heart_count_2(me, 0);
        }        
        if( get_heart_state(me) == WALK_STAT )
        {
	        heart = get_heart_timer(me);    // ��ȡ����ʱ��(��)
	        count = get_heart_count_2(me);    // ��ȡ�������
	        count = set_heart_count_2( me, count - abs( heart - get_heart_timer_2(me) ) );    // ��������֮��
	        set_heart_timer_2(me, heart);
	}
        
        current_count = get_heart_count_2(me);
//        if (current_count<0) current_count = 0;
//        if (current_count>5) current_count = 5;
	current_count = 0;
//tell_user(me, ECHO "get_heart_count_2 %d��heat_beat %d(%d)", get_heart_count_2(me), get_heart_timer(me), get_heart_timer_2(me) );                
//        if( get_heart_count_2(me) > 20 )    // ս��֮�С���·֮��(�ݴ�0.2)
	if (0)
        {
                send_user(me, "%c%w%w", 0x07, x0, y0);    // ��������
//                tell_user(me, ECHO "������·�ݴ�����");
                return 1;
        }
        if( sscanf( arg, "%d,%d %s %d", x, y, arg, time2 ) != 4 )
        {
	        if( sscanf( arg, "%d,%d %s", x, y, arg ) != 3 )
	        {
	                send_user(me, "%c%w%w%c", 0x07, x0, y0, 5);    // ��������
	                return 1;
	        }
	}
	if (time2>time()+4)	   
        {
                send_user(me, "%c%w%w%c%w", 0x07, x0, y0, 6, time2 -time() );    // ��������
                return 1;
        }	
        if (me->get("gotime")==time2)
        {
        	count = me->add("gocount", 1);
        	if (count>2 && MAIN_D->get_host_type()<1000)
        	{
	                send_user(me, "%c%w%w%c%w", 0x07, x0, y0, 14, count );    // ��������
	                return 1;        		
        	}
        }
        else
        {
        	me->set("gocount", 1);
        	me->set("gotime", time2);
        }
	if (time2<time()-10)	   
        {
                send_user(me, "%c%w%w%c%w", 0x07, x0, y0, 6, time2 -time() );    // ��������
                return 1;
        }            
        if( x0 != x || y0 != y )
        {
//write_user(me, ECHO "��ʼ����(%d,%d)��һ�¡�", x0, y0 );
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 7);    // ��������
                return 1;
        }
        if( !arg || arg == "" ) 
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 8);    // ��������
                return 1;
        }

        if(  get_effect(me, EFFECT_CHAR_SLOW) || ( get_effect(me, EFFECT_CHAR_LAZY) || (get_effect(me, EFFECT_CHAR_INVISIBLE) && ! get_effect(me, EFFECT_03643) && !me->get_save("no_visible") ) )
        &&      sizeof(arg) > 1 ) arg = arg[0..0];    // �����ƶ�����

        else    if( sizeof(arg) > 3 ) arg = arg[0..3];

        if( !( p = from_here(z0, x0, y0, arg, IS_MAP_BLOCK) ) )    // �ܷ�ͨ����
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 9);    // ��������
                return 1;
        }
        x = p / 10000;
        y = ( p % 10000 ) / 10;
        d = p % 10;

        if( x0 == x && y0 == y )    // û���ƶ�
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 10);    // ��������
                return 1;
        }
        if( !inside_map(z0, x, y) )    // �������
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 11);    // ��������
                return 1;
        }
        if(     get_effect(me, EFFECT_CHAR_CHAN)    // ���˲�ס(ճ��)
        &&      stringp( chan = me->get_save("pf.chan") )
        &&      sscanf(chan, "%d:(%d,%d)", z1, x1, y1) == 3
        &&    ( abs(x1 - x) > 2 || abs(y1 - y) > 2 ) )
        {
                send_user(me, "%c%w%w%c", 0x07, x0, y0, 12);    // ��������
                return 1;
        }
        if(     objectp( who = me->get_quest("escort.robber#") )    // Ѱ��������
        &&      who->is_escort_robber()
        &&     !inside_screen( x, y, get_x(who), get_y(who) ) )    // �ƶ�������  // !inside_screen_2(me, who)
        {
        	if (get_z(me)!=get_z(who))	// �����ͼ����
        	{
        		who->destruct_npc_callout(who, me);
        	}
        	else
        	{
	                notify(who->get_name()+"���֣������ж��ܵ�Ӱ�졣");
        	        send_user(me, "%c%w%w%c", 0x07, x0, y0, 13);    // ��������
                	return 1;
                }
        }
        if (me->get_attack_move() && me->get_enemy()) 
        {
        	printf(ECHO "����ֹ�ˡ��Զ��������" );
        	me->set_enemy(0);		// ȡ���Զ�����Ŀ��
        }

        if( me->get_char_action() != DEFAULT_ACT ) me->set_char_action(DEFAULT_ACT);    // �ָ�վ��״̬(��ֹС����)

        dx = abs(x0 - x);  dy = abs(y0 - y);
        walk = ( dx > dy ) ? dx : dy;
        
	// �ж��Ƿ���·����      
	me->add_2("gocount.count2", walk);

	if (me->get_2("gocount.time2")==0 )
	{
		me->set_2("gocount.time2",time()) ;
		me->set_2("gocount.count2", 0);
	}   
        set_heart_state(me, WALK_STAT);
        //set_heart_count_2( me, range_value( current_count + (4 * walk+1)/2, -10, MAX_NUMBER ) );    // walk * 10 / 4
        if( me->get_attack_move()==0 && objectp( who = me->get_enemy() ) )
        {
        	if( distance_between(me, who)==1)
        		set_heart_count_2( me, range_value( current_count + 2 * walk, -10, MAX_NUMBER ) );
        }
        else
        	set_heart_count_2( me, range_value( current_count + 4 * walk, -10, MAX_NUMBER ) );        
//tell_user(me, ECHO "get_heart_count_2 %d��heat_beat %d", get_heart_count_2(me), get_heart_timer(me) );                        

        dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
        dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

        if( dx == 0 && dy == 0 )    // ������������
        {
                remove_block(z0, x0, y0, CHAR_BLOCK);
                set_x(me, x);  set_y(me, y);  set_d(me, d);
                set_block(z0, x, y, CHAR_BLOCK);

                user = get_scene_object(z0, x, y, USER_TYPE);
                if( sizeof(arg) == 1 )
                        send_user( user, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg );
                else
                	send_user( user, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg );
			
                me->set_no_fight( MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0 );    // ��ȫ���ж�
        }
        else    // ��Խ��������
        {
                if( dx < 0 )
                {
                        if( dy < 0 ) { dx = 0x12e;  dy = 0x1d2; }
                        else if( dy > 0 ) { dx = 0x1e8;  dy = 0x5e; }
                        else { dx = 0x128;  dy = 0x52; }
                }
                else if( dx > 0 )
                {
                        if( dy < 0 ) { dx = 0x5e;  dy = 0x1e8; }
                        else if( dy > 0 ) { dx = 0x1d2;  dy = 0x12e; }
                        else { dx = 0x52;  dy = 0x128; }
                }
                else
                {
                        if( dy < 0 ) { dx = 0xe;  dy = 0x1c0; }
                        else { dx = 0x1c0;  dy = 0xe; }
                }

                remove_block(z0, x0, y0, CHAR_BLOCK);    // ɾ���赲

                user = get_scene_object(z0, x0, y0, USER_TYPE, dx);    // ɾ������
                npc = get_scene_object(z0, x0, y0, CHAR_TYPE, dx);
                item = get_scene_object(z0, x0, y0, ITEM_TYPE, dx);
                user->remove_to_user(me);
                npc->remove_to_user(me);
                item->remove_to_user(me);

                item = get_scene_object(z0, x0, y0, SEAL_TYPE, dx);
                item->remove_to_user_2(me);

                set_x(me, x);  set_y(me, y);  set_d(me, d);    // �������꣬�����赲
                set_block(z0, x, y, CHAR_BLOCK);
                move_object(me, z0, x, y, USER_TYPE);    // �ƶ����

                user2 = get_scene_object(z0, x, y, USER_TYPE, dy);    // ��������
                npc = get_scene_object(z0, x, y, CHAR_TYPE, dy);
                item = get_scene_object(z0, x, y, ITEM_TYPE, dy);
                user2->show_to_user(me);
                npc->show_to_user(me);
                item->show_to_user(me);

                item = get_scene_object(z0, x, y, SEAL_TYPE, dy);
                item->show_to_user_2(me);

                me->show_to_scene(user2, x0, y0, d, 0);
                user2 = get_scene_object_2(me, USER_TYPE) + user;
                if( sizeof(arg) == 1 )
                        send_user( user2, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg );
                else 
                	send_user( user2, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg );

                send_user( user, "%c%d", 0x78, getoid(me) );

                if( MAP_D->is_inside_safe_zone(z0, x, y) )    // ��ȫ���ж�
                {
                        me->set_no_fight(1);
                }
                else
                {
                        me->set_no_fight(0);

                        npc = get_range_object_2(me, 6, CHAR_TYPE);
                        if( sizeof(npc) ) npc->init_heart_beat_idle();
                }
        }
 
        if(  ( p = get_jumpout(z0, x, y) )  && MAP_D->can_jump(me,z0,z=p / 1000000)  // ��ת��һ����
        &&   ( !objectp( who = me->get_quest("escort.robber#") ) || !who->is_escort_robber() ) )    // Ѱ��������
        {
                x = ( p % 1000000 ) / 1000;  y = p % 1000;    // get_jumpout �ں� z

                if(   ( who = me->get_quest("escort.npc") )    // ��������
                &&      who->get_owner() == me
                &&      inside_screen_2(me, who) )
                        who->add_to_scene(z, x, y, d);
                if(   ( who = me->get_2("orgtask2.npc") )    // ��������
                &&      who->get_owner() == me
                &&      inside_screen_2(me, who) )
                        who->add_to_scene(z, x, y, d);

                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                {
                        x = p / 1000;  y = p % 1000;

                        me->set_login_flag(2);    // ��ת����
                        set_invisible(me, 1);
                        set_effect(me, EFFECT_USER_LOGIN, 4);

                        me->add_to_scene(z, x, y, d);
			jump = z0*1000000 + x0*1000 + y0;
//                      if( z != z0 ) if( map = get_map_object(z) ) notify( map->get_name() );    // ��ʾ��ͼ��
                }
        }
        else if( MAP_D->is_inside_battle(z0) )    // ս��
        {
                if( objectp( map = get_map_object(z0) ) )    // ��ȡս������
                {
                        who = me->get_manager();
                        d = getoid(me);

                        if( map->get_manager() == who )    // ������
                        {
                                user = map->get_user_dbase();
                                send_user( user, "%c%c%d%w%w", 0x54, 10, d, x, y );
//                              for( i = 0, size = sizeof(user); i < size; i ++ ) 
//                                      if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
                        }
                        else if( map->get_manager_2() == who )    // ���ط�
                        {
                                user = map->get_user_2_dbase();
                                send_user( user, "%c%c%d%w%w", 0x54, 10, d, x, y );
//                              for( i = 0, size = sizeof(user); i < size; i ++ ) 
//                                      if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
                        }
                }
        }
        else if( arrayp( user = me->get_team() ) )    // ���¶�Ա����
        {
                user -= ({ me, 0 });
                user = filter_array( user, (: $1 && get_z($1) == $2 :), z0 );
                send_user( user, "%c%c%d%w%w", 0x54, 10, me->get_number(), x, y );
        }
        z0 = get_z(me);
        if( get_block(z0, x, y) & SEAL_BLOCK )
        {
        	item = get_range_object_2(me, 0, SEAL_TYPE);
        	if (sizeof(item)>0)
        	{
        		if (item[0]->is_self_seal())
        			item[0]->heart_beat_loop(0, 0, 0, 0, 0, 0, 0, 0);
        	}
        }
        if ( me->is_leader() )
        {
		USER_HEART_D->team_follow(me,jump);
	}        	
        return 1;
}

// �����������
int main_npc( object me, string arg )
{
        object map, *user, *user2, *npc, who;
        string chan;
        int z0, x0, y0, z1, x1, y1, z, x, y, dx, dy, d, p;

        if( !arg || arg == "" ) return 1;

        if( !me->is_moveable() ) return 1;    // �������ƶ�

        if(     get_effect(me, EFFECT_CHAR_BUSY)
        ||      get_effect(me, EFFECT_CHAR_FAINT)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_CHAR_NO_MOVE)
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_CHAR_FREEZE)
        ||      get_effect(me, EFFECT_CHAR_SHUT) )
                return 1;

        if( sizeof(arg) > 3 ) arg = arg[0..3];

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( !( p = from_here(z0, x0, y0, arg, IS_CHAR_BLOCK) ) ) return 1;    // �ܷ�ͨ����

        x = p / 10000;
        y = ( p % 10000 ) / 10;
        d = p % 10;

        if( x0 == x && y0 == y ) return 1;    // û���ƶ�

        if( !inside_map(z0, x, y) ) return 1;    // �������

        if(     me->cannot_enter_city()
        &&     !me->get_owner()
        &&      MAP_D->is_inside_safe_zone(z0, x, y) ) return 1;    // ���ﲻ�ܽ���(С�����ѡ�����)

        if(     get_effect(me, EFFECT_CHAR_CHAN)    // ���˲�ס(ճ��)
        &&      stringp( chan = me->get_save("pf.chan") )
        &&      sscanf(chan, "%d:(%d,%d)", z1, x1, y1) == 3
        &&    ( abs(x1 - x) > 2 || abs(y1 - y) > 2 ) )
        {
//              send_user(me, "%c%w%w", 0x07, x0, y0);    // ��������
                return 1;
        }

        dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
        dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

        if( dx == 0 && dy == 0 )    // ������������
        {
                remove_block(z0, x0, y0, CHAR_BLOCK);
                set_x(me, x);  set_y(me, y); set_d(me, d);
                set_block(z0, x, y, CHAR_BLOCK);

                user = get_scene_object(z0, x, y, USER_TYPE);
                if( sizeof(arg) == 1 )
                        send_user( user, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg );
                else    send_user( user, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg );

                me->set_no_fight( MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0 );    // ��ȫ���ж�
        }
        else    // ��Խ��������
        {
                if( dx < 0 )
                {
                        if( dy < 0 ) { dx = 0x12e;  dy = 0x1d2; }
                        else if( dy > 0 ) { dx = 0x1e8;  dy = 0x5e; }
                        else { dx = 0x128;  dy = 0x52; }
                }
                else if( dx > 0 )
                {
                        if( dy < 0 ) { dx = 0x5e;  dy = 0x1e8; }
                        else if( dy > 0 ) { dx = 0x1d2;  dy = 0x12e; }
                        else { dx = 0x52;  dy = 0x128; }
                }
                else
                {
                        if( dy < 0 ) { dx = 0xe;  dy = 0x1c0; }
                        else { dx = 0x1c0;  dy = 0xe; }
                }

                remove_block( z0, x0, y0, CHAR_BLOCK);    // ɾ���赲
                user = get_scene_object(z0, x0, y0, USER_TYPE, dx);

                set_x(me, x);  set_y(me, y);  set_d(me, d);    // �������꣬�����赲
                set_block(z0, x, y, CHAR_BLOCK);
                objectp( who = me->get_owner() ) && who->is_user() ? move_object(me, z0, x, y, USER_TYPE) : move_object(me, z0, x, y, CHAR_TYPE);    // �ƶ� NPC
                user2 = get_scene_object(z0, x, y, USER_TYPE, dy);

                me->show_to_scene(user2, x0, y0, d, 0);
                user2 = get_scene_object_2(me, USER_TYPE) + user;
                if( sizeof(arg) == 1 )
                        send_user( user2, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg );
                else    send_user( user2, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg );

                send_user( user, "%c%d", 0x78, getoid(me) );

                if( MAP_D->is_inside_safe_zone(z0, x, y) )    // ��ȫ���ж�
                {
                        me->set_no_fight(1);
                }
                else
                {
                        me->set_no_fight(0);

                        if( objectp( me->get_owner() ) ) 
                        {
                                npc = get_range_object_2(me, 6, CHAR_TYPE);
                                if( sizeof(npc) ) npc->init_heart_beat_idle();
                        }
                }
        }

        if( objectp( who = me->get_owner() ) && who->is_user() ) 
        {
                if (get_z(who)!=get_z(me))
                {
                        send_user( who, "%c%c%d%w%w", 0x2c, 7, getoid(me), -1, -1 );    // �����ٻ�������
                }                        
                else                
                        send_user( who, "%c%c%d%w%w", 0x2c, 7, getoid(me), x, y );    // �����ٻ�������
        }                

        return 1;
}

// -------------------------------------------------------------

// ��������Ӱ�����ƶ�
int main_fly( object me, int x, int y, int d, int flag )
{
        object map, *user, *user2, *npc, *item, who;
        int z0, x0, y0, z, dx, dy;
        int p, i, size;

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( abs(x - x0) > 10 || abs(y - y0) > 10 ) return 1;    // �����Զ
        if( !inside_map(z0, x, y) ) return 1;    // ����Ƿ�
        if( get_block(z0, x, y) & IS_CHAR_BLOCK ) return 1;    // �޷����
        if( !from_to( z0, x0, y0, x - x0, y - y0, MAP_BLOCK ) ) return 1;    // �޷���Խ

        if(     objectp( who = me->get_quest("escort.robber#") )    // Ѱ��������
        &&      who->is_escort_robber()
        &&     !inside_screen( x, y, get_x(who), get_y(who) ) )    // �ƶ�������  // !inside_screen_2(me, who)
                return 1;

        dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
        dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

        if( dx == 0 && dy == 0 )    // ��������˲��
        {
                remove_block(z0, x0, y0, CHAR_BLOCK);
                set_x(me, x);  set_y(me, y);  set_d(me, d);
                set_block(z0, x, y, CHAR_BLOCK);

                user = get_scene_object(z0, x, y, USER_TYPE);
//                send_user( user, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag );

                me->set_no_fight( MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0 );    // ��ȫ���ж�
        }
        else    // ��Խ����˲��
        {
                if( dx < 0 )
                {
                        if( dy < 0 ) { dx = 0x12e;  dy = 0x1d2; }
                        else if( dy > 0 ) { dx = 0x1e8;  dy = 0x5e; }
                        else { dx = 0x128;  dy = 0x52; }
                }
                else if( dx > 0 )
                {
                        if( dy < 0 ) { dx = 0x5e;  dy = 0x1e8; }
                        else if( dy > 0 ) { dx = 0x1d2;  dy = 0x12e; }
                        else { dx = 0x52;  dy = 0x128; }
                }
                else
                {
                        if( dy < 0 ) { dx = 0xe;  dy = 0x1c0; }
                        else { dx = 0x1c0;  dy = 0xe; }
                }

                remove_block(z0, x0, y0, CHAR_BLOCK);    // ɾ���赲

                user = get_scene_object(z0, x0, y0, USER_TYPE, dx);    // ɾ������
                npc = get_scene_object(z0, x0, y0, CHAR_TYPE, dx);
                item = get_scene_object(z0, x0, y0, ITEM_TYPE, dx);
                user->remove_to_user(me);
                npc->remove_to_user(me);
                item->remove_to_user(me);

                item = get_scene_object(z0, x0, y0, SEAL_TYPE, dx);
                item->remove_to_user_2(me);

                set_x(me, x);  set_y(me, y);  set_d(me, d);    // �������꣬�����赲
                set_block(z0, x, y, CHAR_BLOCK);
                move_object(me, z0, x, y, USER_TYPE);    // �ƶ����

                user2 = get_scene_object(z0, x, y, USER_TYPE, dy);    // ��������
                npc = get_scene_object(z0, x, y, CHAR_TYPE, dy);
                item = get_scene_object(z0, x, y, ITEM_TYPE, dy);
                user2->show_to_user(me);
                npc->show_to_user(me);
                item->show_to_user(me);

                item = get_scene_object(z0, x, y, SEAL_TYPE, dy);
                item->show_to_user_2(me);

                me->show_to_scene(user2, x0, y0, d, 0);
                user2 = get_scene_object_2(me, USER_TYPE) + user;
                send_user( user2, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag );

                send_user( user, "%c%d", 0x78, getoid(me) );

                if( MAP_D->is_inside_safe_zone(z0, x, y) )    // ��ȫ���ж�
                {
                        me->set_no_fight(1);
                }
                else
                {
                        me->set_no_fight(0);

                        npc = get_range_object_2(me, 6, CHAR_TYPE);
                        if( sizeof(npc) ) npc->init_heart_beat_idle();
                }
        }

        if(  !MAP_D->is_inside_copy(z0) && ( p = get_jumpout(z0, x, y) )    // ��ת��һ����
        &&   ( !objectp( who = me->get_quest("escort.robber#") ) || !who->is_escort_robber() ) )    // Ѱ��������
        {
                z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;    // get_jumpout �ں� z

                if(   ( who = me->get_quest("escort.npc") )    // ��������
                &&      who->get_owner() == me
                &&      inside_screen_2(me, who) )
                        who->add_to_scene(z, x, y, d);

                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                {
                        x = p / 1000;  y = p % 1000;

                        me->set_login_flag(2);    // ��ת����
                        set_invisible(me, 1);
                        set_effect(me, EFFECT_USER_LOGIN, 4);

                        me->add_to_scene(z, x, y, d);

//                      if( z != z0 ) if( map = get_map_object(z) ) notify( map->get_name() );    // ��ʾ��ͼ��
                }
        }
        else if( MAP_D->is_inside_battle(z0) )    // ս��
        {
                if( objectp( map = get_map_object(z0) ) )    // ��ȡս������
                {
                        who = me->get_manager();
                        d = getoid(me);

                        if( map->get_manager() == who )    // ������
                        {
                                user = map->get_user_dbase();
                                send_user( user, "%c%c%d%w%w", 0x54, 10, d, x, y );
//                              for( i = 0, size = sizeof(user); i < size; i ++ ) 
//                                      if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
                        }
                        else if( map->get_manager_2() == who )    // ���ط�
                        {
                                user = map->get_user_2_dbase();
                                send_user( user, "%c%c%d%w%w", 0x54, 10, d, x, y );
//                              for( i = 0, size = sizeof(user); i < size; i ++ ) 
//                                      if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
                        }
                }
        }
        else if( arrayp( user = me->get_team() ) )    // ���¶�Ա����
        {
                user -= ({ me, 0 });
                user = filter_array( user, (: $1 && get_z($1) == $2 :), z0 );
                send_user( user, "%c%c%d%w%w", 0x54, 10, me->get_number(), x, y );
        }

        if( get_effect(me, EFFECT_CHAR_CHAN) ) set_effect(me, EFFECT_CHAR_CHAN, 1);    // �Ƴ�ճ��Ч��
        z0 = get_z(me);
        if( get_block(z0, x, y) & SEAL_BLOCK )
        {
        	item = get_range_object_2(me, 0, SEAL_TYPE);
        	if (sizeof(item)>0)
        	{
        		if (item[0]->is_self_seal())
        			item[0]->heart_beat_loop(0, 0, 0, 0, 0, 0, 0, 0);
        	}
        }
        return 1;
}

// ��������Ӱ�����ƶ�
int main_fly_npc( object me, int x, int y, int d, int flag )
{
        object map, *user, *user2, *npc, who;
        int z0, x0, y0, z, dx, dy;
        int p, i, size;

        z0 = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( abs(x - x0) > 10 || abs(y - y0) > 10 ) return 1;    // �����Զ
        if( !inside_map(z0, x, y) ) return 1;    // ����Ƿ�
        if( get_block(z0, x, y) & IS_CHAR_BLOCK ) return 1;    // �޷����
        if( !from_to( z0, x0, y0, x - x0, y - y0, MAP_BLOCK ) ) return 1;    // �޷���Խ

        dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
        dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

        if( dx == 0 && dy == 0 )    // ������������
        {
                remove_block(z0, x0, y0, CHAR_BLOCK);
                set_x(me, x);  set_y(me, y); set_d(me, d);
                set_block(z0, x, y, CHAR_BLOCK);

                user = get_scene_object(z0, x, y, USER_TYPE);
                send_user( user, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag );

                me->set_no_fight( MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0 );    // ��ȫ���ж�
        }
        else    // ��Խ��������
        {
                if( dx < 0 )
                {
                        if( dy < 0 ) { dx = 0x12e;  dy = 0x1d2; }
                        else if( dy > 0 ) { dx = 0x1e8;  dy = 0x5e; }
                        else { dx = 0x128;  dy = 0x52; }
                }
                else if( dx > 0 )
                {
                        if( dy < 0 ) { dx = 0x5e;  dy = 0x1e8; }
                        else if( dy > 0 ) { dx = 0x1d2;  dy = 0x12e; }
                        else { dx = 0x52;  dy = 0x128; }
                }
                else
                {
                        if( dy < 0 ) { dx = 0xe;  dy = 0x1c0; }
                        else { dx = 0x1c0;  dy = 0xe; }
                }

                remove_block( z0, x0, y0, CHAR_BLOCK);    // ɾ���赲
                user = get_scene_object(z0, x0, y0, USER_TYPE, dx);

                set_x(me, x);  set_y(me, y);  set_d(me, d);    // �������꣬�����赲
                set_block(z0, x, y, CHAR_BLOCK);
                objectp( who = me->get_owner() ) && who->is_user() ? move_object(me, z0, x, y, USER_TYPE) : move_object(me, z0, x, y, CHAR_TYPE);    // �ƶ� NPC
                user2 = get_scene_object(z0, x, y, USER_TYPE, dy);

                me->show_to_scene(user2, x0, y0, d, 0);
                user2 = get_scene_object_2(me, USER_TYPE) + user;
                send_user( user2, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag );

                send_user( user, "%c%d", 0x78, getoid(me) );

                if( MAP_D->is_inside_safe_zone(z0, x, y) )    // ��ȫ���ж�
                {
                        me->set_no_fight(1);
                }
                else
                {
                        me->set_no_fight(0);

                        if( objectp( me->get_owner() ) ) 
                        {
                                npc = get_range_object_2(me, 6, CHAR_TYPE);
                                if( sizeof(npc) ) npc->init_heart_beat_idle();
                        }
                }
        }
        if( objectp( who = me->get_owner() ) && who->is_user() ) 
        {
                if (get_z(who)!=get_z(me))                
                {
                        send_user( who, "%c%c%d%w%w", 0x2c, 7, getoid(me), -1, -1 );    // �����ٻ�������
                        me->set_owner(0);
                }                        
                else
                        send_user( who, "%c%c%d%w%w", 0x2c, 7, getoid(me), x, y );    // �����ٻ�������
        }

        if( get_effect(me, EFFECT_CHAR_CHAN) ) set_effect(me, EFFECT_CHAR_CHAN, 1);    // �Ƴ�ճ��Ч��

        return 1;
}
