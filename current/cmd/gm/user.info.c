 
// �����������
int main( object me, string arg )
{
        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        tell_user( me, "�û���%d�����ߣ�%d / %d (�ǣͣ�%d����ң�%d)��",
                ID_D->get_max_id(), USER_D->sizeof_user(), sizeof_users(), USER_D->sizeof_gm(), USER_D->sizeof_player() );

	return 1;
}
