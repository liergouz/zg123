#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
//inherit USABLE;   

// ���������촦��
void create()
{
        set_name("���޴�Խ֤����");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(50);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);  	     
	set_no_save(1);		//�������������
}

// ��������ȡ����
string get_desc() 
{
	return "������Ʒ���뾡�콻�붫�����������ļ��޴�Խ���١�";    	
}

//// ������ʹ��Ч��
//int get_use_effect( object me ) 
//{
//	return __FILE__->get_use_effect_callout(me,this_object());	
//}

int get_use_effect_callout( object who,object item) 
{
}