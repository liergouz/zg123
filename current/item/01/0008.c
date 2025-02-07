#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int get_item_color() { return 2; }

// 函数：构造处理
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
void create()
{
        set_name("凤凰玉佩");
        set_picid_1(0904);
        set_picid_2(0904);
        set_value(50);
}

// 函数：获取描述
string get_desc()
{
        return "玉佩上雕刻着传说中的神鸟，蕴含着十分强大的魔力。\n能将2级的门派信物提升到3级。\n玩家等级必须达到45级之后才能使用凤凰玉佩。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	object item2;
	if (me->get_level()<45)
	{
		send_user( me, "%c%s", '!', "你当前的等级过低，无法提升师门信物的等级。" );
		return 0;
	}
	item2 = me->get_equip(FAMILY_TYPE);
	if (!item2)
	{
		send_user( me, "%c%s", '!', "你没有师门信物。" );
		return 0;
	}	
	if (item2->is_newplayer())
	{
		send_user( me, "%c%s", '!', "你所佩戴的门派信物不符合使用要求，无法提升等级。" );
		return 0;
	}	
	if (item2->get_item_level()!=2)
	{
		send_user( me, "%c%s", '!', "你所佩戴的门派信物等级不符合升级条件，无法提升等级。" );
		return 0;
	}	
	send_user(me, "%c%c%w%s", ':', 3, 0, "凤凰玉佩使用后会消失，你确定要使用吗？\n"+ESC+"确定\n"+sprintf("use ! %x#\n", getoid(item))+ESC+"取消\nCLOSE\n");
	return 0;
}

// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object me, object item )
{
	object item2;
	if (me->get_level()<45)
	{
		send_user( me, "%c%s", '!', "你当前的等级过低，无法提升师门信物的等级。" );
		return 0;
	}
	item2 = me->get_equip(FAMILY_TYPE);
	if (!item2)
	{
		send_user( me, "%c%s", '!', "你没有师门信物。" );
		return 0;
	}	
	if (item2->is_newplayer())
	{
		send_user( me, "%c%s", '!', "你所佩戴的门派信物不符合使用要求，无法提升等级。" );
		return 0;
	}	
	if (item2->get_item_level()!=2)
	{
		send_user( me, "%c%s", '!', "你所佩戴的门派信物等级不符合升级条件，无法提升等级。" );
		return 0;
	}	
	item2->set_item_level(3);
	item2->init_familyobj();	
	send_user(me, "%c%d%c", 0x31, getoid(item2), 0);
	"/sys/user/energy"->count_all_prop(me);
	return 1;
}