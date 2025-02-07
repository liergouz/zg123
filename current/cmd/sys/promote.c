
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string cmd1, cmd2, cmd3;
        string id, class0, class1;

        if( me != this_player(1) || !is_god(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arg || sscanf( arg, "%s %s", id, class1 ) != 2 )
        {
                id = "?";  class1 = "?";
        }

        if( id == "?" )
        {
                send_user( me, "%c%c%d%s", '?', 1, 0, sprintf( "警告！用户权限管理。\n\n请输入对方的数字ＩＤ：\n"
                        ESC "promote %%s %s\n", class1 ) );
                return 1;
        }
        if( !( who = find_player(id) ) ) 
        {
                notify( "您找不到这位玩家。" );
                return 1;
        }
        if( !inside_screen_2(me, who) )
        {
                notify( "您离这个人太远了。" );
		return 1;
        }

        if( class1 == "?" )
        {
                cmd1 = sprintf( "promote %s (gm2)\n", id );
                cmd2 = sprintf( "promote %s (gm)\n", id );
                cmd3 = sprintf( "promote %s (player)\n", id );
                send_user( me, "%c%s", ':', sprintf( "警告！用户权限管理。\n\n您想把%s(%d)设为哪种等级？\n", who->get_name(), who->get_number() ) +
                        ESC "测试号等级。(gm2)\n" + cmd1 +
                        ESC "ＧＭ等级。(gm)\n" + cmd2 +
                        ESC "玩家等级。(player)\n" + cmd3 +
                        ESC "我再想想……\nCLOSE\n" );
                return 1;
        }

        if( class1 != PLAYER_CLASS && class1 != GM_CLASS && class1 != GOD_CLASS && class1 != GM2_CLASS ) 
        {
                notify( "系统没有这种级别。" );
		return 1;
        }

        class0 = get_class(who);

        if( !CLASS_D->set_class(me, who, class1) ) 
        {
                notify( "提升用户等级失败！" );
		return 1;
        }

    	tell_user( me, HIY "您将%s(%s)的等级从 %s 改为 %s。", who->get_name(), who->get_id(), class0, class1 );
    	tell_user( who, HIY "%s(%d)将您的等级从 %s 改为 %s。", me->get_name(), me->get_number(), class0, class1 );
        who->setup();

        return 1;
}
