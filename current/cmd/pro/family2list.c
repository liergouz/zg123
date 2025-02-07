
#define LIST_LOG        "list.txt"

// 函数：命令处理
int main( object me, string arg )
{
        int level, i, j, size;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        for( i = 0; i <= 7; i ++ )
        {
                log_file( LIST_LOG, sprintf( "\n等级  ＨＰ  ＭＰ  攻击  防御  法攻  法防  躲闪  (第 %d 转)  ", me->get_reincarnation() ) );

                switch( i )
                {
              default : level = 1;  log_file( LIST_LOG, "无门派\n" );  break;
               case 1 : level = 30;  log_file( LIST_LOG, "桃花源\n" );  break;
               case 2 : level = 30;  log_file( LIST_LOG, "蜀山\n" );  break;
               case 3 : level = 30;  log_file( LIST_LOG, "禁卫军\n" );  break;
               case 4 : level = 30;  log_file( LIST_LOG, "唐门\n" );  break;
               case 5 : level = 30;  log_file( LIST_LOG, "茅山\n" );  break;
               case 6 : level = 30;  log_file( LIST_LOG, "昆仑山\n" );  break;
               case 7 : level = 30;  log_file( LIST_LOG, "云梦泽\n" );  break;
                }

                for( j = level; j <= 150; j ++ )
                {
                        reset_eval_cost();
                        "/cmd/pro/family"->main(me, sprintf("%d %d", i * 10, j) );    // i: 无基本; i * 10 基本
                        log_file( LIST_LOG, sprintf( "%d %d %d %d %d %d %d %d\n", 
                                j, me->get_max_hp(), me->get_max_mp(), me->get_ap(), me->get_dp(), me->get_cp(), me->get_pp(), me->get_sp() ) );
                }
        }

        tell_user( me, "请查看 list.txt 文件。" );

        return 1;
}
