
string get_time_string( int time );

// �����������
int main( object me, string arg )
{
        int time = gone_time( me->get_login_time() );
        string abc = "12345";
        if ( arg )
        {
        	tell_user( me, "����ʱ�䣺%s��", short_time( to_int(arg) ) );	
        	return 1;
        }

        tell_user( me, "����ʱ�䣺%s��", short_time( time() ) );
        tell_user( me, GAME_NAME "�Ѿ�����%s��", get_time_string( uptime() ) );
        tell_user( me, "����" GAME_NAME "�зܶ���%s������%s��",
                get_time_string( me->get_game_time() + time ), get_time_string( me->get_online_time() ) );
	if (me->get_double_time()-time-me->get_game_time()>0)
		tell_user( me, "����˫������ʱ�仹ʣ %d �롣",  me->get_double_time()-time-me->get_game_time() );
        tell_user( me, "�������գ�%s��" ,short_time( me->get_birthday() ) );
        return 1;
}

// ��������ȡʱ���ִ�
string get_time_string( int time )
{
        int day, hour, min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;   time /= 60;
        hour = time % 24;  time /= 24;
        day = time;

        if( day ) result += sprintf( " %d ��", day );
        if( hour ) result += sprintf( " %d ʱ", hour );
        if( min ) result += sprintf( " %d ��", min );
        result += sprintf( " %d ��", sec );

        return result;
}

// ��������ȡʱ���ִ�(���)
string get_time_string_2( int time )
{
        int min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;

        if( min ) result += sprintf( " %d ��", min );
        result += sprintf( " %d ��", sec );

        return result;
}
