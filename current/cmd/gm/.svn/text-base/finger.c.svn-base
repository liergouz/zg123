
#include <cmd.h>

// 函数：命令处理
int main( object me, string arg )
{
        object *user, char, who = me;
        string *ids = ({ }), id, result;
        int i, size, len, flag;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( arg && !( who = find_player(arg) ) )
        {
                id = strlwr(arg);
/*                
                if( !CHECK_D->is_legal_id(me, id) )
                {
	        	return 1;
                }
*/                
                if( !user_exist(id) )
                {
                        notify( "这个用户并不存在！" );
		        return 1;
                }

                who = new( USER );
                who->set_id(id);
                if( !who->restore() ) 
                {
                        notify( "这个用户并不存在！" );
                        destruct(who);  return 1;
                }

                if( char = find_player( sprintf( "%d", who->get_number() ) ) )
                {
                        destruct(who);
                        who = char;
                }
                else    flag = 1;
        }

        tell_user( me, "用户：%s(%d) - %s  性别：%s\n创建：%s  游龄：%s + %s\n前次：%s  ＩＰ：%s",
                who->get_name(), who->get_number(), who->get_id(), who->get_gender() == 1 ? "男性" : "女性",
                short_time( who->get_birthday() ), TIME_CMD->get_time_string( who->get_game_time() ),
                TIME_CMD->get_time_string( gone_time( who->get_login_time() ) ),
                short_time( who->get_quit_time() ), who->get_quit_ip() );

        if( !flag ) 
        {
                result = get_ip_name(who);
                tell_user( me, "现在：%s  ＩＰ：%s  发呆：%d 秒 account：%d", 
                        short_time( who->get_login_time() ), get_ip_name(who), get_idle(who), who->get_acountid() );
        }
        else
        {
                result = who->get_quit_ip();
                destruct(who);
        }

        if( !result || result == "" || result == "0" ) return 1;

        user = filter_array( USER_D->get_user(), (: get_ip_name($1) == $2 :), result );
        for( i = 0, size = sizeof(user); i < size; i ++ )
                ids += ({ sprintf( "%s(%d)-%s", user[i]->get_name(), user[i]->get_number(), user[i]->get_id() ) });

        if( size = sizeof(ids) ) 
        {
                result = "相同ＩＰ：\n";
                for( i = 0, len = 0; i < size; i ++ )
                {
                        len += strlen( ids[i] ) + 2;
                        if( len >= OUTPUT_WIDTH )
                        {
                                len = strlen( ids[i] );
                                result = sprintf( "%s\n%s, ", result, ids[i] );
                        }
                        else    result = sprintf( "%s%s, ", result, ids[i] );
                }
                tell_user( me, "\n" + result );
        }

        return 1;
}
