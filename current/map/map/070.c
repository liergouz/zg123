
// �Զ����ɣ�/make/std/makemap

#include <map.h>
#include <city.h>

inherit SCENE_2;

// ��ֹPK
int get_no_fight() {return 1;}

// ��������ȡ��ʶ
int get_id() { return 070; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 070; }

// ��������ȡ����
string get_name() { return "��"; }

// ��������λ˳��
int get_reset_order() { return 124; }

// ��������ȡ�������
int get_map_type() { return CITY_MAP; }

// ���������촦��
void create() 
{
        object map = this_object();

        set_map_object( map, get_id() );
        MAP_D->load_npc_file( map, "/map/npc/070.npc" );

        set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
        set_heart_loop(map, 60);    // ѭ��������������
        map->heart_beat();
        set_heart_beat(1);

        call_out("reset", 1);    // ��ͼ��λ
        set_clean_time(10);
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
                map->init_herb_dbase();    // �����ҩ����
                set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
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

        MAP_D->clone_fish( this_object(), CITY_YAN );
}
