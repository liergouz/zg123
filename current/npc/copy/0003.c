#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;
int host_type;

// ��������ȡ��������
int get_char_picid() { return 650; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// ���������촦��
void create()
{
	object me=this_object();
        set_name("���潫��");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        setup();
	host_type = MAIN_D->get_host_type();
}

void do_look(object who)
{
	int id;
	object me=this_object();

	id = getoid(me);
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "����ϵͳ��δ���ţ�");
		return;
	}	
	if (who->get_level()>60 && !who->get_vip() )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��������������Ȼ�����ϴ����Ĺ�����λ���������巢�����ң��ҷ����֮������ļ������ʿƽ�����ң���Ҫȥ��὾�Ӫƽ����\n"ESC"��὾�Ӫ��ʲô�ط���\ntalk %x# welcome.1\n"ESC"�����Ӫ�Ĺ���\ntalk %x# welcome.2\n"ESC"ʹ�ÿ���֥������὾�Ӫ\ntalk %x# welcome.3\n"ESC"�뿪",id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��������������Ȼ�����ϴ����Ĺ�����λ���������巢�����ң��ҷ����֮������ļ������ʿƽ�����ң���Ҫȥ��὾�Ӫƽ����\n"ESC"��὾�Ӫ��ʲô�ط���\ntalk %x# welcome.1\n"ESC"�����Ӫ�Ĺ���\ntalk %x# welcome.2\n"ESC"�����὾�Ӫ\ntalk %x# welcome.3\n"ESC"�뿪",id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy, level;
       	object who, item,map;
       	string legend;
        who = this_player();
        flag = to_int(arg);
        level = who->get_level();
        who->set_time( "talk",  0);
        id = getoid(me);
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "����ϵͳ��δ���ţ�");
		return;
	}        
        switch(flag)
        {
        case 1:
        	if (level>60 && !who->get_vip())
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��὾�Ӫ��һ������ĵط��������кܶ�����ȴ����ȥ̽�����кܶ�߼�����ȴ����ȥ��ս����˵����Ĺ�������ܶ༫Ʒ��װ���أ�\n"ESC"�����Ӫ�Ĺ���\ntalk %x# welcome.2\n"ESC"ʹ�ÿ���֥������὾�Ӫ\ntalk %x# welcome.3\n"ESC"�뿪",id,id,));
		else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��὾�Ӫ��һ������ĵط��������кܶ�����ȴ����ȥ̽�����кܶ�߼�����ȴ����ȥ��ս����˵����Ĺ�������ܶ༫Ʒ��װ���أ�\n"ESC"�����Ӫ�Ĺ���\ntalk %x# welcome.2\n"ESC"�����὾�Ӫ\ntalk %x# welcome.3\n"ESC"�뿪",id,id,));
        	break;
        case 2:
        	if (level>60 && !who->get_vip())
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��ұ����Ƕ������ʽ�����὾�Ӫ����὾�Ӫֻ������5λͬ�������ҡ�����Ӫ�������ɺܶ�ܶ���顣ÿ�����鶼���ض��ľ�Ӫ������֮�䲻�ύ�����档ÿ�����鶼����������һ����὾�Ӫ�ڡ���὾�Ӫֻ��������ȼ�40-60����Ҳſ��Խ��롣\n"ESC"ʹ�ÿ���֥������὾�Ӫ\ntalk %x# welcome.3\n"ESC"�뿪",id,));
		else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��ұ����Ƕ������ʽ�����὾�Ӫ����὾�Ӫֻ������5λͬ�������ҡ�����Ӫ�������ɺܶ�ܶ���顣ÿ�����鶼���ض��ľ�Ӫ������֮�䲻�ύ�����档ÿ�����鶼����������һ����὾�Ӫ�ڡ���὾�Ӫֻ��������ȼ�40-60����Ҳſ��Խ��롣\n"ESC"�����὾�Ӫ\ntalk %x# welcome.3\n"ESC"�뿪",id,));
        	break; 
        case 3:        	
        	if (level>60 && !who->get_vip())
        	{
        		item = present("����֥��", who, 1, MAX_CARRY);
        	}
        	
		if ( who->get_level() < 40 || (who->get_level() > 60 && !item && !who->get_vip()) )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ����ȼ�40-60����ҿ��Խ����὾�Ӫ������60���������Ҫʹ�ÿ���֥����ܽ��롣\n"));
			return ;	
		}     
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��὾�Ӫֻ������ӽ��롣\n"));
			return;
		}
		if (level>60 && !who->get_vip() && item)
		{
			send_user( who, "%c%c%s", 0x59, 1, sprintf("����ͨ��"HIR"����֥��"NOR"�����὾�Ӫ������\n"
	                        ESC "%c\n"ESC"talk %x# welcome.4\n"
				, 1, getoid(me) ) );				
			return;
		}   	       	        	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_BARRACK);
        		if ( !map )	//��������
        		{
        			map = "sys/copy/barrack"->new_copy(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance");
//        		who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "�����С���");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;
        case 4:        	
        	item = present("����֥��", who, 1, MAX_CARRY);        	
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ����ȼ�40-60����ҿ��Խ����὾�Ӫ������60���������Ҫʹ�ÿ���֥����ܽ��롣\n"));
			return ;	
		}     
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("���潫����\n    ��὾�Ӫֻ������ӽ��롣\n"));
			return;
		}
		legend = sprintf("���븱��ʹ�� %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);
		item->remove_from_user();
		destruct(item);	       	        	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_BARRACK);
        		if ( !map )	//��������
        		{
        			map = "sys/copy/barrack"->new_copy(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance");
//        		who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 6, "�����С���");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 6);
        	}
		break;		
	}
}


