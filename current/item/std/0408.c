
#include <ansi.h>
#include <map.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

// 函数：构造处理
void create()
{
        set_name( "回门符" );
        set_picid_1(0408);
        set_picid_2(0408);
        set_unit( "张" );
        set_value(1500);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "传送回门派所在地";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        object map, npc;
        int z, x, y, p;

        if( me->get_fam_name() == "" ) return 0;    // 没有门派

        write_user(me, ECHO "您祭起一张回门符……");

        if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && !map->is_changping() )
        {
                send_user(me, "%c%s", '!', "在战场不能使用回门符。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
        if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "带着钱票不能使用回门符。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
        if( present("贵重物品", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "带着贵重物品不能使用回门符。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
        if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "蒙面人出现，您的行动受到影响。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }

        switch( me->get_fam_name() )
        {
              default : 
        case "桃花源" : z = 289;  p = get_jumpin(z, 20);  break;
          case "蜀山" : z = 273;  p = get_jumpin(z, 20);  break;
        case "禁卫军" : z = 080;  p = get_jumpin(z, 20);  break;
          case "唐门" : z = 324;  p = get_jumpin(z, 20);  break;
          case "茅山" : z = 269;  p = get_jumpin(z, 20);  break;
        case "昆仑山" : z = 054;  p = get_jumpin(z, 20);  break;
        case "云梦泽" : z = 165;  p = get_jumpin(z, 20);  break;
        }

        if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 3, "回门符使用中……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 3);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
}
