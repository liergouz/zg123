// make/item/make_ss_item生成

#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_item_number() {return 10001080 ;}   
int get_item_color() { return 2;};
// 函数：构造处理
void create()
{
        set_name("狮子");
        set_picid_1(3025);
        set_picid_2(4264);
        set("picid",3025);
        set_value(888);
        set_no_give(1);
}

// 函数：获取描述
string get_desc() 
{
	return "十二星座之一的狮子座";
}
// 函数：使用效果
int get_use_effect( object me )
{
	send_user( me, "%c%c%w%s", ':', 3, 0,sprintf("使用后将会获得神兽，是否使用？\n"ESC"确定\nuse ! %x#\n"ESC"取消",getoid(this_object()))); 
	return 0;
}
// 函数：使用效果
int confirm_use( object me ) 
{ 
	return "sys/user/beast"->use_shenshou_item(me,this_object());
}
