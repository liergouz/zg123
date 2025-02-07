#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <city.h>

inherit COMBINED;
inherit ITEM;

int get_item_color() {return 1 ;}


// ���������촦��
void create()
{
        set_name("�޵�����");
        set_picid_1(3562);
        set_picid_2(3562);
        set_value(150000);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "һ���޵��������廨�룬�ۼ���������������������ɵ���������������Ǯ��������"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( !sizeof(who->get_org_name()) )
	{
		send_user(who,"%c%s",'!',"��û�а��ɣ�");
		return 0;	
	}
	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"��������ֻ���ǰ��ɳ�Աʹ�á�");
		return 0;	
	}
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("ʹ�øõ��ߺ���ɵ���ֵȫ������ȷ��Ҫʹ����\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",getoid(item))); 
	return 0;
}

string get_loop_desc(object me)
{
	return "ʹ�ú���ʹ���ɵİ���������1000��";
}
// ������ʹ��Ч��
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int confirm_use_callout( object who, object item )
{
	object org;

	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"��������ֻ���ǰ��ɳ�Աʹ�á�");
		return 0;	
	}
	if ( gone_time(who->get("use0026")) <= 2 )
	{
		send_user(who,"%c%s",'!',"�벻ҪƵ��ʹ�ã�");
		return 0;	
	}
	who->set("use0026",time());
	org = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
	if ( !org )
		return 0;
	org->add_stable(100000000);
	org->add_favour(100000000);
	org->add_store(100000000);
	org->add_gold(100000000);
	org->save();
	return 1;
}
