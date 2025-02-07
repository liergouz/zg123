
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

	if( !arg ) 
	{
                notify( "您要打死哪个人物？" );
                return 1;
	}

        if( !( who = find_any_char(arg) ) )
        {
                notify( "您无法找到这个人。" );
                return 1;
        }
        if( who == me )
        {
                notify( "您连自己都想打死？" );
		return 1;
        }
        if( !inside_screen_2(me, who) )
        {
                notify( "您离这个人太远了。" );
                return 1;
        }

        tell_user( who, HIR "游戏管理员ＧＭ突然出现在你面前。\n"
                        HIR "ＧＭ说道：“大家都想你死，你就死一回吧！”" );
        tell_user( me, HIR "您大喝一声：“去死吧！”，将" + who->get_name() + "化为一堆灰烬。" );

        CHAR_DIE_D->is_enemy_die( me, who, who->get_hp() );

        return 1;
}
