#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
inherit USABLE;   
int get_item_type() { return ITEM_TYPE_SPECIAL; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(80);
        set_picid_2(80);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  	     
}

// ��������ȡ����
string get_desc() 
{
	string name;
	int Gold,iFavour,iStable,iStore;
	
	name = get("special");
	if (name==0) return "";
	sscanf(name,"%d|%d|%d|%d",Gold,iFavour,iStable,iStore);
	return sprintf("���ɲ�����Ʒ�������°��ɺ�\n�Ҽ����ʹ�ÿɵõ����²���������Ʒ\nֻ����2007��1��4��֮��ʹ�á�\n�����ʽ�%d\n����������%d\n���ɰ�����%d\n���ɴ�����%d\n",Gold,iFavour,iStable,iStore);
}

// ������ʹ��Ч��
int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	string name,result;
	object orgnpc;
	int Gold,iFavour,iStable,iStore;
	
	if ( time() < mktime(2007,1,4,0,0,0) )
	{
		send_user(who,"%c%s",'!',"����2007��1��4��֮��ʹ�á�");
		return 0;
	}	
	name = item->get("special");
	if ( !name )
		return 0;
	if ( sscanf(name,"%d|%d|%d|%d",Gold,iFavour,iStable,iStore) != 4 )
		return 0;
	name = who->get_org_name();
	if ( sizeof(name) == 0 )
		return;
	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
	if ( !orgnpc )
		return 0;
	orgnpc->add_gold(Gold);
	orgnpc->add_favour(iFavour);
	orgnpc->add_stable(iStable);
	orgnpc->add_store(iStore);
	result = sprintf("ʹ���˰�����������ʽ�+%d������������+%d�����ɰ�����+%d�����ɴ�����+%d��",Gold,iFavour,iStable,iStore);
	send_user(who,"%c%s",'!',"��"+result);
	FAMILY_D->org_channel( name, 0,HIR+who->get_name()+result);
	return 1;
}