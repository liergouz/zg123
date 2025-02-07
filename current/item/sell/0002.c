#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 450 ;}
int get_item_value_2() {return 400 ;}
int get_item_number() {return 10001002 ;}
int get_item_color() {return 1 ;}


// ���������촦��
void create()
{
        set_name("��Ѫʯ");
        set_picid_1(4235);
        set_picid_2(4235);
        set_value(50);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// ��������ȡ����
string get_desc() 
{ 
        return "һ������ĺ�ɫ��ʯ��ʹ�ú�ÿ2��ɻָ�90����Ѫֵ��Ч������60���ӡ�"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( get_effect(who, EFFECT_XUESHI_HP) )
	{
		send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("�������Ѿ���һ��Ѫʯ�ڲ������ã���ȷ��Ҫ��������Ч����\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",getoid(item))); 
		return 0;
	}
	set_effect_2(who, EFFECT_XUESHI_HP,  1800, 2);
	who->set_save("stone_hp", 200);
	send_user( who, "%c%w%w%c", 0x81, 2, 3600, EFFECT_GOOD );
	return 1;
}

void into_effect(object me)
{
	me->add_hp(me->get_save("stone_hp"));	
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE );
	if (get_effect_3(me, EFFECT_XUESHI_HP)==0) me->set_save("stone_hp", 40);
}

string get_loop_desc(object me)
{
	if (me->get_save("stone_hp")==200)
		return sprintf("СѪʯ��\n    ʹ�ú�ÿ2��ɻָ�%d����Ѫֵ", me->get_save("stone_hp"));
	else
		return sprintf("��Ѫʯ��\n    ʹ�ú�ÿ2��ɻָ�%d����Ѫֵ", me->get_save("stone_hp"));
}
// ������ʹ��Ч��
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int confirm_use_callout( object who, object item )
{
	set_effect_2(who, EFFECT_XUESHI_HP,  1800, 2);
	who->set_save("stone_hp", 200);
	send_user( who, "%c%w%w%c", 0x81, 2, 3600, EFFECT_GOOD );
	send_user( who, "%c%w%s", 0x82, 2, CHAR_CHAR_D->get_loop_desc(who, 2) );
	return 1;
}