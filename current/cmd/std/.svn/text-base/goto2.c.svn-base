
#include <effect.h>
#include <map.h>
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who, item, item2, npc, map,map1;
        int z, x, y, x0, y0, p;
        string arg1, arg2;
        if (sscanf(arg, "%s.%s", arg1, arg2)!=2) return 1;
        if (arg1=="?")			// 使用友情呼唤的人
        {
        	item2 =  present("友情呼唤", me, 1, MAX_CARRY);
        	if (!item2) return 1;
        	if( !(who = find_any_char(arg2) ) ) 
        	{
        		notify( "您输入的ID无效。" );
        		return 1;
        	}
        	if ( !who->is_user()) 
        	{
        		notify( "您输入的ID不是玩家。" );
        		return 1;
        	}
                if( me == who )
                {
                        send_user( me, "%c%s", '!', "您不能传送您自己。" );
                        return 1;
                }        	
        	if (!me->get_leader()||me->get_leader()!=who->get_leader())
        	{
        		notify( "您输入的不是同队伍玩家的ID。" );
        		return 1;
        	}       
                if( objectp( map = get_map_object( get_z(who) ) ) )
                {
                        switch( map->get_map_type() )
                        {
              case BATTLE_MAP : send_user( me, "%c%s", '!', "对方在战场，不能传送。" );
                                return 1;
                        }
                }
                else return 1;
                if( who->get_login_flag() < 3 )
                {
                        send_user( me, "%c%s", '!', "对方还没有准备就绪呢。" );
                        return 1;
                }
                if( who->is_die() )
                {
                        send_user( me, "%c%s", '!', "对方已经死亡。" );
                        return 1;
                }
                if( who->is_store_open() )
                {
                        send_user( me, "%c%s", '!', "对方正在摆摊。" );
                        return 1;
                }
                if( present("贵重物品", who, 1, MAX_CARRY*4) )
                {
                        send_user( me, "%c%s", '!', "对方身上带着贵重物品。" );
                        return 1;
                }
                if( objectp( npc = who->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
                {
                        send_user( me, "%c%s", '!', "对方刚遇到蒙面人。" );
                        return 1;
                }      
                who->set("goto2_fly", me);  	
                send_user( who, "%c%s", ':', me->get_name() + "正在" +  map->get_name() + "呼唤你去他的身边，你要过去吗？\n" 
                                ESC "确定。\n" + sprintf( "goto2 !.%d\n", me->get_number() ) +
                                ESC "取消。\nCLOSE\n" ); 
		item2->add_amount(-1);      
		write_user(me, ECHO "您使用了" HIY "友情呼唤" ECHO "，正等待对方的回应。");                          
		return 1;                                               	
        }
        if (arg1=="!")
        {
        	if( !(who = find_any_char(arg2) ) ) 
        	{
        		return 1;
        	}
        	if ( !who->is_user()) 
        	{
        		return 1;
        	}
                if( me == who )
                {
                        send_user( me, "%c%s", '!', "您不能传送您自己。" );
                        return 1;
                }    
                if (me->get("goto2_fly")!=who) return 1;    	
        	if (!me->get_leader()||me->get_leader()!=who->get_leader())
        	{
        		notify( "您不能传送到非队友处。" );
        		return 1;
        	}         	
                if( objectp( map = get_map_object( get_z(me) ) ) )
                {
                        switch( map->get_map_type() )
                        {
              case BATTLE_MAP : send_user( me, "%c%s", '!', "您在战场，不能传送。" );
                                return 1;
                        }
                }
                else return 1;
                if( objectp( map1 = get_map_object( get_z(who) ) ) )
                {
			if( map1->is_copy_scene() )
		        {
		                send_user(me, "%c%s", '!', "不能传送到副本内。");
		                return 1;
		        }
                }
                else return 1;
                if( me->is_die() )
                {
                        return 1;
                }
                if( me->is_store_open() )
                {
                        send_user( me, "%c%s", '!', "您正在摆摊。" );
                        return 1;
                }
                if( present("贵重物品", me, 1, MAX_CARRY*4) )
                {
                        send_user( me, "%c%s", '!', "您身上带着贵重物品。" );
                        return 1;
                }
                if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
                {
                        send_user( me, "%c%s", '!', "您刚遇到蒙面人。" );
                        return 1;
                }     
                z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);    	
	        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
	        {
	                x = p / 1000;  y = p % 1000;
	
	                me->set_login_flag(2);    // 跳转保护
	                set_invisible(me, 1);
	                set_effect(me, EFFECT_USER_LOGIN, 4);
	
	                me->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );
	
	                tell_user( me, "您去到: %d (%d, %d)。", z, x, y );
			return 1;
	        }
	        else 
	        {
	        	if (who)
	                	notify( "您去不了%s那里。", who->get_name() );
	                else
	                	notify( "您去不了那里。" );
			return 1;
	        }                
        }
 	return 1;
}
