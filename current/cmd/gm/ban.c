
// 函数：命令处理
int main( object me, string arg )
{
        string *ip, site, result;
        int i, size;

        if( me != this_player(1) || is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arg )
        {
                ip = CHECK_D->get_banned_ip();
                result = "封闭ＩＰ：\n";
                for( i = 0, size = sizeof(ip); i < size; i ++ ) result += ip[i] + "\n";
                tell_user(me, result);
        }
        else if( sscanf( arg, "+ %s", site ) == 1 ) 
        {
                if( site[<1] == '*' || site[<1] == '?' || site[<1] == '+' )
                {
                        notify( "不能封闭以 *, +, ? 结尾的ＩＰ。" );
	        	return 1;
                }
                else 
                {
                        CHECK_D->add_banned_ip(site);
                        tell_user( me, "指定ＩＰ已被关闭。" );
                }
        }
        else if( sscanf( arg, "- %s", site ) == 1 ) 
        {
                CHECK_D->remove_banned_ip(site);
                tell_user( me, "取消关闭指定ＩＰ。" );
        }

        return 1;
}
