#include <ansi.h>
inherit ITEM;
// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
        
}
int is_usable() {return 1;}
// ��������ȡ����
string get_desc() 
{ 
        return "ս����1����ս���Ž�1�����з�����1����СѪʯ1������������1����"; 
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
	string *item_g=({"/item/08/0001","/item/08/0002","/item/sell/0028","/item/08/0003","/item/sell/0044",});
        if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY-4 )
        {
                send_user(who,"%c%s",'!', "����Ҫ5����Ʒ�ռ䣬��������һ���ٴ�����ɣ�" );
                return ;
        }		
	gift->remove_from_user();
	destruct(gift);

	for (index=0;index<5;index++)
	{
		item = new (item_g[index]);
		if ( item )
		{		
			p = item->move(who,-1);
			item->add_to_user(p);	
		}
	}
	send_user(who,"%c%s",';',"�������ս����1����ս���Ž�1�����з�����1����СѪʯ1������������1����");
	return 0;
}
