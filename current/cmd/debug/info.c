
// 函数：命令处理
int main( object me, string arg )
{
        object obj;
        string result;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arg ) 
        {
                notify( "您要列示什么东西？" );
		return 1;
        }

        if( !( obj = find_any_object(arg) ) )
        {
                notify( "无法找到这样东西。" );
                return 1;
        }

        result = sprintf( "对象：%O [%d]\n", obj, sizeof( children( get_file_name(obj) + ".c" ) ) );
        if( obj->is_user() ) 
                result += sprintf( "名称：%s(%d)%x# - %s %s\n", 
                        obj->get_name(), obj->get_number(), getoid(obj), obj->get_id(), get_class(obj) );
        else if( obj->is_npc() )
                result += sprintf( "名称：%s(%x#)\n", obj->get_name(), getoid(obj) );
        else if( obj->is_item() )
                result += sprintf( "名称：%s(%x#)\n", obj->get_name(), getoid(obj) );
        result += sprintf( "内存：%d  连结：%d\n", memory_info(obj), refs(obj) );
        result += "属性："; 
        if( living(obj) )       result += "living ";
        if( userp(obj) )        result += "user ";
        if( interactive(obj) )  result += "interactive ";
        if( !is_player(obj) )   result += "(gm) ";
        if( clonep(obj) )       result += "clone ";
        if( virtualp(obj) )     result += "virtual ";
        if( get_heart_beat(obj) ) result += sprintf("heart[%d,%d/%d,%d]%d (%d) ",    // 注意：get_heart_beat 效率太低
                get_heart_timer(obj), get_heart_count(obj), get_heart_timer_2(obj), get_heart_count_2(obj), 
                get_heart_idle(obj), get_heart_loop(obj) );
	switch(get_heart_state(obj))
	{
	case WALK_STAT:
		result += " WALK_STAT"; break;
	case FIGHT_STAT:
		result += " FIGHT_STAT"; break;
	case FIGHT_STAT_DONE:
		result += " FIGHT_STAT_DONE"; break;
	case MAGIC_STAT:
		result += " MAGIC_STAT"; break;
	case MAGIC_STAT_DONE:
		result += " MAGIC_STAT_DONE"; break;								
	}              

        tell_user(me, result);

        return 1;
}
