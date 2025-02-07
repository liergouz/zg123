
// �Զ����ɣ�/make/std/makemap

#include <map.h>
#include <time.h>

inherit SCENE;
object huwang,zizhujin;
int hwTime,hwStart;
void clone_npc();

// ��������ȡ��ʶ
int get_id() { return 174; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 174; }

// ��������ȡ����
string get_name() { return "�������"; }

// ��������λ˳��
int get_reset_order() { return 56; }

// ��������ȡ�������
int get_map_type() { return FIELD_MAP; }

// ��������ȡͶ������
int get_caster_amount() { return 1; }

// ���������촦��
void create() 
{
        object map = this_object();
	mixed *mxTmp;

        set_map_object( map, get_id() );
        MAP_D->load_npc_file( map, "/map/npc/174.npc" );

        set_fighter_file( ({ "/npc/npc/0513", "/npc/npc/0512",  }) );
        set_boss_file( ({ "/npc/npc/0563",  }) );

        set_sizeof_xy( sizeof_xy_point( get_id() ) );

        set_heart_timer( map, set_heart_timer_2( map, ( time() % RESET_TIME ) * 10 ) );
        set_heart_loop(map, 60);    // ѭ��������������
        map->heart_beat();
        set_heart_beat(1);
	
	mxTmp = localtime(time());
	hwStart = mktime(mxTmp[TIME_YEAR],mxTmp[TIME_MON]+1,mxTmp[TIME_MDAY],20,30,0);
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
	int p,x,y,z;
	
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
        	if ( !objectp(zizhujin) )
        	{
        		zizhujin = new("npc/task/0186");	
        		zizhujin->add_to_scene(174,161,130,2);
        	}
        	else if ( get_x(zizhujin) != 161 || get_y(zizhujin) != 130 )
        		zizhujin->add_to_scene(174,161,130,2);
     		
        }
        //����
        if( time % 10 == 0 && MAIN_D->get_host_type()!=6012 ) //1����
        {
	        if ( hwTime == 0 )
	        {
	        	if ( time() > hwStart )	//��һ�γ��ֵ�ʱ��
	        	{
				if( p = efun::get_xy_point( 174, IS_CHAR_BLOCK ) )
				{
					x = ( p % 1000000 ) / 1000;  y = p % 1000;
					huwang = new("npc/boss/0001");	
					if ( huwang )
					{
						map->add_boss(huwang);
						huwang->add_to_scene(174,x,y);
						hwTime = -1 ;
					}
				}
			}
	        }
	        else
	        {
		        if ( !objectp(huwang) && hwTime == -1 )
		        {
		        	hwTime = time();
		        }
		        if ( hwTime != -1 && (gone_time(hwTime) >= 3600*48 ))
		        {
				if( p = efun::get_xy_point( 174, IS_CHAR_BLOCK ) )
				{
					x = ( p % 1000000 ) / 1000;  y = p % 1000;
					huwang = new("npc/boss/0001");	
					if ( huwang )
					{
						map->add_boss(huwang);
						huwang->add_to_scene(174,x,y);
						hwTime = -1 ;
					}
				}
		        }
		}
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
