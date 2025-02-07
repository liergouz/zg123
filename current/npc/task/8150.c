
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <task.h>

inherit NPC;

// ������Ҫץ����
int is_thief() { return 1; }

// �������Ƿ��ܽ���
int cannot_enter_city() { return 1; }

// ���������촦��
void create()
{
        set_name( "С͵" + NPC_NAME_D->get_thief_name() );
        set_char_picid(1000);    // ������

        setup();

        set( "birthday", time() );
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }

// ��������λ����
void reset() 
{
        object who;
        string *member, id;
        int i, size,iKind;

        if( gone_time( get("birthday") ) >= 1800 )    // 30 ����
        {
                if(   ( who = find_player( sprintf("%d", get("task") ) ) )
                &&      who->get_quest("thief.flag") == 1    // 1. ʧ������(����)
                &&      who->get_quest("thief.thief") == sprintf( "%x#", getoid( this_object() ) ) )
                {
                        iKind = who->get_quest("thief.flag");
                        who->delete_quest("thief.flag");
                        who->delete_quest("thief.time");
                        who->delete_quest("thief.thief");
                        who->delete_quest("thief.z");
                        who->delete_quest("thief.x");
                        who->delete_quest("thief.y");
                        who->delete_quest("thief.count");

		        send_user( who, "%c%c%c%w%w%w%s", 0x51, 1, 4,TID_THIEF,iKind,0,"" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_THIEF,iKind,"" ); 
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_THIEF,"" ); 
	                     
                }
                remove_from_scene();
                destruct( this_object() );
        }
        else
        {
                member = get("user");
                for( i = 0, size = sizeof(member); i < size; i ++ )
                        if( !( who = find_player( member[i] ) ) ) member[i] = "";
                if( sizeof( member - ({ "" }) ) < 1 )
                {
                        if(   ( who = find_player( sprintf("%d", get("task") ) ) )
                        &&      who->get_quest("thief.flag") == 1    // 1. ʧ������(����)
                        &&      who->get_quest("thief.thief") == sprintf( "%x#", getoid( this_object() ) ) )
                        {
                        	iKind = who->get_quest("thief.flag");
                                who->delete_quest("thief.flag");
                                who->delete_quest("thief.time");
                                who->delete_quest("thief.thief");
                                who->delete_quest("thief.z");
                                who->delete_quest("thief.x");
                                who->delete_quest("thief.y");
                                who->delete_quest("thief.count");
                                
			        send_user( who, "%c%c%c%w%w%w%s", 0x51, 1, 4,TID_THIEF,iKind,0,"" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_THIEF,iKind,"" ); 
				send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_THIEF,"" );                                 
                        }
                        remove_from_scene();
                        destruct( this_object() );
                }
        }
}

// ���������Խ���ս��
int can_be_fighted( object who ) 
{ 
        object owner;

	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() ) return 0;
        if( who->get_enemy() == this_object() ) return 1;

        if( get("task") == who->get_number() ) return 1;

        send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),  get_name() + ":\n    �㿴�����ҡ����㿴�����ҡ���" );
        return 0;
}

// --------------------------------------------------------------- Զ�̵��� ----

// ��������������
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// ��������������(���߸���)
void win_bonus_callout( object me, object who )
{
	int z,iKind;
	string name;
        object owner,map;

        if( !me->can_be_fighted(who) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;

        if( me->get("task") != who->get_number() ) return;
	z = who->get_quest("thief.z");
	map = get_map_object(z);
	name = map ? map->get_name() : "������ͼ";
	who->set_quest("thief.name",me->get_name());
	who->set_quest("thief.map",name);
        who->set_quest("thief.bonus",1);

	iKind = who->get_quest("thief.flag");
        send_user( who, "%c%c%c%w%w%w%s", 0x51, 1, 4,TID_THIEF,iKind,0,"" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2,TID_THIEF,iKind,"" ); 
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,TID_THIEF,"" ); 
	
        TASK_THIEF_D->send_task_list(who);
}
