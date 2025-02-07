
string get_time_string( int time );

// 函数：命令处理
int main( object me, string arg )
{
        int time = gone_time( me->get_login_time() );
        string abc = "12345";
        if ( arg )
        {
        	tell_user( me, "输入时间：%s。", short_time( to_int(arg) ) );	
        	return 1;
        }

        tell_user( me, "现在时间：%s。", short_time( time() ) );
        tell_user( me, GAME_NAME "已经运行%s。", get_time_string( uptime() ) );
        tell_user( me, "您在" GAME_NAME "中奋斗了%s，沉迷%s。",
                get_time_string( me->get_game_time() + time ), get_time_string( me->get_online_time() ) );
	if (me->get_double_time()-time-me->get_game_time()>0)
		tell_user( me, "您的双倍经验时间还剩 %d 秒。",  me->get_double_time()-time-me->get_game_time() );
        tell_user( me, "您的生日：%s。" ,short_time( me->get_birthday() ) );
        return 1;
}

// 函数：获取时间字串
string get_time_string( int time )
{
        int day, hour, min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;   time /= 60;
        hour = time % 24;  time /= 24;
        day = time;

        if( day ) result += sprintf( " %d 天", day );
        if( hour ) result += sprintf( " %d 时", hour );
        if( min ) result += sprintf( " %d 分", min );
        result += sprintf( " %d 秒", sec );

        return result;
}

// 函数：获取时间字串(简短)
string get_time_string_2( int time )
{
        int min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;

        if( min ) result += sprintf( " %d 分", min );
        result += sprintf( " %d 秒", sec );

        return result;
}
