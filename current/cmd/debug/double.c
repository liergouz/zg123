
#include <ansi.h>

string status_color( int num, int max );

// �����������
int main( object me, string arg )
{
        object who;
        string arg2;
        int time, i;

        if( is_player(me) )
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
	if (sscanf(arg, "%s %d", arg2, time)!=2) return 1;
	if (time<0) return 1;
        if( !( who = find_player(arg2) ) )
        {
                notify( "���޷��ҵ������ҡ�" );
		return 1;
        }
	i = gone_time( who->get_login_time() );
	if ( who->get_double_time()< i + who->get_game_time())
	{
		who->set_double_time(i+who->get_game_time()+time*3600);
	}
	else
		who->set_double_time(who->get_double_time()+time*3600);
	send_user( who, "%c%c%c%w%c", 0x51, 1, 1,0001, 0 );
	send_user( who, "%c%c%c%w%w%c", 0x51, 1, 2, 0001, 1, 0 );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);
	if (me==who) tell_user(me, "�����Լ�������%dСʱ��˫��ʱ�䡣", time);
	else
	{
		tell_user(me, "����%s������%dСʱ��˫��ʱ�䡣", who->get_name(), time);
		tell_user(who, "%s����������%dСʱ��˫��ʱ�䡣", me->get_name(), time);
	}
        return 1;
}

