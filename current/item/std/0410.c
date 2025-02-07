
#include <ansi.h>
#include <map.h>
#include <city.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

// 函数：构造处理
void create()
{
        set_name( "回帮符" );
        set_picid_1(0408);
        set_picid_2(0408);
        set_unit( "张" );
        set_value(1400);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "传送回自己的帮派院落。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        object map, npc, orgnpc;
        int z, x, y, p;
        string name;

        if( me->get_org_name() == "" )
        {
        	send_user(me, "%c%s", '!', "你没有加入任何帮派，无法使用回帮符。");
        	return 0;
        } 
        if( me->get_org_name() == 0 ) 
        {
        	send_user(me, "%c%s", '!', "你没有加入任何帮派，无法使用回帮符。");
        	return 0;
        } 
        if (me->get_org_position()<1)
        {
        	send_user(me, "%c%s", '!', "你没有加入任何帮派，无法使用回帮符。");
        	return 0;
        }        

        if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && !map->is_changping() )
        {
                send_user(me, "%c%s", '!', "在战场不能使用回帮符。");
                return 0;
        }
        if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "带着钱票不能使用回帮符。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
        if( present("贵重物品", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "带着贵重物品不能使用回帮符。");
//              write_user(me, ECHO "……可是没有任何效果。");
                return 0;
        }
        if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "蒙面人出现，您的行动受到影响。");
                return 0;
        }
        name = me->get_org_name();
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if (!objectp(orgnpc)) return;
	map = orgnpc->get("map");        
	if (map==0)
	{
		if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
		{
			p = 886;
			init_virtual_map(z, p);    // 生成虚拟地图
			map = new( "/inh/std/org" );
			map->set_client_id(p);
			set_map_object( map, map->set_id(z) );
			orgnpc->set("map", map);
			orgnpc->set("z", z);
			map->set_name(name);
			"/sys/sys/manager"->init_org_place(z, name, orgnpc);
		}
		else
			return ;
	}
	else
	{
		z = orgnpc->get("z");
	}        
	if (random(2)) p = get_jumpin(z, 11);
	else p = get_jumpin(z, 12);	
        write_user(me, ECHO "您祭起一张回帮符……");

        if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 3, "回帮符使用中……");	                
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
