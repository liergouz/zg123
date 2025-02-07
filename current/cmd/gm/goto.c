
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        int z, x, y, x0, y0, p;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arg )
        {
                tell_user( me, "您现在在：%d (%d, %d)", get_z(me), get_x(me), get_y(me) );
		return 1;
        }

        if( sscanf( arg, "%d,%d", x0, y0 ) == 2 )
        {
                z = get_z(me);
        }
        else if( !(who = find_any_char(arg) ) )
        {
                notify( "您无法找到这个人。" );
		return 1;
        }
        else if( who == me )
        {
                notify( "您不能去自己那里。" );
		return 1;
        }
        else
        {
                z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
        }

        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
        {
                x = p / 1000;  y = p % 1000;

                me->set_login_flag(2);    // 跳转保护
                set_invisible(me, 1);
                set_effect(me, EFFECT_USER_LOGIN, 4);

                me->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );

                tell_user( me, "您去到: %d (%d, %d)。", z, x, y );
		return 1;
        }
        else 
        {
        	if (who)
                	notify( "您去不了%s那里。", who->get_name() );
                else
                	notify( "您去不了那里。" );
		return 1;
        }
}
