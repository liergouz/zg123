
// 函数：命令处理
int main( object me, string arg )
{
        object *user;
        string result;
        int i, size;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( arrayp( user = USER_D->get_user() ) ) 
        {
                size = sizeof(user);
                result = sprintf( "现在的玩家有%d个：\n", size );               
                if (size<40)
                {
	                for( i = 0; i < size; i ++ ) 
	                        if( user[i] ) result = sprintf( "%s%s%s(%d)、", 
	                                result, i % 8 ? "" : "\n", user[i]->get_name(), user[i]->get_number() );
		}	                                
                tell_user(me, result);
        }
        else    tell_user(me, "现在没有任何玩家。");

        return 1;
}
