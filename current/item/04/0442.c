#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("������«");
        set_picid_1(4271);
        set_picid_2(4271);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
//��ȡ�ĺ�«
int is_agent() { return 1; }

// ��������ȡ����
string get_desc()
{
	int limit;
	
	limit = get("jishihulu.limit");
	if ( !limit )
	        return "�����նɵĺ�«�������ľ����ۻ������ֵǰ��
	        	�����������־����10��";
	return sprintf("�����նɵĺ�«�������ľ����ۻ������ֵǰ��
			�����������־����10��
			�ۻ����� %d/%d\n"
			HIY"����Ҽ����Է���������«",get("jishihulu.exp"),get("jishihulu.limit")
			);
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("�Ƿ�黹������«\n"ESC"�黹��«\nhulu 7\n"ESC"ȡ��",)); 
	return 0;
}