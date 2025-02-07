
// �Զ����ɣ�/make/std/makemap

#include <map.h>

inherit SCENE;
object zhusan,maxiaoqi;
void clone_npc();

// ��������ȡ��ʶ
int get_id() { return 344; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 344; }

// ��������ȡ����
string get_name() { return "������Ĺ��"; }

// ��������λ˳��
int get_reset_order() { return 80; }

// ��������ȡ�������
int get_map_type() { return CAVE_MAP; }

// ��������ȡͶ������
int get_caster_amount() { return 1; }

// ���������촦��
void create() 
{
        object map = this_object();

        set_map_object( map, get_id() );
        MAP_D->load_npc_file( map, "/map/npc/344.npc" );

        set_fighter_file( ({ "/npc/npc/0860", "/npc/npc/0880", "/npc/npc/0870",  }) );
        set_boss_file( ({ "/npc/npc/0932",  }) );

        set_sizeof_xy( sizeof_xy_point( get_id() ) );

        set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
        set_heart_loop(map, 60);    // ѭ��������������
        map->heart_beat();
        set_heart_beat(1);

        call_out("reset", 1);    // ��ͼ��λ
}

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ���ִ���
{
        call_out("reset", 1);    // ��ͼ��λ
}

// ��������λ����
void reset() 
{
        object map = this_object();
        int time = add_reset_time(1);

        remove_call_out( "reset" );

        if( time % 100 == 0 )    // 10 ����
        {
                MAP_D->reset_npc( get_id() );    // ��λNPC ����
                set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
        }
        if( time % 200 == 0 )    // 20 ����
        {
                MAP_D->clone_boss( this_object() );    // ����СBOSS
        }
        if( time % get_clean_time() == 0 )    // ��λʱ��
        {
                call_out( "reset_call_out", get_reset_order()%6 );    // ����С����
        }
        if ( time % 30 == 0 )		//3����
        {
        	if ( !objectp(zhusan) )
        	{
        		zhusan = new("npc/task/0174");	
        		zhusan->add_to_scene(344,211,123,2);
        	}
        	else if ( get_x(zhusan) != 211 || get_y(zhusan) != 123 )
        		zhusan->add_to_scene(344,211,123,2);
        	if ( !objectp(maxiaoqi) )
        	{
        		maxiaoqi = new("npc/task/0175");	
        		maxiaoqi->add_to_scene(344,198,114,2);
        	}
        	else if ( get_x(maxiaoqi) != 198 || get_y(maxiaoqi) != 114 )
        		maxiaoqi->add_to_scene(344,198,114,2);
        }
}

// ��������λ����
void reset_call_out()
{
        remove_call_out( "reset_call_out" );

        MAP_D->reset_item( get_id() );

        if( sizeof_fighter_file() > 0 ) 
        { 
                set_add_amount(-1);  clone_npc(); 
        }
}

// �������������
void clone_npc()
{
        remove_call_out( "clone_npc" );

        MAP_D->clone_npc( this_object() );

        if( get_add_amount() ) call_out( "clone_npc", 2 );
}
