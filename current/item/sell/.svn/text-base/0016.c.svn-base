#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 750 ;}
int get_item_value_2() {return 650 ;}
int get_item_number() {return 10001013 ;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name( "精神洗点丸" );
        set_picid_1(9167);
        set_picid_2(9167);
        set_value(50);
        set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "能返还玩家所有精神点数的神奇丹药。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        int point;
	point = me->get_spi_2();             
	if (point==0) 
	{
		send_user(me, "%c%s", '!', "你并无分配点数到精神中，不能使用洗点丸。");
		return 0;      
	}        
	me->set_spi_2(0);
	me->add_gift_point(point);
	write_user(me, ECHO "你成功洗掉了%d点的精神。", point);
	return 1;	                        
} 