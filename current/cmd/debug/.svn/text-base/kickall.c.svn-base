
#include <ansi.h>

//int *place = ({ 382, 384, 151, 054, 371, 011, 152, 153, 072, 165, 031, 289, 073, 062, 063, 061, 071, 033, 273, 164, 263, 032, 163, 052, 324, 094, 242, 321, 323, 051, 132, 053, 322, 373, 283, 095, 241, 345, 261, 383, 002, 021, 162, 343, 081, 372, 332, 342, 262, 172, 374, 269, 133, 003, 291, 344, 292, 333, 311, 041, 174, 334, 093, 154, 375, 171, 381, 295, 112, 092, 331, 385, 117, 135, 131, 091, 312, 395, 082, 284, 015, 293, 118, 173, 182, 014, 043, 134, 012, 211, 181, 281, 264, 313, 282, 251, 119, 111, 341, 161, 142, 013, 243, 335, 272, 141, 155, 271, 391, 266, 393, 231, 030, 080, 060, 070, 392, 050, 001, 265, 020, 089, 010, 040, 042, });
int *place = ({ 010, 020, 030, 040, 050, 060, 070, 080 });

#define SUMMON_LOG      "gm/summon.txt"         // 召唤日志文件

// 函数：命令处理
int main( object me, string arg )
{
	object * user, who;
        int z, x, y, x0, y0, p, i, size, number;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arrayp( user = USER_D->get_user() ) ) return 1;
        user -= ({ me });
        size = sizeof(user);
        if (size==0) 
        {
        	tell_user( me, HIY "游戏中没有其他人。" );
        	return 1;
        }
	number = 0;
	for (i=0;i<size;i++)
	{
		who = user[i];
		if (!who) continue;
		z = place[random(sizeof(place))];
		p = get_jumpin(z, -1);
	        if( p )
	        {
	                x = p / 1000;  y = p % 1000;
	                who->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0), 40971, 0, 40971, 0 );
			number ++;
	        }
	        reset_eval_cost();
	}	       
	tell_user( me, sprintf(HIY "你送走了%d个玩家。", number) );
        return 1;
}
