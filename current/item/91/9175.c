
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "玄清丹" );
        set_picid_1(9175);
        set_picid_2(9175);
        set_unit( "粒" );
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "永久增加 20 点法术防御力";
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

        if( me->get_mascot("pp") == 0 )
        {
                me->add_mascot("pp", 1);
                USER_ENERGY_D->count_pp(me);
                return 1;
        }
        else 
        {
                send_user(me, "%c%s", '!', get_name() + "一生只能使用 5 次。" );
                return 0;
        }
}
