
#include <ansi.h>
#include <map.h>
#include <city.h>
#include <time.h>

// �����������
int main( object me, string arg )
{
        object map, orgnpc, npc;
        string name1, name2, name, cmd;
        int z, p, i, size;
	mixed *mxTime;    
	int iTime, time;
	iTime = time();
	mxTime = localtime(iTime);
	
	
        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
        

        if( me->get_org_name() == "" )
	{
                notify( "���ü���һ�����ɣ�" );
                return 1;
	}
	if( !arg || arg == "" ) 
	{
                notify( "������ͬ�ĸ����ɿ�ս��" );
                return 1;
	}
	if(     arg == me->get_org_name()
        ||     !objectp( npc = CITY_ZHOU->get_2( sprintf( "org.%s", arg ) ) ) )
        {
                notify( "����������Ϸ��İ��ɡ�" );
                return 1;
        }
        orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", me->get_org_name() ) );
        if (!orgnpc)
        {
                notify( "�����Ϸ��İ��ɡ�" );
                return 1;
        }        

                                        if( !( z = find_map_flag(BATTLE_MAP_BEGIN, BATTLE_MAP_END, 0) ) )    // ���ҿհ�ս��
                                        {
                                                send_user( me, "%c%s", '!', "������" + arg + "������ս����" );
                                                return;
                                        }
/*                                        
                                        switch( get_z(npc) )    // ���Ҷ�Ӧս��
                                        {
                                      case 10 : p = 910;  break;
                                      case 20 : p = 920;  break;
                                      case 30 : p = 930;  break;
                                      case 40 : p = 940;  break;
                                      case 50 : p = 950;  break;
                                      case 60 : p = 960;  break;
                                      case 70 : p = 970;  break;
                                      default : send_user( me, "%c%s", '!', "������" + arg + "������ս����" );
                                                return;
                                        }
*/
					p = 910;
                                        init_virtual_map(z, p);    // ���������ͼ

                                        map = new(BATTLE);    // �����������
                                        map->set_client_id(p);
                                        set_map_object( map, map->set_id(z) );

					if (time%2==1) time += 3;
					else time += 2;
                                        orgnpc->set_war( time() + 60 );  npc->set_war( time() + 60 );    // ��¼ս��ʱ��

                                        orgnpc->set_battle(z);  npc->set_battle(z);    // ��¼ս�����
                                        orgnpc->set_enemy_95(npc);  npc->set_enemy_95(orgnpc);    // ��¼�з��ܹ�
                                        me->set_wood(0); npc->set_wood(0);
                                        orgnpc->set_level1(1); npc->set_level1(1);
                                        orgnpc->set_level2(1); npc->set_level2(1);
                                        orgnpc->set_level3(1); npc->set_level3(1);                                        
                                        map->set_war_attack( me->get_org_name() );  map->set_war_defense(arg);    // ��¼ս��˫��
                                        map->set_heart_sec(0);    // У��ʱ��
                                        map->set_war(WAR_READY);    // ��¼ս��׼��

                                        NPC_BATTLE_D->war_ready_notice(map);
                                        map->set_starttime( time() + 60 );

        map->set_heart_sec(595);

//        tell_user(me, "ս��λ�ã�%d", z);

        return 1;
}
