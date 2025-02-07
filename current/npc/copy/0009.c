#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 2111; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// ���������촦��
void create()
{
	object me=this_object();
        set_name("��Ĺʯʨ");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
//        set_head_color(0x39eb);
        setup();
}

void do_look(object who)
{
	int id,level,z;
	object me=this_object(),map;

	id = getoid(me);
	z = get_z(me);
	if( !objectp( map = get_map_object(z) ) || !map->is_virtual_scene() ) 
		return;
	if ( map->get("beat_boss") < 3 )	
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"ʯʨ���������һЩ��:\n    ����������ܼ๤���鷿�������������������������������֮һ����ſ���ͨ�����ʯʨ���ؽ����ܼ๤�鷿��\n    1���õ���׷�����ȡ����������˵�ͬ�⣻\n    2������׷�����ȡ������������ܡ�\n"ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���ʯʨ�����Ѿ�����,��������ʯʨ�ϵĻ��ؾͿ��Խ����ܼ๤���鷿�ˡ��������ܼ๤�鷿�󣬹����ڻ������е���֮ǰ�ǲ����Գ����ģ�����Ҫ�����ܼ๤���鷿��\n"ESC"�����ܼ๤�鷿\ntalk %x# welcome.77\n"ESC"ȡ��",id,));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy, level,z;
       	object who, item,map;
       	string legend;
        who = this_player();
        flag = to_int(arg);
        level = who->get_level();
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 77:
		z = get_z(me);
		if( !objectp( map = get_map_object(z) ) || !map->is_virtual_scene() ) 
			return;
		if ( map->get("beat_boss") < 3 )	
			return ;
		tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB3);
        		if ( !map )	//��������
        		{
        			map = "sys/copy/tomb"->new_copy_tomb3(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance1");
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "�����С���");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;
	}
}


