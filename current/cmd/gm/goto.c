
#include <effect.h>

// �����������
int main( object me, string arg )
{
        object who;
        int z, x, y, x0, y0, p;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg )
        {
                tell_user( me, "�������ڣ�%d (%d, %d)", get_z(me), get_x(me), get_y(me) );
		return 1;
        }

        if( sscanf( arg, "%d,%d", x0, y0 ) == 2 )
        {
                z = get_z(me);
        }
        else if( !(who = find_any_char(arg) ) )
        {
                notify( "���޷��ҵ�����ˡ�" );
		return 1;
        }
        else if( who == me )
        {
                notify( "������ȥ�Լ����" );
		return 1;
        }
        else
        {
                z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
        }

        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
        {
                x = p / 1000;  y = p % 1000;

                me->set_login_flag(2);    // ��ת����
                set_invisible(me, 1);
                set_effect(me, EFFECT_USER_LOGIN, 4);

                me->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );

                tell_user( me, "��ȥ��: %d (%d, %d)��", z, x, y );
		return 1;
        }
        else 
        {
        	if (who)
                	notify( "��ȥ����%s���", who->get_name() );
                else
                	notify( "��ȥ�������" );
		return 1;
        }
}
