#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
//inherit USABLE;   

// ���������촦��
void create()
{
        set_name("����ʯ");
        set_picid_1(8901);
        set_picid_2(8901);
        set_value(50);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);
          	     
	set_no_save(1);		//�������������
}

// ��������ȡ����
string get_desc() 
{
	return "������Ʒ��װ��100ֻ�ֺ󽻸���һ�ָ��Ա��ȡ������";    	
}

//// ������ʹ��Ч��
//int get_use_effect( object me ) 
//{
//	return __FILE__->get_use_effect_callout(me,this_object());	
//}

int get_use_effect_callout( object who,object item) 
{
}