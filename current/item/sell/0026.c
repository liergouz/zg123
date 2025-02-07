#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <city.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 999 ;}
int get_item_value_2() {return 888 ;}
int get_item_number() {return 10001021 ;}
int get_item_color() {return 1 ;}


// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(3562);
        set_picid_2(3562);
        set_value(180);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// ��������ȡ����
string get_desc() 
{ 
        return "һ��������廨�룬�ۼ������������\ʹ�ú���ʹ���ɰ�������1000����ȴ2�롣"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( !sizeof(who->get_org_name()) )
	{
		send_user(who,"%c%s",'!',"��û�м����κεİ��ɣ��޷�ʹ�ö������롣");
		return 0;	
	}
	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"��û�м����κεİ��ɣ��޷�ʹ�ö������롣");
		return 0;	
	}
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("ʹ�øõ��ߺ���ɵİ����Ȼ�����1000�㣬��ȷ��Ҫʹ����\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",getoid(item))); 
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
		send_user(who,"%c%s",'!',"��û�м����κεİ��ɣ��޷�ʹ�ö������롣");
		return 0;	
	}
	if ( gone_time(who->get("use0026")) < 2 )
	{
		send_user(who,"%c%s",'!',"�벻ҪƵ��ʹ�ã�");
		return 0;	
	}
	org = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
	if ( !org )
	{
		send_user(who,"%c%s",'!',"���İ�����������");
		return 0;	
	}
	if (org->get_stable()==10000)
	{
		send_user(who,"%c%s",'!',"���ɰ����Ѵ����ֵ��");
		return 0;	
	}	
	who->set("use0026",time());

	org->add_stable(1000);
	org->save();
	return 1;
}