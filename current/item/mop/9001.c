#include <ansi.h>
inherit ITEM;
// ���������촦��
void create()
{
        set_name("�Ͻ�Կ�ס���ͭԿ�ס���ľԿ��");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
        
}
int is_usable() {return 1;}
// ��������ȡ����
string get_desc() 
{ 
        return "װ���Ͻ�Կ�ס���ͭԿ�ס���ľԿ�׵İ������Ҽ�ʹ�ô򿪡�"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	string result;
        if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY-2 )
        {
                send_user(who,"%c%s",'!', "����Ҫ������Ʒ�ռ䡣" );
                return ;
        }		
	gift->remove_from_user();
	destruct(gift);
	item = new ("/item/mop/0202");
	if ( item )
	{		
		p = item->move(who,-1);
		item->add_to_user(p);	
	}
	item = new ("/item/mop/0201");
	if ( item )
	{		
		p = item->move(who,-1);
		item->add_to_user(p);	
	}
	item = new ("/item/mop/0200");
	if ( item )
	{		
		p = item->move(who,-1);
		item->add_to_user(p);	
	}
	send_user(who,"%c%s",'!',"������Ͻ�Կ�ס���ͭԿ�ס���ľԿ�ף�");	
	return 0;
}

