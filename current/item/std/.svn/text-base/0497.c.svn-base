
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
        set_name( "脱逃符" );
        set_picid_1(0407);
        set_picid_2(0407);
        set_unit( "张" );
        set_value(5600);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "战场上使用，20 秒后逃离战场";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        object map;

        write_user(me, ECHO "您祭起一张脱逃符……");

        if( !objectp( map = get_map_object( get_z(me) ) ) || map->get_map_type() != BATTLE_MAP ) 
        {
                send_user(me, "%c%s", '!', "只能在战场使用脱逃符。");
                return 0;
        }

        set_effect(me, EFFECT_USER_ESCAPE, 20);
        send_user(me, "%c%c%w%s", 0x5a, 0, 20, "准备逃离战场……");

        return 1;
}

// 函数：停止逃离战场
void effect_escape_break( object me )
{
        set_effect(me, EFFECT_USER_ESCAPE, 0);
        send_user(me, "%c%c%c", 0x5a, 1, 0);    // send_user(me, "%c%c", 0x5a, 255);
}

// 函数：征状处理
void effect_escape_done( object me )
{
        object map, npc;
        string name;
        int z, x, y, p;

        send_user(me, "%c%c%c", 0x5a, 1, 1);    // 清除进度条

        if(     objectp( map = get_map_object( get_z(me) ) ) 
        &&      map->get_map_type() == BATTLE_MAP
        &&    ( name = me->get_org_name() ) != "" 
        &&      objectp( npc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) ) )
        &&    ( z = get_z(npc) )
        &&    ( p = get_valid_xy( z, get_x(npc) + random(11) - 5, get_y(npc) + random(11) - 5, IS_CHAR_BLOCK ) ) ) 
        {
                map->sub_user(me);
                map->sub_user_2(me);

                me->add_to_scene(z, p / 1000, p % 1000, 3);

                switch( me->get_level() )    // 设置玩家种类
                {
            case 0..9 : USER_D->add_level_a_user(me);  break;
          case 10..29 : USER_D->add_level_b_user(me);  break;
              default : USER_D->add_level_c_user(me);  break;
                }
                USER_D->sub_battle_user(me);
        }
}
