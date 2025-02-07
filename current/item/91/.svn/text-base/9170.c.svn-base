
inherit ITEM;
inherit USABLE;

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "培元丹" );
        set_picid_1(9170);
        set_picid_2(9170);
        set_unit( "粒" );
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "永久增加 150 点气血上限";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
/*      if( gone_time( me->get_time("eat") ) < 1 )
        {
                me->set_time( "eat", time() );
                return 0;
        }
        me->set_time( "eat", time() );  */

        if( me->get_mascot("hp") == 0 )
        {
                me->add_mascot("hp", 1);
                USER_ENERGY_D->count_max_hp(me);
                return 1;
        }
        else 
        {
                send_user(me, "%c%s", '!', get_name() + "一生只能使用 5 次。" );
                return 0;
        }
}
