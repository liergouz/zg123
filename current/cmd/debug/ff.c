
// �����������
int main( object me, string arg )
{
	object obj;
	string name, func, file;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

	if(     !arg || ( sscanf( arg, "%s of %s", func, name ) != 2
        &&      sscanf( arg, "%s %s", name, func ) != 2 ) ) 
        {
                notify( "��������ĸ�������" );
		return 1;
        }

        if( !( obj = find_any_object(name) ) )
        {
                notify( "�޷��ҵ�����������" );
                return 1;
        }

	if( !( file = function_exists(func, obj) ) )
                tell_user( me, "����: %O\n���� %s() �����ڡ�", obj, func );
	else    tell_user( me, "����: %O\n����: %s.c -> %s()��", obj, file, func );

	return 1;
}
