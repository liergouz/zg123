#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name( "��������" );
        set_picid_1(4101);
        set_picid_2(4101);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// ��������ȡ����
string get_desc() 
{ 
        return "������Ʒ������������������ǡ�"; 
}

void say_hello(int i)
{
	object who;
	who = environment();
	if ( !who )
		return ;
	if ( i == 1 )
		send_user(who, "%c%c%d%s", 0x43, 6,0,CHAT "��׷���������������㻹����ô�����Ҵ��ˡ��������õ�ô����ѹ�������Ϣ��ɢ�˰ɡ���");
	else if ( i == 2 )
		send_user(who, "%c%c%d%s", 0x43, 6,0,CHAT "������������һֱ���õ��ġ���ֻ�ǿڲ����ԡ�檲��֣���ڼ��������ܼޣ�ʱʱ����Я��ڷɡ�����δ���ƶ��񣬿�������Ϊ����Ѿ�������");
	else if ( i == 3 )
		send_user(who, "%c%c%d%s", 0x43, 6,0,CHAT "��׷����Щ�˿��԰��㻹�ֻ꣡�������������ȥ�����������䡰�������������");
	else if ( i == 4 )
		send_user(who, "%c%c%d%s", 0x43, 6,0,CHAT "��������Ҫ���ң�ֻԸ����������������Ϊ�������ڵ�Ϊ����֦����");
	else if ( i == 5 )
		send_user(who, "%c%c%d%s", 0x43, 6,0,CHAT "��׷����������Ҫ�úõġ���������Ե������ȴ��Ҫһ�𡭡�");
	else if ( i == 6 )
	{
		send_user(who, "%c%c%d%s", 0x43, 6,0,CHAT "���������ɰ�����");
		return ;
	}
	else
		return;
	call_out("say_hello",4,i+1);
}