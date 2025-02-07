
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
	object who;
        int gold, flag;

        if( gone_time( me->get_time("savings") ) < 1 )    // 时间限制
        {
                me->set_time( "savings", time() );
                return 1;
        }
        me->set_time( "savings", time() );

        if( !arg ) return 1;
        else if( sscanf( arg, "+ %s %d", arg, gold ) == 2 ) flag = 2;
        else if( sscanf( arg, "+ %s", arg ) == 1 ) flag = 1;
        else if( sscanf( arg, "- %s %d", arg, gold ) == 2 ) flag = 4;
        else if( sscanf( arg, "- %s", arg ) == 1 ) flag = 3;
        else return 1;

        if( !objectp( who = find_char(arg) ) ) return 1;

        if( !who->is_banker() ) return 1;

        if( !inside_screen_2(me, who) )
        {
                notify( "您距离%s太远了。", who->get_name() );
                return 1;
        }

        me->to_front_eachother(who);

        if( flag == 1 )
        {
                send_user( me, "%c%c%d%s", '?', 1, me->get_cash(), sprintf( "您身上有 %d 现金，请问您打算存多少？\n" 
                        ESC "savings + %x# %%s\n", me->get_cash(), getoid(who) ) );
        }
        else if( flag == 2 )
        {
                if( gold < 1 )
                {
                        notify( "存入现金必须是正整数。" );
                        return 1;
                }
                if( gold > me->get_cash() )
                {
                        notify( "您手上只有 %d 金。", me->get_cash() );
                        return 1;
                }
                if( me->get_savings() + gold > me->get_max_savings() )
                {
                        notify( "您最多能存 %d 万金。", me->get_max_savings() / 10000 );
                        return 1;
                }

                me->add_cash2( -gold );
                me->add_savings(gold);
                notify( "您把 %d 金存入%s处。", gold, who->get_name() );
                write_user( me, ECHO "您把 %d 金存入%s处。", gold, who->get_name() );
        }
        else if( flag == 3 )
        {
                send_user( me, "%c%c%d%s", '?', 1, me->get_savings(), sprintf( "您的存款有 %d 金，请问您打算取多少？\n" 
                        ESC "savings - %x# %%s\n", me->get_savings(), getoid(who) ) );
        }
        else if( flag == 4 )
        {
                if( gold < 1 )
                {
                        notify( "取出存款必须是正整数。" );
                        return 1;
                }
                if( gold > me->get_savings() )
                {
                        notify( "您的存款只有 %d 金。", me->get_savings() );
                        return 1;
                }
                if( me->get_cash() + gold > me->get_max_cash() )
                {
                        notify( "您手上最多能有 %d 万金。", me->get_max_cash() / 10000 );
                        return 1;
                }

                me->add_savings( -gold );
                me->add_cash2(gold);
                notify( "您从%s处取出 %d 金。", who->get_name(), gold );
                write_user( me, ECHO "您从%s处取出 %d 金。", who->get_name(), gold );
        }

        return 1;
}
