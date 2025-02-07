
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
	int time;
        if( me != this_player(1) || is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }
	if (!arg) time = 30;
	else time = to_int(arg);
	if (time==0) time = 30;
        USER_D->user_channel( sprintf(HIR "游戏将在 %d 分钟后关闭。", time) );

        call_out( "do_reboot", 60, time );

        return 1;
}

// 函数：重启处理
private void do_reboot( int min )
{
        remove_call_out( "do_reboot" );

	if( -- min ) 
	{
                USER_D->user_channel( sprintf( HIR "游戏将在 %d 分钟后关闭。", min ) );
		call_out( "do_reboot", 60, min );
	} 
	else 
	{
                USER_D->user_channel( HIR "游戏重新启动，请稍候一分钟再重新登录。" );

                USER_D->save_all_data();    // 保存所有数据

                shutdown(0);
	}
}
