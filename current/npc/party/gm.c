
#include <npc.h>
#include <ansi.h>
#include <map.h>
#include <task.h>

inherit OFFICER;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 5201; } 

// ���������촦��
void create()
{
        set_name( "�ǣ�" );  
        setup();     
}

void do_look( object who )
{
        int status;
        int time;
        string result;
        object me = this_object();
        time = "/cmd/gm/findgm"->get_save("gm_time");
        if (who->get_save("findgm")==time)
        {
	        send_user( who, "%c%c%w%s", ':', 3, 5201,
	        	sprintf("%s��\n    �ҽ���ܸ�л�㣬������λ��ỹ���ø����˰ɡ�\n"
	                , me->get_name() ) );        	
		return;	               
        }
        send_user( who, "%c%c%w%s", ':', 3, 5201,
        	sprintf("%s��\n    �����������ˣ����¸�ѽ����Ҫлл��ľ���֮�����úõ���л�㣡\n"
                , me->get_name() ) );
	who->add_cash(30000);           	
	who->set_save("findgm", time);
	result = sprintf( HIY "%sԮ�ȣǣͳɹ��������30000��Ǯ������", who->get_name() );
	USER_D->user_channel(result);
	me->remove_from_scene();
	destruct(me);
}
