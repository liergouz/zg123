
// �Զ����ɣ�/make/std/makemap

#include <map.h>

inherit SCENE;
object zhaoshi,lishi,qixiaoliu,shijiu,zhaowu;
void clone_npc();

// ��������ȡ��ʶ
int get_id() { return 071; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 071; }

// ��������ȡ����
string get_name() { return "�೤�ǣ�"; }

// ��������λ˳��
int get_reset_order() { return 57; }

// ��������ȡ�������
int get_map_type() { return FIELD_MAP; }

// ��������ȡͶ������
int get_caster_amount() { return 0; }

// ���������촦��
void create() 
{
        object map = this_object();

        set_map_object( map, get_id() );
        MAP_D->load_npc_file( map, "/map/npc/071.npc" );

        set_fighter_file( ({ "/npc/npc/0560", "/npc/npc/0561", "/npc/npc/0562",  }) );
        set_boss_file( ({ "/npc/npc/0610",  }) );

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
        	if ( !objectp(zhaoshi) )
        	{
        		zhaoshi = new("npc/task/0143");	
        		zhaoshi->add_to_scene(071,108,104,2);
        	}
        	else if ( get_x(zhaoshi) != 108 || get_y(zhaoshi) != 104 )
        		zhaoshi->add_to_scene(071,108,104,2);
        	if ( !objectp(lishi) )
        	{
        		lishi = new("npc/task/0151");	
        		lishi->add_to_scene(071,141,131,2);
        	}
        	else if ( get_x(lishi) != 141 || get_y(lishi) != 131 )
        		lishi->add_to_scene(071,141,131,2);
        	if ( !objectp(qixiaoliu) )
        	{
        		qixiaoliu = new("npc/task/0152");	
        		qixiaoliu->add_to_scene(071,230,121,2);
        	}
        	else if ( get_x(qixiaoliu) != 230 || get_y(qixiaoliu) != 121 )
        		qixiaoliu->add_to_scene(071,230,121,2);
        	if ( !objectp(zhaowu) )
        	{
        		zhaowu = new("npc/task/0153");	
        		zhaowu->add_to_scene(071,178,161,2);
        	}
        	else if ( get_x(zhaowu) != 178 || get_y(zhaowu) != 161 )
        		zhaowu->add_to_scene(071,178,161,2);
        	if ( !objectp(shijiu) )
        	{
        		shijiu = new("npc/task/0154");	
        		shijiu->add_to_scene(071,67,82,2);
        	}
        	else if ( get_x(shijiu) != 67 || get_y(shijiu) != 82 )
        		shijiu->add_to_scene(071,67,82,2);
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
