
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
        string result, arg2;
	int type, i, size;
	object *inv, item;

        if( is_player(me) )
        {
                notify( "您没有足够的权限。" );
		return 1;
        }


        if( arg ==0  )
        {
        	result = sprintf("请选择您的设置：\n");
        	if (me->get_save("no_hurt"))
        		result += ESC "取消无敌\ngmset no_hurt 0\n";
        	else
        		result += ESC "无敌\ngmset no_hurt 1\n";
		if (me->get_save("no_visible"))
			result += ESC "取消隐身\ngmset invisible 0\n";        	
		else
			result += ESC "隐身\ngmset invisible 1\n"; 
		result += ESC "清除身上物品\ngmset clear\n"; 
		result += ESC "气血加倍\ngmset double\n"; 
		result += ESC "气血恢复正常\ngmset normal\n"; 
		result += ESC "气血法力全满\nrecover\n"; 
		result += ESC "取消\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
        }
        if (arg=="clear")
        {
        	inv = all_inventory(me, 1, MAX_CARRY*4);
        	for( i = 0, size = sizeof(inv); i < size; i ++ ) if( objectp( item = inv[i] ) )
        	{
        		item->remove_from_user();
        		destruct(item);
        	}
        	notify( "您的道具已清除。" );
        	return 1;
        }
        if (arg=="double")
        {
        	me->set_max_hp(me->get_max_hp()*2);
        	me->set_hp(me->get_max_hp());
        	return 1;
        }
        if (arg=="normal")
        {
        	"/sys/user/energy"->count_max_hp(me);
        	return 1;
        }        
        if (sscanf(arg, "%s %d", arg2, type)!=2) return 1;
        switch(arg2)
        {
        case "no_hurt":
        	me->set_save("no_hurt", type);
        	if (type==1) notify( "您设置为无敌状态。" );
        	else notify( "您取消了无敌状态。" );
        	break;
        case "invisible":
        	if (type==1)
        	{
	        	set_effect_2( me, EFFECT_CHAR_INVISIBLE, 100, 10 );    // 每十秒减血
        		CHAR_CHAR_D->init_loop_perform(me);
	        	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9000, 1, UNDER_FOOT, PF_LOOP );    // 半透明
			set_invisible(me, 1);
			me->set_save("no_visible", 1);
			send_user( me, "%c%c%c", 0x3d, 241, 2 );
		}
		else
		{
			set_effect_2( me, EFFECT_CHAR_INVISIBLE, 0, 0);
			me->set_save("no_visible", 0);
			set_invisible(me, 0);
			CHAR_CHAR_D->init_loop_perform(me);
			send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9000, 1, UNDER_FOOT, PF_STOP );			
		}
		break;
        }
        return 1;
}
