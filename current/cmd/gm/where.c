
// �����������
int main( object me, string arg )
{
        object who = me;
        int time;

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

        tell_user( me, "%s(%s)����: %d (%d, %d) %d", 
                who->get_name(), who->get_id(), get_z(who), get_x(who), get_y(who), get_d(who) );
	time = time() + 8 * 3600;
	tell_user( me, "time=%d /3600=%d mode 24=%d second=%d", time, time/3600, (time/3600) % 24, time % 3600);
        return 1;
}
