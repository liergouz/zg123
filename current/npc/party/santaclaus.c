#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#define CHRISTMAS "sys/party/christmas"

inherit OFFICER;
int iStart,iFinish;

// ��������ȡ��������
int get_char_picid() { return 9972; }
void do_welcome(string arg);
// ���������촦��
void create()
{
        set_name("ʥ������");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );

        setup();
	iStart = mktime(2007,1,4,0,0,0);	
	iFinish = mktime(2007,2,8,0,0,0);	

}

void do_look(object who)
{
        object me = this_object();
        
        if ( time() > iFinish )
        {
        	me->remove_from_scene();	
        	destruct(me);
        	return ;
        }
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �ǡ��ǡ��ǡ��ǡ�����Ȼʥ�����Ѿ���ȥ�ˣ�����Ϊרҵ��ʥ�������ҿɲ��ܾ��������š�Ϊ�˸�л��ҶԴ�ս�����Թ�����֧�֣�ֻҪ��ĵȼ��ﵽ50�����ϣ��ӱ���4�յ�7�����ʱ���ڵ�������������ȡ�������\n"ESC"���ҾͲ�������������\ntalk %x# welcome.4\n"ESC"�һ����´�����ȡ�ɡ�",me->get_name(),getoid(me)));
//	CHRISTMAS->do_look(this_object(),who);
}


void do_welcome( string arg )
{
        object me = this_object();
        CHRISTMAS->do_welcome(me, arg);
}
