#include <ansi.h>
inherit ITEM;
// ���������촦��
void create()
{
        set_name("�������ʯ");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
        
}
int is_usable() {return 1;}
// ��������ȡ����
string get_desc() 
{ 
        return "װ���������ʯ�İ������Ҽ�ʹ�ô򿪡�"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,index;
	object item;
	string result;
        if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY-4 )
        {
                send_user(who,"%c%s",'!', "����Ҫ�����Ʒ�ռ䡣" );
                return ;
        }		
	gift->remove_from_user();
	destruct(gift);
	for (index=0;index<5;index++)
	{
		item = new ("/item/sell/9304");
		if ( item )
		{		
			p = item->move(who,-1);
			item->add_to_user(p);	
		}
	}
	send_user(who,"%c%s",'!',"������������ʯ��");	
	return 0;
}
