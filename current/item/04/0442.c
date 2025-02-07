#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("济世葫芦");
        set_picid_1(4271);
        set_picid_2(4271);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
//领取的葫芦
int is_agent() { return 1; }

// 函数：获取描述
string get_desc()
{
	int limit;
	
	limit = get("jishihulu.limit");
	if ( !limit )
	        return "济世普渡的葫芦，在它的经验累积到最大值前，
	        	可以增加你打怪经验的10％";
	return sprintf("济世普渡的葫芦，在它的经验累积到最大值前，
			可以增加你打怪经验的10％
			累积经验 %d/%d\n"
			HIY"点击右键可以返还济世葫芦",get("jishihulu.exp"),get("jishihulu.limit")
			);
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("是否归还济世葫芦\n"ESC"归还葫芦\nhulu 7\n"ESC"取消",)); 
	return 0;
}