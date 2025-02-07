#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0450; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// ���������촦��
void create()
{
	object me=this_object();
        set_name("�����Ŀ���");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        set_head_color(0x39eb);
        setup();
}

void do_look(object who)
{
	int id,level;
	object me=this_object();

	id = getoid(me);
	level = who->get_level();
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "����ϵͳ��δ���ţ�");
		return;
	}  	
	if ( level > 70 && !who->get_vip() )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ����ɽ��Ĺ�Ĺ�����ֱ�����磬����ǧ������������˳����ˡ��ҷ���һ��Ҫ����Щ�п�ļ๤�Ǳ������������ȥ��ɽ��Ĺ����Щ�๤�Ĳ�Ļ����ҿ��Ը�����·��������һ��Ҫ�����Ұ�ȫŶ��\n"ESC"ʹ�ÿ���֥�������ɽ��Ĺ\ntalk %x# welcome.85\n"ESC"��ɽ��Ĺ��ʲô�ط���\ntalk %x# welcome.47\n"ESC"�������\ntalk %x# welcome.109\n"ESC"�뿪",id,id,id));
	else		
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ����ɽ��Ĺ�Ĺ�����ֱ�����磬����ǧ������������˳����ˡ��ҷ���һ��Ҫ����Щ�п�ļ๤�Ǳ������������ȥ��ɽ��Ĺ����Щ�๤�Ĳ�Ļ����ҿ��Ը�����·��������һ��Ҫ�����Ұ�ȫŶ��\n"ESC"������ɽ��Ĺ\ntalk %x# welcome.72\n"ESC"��ɽ��Ĺ��ʲô�ط���\ntalk %x# welcome.47\n"ESC"�������\ntalk %x# welcome.109\n"ESC"�뿪",id,id,id));
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
        case 47:
        	if ( level > 70 && !who->get_vip() )
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ��ɽ��Ĺ��һ������ĵط��������кܶ�����ȴ����ȥ̽�����кܶ�߼�����ȴ����ȥ��ս����˵����Ĺ�������ܶ༫Ʒ��װ���أ�\n"ESC"�������\ntalk %x# welcome.109\n"ESC"ʹ�ÿ���֥�������ɽ��Ĺ\ntalk %x# welcome.85\n"ESC"�뿪",id,id,));
        	else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ��ɽ��Ĺ��һ������ĵط��������кܶ�����ȴ����ȥ̽�����кܶ�߼�����ȴ����ȥ��ս����˵����Ĺ�������ܶ༫Ʒ��װ���أ�\n"ESC"�������\ntalk %x# welcome.109\n"ESC"������ɽ��Ĺ\ntalk %x# welcome.72\n"ESC"�뿪",id,id,));
        	break;
        case 109:
        	if ( (level >=50 && level <= 70) || (level>70&&who->get_vip()) )
        		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ��ұ����Ƕ������ʽ������ɽ��Ĺ����ɽ��Ĺֻ������"HIR"5λ"NOR"ͬ�������ҡ�����Ĺ�������ɺܶ�ܶ���顣ÿ�����鶼���ض�����Ĺ������֮�䲻�ύ�����档ÿ�����鶼����������һ����ɽ��Ĺ�ڡ���ɽ��Ĺֻ��������"HIR"�ȼ�50-70�����"NOR"�ſ��Խ��롣\n"ESC"������ɽ��Ĺ\ntalk %x# welcome.72\n"ESC"�뿪",id,));
		else
        		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"�����Ŀ��ۣ�\n    ��ұ����Ƕ������ʽ������ɽ��Ĺ����ɽ��Ĺֻ������"HIR"5λ"NOR"ͬ�������ҡ�����Ĺ�������ɺܶ�ܶ���顣ÿ�����鶼���ض�����Ĺ������֮�䲻�ύ�����档ÿ�����鶼����������һ����ɽ��Ĺ�ڡ���ɽ��Ĺֻ��������"HIR"�ȼ�50-70�����"NOR"�ſ��Խ��롣\n"ESC"�뿪");
        	break; 
        case 72:
        	if ( level <50 || (level > 70 && !who->get_vip()) )
        	{
        		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),"�����Ŀ��ۣ�\n    ��ұ����Ƕ������ʽ������ɽ��Ĺ����ɽ��Ĺֻ������"HIR"5λ"NOR"ͬ�������ҡ�����Ĺ�������ɺܶ�ܶ���顣ÿ�����鶼���ض�����Ĺ������֮�䲻�ύ�����档ÿ�����鶼����������һ����ɽ��Ĺ�ڡ���ɽ��Ĺֻ��������"HIR"�ȼ�50-70�����"NOR"�ſ��Խ��롣\n"ESC"�뿪");
			return ;	
		}  
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ��ɽ��Ĺ�ļ๤�Ǻ������������Ҫ��ȥ��ɽ��Ĺ��ѵ��Щ�๤���������Щ�������ٽ�����ɽ��Ĺ��\n"));
			return;
		}
 	       	        	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB1);
        		if ( !map )	//��������
        		{
        			map = "sys/copy/tomb"->new_copy_tomb1(me,who);
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
	case 85:
		if ( level <= 70 || (level>70&&who->get_vip()) )
			return ;
		item = present("����֥��", who, 1, MAX_CARRY);
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ����ȼ�50-70����ҿ��Խ�����ɽ��Ĺ������70���������Ҫʹ�ÿ���֥����ܽ��롣\n"));
			return ;	
		}
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ��ɽ��Ĺ�ļ๤�Ǻ������������Ҫ��ȥ��ɽ��Ĺ��ѵ��Щ�๤���������Щ�������ٽ�����ɽ��Ĺ��\n"));
			return;
		} 
		send_user( who, "%c%c%s", 0x59, 1, sprintf("����ͨ��"HIR"����֥��"NOR"������ɽ��Ĺ������\n"
                        ESC "%c\n"ESC"talk %x# welcome.95\n"
			, 1, getoid(me) ) );				
		break;
	case 95:
		if ( level <= 70 || (level>70&&who->get_vip()) )
			return ;
		item = present("����֥��", who, 1, MAX_CARRY);
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ����ȼ�50-70����ҿ��Խ�����ɽ��Ĺ������70���������Ҫʹ�ÿ���֥����ܽ��롣\n"));
			return ;	
		} 
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("�����Ŀ��ۣ�\n    ��ɽ��Ĺ�ļ๤�Ǻ������������Ҫ��ȥ��ɽ��Ĺ��ѵ��Щ�๤���������Щ�������ٽ�����ɽ��Ĺ��\n"));
			return;
		}
		legend = sprintf("���븱��ʹ�� %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);
		item->remove_from_user();
		destruct(item);	
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_TOMB1);
        		if ( !map )	//��������
        		{
        			map = "sys/copy/tomb"->new_copy_tomb1(me,who);
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


