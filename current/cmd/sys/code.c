
// �����������
int main( object me, string arg )
{
        int which;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg || arg == "" ) 
        {
                tell_user( me, "��ǰ���ܷ�����%d", get_crypt_code() );
		return 1;        
        }

        which = to_int(arg);
        set_crypt_code(which);

        tell_user( me, "���ü��ܷ�����%d", get_crypt_code() );

    	return 1;
}

int get_crypt_code()
{
	return get_crypt_code();
}

int set_crypt_code(int i)
{
	return set_crypt_code(i);
}