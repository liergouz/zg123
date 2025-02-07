
#include <ansi.h>
#include <map.h>
#include <effect.h>

inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 100; }

// ����������ʶ��
int get_talisman_type() { return 6; }

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(9551);
        set_picid_2(9551);
        set_unit( "��" );

        set_level(1);
        set_value(5000);
        set_max_lasting(1499);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "�����Լ�����ǰ������ָ������";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9551" ->get_use_effect_2_callout( me, who, this_object(), arg ); }

// ������ʹ�÷���Ч��(���߸���)
int get_use_effect_2_callout( object me, object who, object item, string arg )
{
        object map, npc;
        int z, x, y, p;

        if( !arg || arg == "" )
        {
                send_user( me, "%c%c%d%s", '?', 16, 8, "���봫�͵���ǰ������������������꣺X,Y (ȡֵ 0��999)\n"
                        ESC "pf2 00900.%s\n" );
                return 1;
        }
        else
        {
                if( sscanf(arg, "%d,%d", x, y) != 2 )    // && sscanf(arg, "%d��%d", x, y) != 2
                {
                        send_user( me, "%c%s", '!', "�����������" );
                        return 1;
                }

                z = get_z(me);

                if( me->get_login_flag() < 3 ) return 1;    // û��׼������
                if( me->is_die() )
                {
                        send_user( me, "%c%s", '!', "����״̬�²���ʹ�������顣" );
                        return 1;                	
        	}
		if( me->get_save_2("51cuanye.time") )
		{
			send_user(me, "%c%s", '!', "���ܼ��޴�Խ�������ʹ�������顣");
			return 0;
		}
                if( me->is_store_open() )
                {
                        send_user( me, "%c%s", '!', "��̯״̬�²���ʹ�������顣" );
                        return 1;                	
        	}        
                if( me->get_no_fight() )
                {
                        send_user( me, "%c%s", '!', "��ȫ������ʹ�������顣" );
                        return 1;                	
        	}         		
                if( objectp( map = get_map_object( get_z(me) ) ) && map->get_map_type() == BATTLE_MAP )
                {
                        send_user( me, "%c%s", '!', "��ս������ʹ�������顣" );
                        return 1;
                }
		if( map->is_copy_scene() )
	        {
	                send_user(me, "%c%s", '!', "�ڸ����ڲ���ʹ�������顣");
	                return 1;
	        }
                if( present("ǮƱ", me, 1, MAX_CARRY) )
                {
                        send_user( me, "%c%s", '!', "����ǮƱ����ʹ�������顣" );
                        return 1;
                }
                if( present("������Ʒ", me, 1, MAX_CARRY*4) )
                {
                        send_user( me, "%c%s", '!', "���Ź�����Ʒ����ʹ�������顣" );
                        return 1;
                }       
                if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // Ѱ��������
                {
                        send_user( me, "%c%s", '!', "�������������������ء�" );
                        return 1;
                }

                item->add_lasting(-1);    // ʹ�ü����;�

                if(     random(100) < item->get_active_rate()    // �ɹ���
                &&    ( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) ) )
                {
                        x = p / 1000;  y = p % 1000;

                        if( MAP_D->is_inside_city(z, x, y) )
                        {
                                send_user( me, "%c%s", '!', "���ܴ��͵����ڡ�" );
                                return 1;
                        }

/*                      me->set_login_flag(2);    // ��ת����
                        set_invisible(me, 1);
                        set_effect(me, EFFECT_USER_LOGIN, 4);   */
/*
                        if(   ( npc = me->get_quest("escort.npc") )    // ��������
                        &&      npc->get_owner() == me
                        &&      inside_screen_2(me, npc) )    // ͬ��Ļ��
                                npc->add_to_scene( z, x, y, get_d(me), 40991, 40992, 40991, 40992 );
*/
                        if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                        {
                                me->add_to_scene( z, p / 1000, p % 1000, get_d(me), 40991, 40992, 40991, 40992 );
                        }

//                      write_user( me, ECHO "��ʹ��" HIY "��������" ECHO "�ɹ��ˡ�" );
                }
                else    write_user( me, ECHO "��ʹ��" HIY "��������" ECHO "ʧ���ˡ�" );
        }

        return 1;
}
