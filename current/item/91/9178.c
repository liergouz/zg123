#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() {return 350 ;}
int get_item_value_2() {return 250 ;}
int get_item_number() {return 10001018 ;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name( "复生丹" );
        set_picid_1(9120);
        set_picid_2(9120);
	set_value(188);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "注满了生命之力奇异丹药，据说能拯救亡者的灵魂。\n在玩家死亡后可帮助玩家复活，免除死亡的惩罚。\n玩家可选择原地复活或者当前场景随机一个跳转点复活两种复活方式。\n复活后气血与法力全部恢复。";
}

// 函数：使用效果
int revive( object me, int type ) { return __FILE__ ->revive_call(me,this_object(), type); }

// 函数：使用效果(在线更新)
int revive_call( object me,object item, int type)
{
	int z, x, y, p;
        if( me->is_die() )
        {
                set_effect(me, EFFECT_USER_DIE, 0);
                me->set_die(0);
                me->set_hp( me->get_max_hp() );
                me->set_mp( me->get_max_mp() );

                me->set_login_flag(2);    // 跳转保护
                set_invisible(me, 1);
                set_effect(me, EFFECT_USER_LOGIN, 2);
                item->add_amount(-1);
        }
        if (type==2)
        {
        	z = get_z(me);
        	p = get_jumpin(z, -1);
        	if( p )
        	{
        		x = p / 1000;  y = p % 1000;
        		me->add_to_scene(z, x, y, 3);
        	}
        }
        return 1;
}
