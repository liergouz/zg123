
#include <skill.h>
#include <effect.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_color() { return 1; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "天王散" );
        set_picid_1(9150);
        set_picid_2(9150);
        set_unit( "包" );
        set_value(2000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "二十分钟内气血、法力、攻击、防御、法攻、法防增强 45%，但之后半小时元气大伤";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        if( get_effect(me, EFFECT_CHAR_KING) || get_effect(me, EFFECT_CHAR_KING_2) ) 
        {
                send_user(me, "%c%s", '!', "您正在使用" + get_name() + "之中。" );
                return 0;
        }

/*      if( gone_time( me->get_time("eat") ) < 1 )
        {
                me->set_time( "eat", time() );
                return 0;
        }
        me->set_time( "eat", time() );  */

        set_effect(me, EFFECT_CHAR_KING, 1200 );
        send_user( me, "%c%w%w%c", 0x81, 9150, get_effect_3(me, EFFECT_CHAR_KING), EFFECT_GOOD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 9150, 1, EFFECT_GOOD );

        USER_ENERGY_D->count_max_hp(me);
        USER_ENERGY_D->count_max_mp(me);
        USER_ENERGY_D->count_cp(me);    // cp/pp 影响 ap/dp, 所以放前
        USER_ENERGY_D->count_pp(me);
        USER_ENERGY_D->count_ap(me);
        USER_ENERGY_D->count_dp(me);

        return 1;
}
