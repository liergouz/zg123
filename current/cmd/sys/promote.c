
#include <ansi.h>

// �����������
int main( object me, string arg )
{
        object who;
        string cmd1, cmd2, cmd3;
        string id, class0, class1;

        if( me != this_player(1) || !is_god(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg || sscanf( arg, "%s %s", id, class1 ) != 2 )
        {
                id = "?";  class1 = "?";
        }

        if( id == "?" )
        {
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "���棡�û�Ȩ�޹���\n\n������Է������֣ɣģ�\n"
                        ESC "promote %%s %s\n", class1 ) );
                return 1;
        }
        if( !( who = find_player(id) ) ) 
        {
                notify( "���Ҳ�����λ��ҡ�" );
                return 1;
        }
        if( !inside_screen_2(me, who) )
        {
                notify( "���������̫Զ�ˡ�" );
		return 1;
        }

        if( class1 == "?" )
        {
                cmd1 = sprintf( "promote %s (gm2)\n", id );
                cmd2 = sprintf( "promote %s (gm)\n", id );
                cmd3 = sprintf( "promote %s (player)\n", id );
                send_user( me, "%c%s", ':', sprintf( "���棡�û�Ȩ�޹���\n\n�����%s(%d)��Ϊ���ֵȼ���\n", who->get_name(), who->get_number() ) +
                        ESC "���Ժŵȼ���(gm2)\n" + cmd1 +
                        ESC "�ǣ͵ȼ���(gm)\n" + cmd2 +
                        ESC "��ҵȼ���(player)\n" + cmd3 +
                        ESC "�������롭��\nCLOSE\n" );
                return 1;
        }

        if( class1 != PLAYER_CLASS && class1 != GM_CLASS && class1 != GOD_CLASS && class1 != GM2_CLASS ) 
        {
                notify( "ϵͳû�����ּ���" );
		return 1;
        }

        class0 = get_class(who);

        if( !CLASS_D->set_class(me, who, class1) ) 
        {
                notify( "�����û��ȼ�ʧ�ܣ�" );
		return 1;
        }

    	tell_user( me, HIY "����%s(%s)�ĵȼ��� %s ��Ϊ %s��", who->get_name(), who->get_id(), class0, class1 );
    	tell_user( who, HIY "%s(%d)�����ĵȼ��� %s ��Ϊ %s��", me->get_name(), me->get_number(), class0, class1 );
        who->setup();

        return 1;
}
