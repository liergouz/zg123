
#include <ansi.h>

#define DEFAULT_TIME    10080                   // 缺省封闭一周
#define CHANNEL_LOG     "gm/channel.txt"        // 频道管理日志

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string cmd1, cmd2, cmd3;
        string id, channel;
        int min, t, n;

        if( is_player(me) && !me->get_save("channel_manager") ) 
        {
                notify( "您不是频道管理员。" );
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
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "封闭频道。\n\n请输入对方的数字ＩＤ：\n"
                        ESC "shutup %%s %s %d\n", channel, min ) );
                return 1;
        }
        if( !( who = find_player(id) ) ) 
        {
                notify( "您找不到这位玩家。" );
                return 1;
        }
        if( !is_player(who) )
        {
                notify( "您只能封闭玩家的频道。" );
                return 1;
        }
        if( who->get_save("channel_manager") ) 
        {
                notify( "对方是频道管理员。" );
		return 1;
        }

        if( channel == "?" )
        {
                cmd1 = sprintf( "shutup %s chat %d\n", id, min );
                cmd2 = sprintf( "shutup %s rumor %d\n", id, min );
                cmd3 = sprintf( "shutup %s\n", id );
                send_user( me, "%c%s", ':', sprintf( "您要封闭%s(%d)哪个频道？\n", who->get_name(), who->get_number() ) +
                        ESC "封闭公众频道。\n" + cmd1 +
                        ESC "封闭谣言频道。\n" + cmd2 +
                        ESC "查看频道封闭情况。\n" + cmd3 +
                        ESC "我再想想……\nCLOSE\n" );
                return 1;
        }

        if( min < 0 )
        {
                send_user( me, "%c%c%d%s", '?', 1, DEFAULT_TIME, sprintf( "封闭%s(%d)频道。\n\n请输入要封闭的分钟数：\n"
                        ESC "shutup %s %s %%s\n", who->get_name(), who->get_number(), id, channel ) );
                return 1;
        }
        if( min < 1 || min > DEFAULT_TIME ) min = DEFAULT_TIME;

        t = gone_time( who->get_chblk("time") );
        if( !channel || channel == "" ) 
        {
                if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                        tell_user( me, "%s公众频道被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "公众频道：打开。" );
                if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                        tell_user( me, "%s谣言频道被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else    tell_user( me, who->get_name() + "谣言频道：打开。" );
        } 
        else if( channel == "chat" )
        {
                if( ( n = who->get_chblk("chat") - t ) > 0 ) 
                        tell_user( me, "%s公众频道已经被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else 
                {
                        tell_user( me, "%s公众频道被封闭 %d 分。", who->get_name(), min );
                        if( who->get_chblk("rumor") )
                        {
                                if( who->add_chblk("rumor", -t ) < 1 ) 
                                        who->delete_chblk("rumor");
//                              else    who->set_chblk("time", time() );
                        }
                        who->set_chblk("chat", min * 60 );
                        who->set_chblk("time", time() );
//                      who->save();

                        CHAT_D->chat_channel( 0, sprintf( HIC "管理员%s(%d)封闭%s(%d)的公众频道 %d 分钟。", 
                                me->get_name(), me->get_number(), who->get_name(), who->get_number(), min ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 封闭 %s(%d)%s 的 chat 频道 %d 分钟。\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id(), min ) );
                }
        }
        else if( channel == "rumor" )
        {
                if( ( n = who->get_chblk("rumor") - t ) > 0 ) 
                        tell_user( me, "%s谣言频道已经被封闭 %d 分。", who->get_name(), n / 60 + 1 );
                else 
                {
                        tell_user( me, "%s谣言频道被封闭 %d 分。", who->get_name(), min );
                        if( who->get_chblk("chat") )
                        {
                                if( who->add_chblk("chat", -t ) < 1 ) 
                                        who->delete_chblk("chat");
//                              else    who->set_chblk("time", time() );
                        }
                        who->set_chblk("rumor", min * 60 );
                        who->set_chblk("time", time() );
//                      who->save();

//                        CHAT_D->rumor_channel( 0, sprintf( HIM "管理员%s(%d)封闭%s(%d)的谣言频道 %d 分钟。", 
//                                me->get_name(), me->get_number(), who->get_name(), who->get_number(), min ) );
                        log_file( CHANNEL_LOG, sprintf("%s %s(%d)%s 封闭 %s(%d)%s 的 rumor 频道 %d 分钟。\n", 
                                short_time(), me->get_name(), me->get_number(), me->get_id(),
                                who->get_name(), who->get_number(), who->get_id(), min ) );
                }
        }
        else 
        {
                notify( "您能封闭的频道有：chat, rumor" );
		return 1;
        }

        return 1;
}
