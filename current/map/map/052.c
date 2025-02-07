
// �Զ����ɣ�/make/std/makemap

#include <map.h>

inherit SCENE;
object shiqi,yejiu;
void clone_npc();

// ��������ȡ��ʶ
int get_id() { return 052; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 052; }

// ��������ȡ����
string get_name() { return "�س��ǣ�"; }

// ��������λ˳��
int get_reset_order() { return 64; }

// ��������ȡ�������
int get_map_type() { return FIELD_MAP; }

// ��������ȡͶ������
int get_caster_amount() { return 1; }

// ���������촦��
void create() 
{
        object map = this_object();

        set_map_object( map, get_id() );
        MAP_D->load_npc_file( map, "/map/npc/052.npc" );

        set_fighter_file( ({ "/npc/npc/0660", "/npc/npc/0661", "/npc/npc/0662",  }) );
        set_boss_file( ({ "/npc/npc/0710",  }) );

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
        	if ( !objectp(shiqi) )
        	{
        		shiqi = new("npc/task/0160");	
        		shiqi->add_to_scene(52,182,83,2);
        	}
        	else if ( get_x(shiqi) != 182 || get_y(shiqi) != 83 )
        		shiqi->add_to_scene(52,182,83,2);
        	if ( !objectp(yejiu) )
        	{
        		yejiu = new("npc/task/0161");	
        		yejiu->add_to_scene(52,127,111,2);
        	}
        	else if ( get_x(yejiu) != 127 || get_y(yejiu) != 111 )
        		yejiu->add_to_scene(52,127,111,2);
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
