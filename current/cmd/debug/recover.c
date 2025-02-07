
#include <ansi.h>

#define RECOVER_LOG     "gm/recover.txt"        // 恢复日志文件

// 函数：命令处理
int main( object me, string arg )
{
	object who = me;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "您无法找到这个人。" );
		return 1;
        }

        who->set_hp( who->get_max_hp() );
        who->set_mp( who->get_max_mp() );
        who->set_yuan( who->get_max_yuan() );

        tell_user( me, HIY "%s已经完全恢复。", who->get_name() );
        if( who != me && userp(who) ) 
        {
                write_user( who, HIY "%s使您完全恢复。",  me->get_name() );
                log_file( RECOVER_LOG, sprintf( "%s %s 使 %s(%s)完全恢复。\n", 
                        short_time(), me->get_id(), who->get_name(), who->get_id() ) );
        }

        return 1;
}
