
// 函数：命令处理
int main( object me, string arg )
{
        object item;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

	if( !arg ) 
	{
                notify( "您要将哪样东西变成蓝色？" );
                return 1;
	}

        if( !( item = find_any_object(arg) ) )
        {
                notify( "无法找到这样东西。" );
                return 1;
        }
        if( item == me )
        {
                notify( "您连自己都想清除？" );
		return 1;
        }
        if (item->get_equip_type()==0)
	{
                notify( "只能将装备变成蓝色" );
                return 1;
	}
	
        tell_user( me, "您将%s变成蓝色装备。", item->get_name() );

        "/sys/item/equip"->init_equip_prop_1(item);
        send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

        return 1;
}
