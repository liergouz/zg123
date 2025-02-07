
#include <ansi.h>

#define DEFAULT_TIME    43200                   // ȱʡ���һ����
#define CHANNEL_LOG     "gm/channel.txt"        // Ƶ��������־

// �����������
int main( object me, string arg )
{
        object who;
        string cmd1, cmd2, cmd3, cmd4, cmd5;
        string id, channel;
        int min, t, n;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
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
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "Ƶ������\n\n������Է������֣ɣģ�\n"
                        ESC "channel %%s %s %d\n", channel, min ) );
                return 1;
        }
        if( !( who = find_player(id) ) ) 
        {
                notify( "���Ҳ�����λ��ҡ�" );
                return 1;
        }
/*        if( !is_player(who) )
        {
                notify( "��ֻ�ܷ����ҵ�Ƶ����" );
                return 1;
        }*/

        if( channel == "?" )
        {
                cmd1 = sprintf( "channel %s all %d\n", id, min );
                cmd2 = sprintf( "channel %s chat %d\n", id, min );
                cmd3 = sprintf( "channel %s rumor %d\n", id, min );
                cmd4 = sprintf( "channel %s vipchat %d\n", id, min );
                cmd5 = sprintf( "channel %s\n", id );
                send_user( me, "%c%s", ':', sprintf( "��Ҫ����%s(%d)�ĸ�Ƶ����\n", who->get_name(), who->get_number() ) +
                        ESC "��������Ƶ����\n" + cmd1 +
                        ESC "������Ƶ����\n" + cmd2 +
                        ESC "����ҥ��Ƶ����\n" + cmd3 +
                        ESC "����VIPƵ����\n" + cmd4 +
                        ESC "�鿴Ƶ����������\n" + cmd5 +
                        ESC "�������롭��\nCLOSE\n" );
                return 1;
        }

        if( min < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, DEFAULT_TIME, sprintf( "���%s(%d)Ƶ����\n\n������Ҫ��յķ�������(0 ��ʾ��Ƶ��)\n"
                        ESC "channel %s %s %%s\n", who->get_name(), who->get_number(), id, channel ) );
                return 1;
        }
        if( min < 0 || min > DEFAULT_TIME ) min = DEFAULT_TIME;

        t = gone_time( who->get_chblk("time") );
        if( !channel || channel == "" )
        {
                if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                        tell_user( me, "%s����Ƶ������� %d �֡�", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "����Ƶ�����򿪡�" );
                if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                        tell_user( me, "%sҥ��Ƶ������� %d �֡�", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "ҥ��Ƶ�����򿪡�" );
                if( ( n = who->get_chblk("vipchat") - t ) > 0 ) 
                        tell_user( me, "%sVIPƵ������� %d �֡�", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "VIPƵ�����򿪡�" );
        } 
        else if( channel == "all" )
        {
                if( min )
                {
                        tell_user( me, "%s����Ƶ������� %d �֡�", who->get_name(), min );
                        who->set_chblk("chat", min * 60 );
                        who->set_chblk("rumor", min * 60 );
                        who->set_chblk("family", min * 60 );
                        who->set_chblk("say", min * 60 );
                        who->set_chblk("city", min * 60 );
                        who->set_chblk("vipchat", min * 60 );
                        who->set_chblk("time", time() );
                        who->set_save("nomail", time()+min*60);
//                      who->save();

//                        CHAT_D->chat_channel( 0, sprintf( HIC "��Ϸ����Ա�ǣͷ��%s(%d)������Ƶ�� %d ���ӡ�", 
//                                who->get_name(), who->get_number(), min ) );
//                        CHAT_D->rumor_channel( 0, sprintf( HIM "��Ϸ����Ա�ǣͷ��%s(%d)��ҥ��Ƶ�� %d ���ӡ�", 
//                                who->get_name(), who->get_number(), min ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s ��� %s(%d)%s ��ȫ��Ƶ�� %d ���ӡ�(�ǣ�)\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id(), min ) );
                }
                else
                {
                        tell_user( me, who->get_name() + "����Ƶ���Ѵ򿪡�" );
                        who->delete_chblk("chat");
                        who->delete_chblk("rumor");
                        who->delete_chblk("say");
                        who->delete_chblk("city");
                        who->delete_chblk("family");
                        who->delete_chblk("vipchat");
                        who->delete_chblk("time");
                        who->set_save("nomail", 0);
//                      who->save();

//                        CHAT_D->chat_channel( 0, sprintf( HIC "��Ϸ����Ա�ǣʹ�%s(%d)������Ƶ����", 
//                              who->get_name(), who->get_number() ) );
//                        CHAT_D->rumor_channel( 0, sprintf( HIM "��Ϸ����Ա�ǣʹ�%s(%d)��ҥ��Ƶ����", 
//                                who->get_name(), who->get_number() ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s �� %s(%d)%s ��ȫ��Ƶ����(�ǣ�)\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id() ) );
                }
        }
        else if( channel == "chat" )
        {
                if( min )
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
                                }
                                if( who->get_chblk("vipchat") )
                                {
                                        if( who->add_chblk("vipchat", -t ) < 1 ) 
                                                who->delete_chblk("vipchat");
                                }
                                who->set_chblk("chat", min * 60 );
                                who->set_chblk("time", time() );

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s ��� %s(%d)%s �� chat Ƶ�� %d ���ӡ�(�ǣ�)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id(), min ) );
                        }
                }
                else
                {
                        if( !who->get_chblk("chat") ) 
                                tell_user( me, who->get_name() + "����Ƶ���Ѵ򿪡�" );
                        else 
                        {
                                tell_user( me, who->get_name() + "����Ƶ���Ѵ򿪡�" );
                                who->delete_chblk("chat");

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s �� %s(%d)%s �� chat Ƶ����(�ǣ�)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id() ) );
                        }
                }
        }
        else if( channel == "rumor" )
        {
                if( min )
                {
                        if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                                tell_user( me, "%sҥ��Ƶ���Ѿ������ %d �֡�", who->get_name(), n / 60 + 1 );
                        else 
                        {
                                tell_user( me, "%sҥ��Ƶ������� %d �֡�", who->get_name(), min );
                                if( who->get_chblk("chat") )
                                {
                                        if( who->add_chblk("chat", -t ) < 1 ) 
                                                who->delete_chblk("chat");;
                                }
                                if( who->get_chblk("vipchat") )
                                {
                                        if( who->add_chblk("vipchat", -t ) < 1 ) 
                                                who->delete_chblk("vipchat");
                                }
                                who->set_chblk("rumor", min * 60 );
                                who->set_chblk("time", time() );
//                              who->save();

//                                CHAT_D->rumor_channel( 0, sprintf( HIM "��Ϸ����Ա�ǣͷ��%s(%d)��ҥ��Ƶ�� %d ���ӡ�", 
//                                        who->get_name(), who->get_number(), min ) );
                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s ��� %s(%d)%s �� rumor Ƶ�� %d ���ӡ�(�ǣ�)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id(), min ) );
                        }
                }
                else
                {
                        if( !who->get_chblk("rumor") ) 
                                tell_user( me, who->get_name() + "ҥ��Ƶ���Ѵ򿪡�" );
                        else 
                        {
                                tell_user( me, who->get_name() + "ҥ��Ƶ���Ѵ򿪡�" );
                                who->delete_chblk("rumor");

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s �� %s(%d)%s �� rumor Ƶ����(�ǣ�)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id() ) );
                        }
                }
        }
        else if(channel == "vipchat")
        {
        	if( min )
                {
                        if( ( n = who->get_chblk("vipchat") - t ) > 0 ) 
                                tell_user( me, "%sVIPƵ���Ѿ������ %d �֡�", who->get_name(), n / 60 + 1 );
                        else 
                        {
                                tell_user( me, "%sVIPƵ������� %d �֡�", who->get_name(), min );
                                if( who->get_chblk("chat") )
                                {
                                        if( who->add_chblk("chat", -t ) < 1 ) 
                                                who->delete_chblk("chat");
                                }
                                if( who->get_chblk("rumor") )
                                {
                                        if( who->add_chblk("rumor", -t ) < 1 ) 
                                                who->delete_chblk("rumor");
                                }
                                who->set_chblk("vipchat", min * 60 );
                                who->set_chblk("time", time() );

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s ��� %s(%d)%s �� vipchat Ƶ�� %d ���ӡ�(�ǣ�)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id(), min ) );
                        }
                }
                else
                {
                        if( !who->get_chblk("vipchat") ) 
                                tell_user( me, who->get_name() + "VIPƵ���Ѵ򿪡�" );
                        else 
                        {
                                tell_user( me, who->get_name() + "VIPƵ���Ѵ򿪡�" );
                                who->delete_chblk("vipchat");

                                log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s �� %s(%d)%s �� VIP Ƶ����(�ǣ�)\n", 
                                        short_time(), me->get_name(), me->get_number(), me->get_id(),
                                        who->get_name(), who->get_number(), who->get_id() ) );
                        }
                }
        }
        else 
        {
                notify( "���ܷ�յ�Ƶ���У�chat, rumor,vipchat" );
		return 1;
        }

        return 1;
}
