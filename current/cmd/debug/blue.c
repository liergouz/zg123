
// �����������
int main( object me, string arg )
{
        object item;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

	if( !arg ) 
	{
                notify( "��Ҫ���������������ɫ��" );
                return 1;
	}

        if( !( item = find_any_object(arg) ) )
        {
                notify( "�޷��ҵ�����������" );
                return 1;
        }
        if( item == me )
        {
                notify( "�����Լ����������" );
		return 1;
        }
        if (item->get_equip_type()==0)
	{
                notify( "ֻ�ܽ�װ�������ɫ" );
                return 1;
	}
	
        tell_user( me, "����%s�����ɫװ����", item->get_name() );

        "/sys/item/equip"->init_equip_prop_1(item);
        send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

        return 1;
}
