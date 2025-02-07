
#include <ansi.h>

#define DEFAULT_TIME    10080                   // ȱʡ���һ��
#define CHANNEL_LOG     "gm/channel.txt"        // Ƶ��������־

// �����������
int main( object me, string arg )
{
        object who;
        string cmd1, cmd2, cmd3;
        string id, channel;
        int min, t, n;

        if( is_player(me) && !me->get_save("channel_manager") ) 
        {
                notify( "������Ƶ������Ա��" );
		return 1;
        }

        if( !arg )
        {
                id = "?";  channel = "?";  min = -1;
        }
        else if( sscanf( arg, "%s %s %d", id, channel, min ) != 3 )
	{
                min = DEFAULT_TIME;
                if( sscanf( arg, "%s %s", id, channel ) != 2 )
                {
                        id = arg;  channel = "";
                }
	}

        if( id == "?" )
        {
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "���Ƶ����\n\n������Է������֣ɣģ�\n"
                        ESC "shutup %%s %s %d\n", channel, min ) );
                return 1;
        }
        if( !( who = find_player(id) ) ) 
        {
                notify( "���Ҳ�����λ��ҡ�" );
                return 1;
        }
        if( !is_player(who) )
        {
                notify( "��ֻ�ܷ����ҵ�Ƶ����" );
                return 1;
        }
        if( who->get_save("channel_manager") ) 
        {
                notify( "�Է���Ƶ������Ա��" );
		return 1;
        }

        if( channel == "?" )
        {
                cmd1 = sprintf( "shutup %s chat %d\n", id, min );
                cmd2 = sprintf( "shutup %s rumor %d\n", id, min );
                cmd3 = sprintf( "shutup %s\n", id );
                send_user( me, "%c%s", ':', sprintf( "��Ҫ���%s(%d)�ĸ�Ƶ����\n", who->get_name(), who->get_number() ) +
                        ESC "��չ���Ƶ����\n" + cmd1 +
                        ESC "���ҥ��Ƶ����\n" + cmd2 +
                        ESC "�鿴Ƶ����������\n" + cmd3 +
                        ESC "�������롭��\nCLOSE\n" );
                return 1;
        }

        if( min < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, DEFAULT_TIME, sprintf( "���%s(%d)Ƶ����\n\n������Ҫ��յķ�������\n"
                        ESC "shutup %s %s %%s\n", who->get_name(), who->get_number(), id, channel ) );
                return 1;
        }
        if( min < 1 || min > DEFAULT_TIME ) min = DEFAULT_TIME;

        t = gone_time( who->get_chblk("time") );
        if( !channel || channel == "" ) 
        {
                if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                        tell_user( me, "%s����Ƶ������� %d �֡�", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "����Ƶ�����򿪡�" );
                if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                        tell_user( me, "%sҥ��Ƶ������� %d �֡�", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "ҥ��Ƶ�����򿪡�" );
        } 
        else if( channel == "chat" )
        {
                if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                        tell_user( me, "%s����Ƶ���Ѿ������ %d �֡�", who->get_name(), n / 60 + 1 );
                else 
                {
                        tell_user( me, "%s����Ƶ������� %d �֡�", who->get_name(), min );
                        if( who->get_chblk("rumor") )
                        {
                                if( who->add_chblk("rumor", -t ) < 1 ) 
                                        who->delete_chblk("rumor");
//                              else    who->set_chblk("time", time() );
                        }
                        who->set_chblk("chat", min * 60 );
                        who->set_chblk("time", time() );
//                      who->save();

                        CHAT_D->chat_channel( 0, sprintf( HIC "����Ա%s(%d)���%s(%d)�Ĺ���Ƶ�� %d ���ӡ�", 
                                me->get_name(), me->get_number(), who->get_name(), who->get_number(), min ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s ��� %s(%d)%s �� chat Ƶ�� %d ���ӡ�\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id(), min ) );
                }
        }
        else if( channel == "rumor" )
        {
                if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                        tell_user( me, "%sҥ��Ƶ���Ѿ������ %d �֡�", who->get_name(), n / 60 + 1 );
                else 
                {
                        tell_user( me, "%sҥ��Ƶ������� %d �֡�", who->get_name(), min );
                        if( who->get_chblk("chat") )
                        {
                                if( who->add_chblk("chat", -t ) < 1 ) 
                                        who->delete_chblk("chat");
//                              else    who->set_chblk("time", time() );
                        }
                        who->set_chblk("rumor", min * 60 );
                        who->set_chblk("time", time() );
//                      who->save();

//                        CHAT_D->rumor_channel( 0, sprintf( HIM "����Ա%s(%d)���%s(%d)��ҥ��Ƶ�� %d ���ӡ�", 
//                                me->get_name(), me->get_number(), who->get_name(), who->get_number(), min ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s ��� %s(%d)%s �� rumor Ƶ�� %d ���ӡ�\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id(), min ) );
                }
        }
        else 
        {
                notify( "���ܷ�յ�Ƶ���У�chat, rumor" );
		return 1;
        }

        return 1;
}
