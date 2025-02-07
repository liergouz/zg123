//用来设置游戏时间，供某些活动测试用
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
	int year,mon,day,hour,min,sec;
	string tmp;
	
        if( !is_gm2(me) && !is_god(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }
        if ( !arg )
        {
        	tell_user(me,"游戏的活动时间是：%s",short_time(get_party_time()));
        	tell_user(me,"设置的指令格式是：/set_party_time 年-月-日 时:分:秒");
        	return 1;	
        }
	if ( sscanf(arg,"%d-%d-%d %d:%d:%d",year,mon,day,hour,min,sec) != 6 )
	{
		send_user(me,"%c%s",'!',"错误的格式");
        	tell_user(me,"游戏的活动时间是：%s",short_time(get_party_time()));
        	tell_user(me,"设置的指令格式是：/set_party_time 年-月-日 时:分:秒");
		return 1;
	}
	tell_user(me,"游戏的活动时间设置为：%s",short_time(set_party_time(year,mon,day,hour,min,sec)));
	return 1;
	
}