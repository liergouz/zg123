
#include <ansi.h>

// �����������
int main( object me, string arg )
{
        object *char, who = me;
        int i, size;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "���޷��ҵ�����ˡ�" );
		return 1;
        }

        who->stop_fight();

        char = get_range_object_2(who, 5, CHAR_TYPE) + get_range_object_2(who, 5, USER_TYPE) - ({ who });
        for( i = 0, size = sizeof(char); i < size; i ++ )
                if( char[i] && char[i]->get_enemy() == who ) char[i]->stop_fight();

        if( who == me )
        {
                tell_user( me, HIY "��ǿ����ֹ���漰����ս����" );
        }
        else
        {
                tell_user( me, HIY "��ǿ����ֹ���漰%s��ս����", who->get_name() );
                write_user( who, HIY "%sǿ����ֹ���漰����ս����", me->get_name() );
        }

        return 1;
}
