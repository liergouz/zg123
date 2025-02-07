
// 函数：命令处理
int main( object me, string arg )
{
        object item,*inv;
	int i;
        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

	if( !arg ) 
	{
                notify( "您要清除哪样东西？" );
                return 1;
	}

	if( arg == "all") 
	{
		inv = all_inventory(me, 1, MAX_CARRY);
		for (i=0;i<sizeof(inv);i++)
		{
			inv[i]->remove_from_user();
			destruct(inv[i]);
		}
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

        tell_user( me, "您召唤出一个黑洞，将%s吞没了。", item->get_name() );

        if( item->is_char() )
        {
                item->remove_from_scene();
        }
        else if( item->is_item() )
        {
                if( !item->remove_from_user() ) item->remove_from_scene();
        }

        item->before_destruct();
        destruct(item);



        if( item ) 
        {
                notify( "您无法摧毁这玩艺。" );
                return 1;
        }

        return 1;
}
