
#include <ansi.h>

// �����������
int main( object me, string arg )
{
        object who;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg ) return 1;

        if( arg=="none" )
        {
                who->set_snooper(0);
                tell_user( me, "��ֹͣ����" );
                return 1;
        }

	if( !arg ) 
	{
                notify( "��Ҫ������λ��ң�" );
                return 1;
	}

        if( !( who = find_player(arg) ) )
        {
                notify( "���޷��ҵ�����ˡ�" );
                return 1;
        }
        who->set_snooper(me);
        tell_user( me, "����ʼ����%s(%d)��", who->get_name(), who->get_number() );


        return 1;
}
