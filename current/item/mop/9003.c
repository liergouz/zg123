#include <ansi.h>
inherit ITEM;

int get_item_value() {return 190 ;}
int get_item_value_2() {return 190 ;}
int get_item_number() {return 10001099 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(3025);
        set_picid_2(3025);
        set_value(198);
        
}
int is_usable() {return 1;}
// ��������ȡ����
string get_desc() 
{ 
        return "��ս�������������ں�����ս����ϡ��Ʒ���ۼ�390Ԫ����"; 
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
	string *item_g=({"/item/08/0015","/item/54/8100","/item/sell/0033","/item/mop/0202","/item/sell/0045","/item/sell/0034","/item/08/0001","/item/sell/0043","/item/sell/0044","/item/sell/0029","/item/sell/0060","/item/sell/0041","/item/sell/0030"});
        if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY-12 )
        {
                send_user(who,"%c%s",'!', "����Ҫ13����Ʒ�ռ䣬��������һ���ٴ�����ɣ�" );
                return ;
        }		
	gift->remove_from_user();
	destruct(gift);

	for (index=0;index<13;index++)
	{
		item = new (item_g[index]);
		if ( item )
		{		
			p = item->move(who,-1);
			item->add_to_user(p);	
		}
	}
	send_user(who,"%c%s",';',"������˸ɽ���ʯ�����޿���³�౦ʯ���Ͻ�Կ�ס���������������׷���ս�������֥�顢���������з��������˲��������ҡ�ħ������");
	return 0;
}

