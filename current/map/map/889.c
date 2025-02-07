
#include <map.h>

inherit SCENE;

void clone_npc();

int is_wushuang() {return 1;}
int is_wushuang_palace() {return 1;}

// ��������ȡ��ʶ
int get_id() { return 889; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 889; }

// ��������ȡ����
string get_name() { return "��˫��"; }

// ��������λ˳��
int get_reset_order() { return 158; }

// ��������ȡ�������
int get_map_type() { return FIELD_MAP; }

// ��������ȡͶ������
int get_caster_amount() { return 0; }

// ���������촦��
void create() 
{
        object map = this_object();

        set_map_object( map, get_id() );

        set_sizeof_xy( sizeof_xy_point( get_id() ) );

        set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
        set_heart_loop(map, 60);    // ѭ��������������
        map->heart_beat();
        set_heart_beat(1);

//        call_out("reset", 1);    // ��ͼ��λ
}

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4 )    // ÿ���ִ���
{
//        call_out("reset", 1);    // ��ͼ��λ
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

// ������ȡ��ͼ�ڵ��������
object *get_all_user( )
{
        object *item, who, *npc=({}),*all=({});
        int z, x, y, p, max_x, max_y;
        int i, size;

        reset_eval_cost();

        z = get_id();  max_x = get_map_max_x(z);  max_y = get_map_max_y(z);

        for( x = 0; x < max_x; x += AREA_SIZE ) for( y = 0; y < max_y; y += AREA_SIZE )
        {
                if( have_scene_object(z, x, y, USER_TYPE, 1) )
                {
                        item = get_scene_object(z, x, y, USER_TYPE, 1);

                        for( i = 0, size = sizeof(item); i < size; i ++ ) if( who = item[i] )
                        {
                                all += ({ item[i] });
                        }
                }
        }
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]&&all[i]->is_user())
			npc += ({all[i]});
	}
	return npc;
}
