
#include <skill.h>
#include <effect.h>

inherit "/inh/item/poison";

// 函数：原料类型
int get_stuff_type() { return 106; }

// 函数：获取毒性点数
int get_poison() { return 100; }

// 函数：构造处理
void create()
{
        set_name( "砒霜" );
        set_picid_1(5210);
        set_picid_2(5210);
        set_unit( "包" );
        set_value(40);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "一种比较常见的毒药，每2秒使玩家气血值下降10点，持续20秒。";
}

// 函数：使用效果
int get_poison_effect( object me, object who, int poison ) { return __FILE__ ->get_poison_effect_callout(me, who, poison); }

// 函数：使用效果(在线更新)
int get_poison_effect_callout( object me, object who, int poison )
{
        if(    !get_effect(who, EFFECT_CHAR_POISON)
        &&     !get_effect(who, EFFECT_CHAR_9140)    // 辟毒散
        &&      random(100) < 100 - who->get_anti_poison() )
        {
                who->set_poison(poison);
                set_effect_2(who, EFFECT_CHAR_POISON, 10, 2);
                send_user( who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD );
        }
        return 1;
}
