
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

	if( !arg ) 
	{
                notify( "��Ҫ�����ĸ����" );
                return 1;
	}

        if( !( who = find_any_char(arg) ) )
        {
                notify( "���޷��ҵ�����ˡ�" );
                return 1;
        }
        if( who == me )
        {
                notify( "�����Լ����������" );
		return 1;
        }
        if( !inside_screen_2(me, who) )
        {
                notify( "���������̫Զ�ˡ�" );
                return 1;
        }

        tell_user( who, HIR "��Ϸ����Ա�ǣ�ͻȻ����������ǰ��\n"
                        HIR "�ǣ�˵��������Ҷ��������������һ�ذɣ���" );
        tell_user( me, HIR "�����һ������ȥ���ɣ�������" + who->get_name() + "��Ϊһ�ѻҽ���" );

        CHAR_DIE_D->is_enemy_die( me, who, who->get_hp() );

        return 1;
}
