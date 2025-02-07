#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 450 ;}
int get_item_value_2() {return 400 ;}
int get_item_number() {return 10001004 ;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name("大法力石");
        set_picid_1(4233);
        set_picid_2(4233);
        set_value(80);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "一种奇异的蓝色晶石，使用后每2秒可恢复100点法术力。效果持续60分钟。"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( get_effect(who, EFFECT_FALISHI_MP) )
	{
		send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("你身上已经有一个法石在产生作用，你确定要覆盖它的效果吗？\n"ESC"确定\nuse ! %x#\n"ESC"取消",getoid(item))); 
		return 0;
	}
	set_effect_2(who, EFFECT_FALISHI_MP,  1800, 2);
	who->set_save("stone_mp", 200);
	send_user( who, "%c%w%w%c", 0x81, 4, 3600, EFFECT_GOOD );
	return 1;
}

void into_effect(object me)
{
	me->add_mp(me->get_save("stone_mp"));	
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE );
	if (get_effect_3(me, EFFECT_FALISHI_MP)==0) me->set_save("stone_mp", 0);
}

string get_loop_desc(object me)
{
	if (me->get_save("stone_mp")==200)
		return sprintf("小法力石：\n    使用后每2秒可恢复%d点法力值", me->get_save("stone_mp"));
	else
		return sprintf("大法力石：\n    使用后每2秒可恢复%d点法力值", me->get_save("stone_mp"));
}
// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	set_effect_2(who, EFFECT_FALISHI_MP,  1800, 2);
	who->set_save("stone_mp", 200);
	send_user( who, "%c%w%w%c", 0x81, 4, 3600, EFFECT_GOOD );
	send_user( who, "%c%w%s", 0x82, 4, CHAR_CHAR_D->get_loop_desc(who, 4) );
	return 1;
}